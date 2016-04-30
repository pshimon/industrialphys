#! python
import numpy as np
#import xml.etree.ElementTree as ET
from PIL import Image
import os
import shutil

def get_fname_img(ra,di,dj,slc):
    fname='{0:0=3}_{1:0=+3}_{2:0=+3}_{3:0=2}'.format(ra,di,dj,slc)
    return fname+'.tif'

def get_fname_xml(ra,di,dj,slc):
    fname='{0:0=3}_{1:0=+3}_{2:0=+3}_{3:0=2}'.format(ra,di,dj,slc)
    return fname+'.xml'

def get_slice(ra,di,dj,slc) :
    fname=get_fname_img(ra,di,dj,slc)
    im=Image.open(fname)
    ima=np.array(im,dtype=float)
    return ima

def avslice(ra,di,dj,slcnum):
    isp=(576,766)
    a=np.zeros(isp,dtype=float)
    for i in range(1,slcnum+1):
        b=get_slice(ra,di,dj,i)
        a=a+b
    a=a/slcnum
    return a

def avslice0(ra,di,dj,slcnum):
    a=avslice(ra,di,dj,slcnum)
    img=Image.fromarray(a.astype(dtype=np.uint8))
    img.save(get_fname_img(ra,di,dj,0))

slclast=11 
count=0  
for ra in [0,180]:
    for di in range(-3,4):
        for dj in range(-3,4):
            if os.path.exists(get_fname_img(ra,di,dj,slclast)):
                avslice0(ra,di,dj,slclast)
                shutil.copyfile(get_fname_xml(ra,di,dj,6),get_fname_xml(ra,di,dj,0))
                count=count+1

print(count)



    
#im.show()
#ima=np.array(im)
#ima.shape

