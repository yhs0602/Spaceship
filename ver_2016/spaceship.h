#include <windows.h>		// Header File For Windows
#include <gl\gl.h>			// Header File For The OpenGL32 Library
#include <gl\glu.h>			// Header File For The GLu32 Library
//#include <gl\glaux.h>		// Header File For The Glaux Library
#include <time.h>
//class VecGLf3D
//{
//	GLfloat x,y,z;
//	public:
//		VecGLf3D operator+(const VecGLf3D &op);
//		VecGLf3D operator-(const VecGLf3D &op);
//		VecGLf3D operator=(const VecGLf3D &op);
//		VecGLf3D(GLfloat _x=0,GLfloat _y=0,GLfloat _z=0);
//};
#include "geom.h"

class Camera
{
	public:
		GLfloat eyeX,eyeY,eyeZ;
		Camera(GLfloat _x=0,GLfloat _y=0, GLfloat _z=0);
		vec look;
		vec up;
		vec right;
		void Move(GLfloat dx,GLfloat dy, GLfloat dz);
		void Pitch(GLfloat angle);
		void Yaw(GLfloat angle);
		void Roll(GLfloat angle);
		void LookAt();
};
