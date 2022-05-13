#include "spaceship.hpp"

VecGLf3D::VecGLf3D operator+(const VecGLf3D &op)
{
	return VecGLf3D(op.x+x,op.y+y,op.z+z);
}

VecGLf3D::VecGLf3D operator-(const VecGLf3D &op)
{
	return VecGLf3D(op.x-x,op.y-y,op.z-z);
}

//VecGLf3D::VecGLf3D operator=(const VecGLf3D &op)
//{
//	return VecGLf3D(op.x,op.y,op.z);
//}

VecGLf3D::VecGLf3D(GLfloat _x=0,GLfloat _y=0,GLfloat _z=0)
{
	x=_x,y=_y,z=_z;
}

