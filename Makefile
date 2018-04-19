#OBJS specifies which files to compile as part of the project
OBJS = \
main.cpp \
Engine\WindowSetup.cpp \
Dependencies\SDL_gfx\SDL2_framerate.c \
Dependencies\SDL_gfx\SDL2_gfxPrimitives.c \
Dependencies\SDL_gfx\SDL2_imageFilter.c \
Dependencies\SDL_gfx\SDL2_rotozoom.c \
Engine\Particle.cpp \
Engine\Vec2.cpp \
Engine\Player.cpp \
Engine\Enemy.cpp \
Engine\GSM.cpp \
Engine\Text.cpp \
Script\TestBench.cpp \
Script\ReOpinion.cpp \
Script\DistanceLines.cpp \
Script\Strange.cpp \
Script\War.cpp


#CC specifies which compiler we're using
CC = g++

#INCLUDE_PATHS specifies the additional include paths we'll need
INCLUDE_PATHS = -IDependencies\SDL\include\SDL2 -IDependencies\SDL_gfx -IEngine -IScript -IDependencies\SDL_mixer\include\SDL2 -IDependencies\SDL_ttf\include\SDL2


#LIBRARY_PATHS specifies the additional library paths we'll need
LIBRARY_PATHS = -LDependencies\SDL\lib -LDependencies\SDL_mixer\lib -LDependencies\SDL_ttf\lib

#COMPILER_FLAGS specifies the additional compilation options we're using
# -w suppresses all warnings
# -Wl,-subsystem,windows gets rid of the console window
#COMPILER_FLAGS = -w -Wl,-subsystem,windows


#LINKER_FLAGS specifies the libraries we're linking against
LINKER_FLAGS = -lmingw32 -lSDL2main -lSDL2 -lstdc++ -lSDL2_mixer -lSDL2_ttf

#OBJ_NAME specifies the name of our exectuable
OBJ_NAME = "Builds\Windows\Particle Fire"

#This is the target that compiles our executable
all : $(OBJS)
	$(CC) $(OBJS) $(INCLUDE_PATHS) $(LIBRARY_PATHS) $(COMPILER_FLAGS) $(LINKER_FLAGS) -o $(OBJ_NAME)