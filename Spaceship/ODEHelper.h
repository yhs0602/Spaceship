#ifndef _ODEHELPER_H
#define _ODEHELPER_H

#include <ode/ode.h>
class ODEHelper{
	public:
		// returns <0 if error
		int Initialize();
		int Finalize();
		vec getPlayerPosition();
	private:
		dWorldID theWorld;
};


#endif
