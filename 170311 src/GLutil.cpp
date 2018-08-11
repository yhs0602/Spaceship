#include "spaceship.h"
#include "glutil.h"
#include "terrain/terrain.h"
#include "playercontroller.h"
#include "fps2.h"


GLUquadricObj *pQuad;
GLYPHMETRICSFLOAT gmf[256];	// Storage For Information About Our Outline Font Characters

int InitGL()
{
	glClearColor(0.6,0.85,1,1);
	glEnable(GL_TEXTURE_2D);							// Enable Texture Mapping
	pQuad=gluNewQuadric();
	gluQuadricNormals(pQuad, GLU_SMOOTH);			// Create Smooth Normals (NEW)
	gluQuadricTexture(pQuad, GL_TRUE);				// Create Texture Coords (NEW)
	glEnable(GL_COLOR_MATERIAL);						// Enable Coloring Of Material
	//glEnable(GL_CULL_FACE);
	glEnableClientState(GL_VERTEX_ARRAY);
	if(LoadGLTextures()==FALSE)
	{
		return FALSE;
	}
	BuildFont();
	GLfloat fogColor[4] = {0.6, 0.85,1.0,1.0};
	glFogi(GL_FOG_MODE, GL_LINEAR);        // 안개모드
	glFogfv(GL_FOG_COLOR, fogColor);            // 안개 색을 설정
	glFogf(GL_FOG_DENSITY, 10.0f);                // 안개의 밀집도
	glHint(GL_FOG_HINT, GL_NICEST);            // 안개 힌트 값
	glFogf(GL_FOG_START, 100.0f);                // 안개 시작 깊이
	glFogf(GL_FOG_END, 200.0f);                // 안개 끝 깊이
	glEnable(GL_FOG);                    // GL_FOG를 켠다.
	return TRUE;	
}

void DeInitGL()
{
	gluDeleteQuadric(pQuad);
	glDeleteTextures(NUM_TEXTURES,texture);
	KillFont();
}


#define WORLDSIZ 300
void DrawWorld(void)
{
	glBindTexture(GL_TEXTURE_2D,texture[TX_FLOOR]);
	//glPolygonMode(GL_FRONT_AND_BACK,GL_LINE);
	theTerrain->draw(false);
	//glPolygonMode(GL_FRONT_AND_BACK,GL_FILL);
	/*glBegin(GL_QUADS);
		glNormal3f(0,1,0);
		glTexCoord2f(0.0f,0.0f);
		glVertex3f(-WORLDSIZ,-WORLDSIZ,-WORLDSIZ);
		glTexCoord2f(0,1);
		glVertex3f(-WORLDSIZ,-WORLDSIZ,WORLDSIZ);
		glTexCoord2f( 1,1);
		glVertex3f(WORLDSIZ,-WORLDSIZ,WORLDSIZ);
		glTexCoord2f(1,0);
		glVertex3f(WORLDSIZ,-WORLDSIZ,-WORLDSIZ);
	glEnd();
	*/
//	glBindTexture(GL_TEXTURE_2D,texture[TX_SKY]);
//	glBegin(GL_QUADS);
//		glNormal3f(0,-1,0);
//		glTexCoord2f(0.0f,0.0f);
//		glVertex3f(-WORLDSIZ,WORLDSIZ,WORLDSIZ);
//		glTexCoord2f(0,1);
//		glVertex3f(-WORLDSIZ,WORLDSIZ,-WORLDSIZ);
//		glTexCoord2f( 1,1);
//		glVertex3f(WORLDSIZ,WORLDSIZ,-WORLDSIZ);
//		glTexCoord2f(1,0);
//		glVertex3f(WORLDSIZ,WORLDSIZ,WORLDSIZ);
//	glEnd();
//	
	glBindTexture(GL_TEXTURE_2D,texture[TX_WALL]);
	glBegin(GL_QUADS);
		glNormal3f(1,0,0);
		glTexCoord2f(0.0f,0.0f);
		glVertex3f(-WORLDSIZ,-WORLDSIZ,WORLDSIZ);
		glTexCoord2f(1,0);
		glVertex3f(-WORLDSIZ,-WORLDSIZ,-WORLDSIZ);
		glTexCoord2f( 1,1);
		glVertex3f(-WORLDSIZ,WORLDSIZ,-WORLDSIZ);
		glTexCoord2f(0,1);
		glVertex3f(-WORLDSIZ,WORLDSIZ,WORLDSIZ);
	glEnd();
	glBegin(GL_QUADS);
		glNormal3f(-1,0,0);
		glTexCoord2f(0.0f,0.0f);
		glVertex3f(WORLDSIZ,-WORLDSIZ,WORLDSIZ);
		glTexCoord2f(0,1);
		glVertex3f(WORLDSIZ,WORLDSIZ,WORLDSIZ);
		glTexCoord2f( 1,1);
		glVertex3f(WORLDSIZ,WORLDSIZ,-WORLDSIZ);
		glTexCoord2f(1,0);
		glVertex3f(WORLDSIZ,-WORLDSIZ,-WORLDSIZ);
	glEnd();
	glBegin(GL_QUADS);
		glNormal3f(0,0,1);
		glTexCoord2f(0.0f,0.0f);
		glVertex3f(-WORLDSIZ,-WORLDSIZ,-WORLDSIZ);
		glTexCoord2f(1,0);
		glVertex3f(WORLDSIZ,-WORLDSIZ,-WORLDSIZ);
		glTexCoord2f( 1,1);
		glVertex3f(WORLDSIZ,WORLDSIZ,-WORLDSIZ);
		glTexCoord2f(0,1);
		glVertex3f(-WORLDSIZ,WORLDSIZ,-WORLDSIZ);
	glEnd();
	glBegin(GL_QUADS);
		glNormal3f(0,0,-1);
		glTexCoord2f(0.0f,0.0f);
		glVertex3f(-WORLDSIZ,-WORLDSIZ,WORLDSIZ);
		glTexCoord2f(1,0);
		glVertex3f(WORLDSIZ,-WORLDSIZ,WORLDSIZ);
		glTexCoord2f( 1,1);
		glVertex3f(WORLDSIZ,WORLDSIZ,WORLDSIZ);
		glTexCoord2f(0,1);
		glVertex3f(-WORLDSIZ,WORLDSIZ,WORLDSIZ);
	glEnd();
}

