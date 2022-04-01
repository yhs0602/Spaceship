//AudioManager.cpp
#include "spaceship.h"
#include "audiomanager.h"
#include "alCWaves.h"

const char * audioFileNames[NUM_SND]={
	"Data\\Shot.wav"
};


bool AudioManager::Initialize()
{	
	Initialized=false;
	if(MyInitializeOpenAL()==TRUE)
	{
		cwaves=new CWaves();
		if(LoadAudios()==false||cwaves==NULL)return false;
		Initialized=true;
	}
	return true;
}

void AudioManager::DeInitialize()
{
	delete cwaves;
	MyDeInitializeOpenAL();
}

// Initialization
BOOL AudioManager::MyInitializeOpenAL()
{
	Device = alcOpenDevice(NULL); // select the "preferred device"
	if (Device) {
		Context=alcCreateContext(Device,NULL);
		alcMakeContextCurrent(Context);
	}else
	{
		Warning("unable to Initialize OPENAL(AUDIO SYSTEM)");
		return FALSE;
	}
	// Check for EAX 2.0 support
	bEAX = alIsExtensionPresent("EAX2.0");
	alGetError(); // clear error code
	// Generate Buffers
	alGenBuffers(NUM_BUFFERS, Buffers);
	if ((error = alGetError()) != AL_NO_ERROR)
	{
		//DisplayALError("alGenBuffers :", error);
		return FALSE;
	}
	alGenSources( NUM_SOURCES, Sources );
	nextAudio=0;
	nextSource=0;
	return /*Initialized=*/alGetError()==AL_NO_ERROR;
}

void AudioManager::MyDeInitializeOpenAL()
{
	for(int i=0;i<NUM_SOURCES;i++)
		alSourceStop(Sources[i]);
        alDeleteSources(NUM_SOURCES, Sources);
	alDeleteBuffers(NUM_BUFFERS, Buffers);
	// Exit
	Context=alcGetCurrentContext();
	Device=alcGetContextsDevice(Context);
	alcMakeContextCurrent(NULL);
	alcDestroyContext(Context);
	alcCloseDevice(Device);
}

void AudioManager::ListenerPos(const vec & pos)
{
	alListener3f(AL_POSITION,pos.x,pos.y,pos.z);
}

void AudioManager::ListenerVel(const vec & vel)
{
	alListener3f(AL_VELOCITY,vel.x,vel.y,vel.z);
}

AudioIndex AudioManager::LoadAudio(const char *filename)
{
	//int wid;
	//cwaves->LoadWaveFile("data/Shot.wav",&wid);
	WAVEID			WaveID;
	ALint			iDataSize, iFrequency;
	ALenum			eBufferFormat;
	ALchar			*pData;
	ALboolean		bReturn;

	bReturn = AL_FALSE;
	if (SUCCEEDED(cwaves->LoadWaveFile(filename, &WaveID)))
	{
		if ((SUCCEEDED(cwaves->GetWaveSize(WaveID, (unsigned long*)&iDataSize))) &&
			(SUCCEEDED(cwaves->GetWaveData(WaveID, (void**)&pData))) &&
			(SUCCEEDED(cwaves->GetWaveFrequency(WaveID, (unsigned long*)&iFrequency))) &&
			(SUCCEEDED(cwaves->GetWaveALBufferFormat(WaveID, &alGetEnumValue, (unsigned long*)&eBufferFormat))))
		{
			// Set XRAM Mode (if application)
			//if (eaxSetBufferMode && eXRAMBufferMode)
			//	eaxSetBufferMode(1, &uiBufferID, eXRAMBufferMode);
			alGetError();
			alBufferData(Buffers[nextAudio], eBufferFormat, pData, iDataSize, iFrequency);
			if (alGetError() == AL_NO_ERROR)
				bReturn = AL_TRUE;
			cwaves->DeleteWaveFile(WaveID);
			return nextAudio++;
		}else{
			MessageBox(0,TEXT("부가정보 얻기 실패"),"",0);
		}
	}else{
		MessageBox(0,TEXT("loadwavfileerror"),"",0);
	}
	return -1;
}

SourceIndex AudioManager::AllocSource(AudioIndex i)
{
	//if(!Initialized)return -1;
	alSourcei( Sources[nextSource], AL_BUFFER, Buffers[i] );
	return nextSource++;
}

bool AudioManager::PlaySource(SourceIndex src)
{
	alSourcePlay( Sources[src] );
}

bool AudioManager::LoadAudios()
{
	for(int i=0;i<NUM_SND;++i)
	{
		if(LoadAudio(audioFileNames[i])==-1){
			return false;
		}
	}
	return true; 
}
