#include "spaceship.h"
#include "ODEHelper.h"

int ODEHelper::Initialize() {
	theWorld =  dWorldCreate();
	dWorldSetGravity(theWorld, 0, -9.8, 0);
}

int ODEHelper::Finalize() {
	dWorldDestroy(theWorld);

}	