void DrawBoss()
{
	glPushMatrix();
	//glColor3ub(0,255,255);
	glTranslatef(0,159,0);
	//glRotatef(90,0,1,0);
	//glTranslatef(0,0,);
	glBindTexture(GL_TEXTURE_2D,texture[TX_BOSS]);
	gluSphere(pQuad,1.0f,30,30);
	glPopMatrix();
}
void Draw (void)
{
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);	// Clear Screen And Depth Buffer
	glLoadIdentity();
	glColor3f(1,1,1);
	playerController.GetView();
	DrawWorld();
	DrawBoss();
	//HUD
	glDisable(GL_DEPTH_TEST);
	glDisable(GL_TEXTURE_2D);
	glLoadIdentity();
	gluLookAt(0,0,1,0,0,0,0,1,0);
	glColor4ub(0xff,0,0,0x20);
	//glLineWidth(2.0f);
	//glPolygonMode(GL_FRONT,GL_FILL);
	glBegin(GL_LINES); 
	glVertex2f(-0.03, 0); 
	glVertex2f(0.03, 0); 
	glVertex2f(0, -0.03);
	glVertex2f(0, 0.03);
	glEnd();
	fpsCounter.Draw();
	glPushMatrix();
	//glLoadIdentity();
	glColor3f(1,1,1);
	glRasterPos2f(-0.40f, 0.35f);
	vec pos=playerController.camera.getPosition();
	glPrint("%3.2f %3.2f, %3.2f",pos.x,pos.y,pos.z);
	glPopMatrix();
	//glPrint("War OF dduty");
	glEnable(GL_DEPTH_TEST);
	glEnable(GL_TEXTURE_2D);
	glFlush();
}

const char *TexFileNames[NUM_TEXTURES]=
{
	"Data\\font.bmp",
	"Data\\boss.bmp",
	"terrain\\grass.bmp",
	"Data\\wall.bmp",
	"Data\\sky.bmp"
};

