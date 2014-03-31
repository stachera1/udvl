Cvičenie 7
==========

**Riešenie odovzdávajte podľa
[pokynov na konci tohoto zadania](#technické-detaily-riešenia)
do Štvrtka 16.4. 23:59:59.**

Súbory potrebné pre toto cvičenie si môžete stiahnúť ako jeden zip
[`cv07.zip`](https://github.com/FMFI-UK-1-AIN-411/udvl/archive/cv07.zip).

toCnf (4b)
----------

Do tried na reprezentáciu formúl z cvičenia 3 doimplementujte metódu `toCnf()`,
ktorá vráti ekvisplniteľnú (alebo equivalentnu) formulu v konjunktívnej
normálnej forme reprezentovanú pomocou tried z cvičenia 5.

Na prednáške bolo spomenutých niekoľkoľko rôznych prístupov s rôznymi
vlastnosťami. Pri našej reprezentácii formúl je asi najjednoduchšií (na
naprogramovanie :) spôsob taký, že každej z našich predchádzajúcich tried
implementujeme virtuálnu metódu toCnf, ktorá daný typ preloží do Cnf, s tým, že
rekurívne zavolá toCnf na svoje podformuly a potom ich nejak spojí / upraví.

Premenná jednoducho vráti Cnf s jednou Cnf klauzou v ktorej je jedna Cnf premenná

Konjunkcia zavolá toCnf na jednotlivé konjunkty, dostane niekoľko Cnf a vyrobí
z nej jednu tak, že jednoducho dá dokopy všetky Cnf klauzy.

Disjunkcia už je zložitejšia, pretože čiastočné Cnf pre jednotlivé disjunkty
musíme medzi sebou "roznásobiť", pričom roznásobujeme ľubovoľne veľa
disjunktov, ktoré môžu obsahovať ľubovoľne veľa klauz.

V prípade negácie sa dostaneme tiež k podobnému problému (oplatí sa
optimalizovať / špecialne ošetriť prípad keď je v nej iba premenná).

Implikácia (a podobne aj ekvivalencia) sa najjednoduchšie implemetuje tak, že z
nej spravíme disjunkciu a zavoláme toCnf na nej :) (pri takýchto operáciách si
ale treba dať pozor na "zacyklenie").

Príklad pre disjunkciu:
```python
class Disjunction(Formula):
    def doProduct(self, cnfs, level, rClause, rCnf):
        if level < len(cnfs):
            for clause in cnfs[level]:
                extRClause = copy.deepcopy(rClause)
                extRClause.extend(copy.deepcopy(clause))
                self.doProduct(cnfs, level+1, extRClause, rCnf)
        else:
            rCnf.append(rClause)

    def toCnf(self):
        # prevedieme vsetky podrofmuly do cnf
        cnfs = []
        for sf in self.subf():
            cnfs.append(sf.toCnf())

        # roznmasobime ich, pricom vzniknute klauzy
        # ukladame do c
        c = cnf.Cnf()
        self.doProduct(cnfs, 0, cnf.CnfClause(), c)
        return c
```

## Technické detaily riešenia

Riešenie odovzdajte do vetvy `cv07` v adresári `cv07`.  Odovzdávajte
(modifikujte) súbor `formula.py`. Program [`cv07test.py`](cv07test.py) musí
korektne zbehnúť s vašou knižnicou.

Súbory `formula.py` a `cnf.py` obsahujú vzorové riešenia predchádzajúcich
cvičení.  Vašou úlohou je doimplementovať metódu toCnf pre každú triedu
odvodenú od `Formula`.

Odovzdávanie riešení v iných jazykoch konzultujte s cvičiacimi.

## Bonus

Uvedená "jednoduchá" metóda je veľmi neefektívna vzhľadom na veľkosť /
komplikovanosť výsledných formúl. Napríklad pre niektoré formuly
stupňa menšieho ako 10 vyrobíme CNF obsahujúce desaťtisíce až
stotisíce literálov.

Ak implementujete nejakú efektívnejšiu (vzhľadom na veľkosť výslednej
formuly, ale pozor aj na čas behu) metódu na konverziu do CNF, uveďte
to v pull requeste s krátkym popisom vášho algoritmu (odkaz na nejaký
internetový zdroj je OK, implementácia ale musí byť vaša vlastná) a
môžete získať až 4 bonusové body.
