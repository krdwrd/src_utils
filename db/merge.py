
def foo(fn):
    r = {}
    for a in file(fn).readlines():
        k, v = a.split('|')
        r[int(k)] = v.strip()
    return r

a = foo('tutorial')
b = foo('corpus')
u = foo('users')

A = set(a.keys())
B = set(b.keys())

tot = []
pls = []

print "username\ttutorial (max 2)\tregular corpus (max 8)\tbonus points (max 10)\tregular points (max 10)"

for k in sorted(A | B):
    tut = (int(a.get(k, 0)) >= 12) * 2
    c = int(b.get(k, 0))
    c1 = min(c, 15) * (8.0 / 15.0)
    c2 = min(max(c - 15, 0), 10) * (10.0 / 10.0)
    print "%s\t%d\t%d\t%d\t%d" % (u[k], tut, c1, c2, tut + c1, )
    tot.append(tut + c1)
    pls.append(c2)

from matplotlib import use

use('pdf')

from pylab import *

title('Distribution of (regular) Points for Homework Task')
hist(tot)
savefig('total.pdf')
title('Distribution of Bonus Points for Homework Task')
hist(pls)
savefig('bonus.pdf')


