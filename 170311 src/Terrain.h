#if 0
#ifndef TERRAIN_H
#define TERRAIN_H 1

typedef float terunit;

class World
{
	public:	
		int Save();
		int SaveAndExit();
		int SaveAs(string filename);
		bool GetCollisionRayS();
		bool GEtCollisionRayP();
		bool GetCollisionSphereS();
		bool GetCollisionSphereP();
		bool LoadTerrain(string fname);
		terunit GetHeightFloor(terunit x, terunit z,terunit y);
		terunit GetHeightCeil(terunit x, terunit z,terunit y);
		bool Render();
		
		bool SetBlock(Block &b, terunit x, terunit y, terunit z);
		bool WorldToChunkCoord(Chunk *c,terunit x, terunit z);
		string FileName;
	private:
		//Actual Loaded TerrainData
		Chunk chunks[27];
		Chunk & FindChunk(terutit x, terunit z);
		bool init;
		
};

//class for storing Actual Chunkdata(array of Blocks)
#define CHUNKSIZE 64
#define CHUNKSIZEX CHUNKSIZE
#define CHUNKSIZEY CHUNKSIZE
#define CHUNKSIZEZ CHUNKSIZE

class Chunk
{
	public:
		Block blocks[CHUNKSIZEX][CHUNKSIZEY][CHUNKSIZEZ];
		terunit GetHeight(terunit x, terunit z); 
	private:
		World * world;
};
class Block
{
	float weight;
	float opacity;
	bool opaque;
};

#endif
#endif

