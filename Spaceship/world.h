//world.h

#ifndef _WORLD_H
#define _WORLD_H
#include "spaceship.h"
struct Box
{
	vec pos;	//pos
	vec end;	//end point
	bool IsPtInBox(vec p)
	{
		return (pos.x<=p.x&&p.x<=end.x)&&(pos.y<=p.y&&p.y<=end.y)&&(pos.z<=p.z&&p.z<=end.z);
	}
	bool IsSphereInBox(struct BoundingSphere & s)
	{
		if(!IsPtInBox(s.pos))return false;
		return (pos.x<=s.pos.x-s.radius)&&(pos.y<=s.pos.y-s.radius)&&(pos.z<=s.pos.z-s.radius)&&
				(end.x>=s.pos.x+s.radius)&&(end.y>=s.pos.y+s.radius)&&(end.z>=s.pos.z+s.radius);
	}
};
#endif
