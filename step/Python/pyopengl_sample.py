import sys
import numpy as np
import scipy.misc
try:
  from OpenGL.GLUT import *
  from OpenGL.GL import *
  from OpenGL.GLU import *
except:
  print ('''
ERROR: PyOpenGL not installed properly.
        ''')
  sys.exit()
              
class GLRenderShape:
    def Triangle(self):
        glBegin(GL_TRIANGLES)
        glColor3f(0., 1., 1.)
        glVertex3f(-1, -1, 0.)
        glColor3f(1., 0., 1.)
        glVertex3f(1., -1., 0.)
        glColor3f(1., 1., 1.)
        glVertex3f(0, 1, 0.)
        glEnd()

class Scene:
    def __init__(self):
        self.quadric = gluNewQuadric()
        self.render_shapes = GLRenderShape()
        self.init()
        self.eye = [0.25, .25, -100]
        self.center = [0.2, -.3, 0]
        self.up = [0, 1, 0]
        
       
                  
    def display(self):
        glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT)
        
        glPushMatrix()
        glRotatef(45, 0., 0. , 1.)
        glScalef(0.5, 0.5, 0.5)
        self.render_shapes.Triangle();
        glPopMatrix()
        
        glPushAttrib(GL_COLOR_BUFFER_BIT)
        glColor3f(0.4, 0.2, 0.2)
        glPushMatrix()
        glTranslatef(0, .25, 0)
        glutSolidTeapot(0.25)
        glPopMatrix()
        glPopAttrib()
        
        glPushMatrix()
        glColor3f(1., 0., 0.)
        glTranslatef(-.5, -.5, -1)
        gluSphere(self.quadric, 0.5, 32, 32)
        glPopMatrix()
        
        glutSwapBuffers()
    
    def reshape(self, width, height):
        self.width = width
        self.height = height
        glViewport(0, 0, self.width, self.height)
        
        glMatrixMode(GL_PROJECTION)
        glLoadIdentity()
                
        glMatrixMode(GL_MODELVIEW)
        glLoadIdentity()
    
    def keyboard(self, key, x, y ):
        if key == '\033':
            sys.exit()
        elif key == 's' or 'S':
            filename = 'a1.png'
            print('saving screen shot to %s' %filename)
            glReadBuffer(GL_FRONT)
            im = glReadPixels(0, 0, self.width, self.height, 
                                   GL_RGBA, GL_UNSIGNED_INT)
            scipy.misc.imsave('a1.png', np.flipud(im))
            im_depth = glReadPixels(0, 0, self.width, self.height, GL_DEPTH_COMPONENT, GL_FLOAT)
            scipy.misc.imsave('test_depth.png', np.flipud(im_depth))
            
#            import matplotlib.pyplot as plt
#            plt.imshow(np.flipud(im_depth))
#            plt.show()
            print('done')
                                  
    def mouse(self, button, state, x, y):
        print(button, state, x, y)
    
    def motion(self, x, y):
        #print(x, y)
        pass
        
    def init(self):
        glClearColor(0.0, 0.0, 0.0, 1.0)
        glEnable(GL_DEPTH_TEST)
    

if __name__ == '__main__':
    glutInit()
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGBA)
    w1 = glutCreateWindow('COMP557 Sample')
    glutReshapeWindow(512,512)
    scene = Scene()
    glutReshapeFunc(scene.reshape)
    glutDisplayFunc(scene.display)
    glutKeyboardFunc(scene.keyboard)
    glutMouseFunc(scene.mouse)
    glutMotionFunc(scene.motion)
    scene.init()
    glutMainLoop()
    
