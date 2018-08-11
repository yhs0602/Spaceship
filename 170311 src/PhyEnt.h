//name: PhyEnt.h
#ifndef _PHYENT_H
#define _PHYENT_H

#include "spaceship.h"

class PhyEnt
{
	public:
		typedef struct _Bound
		{
			typedef struct _BoundingSphere
			{
				vec center;
				float radius;
			} BoundingSphere;
			BoundingSphere sphere;
			typedef struct _BoundingCylinder
			{
				vec centerBottom;
				float radius;
				float height;
			} BoundingCylinder;
			BoundingCylinder cylinder;
		} Bound;
		Bound bound;
		bool isCollidable;
		vec vel;
		vec pos;
};

#endif
