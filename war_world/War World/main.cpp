#include "main.h"

WinDependencyVars winVars;
Renderer renderer;
Game game;
/*  Declare Windows procedure  */
LRESULT CALLBACK WindowProcedure (HWND, UINT, WPARAM, LPARAM);

/*  Make the class name into a global variable  */
char szClassName[ ] = "WindowsApp";

int WINAPI WinMain (HINSTANCE hThisInstance,
                    HINSTANCE hPrevInstance,
                    LPSTR lpszArgument,
                    int nFunsterStil)

{
    HWND hwnd;               /* This is the handle for our window */
    MSG messages;            /* Here messages to the application are saved */
    WNDCLASSEX wincl;        /* Data structure for the windowclass */

    /* The Window structure */
    wincl.hInstance = hThisInstance;
    wincl.lpszClassName = szClassName;
    wincl.lpfnWndProc = WindowProcedure;      /* This function is called by windows */
    wincl.style = CS_OWNDC;                 /* Catch double-clicks */
    wincl.cbSize = sizeof (WNDCLASSEX);

    /* Use default icon and mouse-pointer */
    wincl.hIcon = LoadIcon (NULL, IDI_APPLICATION);
    wincl.hIconSm = LoadIcon (NULL, IDI_APPLICATION);
    wincl.hCursor = LoadCursor (NULL, IDC_ARROW);
    wincl.lpszMenuName = NULL;                 /* No menu */
    wincl.cbClsExtra = 0;                      /* No extra bytes after the window class */
    wincl.cbWndExtra = 0;                      /* structure or the window instance */
    /* Use Windows's default color as the background of the window */
    wincl.hbrBackground = (HBRUSH) COLOR_BACKGROUND;

    /* Register the window class, and if it fails quit the program */
    if (!RegisterClassEx (&wincl))
        return 0;

    /* The class is registered, let's create the program*/
    hwnd = CreateWindowEx (
           0,                   /* Extended possibilites for variation */
           szClassName,         /* Classname */
           "War World",       /* Title Text */
           WS_OVERLAPPEDWINDOW, /* default window */
           CW_USEDEFAULT,       /* Windows decides the position */
           CW_USEDEFAULT,       /* where the window ends up on the screen */
           544,                 /* The programs width */
           375,                 /* and height in pixels */
           HWND_DESKTOP,        /* The window is a child-window to desktop */
           NULL,                /* No menu */
           hThisInstance,       /* Program Instance handler */
           NULL                 /* No Window Creation data */
           );

    /* Make the window visible on the screen */
    ShowWindow (hwnd, nFunsterStil);

    /* Run the message loop. It will run until GetMessage() returns 0 */
    while (GetMessage (&messages, NULL, 0, 0))
    {
        /* Translate virtual-key messages into character messages */
        TranslateMessage(&messages);
        /* Send message to WindowProcedure */
        DispatchMessage(&messages);
    }

    /* The program return-value is 0 - The value that PostQuitMessage() gave */
    return messages.wParam;
}


/*  This function is called by the Windows function DispatchMessage()  */

LRESULT CALLBACK WindowProcedure (HWND hwnd, UINT message, WPARAM wParam, LPARAM lParam)
{
    switch (message)                  /* handle the messages */
    {
        case WM_CREATE:
             winVars.hwnd=hwnd;
             PIXELFORMATDESCRIPTOR pfd;
             int nPixelFormat;
             winVars.hdc=GetDC(hwnd);
             memset(&pfd, 0, sizeof(pfd));
             pfd.nSize = sizeof(pfd);
             pfd.nVersion = 1;
             pfd.dwFlags = PFD_DRAW_TO_WINDOW | PFD_SUPPORT_OPENGL;
             pfd.iPixelType = PFD_TYPE_RGBA;
             pfd.cColorBits = 32;
             nPixelFormat = ChoosePixelFormat(winVars.hdc, &pfd);
             SetPixelFormat(winVars.hdc, nPixelFormat, &pfd);
             winVars.hrc=wglCreateContext(winVars.hdc);
             wglMakeCurrent(winVars.hdc, winVars.hrc);
             game.Init();
             return 0;
        case WM_DESTROY:
            wglMakeCurrent(winVars.hdc, NULL);
            wglDeleteContext(winVars.hrc);
            ReleaseDC(winVars.hwnd,winVars.hdc);
            PostQuitMessage (0);       /* send a WM_QUIT to the message queue */
            break;
        case WM_SIZE:
             glViewport( 0, 0, LOWORD(lParam), HIWORD(lParam));
             glMatrixMode(GL_PROJECTION);
             glLoadIdentity();
             glOrtho(-1, 1, -1, 1, 1, -1);
             glMatrixMode(GL_MODELVIEW );
             glLoadIdentity();
             return 0;
        case WM_PAINT:
             renderer.DoDisplay(); 
             return 0;
        case WM_TIMER:
             
             break;
        case WM_KEYDOWN:
             
             break;
        default:                      /* for messages that we don't deal with */
            return DefWindowProc (hwnd, message, wParam, lParam);
    }

    return 0;
}
