import numpy as np
import matplotlib.pyplot as plt
from scipy.integrate import odeint
def rhs(Y,t,omega):
    y,ydot=Y
    return ydot,-omega**2*y

t_arr=np.linspace(0,2*np.pi,101)
y_init=[1, 0]
omega=2.0
y_arr=odeint(rhs,y_init,t_arr,args=(omega,))
y,ydot=y_arr[:,0],y_arr[:,1]
plt.ion()
plt.plot(t_arr,y,t_arr,ydot)
plt.figure() # to set up a new canvas
plt.plot(y,ydot)
plt.title("Solution curve when omega = %5g" % omega)
plt.figure()
y,ydot=np.mgrid[-3:3:21j,-6:6:21j]
u,v=rhs(np.array([y,ydot]),0.0,omega)
mag=np.hypot(u,v)
mag[mag==0]=1.0
plt.quiver(y,ydot,u/mag,v/mag,color='red')

plt.figure()
# Enable drawing of arbitrary number of trajectories DOES NOT WORK
print ("\n\n\nUse mouse to select each starting point.")
print ("Timeout after 30 seconds")
choice=plt.ginput()
while len(choice)>0 :
    y01=np.array([choice[0][0],choice[0][1]])
    y= odeint(rhs,y01,t_arr,args=(omega,))
    plt.plot(y[:, 0],y[:, 1],lw=2)
    choice=plt.ginput()

print ("Timed out!")
