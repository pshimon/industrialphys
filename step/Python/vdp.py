import numpy as np
import matplotlib.pyplot as plt
from scipy.integrate import odeint
def rhs(y,t,mu):
    return [ y[1], mu*(1-y[0]**2)*y[1]-y[0] ]

def jac(y,t,mu):
    return [ [0, 1],[-2*mu*y[0]*y[1]-1, mu*(1-y[0]**2)] ]

mu=1
t=np.linspace(0,30,1001)
y0=np.array([2.0,0.0])
y,info=odeint(rhs,y0,t,args=(mu,),Dfun=jac,full_output=True)
print (" mu = %g, number of Jacobian calls is %d" % (mu, info['nje'][-1]))
plt.ion()
plt.plot(t,y[:,0])