GLuint	texture[NUM_TEXTURES];			// Storage For Textures
//int LoadGLTextures()									// Load Bitmaps And Convert To Textures
//{
//	int Status=FALSE;									// Status Indicator
//	GLubyte *data[2];
//	int width[2], height[2];
//	// Load The Bitmap, Check For Errors, If Bitmap's Not Found Quit
//	if ((data[0]=LoadBmp("Data\\Font.bmp",&width[0],&height[0]))&&(data[1]=LoadBmp("Data\\Boss.bmp",&width[1],&height[1])))
//	{
//		Status=TRUE;									// Set The Status To TRUE
//		glGenTextures(2, &texture[0]);					// Create Three Textures
//		// Create Linear Filtered Texture
//		glBindTexture(GL_TEXTURE_2D, texture[0]);
//		glTexParameteri(GL_TEXTURE_2D,GL_TEXTURE_MAG_FILTER,GL_LINEAR);
//		glTexParameteri(GL_TEXTURE_2D,GL_TEXTURE_MIN_FILTER,GL_LINEAR);
//		glTexImage2D(GL_TEXTURE_2D, 0, 3, width[0], height[0], 0, GL_RGB, GL_UNSIGNED_BYTE, data[0]);
//		// Create Linear Filtered Texture
//		glBindTexture(GL_TEXTURE_2D, texture[1]);
//		glTexParameteri(GL_TEXTURE_2D,GL_TEXTURE_MAG_FILTER,GL_LINEAR);
//		glTexParameteri(GL_TEXTURE_2D,GL_TEXTURE_MIN_FILTER,GL_LINEAR);
//		glTexImage2D(GL_TEXTURE_2D, 0, 3, width[1], height[1], 0, GL_RGB, GL_UNSIGNED_BYTE, data[1]);
//	}
//	if (data[0])								// If Texture Exists
//	{
//		free(data[0]);							// Free The Image Structure
//	}
//	if(data[1])
//	{
//		free(data[1]);
//	}
//	return Status;										// Return The Status
//}
int LoadGLTextures()
{
	GLubyte *data=NULL;
	int width=0,height=0;
	//char FileName[64];
	glGenTextures(NUM_TEXTURES,&texture[0]);
	for(int i=0;i<NUM_TEXTURES;i++)
	{
		//sprintf(FileName,"Data\\%s\0",TexFileNames[i]);
		//FileName[63]='\0';
		if(data=LoadBmp(TexFileNames[i],&width,&height))
		{
			glBindTexture(GL_TEXTURE_2D,texture[i]);
			glTexImage2D(GL_TEXTURE_2D,0,3,width,height,0,GL_RGB,GL_UNSIGNED_BYTE,data);
			glTexParameteri(GL_TEXTURE_2D,GL_TEXTURE_MAG_FILTER,GL_LINEAR);
			glTexParameteri(GL_TEXTURE_2D,GL_TEXTURE_MIN_FILTER,GL_LINEAR);
			if(data)free(data);
			data=NULL;
		}
		else
		{
			return FALSE;
		}
	}
	return TRUE;
}

GLubyte *LoadBmp(const char *Path, int *Width, int *Height)
{ 
	HANDLE hFile;
	DWORD FileSize, dwRead; 
	BITMAPFILEHEADER *fh=NULL; 
	BITMAPINFOHEADER *ih; 
	BYTE *pRaster; 
	hFile=CreateFileA(Path,GENERIC_READ,0,NULL, OPEN_EXISTING,FILE_ATTRIBUTE_NORMAL,NULL); 
	if (hFile==INVALID_HANDLE_VALUE) 
	{ 
		return NULL; 
	} 
	FileSize=GetFileSize(hFile,NULL); 
	fh=(BITMAPFILEHEADER *)malloc(FileSize); 
	ReadFile(hFile,fh,FileSize,&dwRead,NULL); 
	CloseHandle(hFile); 
	int len = FileSize - fh->bfOffBits;
	pRaster=(GLubyte *)malloc(len); 
	memcpy(pRaster, (BYTE *)fh+fh->bfOffBits, len); // RGB로 순서를 바꾼다. 
	for (BYTE *p=pRaster;p < pRaster + len - 3;p+=3) 
	{
		BYTE b = *p; 
		*p = *(p+2); 
		*(p+2) = b; 
	} 
	ih=(BITMAPINFOHEADER *)((PBYTE)fh+sizeof(BITMAPFILEHEADER)); 
	*Width=ih->biWidth;
	*Height=ih->biHeight; 
	free(fh); 
	return pRaster; 
}


//GLuint	texture[2];											// Font Texture Storage Space
GLuint	base;												// Base Display List For The Font
int loop1;

