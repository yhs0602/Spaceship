#include <windows.h>
#include <gl/GL.h>
#include <gl/GLU.h>

class game;
class Renderer;
class Player;

enum GameState {UNSTARTED,PLAYING,PAUSE};
enum GameState gameState;
typedef struct{
        HDC hdc;
        HGLRC hrc;
        HWND hwnd;
} WinDependencyVars;

extern WinDependencyVars winVars;

class Player{
      
};
class Game{
      public:
             void Init()
             {
                  gameState=UNSTARTED;
             }
};

class Renderer
{
      private:
              Game *game;
      public:
             Renderer()
             {
                       ;
             }
             Renderer(Game * game)
             {
                           this->game=game;
             }
             
             void DoGLDisplay()
             {
                  GLfloat xAngle=60, yAngle=30, zAngle=45; 
                  GLfloat red=0.5, green=0.5, blue=0.5;
                  glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
                  glShadeModel(GL_FLAT); 
                  glEnable(GL_DEPTH_TEST); // �ֺ��� ���� glEnable(GL_LIGHTING);
                  GLfloat arLight[]={red, green, blue, 1.0}; 
                  glLightModelfv(GL_LIGHT_MODEL_AMBIENT, arLight); 
                  if (1/*bColorTrack*/) 
                  { 
                                   glEnable(GL_COLOR_MATERIAL); 
                                   glColorMaterial(GL_FRONT,GL_AMBIENT); 
                  } else { 
                                   glDisable(GL_COLOR_MATERIAL); 
                  } 
                  glPushMatrix(); 
                  glRotatef(xAngle, 1.0f, 0.0f, 0.0f); 
                  glRotatef(yAngle, 0.0f, 1.0f, 0.0f); 
                  glRotatef(zAngle, 0.0f, 0.0f, 1.0f); // �Ʒ��� �� �ٴ� 
                  GLfloat arbottom[]={1.0, 1.0, 1.0, 1.0}; 
                  glMaterialfv(GL_FRONT, GL_AMBIENT, arbottom); 
                  glColor3f(1,1,1); 
                  glBegin(GL_QUADS); 
                  glVertex2f(-0.5, 0.5); 
                  glVertex2f(0.5, 0.5); 
                  glVertex2f(0.5, -0.5); 
                  glVertex2f(-0.5, -0.5); 
                  glEnd(); // ���� ���� �� 
                  GLfloat arMat1[]={1.0, 0.0, 0.0, 1.0}; 
                  glMaterialfv(GL_FRONT, GL_AMBIENT, arMat1); 
                  glBegin(GL_TRIANGLE_FAN); 
                  glColor3f(1,1,1); 
                  glVertex3f(0.0, 0.0, -0.8); 
                  glColor3f(1,0,0); 
                  glVertex2f(0.5, 0.5); 
                  glVertex2f(-0.5, 0.5); // ���� ��� �� 
                  GLfloat arMat2[]={0.0, 0.0, 0.5, 1.0}; 
                  glMaterialfv(GL_FRONT, GL_AMBIENT, arMat2); 
                  glColor3f(1,1,0); glVertex2f(-0.5, -0.5); // �Ʒ��� �ʷ� �� 
                  GLfloat arMat3[]={0.0, 0.25, 0.0, 1.0}; 
                  glMaterialfv(GL_FRONT, GL_AMBIENT, arMat3); 
                  glColor3f(0,1,0); glVertex2f(0.5, -0.5); // ������ �Ķ� �� 
                  GLfloat arMat4[]={0.0, 0.0, 1.0, 1.0}; 
                  glMaterialfv(GL_FRONT, GL_AMBIENT, arMat4); 
                  glColor3f(0,0,1); 
                  glVertex2f(0.5, 0.5); 
                  glEnd(); 
                  glPopMatrix();
                  
                  glFinish();
             }
             void DoWinDisplay()
             {
                  SetTextColor(winVars.hdc, RGB(255,255,0)); 
                  SetBkMode(winVars.hdc,TRANSPARENT); 
                  TextOutA(winVars.hdc,10,10,"War War You won!",12);
             }
             void DoDisplay()
             {
                  DoGLDisplay();
                  DoWinDisplay();
                  ValidateRect(winVars.hwnd, NULL);
             }

};
