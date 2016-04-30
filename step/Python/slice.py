#! python
import numpy as np
import xml.etree.ElementTree as ET
from PIL import Image
im=Image.open('slice.tif')
#im.show()
ima=np.array(im)
ima.shape
tree=ET.parse('slice.xml')

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

fname='d{0:0=+4}{1:0=+4}_t{2:0=+4}_s{3:0=+4}'.format(dieI,dieJ,tst,slc)

#root=tree.getroot()
#root.tag
#tags=['DieIJ', 'ElementIJ', 'Slice', 'TestNumber']
#for t in tags:
#    el=tree.find(t)
#    print(el.tag,el.text)



#li=tree.find('Data/LayerInner')
#for child in li:
#	print(child.tag,child.attrib)