GLvoid BuildFont(GLvoid)								// Build Our Bitmap Font
{
	HFONT	font;										// Windows Font ID
	HFONT	oldfont;									// Used For Good House Keeping

	base = glGenLists(96);								// Storage For 96 Characters

	font = CreateFont(	-24,							// Height Of Font
						0,								// Width Of Font
						0,								// Angle Of Escapement
						0,								// Orientation Angle
						FW_BOLD,						// Font Weight
						FALSE,							// Italic
						FALSE,							// Underline
						FALSE,							// Strikeout
						ANSI_CHARSET,					// Character Set Identifier
						OUT_TT_PRECIS,					// Output Precision
						CLIP_DEFAULT_PRECIS,			// Clipping Precision
						ANTIALIASED_QUALITY,			// Output Quality
						FF_DONTCARE|DEFAULT_PITCH,		// Family And Pitch
						"Times New Roman");					// Font Name

	oldfont = (HFONT)SelectObject(window->hDC, font);           // Selects The Font We Want
	wglUseFontBitmaps(window->hDC, 32, 96, base);				// Builds 96 Characters Starting At Character 32
	SelectObject(window->hDC, oldfont);							// Selects The Font We Want
	DeleteObject(font);									// Delete The Font
}

GLvoid KillFont(GLvoid)									// Delete The Font List
{
	glDeleteLists(base, 96);							// Delete All 96 Characters
}

GLvoid glPrint(const char *fmt, ...)					// Custom GL "Print" Routine
{
	char		text[256];								// Holds Our String
	va_list		ap;										// Pointer To List Of Arguments

	if (fmt == NULL)									// If There's No Text
		return;											// Do Nothing

	va_start(ap, fmt);									// Parses The String For Variables
	    vsprintf(text, fmt, ap);						// And Converts Symbols To Actual Numbers
	va_end(ap);											// Results Are Stored In Text

	glPushAttrib(GL_LIST_BIT);							// Pushes The Display List Bits
	glListBase(base - 32);								// Sets The Base Character to 32
	glCallLists(strlen(text), GL_UNSIGNED_BYTE, text);	// Draws The Display List Text
	glPopAttrib();										// Pops The Display List Bits
}


//
//GLvoid BuildFont(GLvoid)								// Build Our Bitmap Font
//{
//	HFONT	font;										// Windows Font ID
//
//	base = glGenLists(256);								// Storage For 256 Characters
//
//	font = CreateFont(	-12,							// Height Of Font
//						0,								// Width Of Font
//						0,								// Angle Of Escapement
//						0,								// Orientation Angle
//						FW_THIN,						// Font Weight
//						FALSE,							// Italic
//						FALSE,							// Underline
//						FALSE,							// Strikeout
//						ANSI_CHARSET,					// Character Set Identifier
//						OUT_TT_PRECIS,					// Output Precision
//						CLIP_DEFAULT_PRECIS,			// Clipping Precision
//						ANTIALIASED_QUALITY,			// Output Quality
//						FF_DONTCARE|DEFAULT_PITCH,		// Family And Pitch
//						"Comic Sans MS");				// Font Name
//
//	SelectObject(window->hDC, font);							// Selects The Font We Created
//
//	wglUseFontOutlines(	window->hDC,							// Select The Current DC
//						0,								// Starting Character
//						255,							// Number Of Display Lists To Build
//						base,							// Starting Display Lists
//						0.0f,							// Deviation From The True Outlines
//						0.2f,							// Font Thickness In The Z Direction
//						WGL_FONT_POLYGONS,				// Use Polygons, Not Lines
//						gmf);							// Address Of Buffer To Recieve Data
//}
//
//GLvoid glPrint(const char *fmt, ...)					// Custom GL "Print" Routine
//{
//	float		length=0;								// Used To Find The Length Of The Text
//	char		text[256];								// Holds Our String
//	va_list		ap;										// Pointer To List Of Arguments
//
//	if (fmt == NULL)									// If There's No Text
//		return;											// Do Nothing
//
//	va_start(ap, fmt);									// Parses The String For Variables
//	    vsprintf(text, fmt, ap);						// And Converts Symbols To Actual Numbers
//	va_end(ap);											// Results Are Stored In Text
//
//	for (unsigned int loop=0;loop<(strlen(text));loop++)	// Loop To Find Text Length
//	{
//		length+=gmf[text[loop]].gmfCellIncX;			// Increase Length By Each Characters Width
//	}
//
//	glTranslatef(-length/2,0.0f,0.0f);					// Center Our Text On The Screen
//
//	glPushAttrib(GL_LIST_BIT);							// Pushes The Display List Bits
//	glListBase(base);									// Sets The Base Character to 0
//	glColor3f(1,1,1);
//	glCallLists(strlen(text), GL_UNSIGNED_BYTE, text);	// Draws The Display List Text
//	glPopAttrib();										// Pops The Display List Bits
//}
//GLvoid BuildFont(GLvoid)									// Build Our Font Display List
//{
//	base=glGenLists(256);									// Creating 256 Display Lists
//	glBindTexture(GL_TEXTURE_2D, texture[0]);				// Select Our Font Texture
//	for (loop1=0; loop1<256; loop1++)						// Loop Through All 256 Lists
//	{
//		float cx=float(loop1%16)/16.0f;						// X Position Of Current Character
//		float cy=float(loop1/16)/16.0f;						// Y Position Of Current Character
//
//		glNewList(base+loop1,GL_COMPILE);					// Start Building A List
//			glBegin(GL_QUADS);								// Use A Quad For Each Character
//				glTexCoord2f(cx,1.0f-cy-0.0625f);			// Texture Coord (Bottom Left)
//				glVertex2d(0,16);							// Vertex Coord (Bottom Left)
//				glTexCoord2f(cx+0.0625f,1.0f-cy-0.0625f);	// Texture Coord (Bottom Right)
//				glVertex2i(16,16);							// Vertex Coord (Bottom Right)
//				glTexCoord2f(cx+0.0625f,1.0f-cy);			// Texture Coord (Top Right)
//				glVertex2i(16,0);							// Vertex Coord (Top Right)
//				glTexCoord2f(cx,1.0f-cy);					// Texture Coord (Top Left)
//				glVertex2i(0,0);							// Vertex Coord (Top Left)
//			glEnd();										// Done Building Our Quad (Character)
//			glTranslated(15,0,0);							// Move To The Right Of The Character
//		glEndList();										// Done Building The Display List
//	}														// Loop Until All 256 Are Built
//}

