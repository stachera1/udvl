#!/bin/env python3
"""
    Ukazkovy program ktory pouziva TableauBuilder na dokazovanie.
"""
import builder
from formula import Formula, Variable, Negation, Conjunction, Disjunction, Implication, Equivalence

Not = Negation
Var = Variable
And = Conjunction
Or = Disjunction
Impl = Implication
Eq = Equivalence

T = True
F = False

signedFormulas = [
    (T, Impl(Var('kolace'), Var('praca'))),
    (T, Impl(
            And([Not(Var('kolace')),Not(Var('chlieb'))]),
            Var('hlad')
        )
    ),
    (T, Impl(Var('chlieb'), Var('muka'))),
    (F, Impl(
                    And( [ Not(Var('muka')), Not(Var('hlad')) ] ),
                    Var('praca'),
                )
    ),
]

#
# Ti, co vyriesili bonus01 mozu napriklad pouzit pekne
# Formula.parse(  '((-muka&-hlad)=>praca)'  )
# atd...
#

t = builder.TableauBuilder().build(signedFormulas)
print(t)
print()
if t.isClosed():
    print("Proved!")
else:
    print("Not closed!")
