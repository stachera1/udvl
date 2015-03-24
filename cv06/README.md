Cvičenie 6
==========

**Riešenie odovzdávajte podľa
[pokynov na konci tohoto zadania](#technické-detaily-riešenia)
do Štvrtka 2.4. 23:59:59.**


Súbory potrebné pre toto cvičenie si môžete stiahnúť ako jeden zip
[`cv06.zip`](https://github.com/FMFI-UK-1-AIN-411/udvl/archive/cv06.zip).

Tablo (4b)
------------------

Implementujte tablový algoritmus.

Vaše riešenie sa má skladať z dvoch častí:

- do tried na reprezentáciu formúl z cvičenia 3 doimplementujte
  metódy `signedSubf` a `getType`, ktoré reprezentujú informácie o
  tablových pravidlách pre jednotlivé typy formúl
- implementujte triedu `TableauBuilder` obsahujúcu metódu `build`,
  ktorá dostane zoznam označených formúl a vytvorí pre ne úplné (alebo
  uzavreté) tablo

### Označené formuly a tablové pravidlá

Označené formuly reprezentujeme ako dvojice `(sign, formula)`, kde
`sign` je buď `True` (značka `T`) alebo `False` (značka `F`).

Metóda `getType(sign)` vráti akého typu (&alpha; alebo &beta;) by dotyčná
formula bola, ak by bola označená značkou `sign` (negácia a premenná sú vždy
typu &alpha;).

Metóda `signedSubf` vráti "podformuly" označenej formuly,
tj &alpha;<sub>1</sub> a &alpha;<sub>2</sub> ak by bola typu &alpha;
a &beta;<sub>1</sub> a &beta;<sub>2</sub> ak by bola typu &beta;.

Pamätajte, že konjukcia a disjunkcia môžu mať viacero podformúl, takže
tablové pravidlá v skutočnosti vyzerajú nasledovne:

```
 T A1 ∧ A2 ∧ A3 ∧ ... ∧ An           F A1 ∧ A2 ∧ A3 ∧ ... ∧ An
 ───────────────────────────      ──────┬──────┬──────┬─────┬──────
           T A1                    F A1 │ F A2 │ F A3 │ ... │ F An
           T A2
           T A3
           ...
           T An
```
Ekvivalencia je konjunkcia dvoch implikácií ((A⇔B) je ekvivalentné
((A⇒B)∧(B⇒A)), takže pravidlá pre ňu vyzerajú podobne ako pre konjunkciu, len
podformule majú trošku zložitejší tvar:

```
 T A⇔B             F A⇔B
───────       ───────┬───────
 T A⇒B         F A⇒B │ F B⇒A
 T B⇒A
```

### Tablo

Tablo, ktoré vytvorí metóda `TableauBuilder::build` bude reprezentované ako
strom vytvorený z objektov `tableau.Node` definovaných v knižnici
[`tableau.py`](tableau.py). Ukážková implementácia v [`builder.py`](builder.py)
iba vytvorí prázdne tablo a následne doň popridáva "vstupné" formuly.

Pri vytváraní ďalších formúl potom treba vždy ako tretí parameter konštruktora
`Node` uviesť referenciu na formulu, z ktorej vznikla (`source`).

Keď pridáme formulu, ktorá uzatvára vetvu, treba ju "označiť" volaním metódy
`close`, ktorá má ako parameter referenciu na príslušnú formulu, s ktorou sa
uzavrela.

## Technické detaily riešenia

Riešenie odovzdajte do vetvy `cv06` v adresári `cv06`.  Odovzdávajte
(modifikujte) súbory `formula.py` a `builder.py`.  Program
[`cv06test.py`](cv06test.py) musí korektne zbehnúť s vašou knižnicou.

Odovzdávanie riešení v iných jazykoch konzultujte s cvičiacimi.
