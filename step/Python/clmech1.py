#! python
########################################################################
# Shimon Panfil: Industrial Physics and Simulations                   ##
# http://industrialphys.com                                           ##
# THE SOFTWARE IS PROVIDED "AS IS", USE IT AT YOUR OWN RISK           ##
########################################################################
import numpy as np
import matplotlib.pyplot as plt
importscipy.integrate as intg

def U(x,a):
    return -x*(1+x**2)**(a-1)

def rhs(x,t,a):
    return [ x[1], F(x[0],a) ]

t=np.linspace(0,4*np.pi,1001)
x0=np.array([0,1])
a=0.1
x1=odeint(rhs,x0,t,args=(a,))
x0=np.array([0,2])
x2=odeint(rhs,x0,t,args=(a,))
plt.ion()
plt.plot(t,x1[:,0],t,x2[:,0])

