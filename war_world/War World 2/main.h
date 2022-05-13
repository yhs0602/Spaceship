#include <windows.h>		// Header File For Windows
#include <gl\gl.h>			// Header File For The OpenGL32 Library
#include <gl\glu.h>			// Header File For The GLu32 Library
//#include <gl\glaux.h>		// Header File For The Glaux Library

class Observer;
class SpecialEffect;
class Transportation;
class Entity;

class Observer
{
      GLdouble _eyeX;            //������ �� x��ǥ 
      GLdouble _eyeY;
      GLdouble _eyeZ;
      GLdouble _centerX;         //�Ĵٺ��� �� 
      GLdouble _centerY;
      GLdouble _centerZ;
      GLdouble _upX;             //up ���� 
      GLdouble _upY;
      GLdouble _upZ;
      void SetPosition(GLdouble x,GLdouble y,GLdouble z);
};
