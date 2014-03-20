#ifndef __HAVE_CNF_H_
#define __HAVE_CNF_H_

#include <string>
#include <vector>
#include <stdexcept>
#include <map>
#include <istream>
#include <ostream>

// vynimky
#include <ios>
#include <stdexcept>

/**
 * Interpretacia: mapovanie z mien premennych
 * na true/false.
 */
typedef std::map<std::string, bool> Interpretation;

/**
 * Mapovanie mien premennych na cisla.
 * Premennym vzdy priraduje suvisly usek cisel 1 .. n.
 */
class VariableMap {
public:
	/**
	 * Vytvori nove mapovanie, ktore bude obsahovat
	 * premenne z pola variables.
	 * TODO Priradi im hodnoty v poradi ako su.
	 */
	VariableMap(std::vector<std::string> variables);

	/**
	 * Prida premennu var.
	 * Ak uz je v mape, nic sa nestane, ak nie je, prida sa
	 * s dalsim cislom v poradi.
	 */
	VariableMap& addVar(std::string var);

	/**
	 * Vrati cislo priradene premennej s menom var.
	 *
	 * Vyhodi std::out_of_range vynimku, ak taka premenna nie je v mape.
	 */
	int get(std::string var) const;

	/**
	 * Vrati csilo priradene premennej s menom var.
	 *
	 * Vyhodi std::out_of_range vynimku, ak taka premenna nie je v mape.
	 */
	int operator[](std::string var) const;

	/**
	 * Vrati textovu reprezentaciu mapovania premennych.
	 * Napriklad vo formate "{'a':1, 'b':2, ... }",
	 * alebo podobnom.
	 * Podmienkou je, ze reprezentacie tych istych mapovani
	 * musia byt rovnake.
	 */
	std::string toString() const;

	/**
	 * Vrati zoznam premennych, ktore tato trieda mapuje
	 * na cisla.
	 */
	std::vector<std::string> keys() const;

	/**
	 * Vrati reverzne mapovanie ako jednoduchu
	 * mapu z int na std::string.
	 */
	std::map<int, std::string> reverse() const;

	/**
	 * Zapise mapovanie do suboru (stream-u) outFile.
	 */
	void writeToFile(std::ostream &outfile) const;

	/**
	 * Nacita mapovanie zo suboru inFile.
	 */
	static VariableMap readFromFile(std::istream &inFile);
};

/**
 * Reprezentacia literalu (premenna alebo negovana premenna)
 * v CNF formule.
 */
class CnfLit {
	std::string m_name;
	bool m_neg = false;
public:
	/**
	 * Vytvori novy, kladny (nenegovany) literal
	 * pre premennu name.
	 */
	CnfLit(std::string name);

	/**
	 * Vytvori novy, negovany literal pre
	 * premennu name.
	 */
	static CnfLit Not(std::string name);

	/**
	 * Vrati novy literal, ktory je negaciou tohoto.
	 */
	CnfLit operator-() const;

	/**
	 * Vrati meno premennej.
	 */
	std::string name() const;
	/**
	 * Vrati true ak je tento literal negaciou premennej,
	 * false ak je to nenegovana premenna.
	 */
	bool neg() const;

	/**
	 * Vrati textovu reprezentaciu tohoto literalu.
	 */
	std::string toString() const;
	/**
	 * Vrati ohodnotenie tohoto literalu pri interpretacii i.
	 */
	bool eval(const Interpretation &i) const;

	/**
	 * Rozsiri varMap o premennej tohoto literalu.
	 */
	void extendVarMap(VariableMap &varMap) const;

	/**
	 * Zapise literal do suboru (stream-u) outFile.
	 */
	void writeToFile(std::ostream &outFile, const VariableMap &varMap) const;
};

/**
 * Reprezentacia klauzy (pola literalov)
 */
class CnfClause : public std::vector<CnfLit>
{
public:
	/**
	 * Vytvori novu klauzu obsahujucu literaly
	 * literals.
	 */
	CnfClause(const std::vector<CnfLit> &literals);
	/**
	 * Copy constructor.
	 * Vytvori klauzu ako kopiu inej.
	 */
	CnfClause(const CnfClause &other);

	/**
	 * Vrati textovu reprezentaciu klauzy.
	 * Vid. zadanie.
	 */
	std::string toString() const;

	/**
	 * Vyhodnoti ohodnotenie tejto klauzy pri interpretacii i.
	 */
	bool eval(const Interpretation &i) const;

	/**
	 * Rozsiri mapovanie varMap o premennej v tejto klauze.
	 */
	void extendVarMap(VariableMap &varMap) const;

	/**
	 * Zapise klauzu do suboru outFile v DIMACS formate,
	 * pouzije varMap na zakodovanie premennych na cisla.
	 * Klauzu zapise na jeden riadok (ukonceny znakom konca riadku).
	 */
	void writeToFile(std::ostream &outFile, const VariableMap &varMap) const;

	/**
	 * Nacita novu klauzu zo suboru inFile a vrati ju ako vysledok.
	 * Mozete predpokladat, ze klauza je samostatne na jednom riadku.
	 *
	 * Ak sa z aktualneho riadku na vstup neda nacitat korektna klauza,
	 * vyhodi vynimku std::ios_base::failure (s rozumnym textom).
	 */
	static CnfClause readFromFile(std::istream &inFile, const VariableMap &varMap);
};


/**
 * Reprezentacia Cnf formuly ako pola klauz.
 */
class Cnf : public std::vector<CnfClause>
{
public:
	/**
	 * Vytvori novu cnf formulu obsahujucu klauzy
	 * clauses.
	 */
	Cnf(const std::vector<CnfClause> &clauses);

	/**
	 * Copy constructor.
	 * Vytvori cnf formulu ako kopiu inej.
	 */
	Cnf(const Cnf &other);


	/**
	 * Vrati textovu reprezentaciu formuly.
	 * Vid. zadanie.
	 */
	std::string toString() const;

	/**
	 * Vyhodnoti ohodnotenie tejto formuly pri interpretacii i.
	 */
	bool eval(const Interpretation &i) const;

	/**
	 * Rozsiri mapovanie varMap o premennej v tejto formule.
	 */
	void extendVarMap(VariableMap &varMap) const;

	/**
	 * Zapise formulu do suboru outFile v DIMACS formate,
	 * pouzije varMap na zakodovanie premennych na cisla.
	 * Zapise kazdu klauzu na jeden riadok.
	 */
	void writeToFile(std::ostream &outFile, const VariableMap &varMap) const;

	/**
	 * Nacita novu formuluu zo suboru inFile a vrati ju ako vysledok.
	 * Mozete predpokladat, ze klauza je samostatne na jednom riadku.
	 */
	static Cnf readFromFile(std::istream &inFile, const VariableMap &varMap);
};

#endif
