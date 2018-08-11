//PhysicsManager.h

#ifndef _PHYSICSMANAGER_
#define _PHYSICSMANAGER_
#include "spaceship.h"
#include "TVector.h"


struct _PhyStruct;

typedef struct
{
	TVector _Pos;
	float dist;
} RayCastInfo;

typedef struct
{
	TVector _Pos;
	float _amt;
} CollisionInfo;

class SimIsland
{
	public:
		void Update(DWORD mills);
		bool RayCast(int ray, RayCastInfo *info);
		bool RayCast(int ray, RayCastInfo *info,int &num);
		bool Collide(int a, int b, CollisionInfo *info);
		bool Collide(int a, int b, CollisionInfo *info[],int &num);
	private:
		
		_PhyStruct *bodies;
		int numOfBodies;
};

class PhysicsManager
{
	public:
		void Update(DWORD mills);
		bool RayCast(int ray, RayCastInfo *info);
		bool RayCast(int ray, RayCastInfo *info[],int &num);
		bool Collide(int a, int b, CollisionInfo *info);
		bool Collide(int a, int b, CollisionInfo *info[],int &num);
		
		int RegisterObject(_PhyStruct * ptr);
		_PhyStruct * GetObjectPtr(int id);
		void UnRegisterObject(int id);
	private:
		SimIsland islands[];
		int numOfIslands;
		#define MAX_OBJECTS 1024
		_PhyStruct * ObjectsPtr[MAX_OBJECTS];
		int nextID;
};


enum BodyType{
	BT_PLANE,
	BT_SPHERE,
	BT_CYLINDER,
	BT_CAPSULE,
	BT_AABB
};

typedef struct _PhyStruct
{
	BodyType type;
	int id;
	_PhyStruct()
	{
		
	}
	virtual ~_PhyStruct()
	{
		//physicsManager->
	}
} PhyStruct;

typedef struct _Plane: PhyStruct
{
	TVector _Pos;
	TVector _Normal;
	_Plane()
	{
		type=BT_PLANE;
	}
} Plane;

typedef struct _Sphere: PhyStruct
{
	TVector _Pos;
	float _radius;
	_Sphere()
	{
		type=BT_SPHERE;
	}
} Sphere;

typedef struct _Cylinder: PhyStruct
{
	TVector _Pos;
	float _radius;
	float height;
	_Cylinder()
	{
		type=BT_CYLINDER;
	}
} Cylinder;

typedef struct _Capsule: PhyStruct
{
	TVector _Pos;
	float _radius;
	float _height;
	_Capsule()
	{
		type=BT_CAPSULE;
	}
} Capsule;

typedef struct _AxisAlignedBB: PhyStruct
{
	TVector _Pos;
	TVector _End;
	_AxisAlignedBB()
	{
		type=BT_AABB;
	}
} AxisAlignedBB;


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

////Bound.h
//
//
//
//struct Bound
//{
//	public:
//		bool Collidable;
//		virtual bool RayCast(const vec &ray);	
//		virtual ~Bound();
//};
//
//struct BoundingSphere: Bound
//{
//		vec pos;
//		float radius;
//	public:
//		
//};
//
//struct BoundingCapsule:Bound
//{
//		vec pos;	//bottom center
//		float radius;
//		float height;
//};
//
//struct BoundingCylinder:Bound
//{
//		vec pos;	//BOTTOM CENTER
//		float radius;
//		float height;
//};

#endif
