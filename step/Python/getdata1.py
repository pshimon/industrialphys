#! python
import glob
import shutil
import xml.etree.ElementTree as ET
import os

def get_fname(ra,di,dj,slc):
    fname='{0:0=3}_{1:0=+3}_{2:0=+3}_{3:0=2}'.format(ra,di,dj,slc)
    return fname

pref='D:\shimon\wd\LowNAThroughFocus\QNI_27um_1200nm_D@MA_015NA_572nm_CAPB_DECX0Y0/'
suf=['.xml','.tif']
xf=glob.glob(pref+'*'+suf[0])

for f in xf :
    fl,fext=os.path.splitext(f)
    tree=ET.parse(fl+suf[0])
    a=tree.find('DieIJ')
    dieI=int(a.text.split(',')[0])
    dieJ=int(a.text.split(',')[1])
    a=tree.find('RotateAngle')
    ra=int(a.text.split('_')[1])
    a=tree.find('Slice')
    slc=int(a.text)
    fname=get_fname(ra,dieI,dieJ,slc)
    shutil.copyfile(fl+suf[0],fname+suf[0])
    shutil.copyfile(fl+suf[1],fname+suf[1])

