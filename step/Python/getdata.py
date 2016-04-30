#! python
#import numpy as np
import glob
import shutil
import xml.etree.ElementTree as ET
import os
#from PIL import Image
#im=Image.open('slice.tif')
#im.show()
#ima=np.array(im)
#ima.shape
pref='D:\shimon\wd\LowNAThroughFocus\QNI_27um_1200nm_D@MA_015NA_572nm_CAPB_DECX0Y0/'
suf=['.xml','.tif']
xf=glob.glob(pref+'*'+suf[0])

for f in xf :
    fl,fext=os.path.splitext(f)
    tree=ET.parse(fl+suf[0])
    a=tree.find('DieIJ')
    dieI=int(a.text.split(',')[0])
    dieJ=int(a.text.split(',')[1])
    a=tree.find('ElementIJ')
    elI=int(a.text.split(',')[0])
    elJ=int(a.text.split(',')[1])
    a=tree.find('TestNumber')
    tst=int(a.text)
    a=tree.find('Slice')
    slc=int(a.text)
    fname='d_{0:0=+4}_{1:0=+4}_t_{2:0=+4}_e_{3:0=+4}_{4:0=+4}_s_{5:0=+4}'.format(dieI,dieJ,elI,elJ,tst,slc)
    if os.path.exists(fname+suf[0]) :
        fname=fname+'~'
    shutil.copyfile(fl+suf[0],fname+suf[0])
    shutil.copyfile(fl+suf[1],fname+suf[1])


#root=tree.getroot()
#root.tag
#tags=['DieIJ', 'ElementIJ', 'Slice', 'TestNumber']
#for t in tags:
#    el=tree.find(t)
#    print(el.tag,el.text)



#li=tree.find('Data/LayerInner')
#for child in li:
#	print(child.tag,child.attrib)

