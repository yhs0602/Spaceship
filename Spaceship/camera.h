//name:camera.h
#ifndef _CAMERA_H
#define _CAMERA_H

class Camera
{
	private:
		vec pos;
		vec look;
		vec up;
		vec right;
		
	public:
		enum CameraType {
			AIRCRAFT,
			LANDOBJECT_F,
			LANDOBJECT_L
		};
		CameraType type;
		void Initialize(void);
		Camera(GLfloat _x=0,GLfloat _y=0, GLfloat _z=0);
		void Move(GLfloat dx,GLfloat dy, GLfloat dz);
		void Pitch(GLfloat angle);
		void Yaw(GLfloat angle);
		void Roll(GLfloat angle);
		void Walk(GLfloat delta);
		void Strafe(GLfloat delta);
		void Fly(GLfloat delta);
		
		void GetView();
		
		inline vec &getPosition()
		{
			return pos;
		}
		inline void setPosition(vec &p)
		{
			pos=p;
		}
		
		inline float getX()	const
		{
			return pos.x;
		}
		inline float getY()	const
		{
			return pos.y;
		}
		inline float getZ()	const
		{
			return pos.z;
		}
		
		inline float getLookX()	const
		{
			return look.x;
		}
		inline float getLookY()	const
		{
			return look.y;
		}
		inline float getLookZ()	const
		{
			return look.z;
		}
		
		inline float getUpX()	const
		{
			return up.x;
		}
		inline float getUpY()	const
		{
			return up.y;
		}
		inline float getUpZ()	const
		{
			return up.z;
		}
		
		inline float getRightX()	const
		{
			return right.x;
		}
		inline float getRightY()	const
		{
			return right.y;
		}
		inline float getRightZ()	const
		{
			return right.z;
		}
			
};

#endif
