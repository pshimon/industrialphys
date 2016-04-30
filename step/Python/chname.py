#! python

import glob
import shutil
xf=glob.glob('*.*')

for f in xf :
    shutil.move(f,'QQQ_'+f)

