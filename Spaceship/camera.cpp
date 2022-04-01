#include "spaceship.h"
#include "camera.h"
void Camera::Initialize(void)
{
	look=vec(0.0f,0.0f,-1.0f);
	up=vec(0.0f,1.0f,0.0f);
	right=vec(1.0f,0.0f,0.0f);
	pos=vec(0.0f,0.0f,0.0f);
	type=LANDOBJECT_F;
}

void Camera::Move(GLfloat dx,GLfloat dy,GLfloat dz)
{
	pos.add(vec((float)dx,(float)dy,(float)dz));
}

Camera::Camera(GLfloat _x,GLfloat _y, GLfloat _z)
{
	look=vec(0.0f,0.0f,-1.0f);
	up=vec(0.0f,1.0f,0.0f);
	right=vec(1.0f,0.0f,0.0f);
	pos=vec(_x,_y,_z);
}

void Camera::GetView()
{
	// Keep camera's axes orthogonal to each other
	look.normalize();
	up.cross(right,look);
	up.normalize();
	right.cross(look,up);
	right.normalize();
	gluLookAt(
		pos.x,pos.y,pos.z,
		pos.x+look.x,pos.y+look.y,pos.z+look.z,
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
	if(type==AIRCRAFT)
	{
		look.rotate(angle,up);
		right.rotate(angle,up);
	}
	else
	{
		vec t=vec(0,1,0);
		look.rotate(angle,t );
		right.rotate(angle,t);
	}
}

void Camera::Roll(GLfloat angle)
{
	if(type==AIRCRAFT)
	{
		up.rotate(angle,look);
		right.rotate(angle,look);
	}
}

void Camera::Walk(GLfloat delta)
{
	pos.add(vec(delta*look.x,delta*look.y,delta*look.z));
}
void Camera::Strafe(GLfloat delta)
{
	pos.add(vec(delta*right.x,delta*right.y,delta*right.z));
}
void Camera::Fly(GLfloat delta)
{
	pos.add(vec(delta*up.x,delta*up.y,delta*up.z));
}