//GLvoid glPrint(GLint x, GLint y, int set, const char *fmt, ...)	// Where The Printing Happens
//{
//	char		text[256];									// Holds Our String
//	va_list		ap;											// Pointer To List Of Arguments
//
//	if (fmt == NULL)										// If There's No Text
//		return;												// Do Nothing
//
//	va_start(ap, fmt);										// Parses The String For Variables
//	    vsprintf(text, fmt, ap);							// And Converts Symbols To Actual Numbers
//	va_end(ap);												// Results Are Stored In Text
//
//	if (set>1)												// Did User Choose An Invalid Character Set?
//	{
//		set=1;												// If So, Select Set 1 (Italic)
//	}
//	glBindTexture(GL_TEXTURE_2D, texture[0]);			// Select Our Font Texture
//	glDisable(GL_DEPTH_TEST);							// Disables Depth Testing
//	glMatrixMode(GL_PROJECTION);						// Select The Projection Matrix
//	glPushMatrix();										// Store The Projection Matrix
//	glLoadIdentity();									// Reset The Projection Matrix
//	glOrtho(0,640,0,480,-1,1);							// Set Up An Ortho Screen
//	glMatrixMode(GL_MODELVIEW);							// Select The Modelview Matrix
//	glPushMatrix();										// Store The Modelview Matrix
//	glLoadIdentity();									// Reset The Modelview Matrix
//	glTranslated(x,y,0);								// Position The Text (0,0 - Bottom Left)
//	glListBase(base-32+(128*set));							// Choose The Font Set (0 or 1)
//
//	if (set==0)												// If Set 0 Is Being Used Enlarge Font
//	{
//		glScalef(1.5f,2.0f,1.0f);							// Enlarge Font Width And Height
//	}
//
//	glCallLists(strlen(text),GL_UNSIGNED_BYTE, text);		// Write The Text To The Screen
//	glMatrixMode(GL_PROJECTION);						// Select The Projection Matrix
//	glPopMatrix();										// Restore The Old Projection Matrix
//	glMatrixMode(GL_MODELVIEW);							// Select The Modelview Matrix
//	glPopMatrix();										// Restore The Old Projection Matrix
//	glEnable(GL_DEPTH_TEST);							// Enables Depth Testing
//	//glDisable(GL_TEXTURE_2D);								// Disable Texture Mapping
//}

