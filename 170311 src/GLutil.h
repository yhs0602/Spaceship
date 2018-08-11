#ifndef _GLUTIL_H
#define _GLUTIL_H
GLubyte *LoadBmp(const char *Path, int *Width, int *Height);
int LoadGLTextures();
int InitGL();
void DeInitGL();
GLvoid BuildFont(GLvoid);
GLvoid KillFont();
GLvoid glPrint(const char *fmt, ...);
enum TEXTURENUM {
	TX_FONT=0,
	TX_BOSS,
	TX_FLOOR,
	TX_WALL,
	TX_SKY,
	NUM_TEXTURES
};

extern const char *TexFileNames[NUM_TEXTURES];

extern GLuint	texture[NUM_TEXTURES];
#endif
