//PhysicsManager.cpp

#include "spaceship.h"
#include "physicsmanager.h"

//How To RegisterObject:
//
//
//
//
int PhysicsManager::RegisterObject(PhyStruct * ptr)
{
	if(!ptr)
	{
		return -1;
	}
	if(nextID>=MAX_OBJECTS)
	{
		for(nextID=0;nextID<MAX_OBJECTS;nextID++)
		{
			if(ObjectsPtr[nextID]==NULL)
			{
				ObjectsPtr[nextID]=ptr;
				int t=nextID;
				nextID=MAX_OBJECTS;
				return t;
			}
		}
		return -1;
	}
	ObjectsPtr[nextID]=ptr;
	return nextID++;
}

void PhysicsManager::UnRegisterObject(int id)
{
	if(id>=MAX_OBJECTS||id<0)
	{
		return;
	}
	ObjectsPtr[id]=NULL;
}

PhyStruct *PhysicsManager::GetObjectPtr(int id)
{
	if(id>=MAX_OBJECTS||id<0)
	{
		return NULL;
	}
	return ObjectsPtr[id];
}


