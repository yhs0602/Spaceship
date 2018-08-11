//Bound.h
#ifndef _BOUND_H
#define _BOUND_H

struct Bound
{
	public:
		bool Collidable;
		virtual bool RayCast(const vec &ray);	
		virtual ~Bound();
};

struct BoundingSphere: Bound
{
		vec pos;
		float radius;
	public:
		
};

struct BoundingCapsule:Bound
{
		vec pos;	//bottom center
		float radius;
		float height;
};

struct BoundingCylinder:Bound
{
		vec pos;	//BOTTOM CENTER
		float radius;
		float height;
};

#endif
