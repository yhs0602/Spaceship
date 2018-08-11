//AudioManager.h
//
#ifndef _AUDIOMANAGER_H
#define _AUDIOMANAGER_H
#include "spaceship.h"
typedef ALuint AudioIndex;
typedef ALuint SourceIndex;
class CWaves;
class AudioManager
{
	public:
		ALboolean bEAX;
		AudioIndex LoadAudio(const char *filename);
		SourceIndex AllocSource(AudioIndex i);
		void ListenerPos(const vec & pos);
		void ListenerVel(const vec & vel);
		enum SoundPriority {
			SP_LOWEST=0,
			SP_LOW,
			SP_LOWER,
			SP_MEDIUM,
			SP_HIGH,
			SP_HIGHER,
			SP_HIGHEST
		};
		bool PlaySoundAt(AudioIndex ai, const vec &pos, enum SoundPriority sp);
		bool PlaySoundL(AudioIndex ai,enum SoundPriority);
		bool PlaySource(SourceIndex src);
		//should be Void
		AudioManager()
		{
			Initialized=false;	
		}
		~AudioManager()
		{
			
		}
		bool Initialize();
		void DeInitialize();
	private:
		ALCdevice	*Device;
		ALCcontext  *Context;
		ALenum error;
		CWaves *cwaves;
		AudioIndex nextAudio;
		SourceIndex nextSource;
		
		#define NUM_BUFFERS 32
		#define NUM_SOURCES 64
		ALuint		Buffers[NUM_BUFFERS];
		ALuint		Sources[NUM_SOURCES];
		BOOL MyInitializeOpenAL();
		void MyDeInitializeOpenAL();
		bool LoadAudios();
		bool Initialized;
};

enum Sound{
	SND_SHOT=0,
	NUM_SND
};

extern const char * audioFileNames[];

#endif
