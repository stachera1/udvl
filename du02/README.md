Domáca úloha 2
==============

Domácu úlohu odovzdávajte do štvrtku 9.4. 13:10 (t.j. najneskôr
na začiatku štvrtkových cvičení).

Úlohu odovzdávajte buď fyzicky na papier formátu A4 (čitateľne označenom a
podpísanom) na prednáške alebo na cvičeniach, alebo elektronicky vo formáte PDF
(ako súbor `du02.pdf`), ako obyčjaný textový alebo súbor (`du02.txt`), alebo
ako súbor v GitHub Markdown formáte (`du02.md`) do vetvy `du02`. Nezabudnite vyrobiť
pull request.

Wordovské dokumenty, obrázky a skenované / fotografované riešenia nebudú hodnotené.

Bohužiaľ cez webové rozhranie sa na GitHub dajú súbory len priamo písať alebo
copy-paste-ovať, binárne súbory treba nahrať pomocou GIT-u
([msysgit](http://msysgit.github.io/) alebo čistý
[git](http://git-scm.com/downloads)) alebo [github programu pre
windows](http://windows.github.com/) respektíve pre
[Mac](http://mac.github.com/).  Samozrejme potom treba ešte (cez webové
rozhranie) vyrobiť pull request.

## 2.1 (2b)

O každej z nasledovných formúl rozhodnite a **dokážte** či je alebo nie je
i) splniteľná, ii) tautológia, iii) občas pravdivá:

a) ((a→b)→(b→a))

b) ((a→(b→(c∨d)))∧¬((a→b)→((a∧¬d)→c)))

c) ((¬a∨¬b)→c)→((¬a→c)∧b)

d) (((a∧(b∧¬c))∨d)→((¬d→(a∨e))∧((¬b∨(c∧d))→(d∨e))))

Z minulej DU: formula X je **občas pravdivá** práve vtedy, keď existuje aspoň
jedno boolovské ohodnotenie, pri ktorom je pravidvá a aspoň jedno boolovské
ohodnotenie, pri ktorom je nepravdivá.

## 2.2 (2b)

Predment môže študent úspešne absolvovať iba vtedy, keď odovzdá domáce úlohy a
úspešne absolvuje (spraví) riadny alebo náhradný test.
Náhradný test môžu písať iba tí, čo boli chorí, ale keďže býva ľahký, tak ho aj
hneď spravia (teda iba chorí mohli spraviť náhradný test).
Riadny test spravia iba tí, ktorí sa učili alebo aspoň riešili domáce úlohy.
Študenti, ktorí odovzdali domáce úlohy ich buď riešili alebo odpísali.
Odpisujú ich ale iba flákači, čo sa neučia.

Dokážte tablovou metódou, že ak som predmet úspešne absolvoval a nebol som pri
tom chorý, musel som riešiť domáce úlohy.

Jednotlivé tvrdenia sformalizujte pomocou výrokovologických premenných:
- `a` - absolvoval predmet
- `t` - spravil test,
- `n` - spravil náhradný test,
- `du` - odovzdal dú,
- `r` - riešil dú,
- `o` - odpísal dú,
- `u` - učil sa,
- `ch` - bol chorý.

## Príklad veľmi jednoduchého tabla
<table style="text-align: center;">
  <tr> <td colspan="2">(1) F (¬(a∧b) → (¬a∨¬b))</td> </tr>
  <tr> <td colspan="2">(2) T ¬(a∧b) [1]</td> </tr>
  <tr> <td colspan="2">(3) F (¬a∨¬b) [1]</td> </tr>
  <tr> <td colspan="2" style="border-bottom: 1px solid black;">(4) F (a∧b) [2]</td> </tr>
  <tr> <td style="border-right: 1px solid black;"> (5) F a          </td> <td> (8) F  b [4] </td></tr>
  <tr> <td style="border-right: 1px solid black;"> (6) F ¬a [3] </td> <td> (9) F ¬b [3] </td></tr>
  <tr> <td style="border-right: 1px solid black;"> (7) T a [6]      </td> <td> (10) T b  [9] </td></tr>
  <tr> <td style="border-right: 1px solid black;"> * [5 a 7]        </td> <td> * [8 a 10]</td></tr>
</table>

Iná možnosť (textový formát, iné poradie rozpisovania):

```
 (1) F (-(a&b)=>(-a|-b))
==========================
     (2) T -(a&b) [1]
    (3) F (-a|-b) [1]
     (4) F (a&b) [2]
       (5) F -a [3]
       (6) F -b [3]
       (7) T a [5]
       (8) T b [6]
--------------------------
(9) F a [4] | (10) F b [4]
  * [9,7]   |   * [10,8]
```
