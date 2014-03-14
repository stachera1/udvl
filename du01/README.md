Domáca úloha 1
==============

Domácu úlohu odovzdávajte do Štvrtku 26.3. 13:10 (t.j. najneskôr
na začiatku štvrtkových cvičení).

Úlohu odovzdávajte buď fyzicky na papier formátu A4 (čitateľne označenom a
podpísanom) na prednáške alebo na cvičeniach, alebo elektronicky vo formáte PDF
(ako súbor `du01.pdf`), ako obyčjaný textový alebo súbor (`du01.txt`), alebo
ako súbor v GitHub Markdown formáte (`du01.md`) do vetvy `du01`. Nezabudnite vyrobiť
pull request.

Wordovské dokumenty, obrázky a skenované / fotografované riešenia nebudú hodnotené.

Bohužiaľ cez webové rozhranie sa na GitHub dajú súbory len priamo písať alebo
copy-paste-ovať, binárne súbory treba nahrať pomocou GIT-u
([msysgit](http://msysgit.github.io/) alebo čistý
[git](http://git-scm.com/downloads)) alebo [github programu pre
windows](http://windows.github.com/) respektíve pre
[Mac](http://mac.github.com/).  Samozrejme potom treba ešte (cez webové
rozhranie) vyrobiť pull request.

## 1.1 (1b)

[Piercova spojka (NOR)](http://en.wikipedia.org/wiki/Peirce arrow)
, značka: `↓`, je binárna logická spojka s nasledovným významom:
* `A ↓ B` je pravdivé vtt keď ani `A` ani `B` nie je pravdivé (obidve sú nepravdivé).

Vybudujte teóriu výrokovej logiky používajúcej **iba** túto spojku: zadefinujte pojem
formuly, vytvárajúcej postupnosti a stromu pre formulu, boolovského ohodnotenia.

## 1.2 (1b)

Hovríme, že binárna logická spojka `◊` je **definovateľná** zo spojok `α`, `β`,
... ak existuje formula, obsahujúca iba spojky `α`, `β`, ...  a premenné `a` a
`b`, ekvivalentná formule `(a◊b)`.

Hovríme, že unárna logická spojka `◊` je **definovateľná** zo spojok `α`, `β`,
... ak existuje formula, obsahujúca iba spojky `α`, `β`, ...  a premennú `a`,
ekvivalentná formule `◊`.

Napríklad `→` je definovateľná z `¬`, `∧` a `∨` pretože `(a→b)` je ekvivalentná s `(¬a∨b)`
(samozrejme ekvivalenciu tých dvoch formúl by bolo treba ešte dokázať).

Dokážte, že
  * `↓` je definovateľná zo spojok ¬, ∧ a ∨;
  * `¬`, `∧`, `∨`, `→` sú definovateľné z `↓`.

## 1.3 (1b)

Uvažujme naslednovnú definíciu:

Formula `X` je občas pravdivá práve vtedy, keď existuje aspoň jedno boolovské ohodnotenie, pri
ktorom je pravidvá a aspoň jedno boolovské ohodnotenie, pri ktorom je nepravdivá.

Dokážte alebo vyvráťte :

* Negácia `¬X` občas pravdivej formuly `X` je tiež občas pravdivá.
* Negácia splniteľnej formuly je občas pravdivá.
* Negácia občas pravdivej formuly je splniteľná.
