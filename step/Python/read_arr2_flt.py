#! python
########################################################################
# Shimon Panfil: Industrial Physics and Simulations                   ##
# http://industrialphys.com                                           ##
# THE SOFTWARE IS PROVIDED "AS IS", USE IT AT YOUR OWN RISK           ##
########################################################################
import numpy as np
def read_arr2_flt(filename):
    fid = open(filename, 'rb')
    n1 = np.fromfile(fid,int,1)
    n2=np.fromfile(fid,int,1)
    a = np.fromfile(fid,np.float32,n1*n2)
    return np.reshape(a, (n2, n1))

a=read_arr2_flt("qq.flt")
a.shape 

import matplotlib.pyplot as plt
b=plt.matshow(a,cmap=plt.cm.gray)
plt.show(b)  
#from PIL import Image
#im=Image.fromarray(a.astype(dtype=np.float32)) 
#im.show()


