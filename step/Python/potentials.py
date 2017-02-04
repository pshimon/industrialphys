#! python
########################################################################
# Shimon Panfil: Industrial Physics and Simulations                   ##
# http://industrialphys.com                                           ##
# THE SOFTWARE IS PROVIDED "AS IS", USE IT AT YOUR OWN RISK           ##
########################################################################
import numpy as np
import matplotlib.pyplot as plt

def u1(x):
    return 0.5*x**2

def u2(x):
    return 0.5*np.log(1+x**2)

def u3(x):
    return np.cosh(x)-1


x=np.linspace(-4.0,4.0,501)
y1=u1(x)
y2=u2(x)
y3=u3(x)
plt.ion()
plt.plot(x, y1,x,y2,x,y3)

[X,Y] = np.mgrid[-4.0:4.0:101j,-4.0:4.0:101j]
Z=u1(X)+Y**2/2
plt.figure()
plt.contour(X,Y,Z,20)
plt.title("harm")

[X,Y] = np.mgrid[-4.0:4.0:101j,-4.0:4.0:101j]
Z=u2(X)+Y**2/2
plt.figure()
plt.contour(X,Y,Z,20)
plt.title("log")

[X,Y] = np.mgrid[-4.0:4.0:101j,-4.0:4.0:101j]
Z=u3(X)+Y**2/2
plt.figure()
plt.contour(X,Y,Z,20)
plt.title("cosh")

#plt.savefig("potentials.pdf")
