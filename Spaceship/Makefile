# Project: Call Of Dduty
# Makefile created by Dev-C++ 5.11

CPP      = g++
CC       = gcc
WINDRES  = windres
RES      = Call_Of_Dduty_private.res
OBJ      = camera.o NeHeGL.o PlayerController.o main.o GLutil.o AudioManager.o fps2.o Tmatrix.o Tray.o Tvector.o World.o chunk.o Terrain/camera.o Terrain/terrain.o Terrain/terrainDriver.o PhysicsManager.o alCWaves.o ODEHelper.o $(RES)
LINKOBJ  = camera.o NeHeGL.o PlayerController.o main.o GLutil.o AudioManager.o fps2.o Tmatrix.o Tray.o Tvector.o World.o chunk.o Terrain/camera.o Terrain/terrain.o Terrain/terrainDriver.o PhysicsManager.o alCWaves.o ODEHelper.o $(RES)
LIBS     = -L"C:/Program Files (x86)/Dev-Cpp/MinGW64/lib32" -L"C:/Program Files (x86)/Dev-Cpp/MinGW64/x86_64-w64-mingw32/lib32" -static-libgcc -mwindows -verbose -lopengl32 -lglu32  -lkernel32 -luser32 -lgdi32 -lwinspool -lcomdlg32 -ladvapi32 -lshell32 -lole32 -loleaut32 -luuid -lodbc32 -lodbccp32 -lopenal32 -lode -m32
INCS     = -I"C:/Program Files (x86)/Dev-Cpp/MinGW64/include" -I"C:/Program Files (x86)/Dev-Cpp/MinGW64/x86_64-w64-mingw32/include" -I"C:/Program Files (x86)/Dev-Cpp/MinGW64/lib/gcc/x86_64-w64-mingw32/4.9.2/include"
CXXINCS  = -I"C:/Program Files (x86)/Dev-Cpp/MinGW64/include" -I"C:/Program Files (x86)/Dev-Cpp/MinGW64/x86_64-w64-mingw32/include" -I"C:/Program Files (x86)/Dev-Cpp/MinGW64/lib/gcc/x86_64-w64-mingw32/4.9.2/include" -I"C:/Program Files (x86)/Dev-Cpp/MinGW64/lib/gcc/x86_64-w64-mingw32/4.9.2/include/c++"
BIN      = "Call Of Dduty.exe"
CXXFLAGS = $(CXXINCS) -m32 -std=c11
CFLAGS   = $(INCS) -m32 -std=c11
RM       = rm.exe -f

.PHONY: all all-before all-after clean clean-custom

all: all-before $(BIN) all-after

clean: clean-custom
	${RM} $(OBJ) $(BIN)

$(BIN): $(OBJ)
	$(CPP) $(LINKOBJ) -o $(BIN) $(LIBS)

camera.o: camera.cpp
	$(CPP) -c camera.cpp -o camera.o $(CXXFLAGS)

NeHeGL.o: NeHeGL.cpp
	$(CPP) -c NeHeGL.cpp -o NeHeGL.o $(CXXFLAGS)

PlayerController.o: PlayerController.cpp
	$(CPP) -c PlayerController.cpp -o PlayerController.o $(CXXFLAGS)

main.o: main.cpp
	$(CPP) -c main.cpp -o main.o $(CXXFLAGS)

GLutil.o: GLutil.cpp
	$(CPP) -c GLutil.cpp -o GLutil.o $(CXXFLAGS)

AudioManager.o: AudioManager.cpp
	$(CPP) -c AudioManager.cpp -o AudioManager.o $(CXXFLAGS)

fps2.o: fps2.cpp
	$(CPP) -c fps2.cpp -o fps2.o $(CXXFLAGS)

Tmatrix.o: Tmatrix.cpp
	$(CPP) -c Tmatrix.cpp -o Tmatrix.o $(CXXFLAGS)

Tray.o: Tray.cpp
	$(CPP) -c Tray.cpp -o Tray.o $(CXXFLAGS)

Tvector.o: Tvector.cpp
	$(CPP) -c Tvector.cpp -o Tvector.o $(CXXFLAGS)

World.o: World.cpp
	$(CPP) -c World.cpp -o World.o $(CXXFLAGS)

chunk.o: chunk.cpp
	$(CPP) -c chunk.cpp -o chunk.o $(CXXFLAGS)

Terrain/camera.o: Terrain/camera.cpp
	$(CPP) -c Terrain/camera.cpp -o Terrain/camera.o $(CXXFLAGS)

Terrain/terrain.o: Terrain/terrain.cpp
	$(CPP) -c Terrain/terrain.cpp -o Terrain/terrain.o $(CXXFLAGS)

Terrain/terrainDriver.o: Terrain/terrainDriver.cpp
	$(CPP) -c Terrain/terrainDriver.cpp -o Terrain/terrainDriver.o $(CXXFLAGS)

PhysicsManager.o: PhysicsManager.cpp
	$(CPP) -c PhysicsManager.cpp -o PhysicsManager.o $(CXXFLAGS)

alCWaves.o: alCWaves.cpp
	$(CPP) -c alCWaves.cpp -o alCWaves.o $(CXXFLAGS)

ODEHelper.o: ODEHelper.cpp
	$(CPP) -c ODEHelper.cpp -o ODEHelper.o $(CXXFLAGS)

Call_Of_Dduty_private.res: Call_Of_Dduty_private.rc 
	$(WINDRES) -i Call_Of_Dduty_private.rc -F pe-i386 --input-format=rc -o Call_Of_Dduty_private.res -O coff 

