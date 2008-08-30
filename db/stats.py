try:
    import sqlite3 as sqlite
except ImportError:
    from pysqlite2 import dbapi2 as sqlite

from time import mktime, strptime
import os
os.umask(0002)

KWDB = '/home/projects/krdwrd/db/corpora.db'

db = sqlite.connect(KWDB)

cursor = db.cursor()

cursor.execute('SELECT added FROM submissions')

times = [mktime(strptime(i, "%Y-%m-%d %H:%M:%S")) for i, in cursor.fetchall()]

cursor.execute('SELECT current_timestamp')

current = mktime(strptime(cursor.fetchall()[0][0], "%Y-%m-%d %H:%M:%S")) 

import matplotlib
matplotlib.use('Agg')

from pylab import *

figure(figsize=(5,3.5))

a = array(times)
a -= current
a /= 24 * 60 * 60
a = a[a>-14]

hist(a, 7*8*2, linewidth=0)
xlabel('Past Days [3hr bins]')
ylabel('New Submissions')
title('Submissions per day')
show()

savefig('spd.png')
