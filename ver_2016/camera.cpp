#include "spaceship.h"

void Camera::Move(GLfloat dx,GLfloat dy,GLfloat dz)
{
//	VecGLf3D v = VecGLf3D(dx,dy,dz);
//	eye= eye+v;
//	center=center+v;
	vec v=vec((float)dx,(float)dy,(float)dz);
	look=look.add(v);
}

Camera::Camera(GLfloat _x,GLfloat _y, GLfloat _z)
{
	look=vec(0.0f,0.0f,-1.0f);
	up=vec(0.0f,1.0f,0.0f);
	right=vec(1.0f,0.0f,0.0f);
	eyeX=_x;
	eyeY=_y;
	eyeZ=_z;
}

void Camera::LookAt()
{
	gluLookAt(
		eyeX,eyeY,eyeZ,
		eyeX+look.x,eyeY+look.y,eyeZ+look.z,
		up.x,up.y,up.z
	);
}

void Camera::Pitch(GLfloat angle)
{
	look.rotate(angle,right);
	up.rotate(angle,right);
}

void Camera::Yaw(GLfloat angle)
{
	look.rotate(angle,up);
	right.rotate(angle,up);
}

void Camera::Roll(GLfloat angle)
{
	up.rotate(angle,look);
	right.rotate(angle,look);
}

