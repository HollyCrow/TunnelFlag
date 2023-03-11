# Build
CLIENTBUILDDIR=build/client

# Sources
MAIN_SRC=client/src/main.cpp
OBJECT_SRC=client/src/objects/object.cpp
LOCALPLAYER_SRC=client/src/objects/localplayer.cpp
PLAYER_SRC=client/src/objects/player.cpp
KEYBOARD_SRC=client/src/utils/keyboard.cpp
COLOR_SRC=client/src/utils/color.cpp
VECTOR2_SRC=client/src/utils/vector2.cpp
GAME_SRC=client/src/game/game.cpp
CAMERA_SRC=client/src/camera/camera.cpp

# Object files
MAIN_OBJ=$(CLIENTBUILDDIR)/main.o
OBJECT_OBJ=$(CLIENTBUILDDIR)/object.o
LOCALPLAYER_OBJ=$(CLIENTBUILDDIR)/localplayer.o
PLAYER_OBJ=$(CLIENTBUILDDIR)/player.o
KEYBOARD_OBJ=$(CLIENTBUILDDIR)/keyboard.o
COLOR_OBJ=$(CLIENTBUILDDIR)/color.o
VECTOR2_OBJ=$(CLIENTBUILDDIR)/vector2.o
GAME_OBJ=$(CLIENTBUILDDIR)/game.o
CAMERA_OBJ=$(CLIENTBUILDDIR)/camera.o

# Dependencies
MAIN_DEPS=$(MAIN_SRC)
OBJECT_DEPS=$(OBJECT_SRC) client/src/objects/object.h
LOCALPLAYER_DEPS=$(LOCALPLAYER_SRC) client/src/objects/localplayer.h
PLAYER_DEPS=$(PLAYER_SRC) client/src/objects/player.h
KEYBOARD_DEPS=$(KEYBOARD_SRC) client/src/utils/keyboard.h
COLOR_DEPS=$(COLOR_SRC) client/src/utils/color.h
VECTOR2_DEPS=$(VECTOR2_SRC) client/src/utils/vector2.h
GAME_DEPS=$(GAME_SRC) client/src/game/game.h
CAMERA_DEPS=$(CAMERA_SRC) client/src/camera/camera.h

all: $(MAIN_OBJ) $(OBJECT_OBJ) $(LOCALPLAYER_OBJ) $(PLAYER_OBJ) $(KEYBOARD_OBJ) $(COLOR_OBJ) $(VECTOR2_OBJ) $(GAME_OBJ) $(CAMERA_OBJ)
	g++ $(MAIN_OBJ) $(OBJECT_OBJ) $(LOCALPLAYER_OBJ) $(PLAYER_OBJ) $(KEYBOARD_OBJ) $(COLOR_OBJ) $(VECTOR2_OBJ) $(GAME_OBJ) $(CAMERA_OBJ) -o build/client.rar -lSDL2

$(CLIENTBUILDDIR)/client.rar:
	g++ $^ -o $@ -lSDL2

$(MAIN_OBJ): $(MAIN_DEPS)
	mkdir -p $(CLIENTBUILDDIR)
	g++ -c $(MAIN_SRC) -lSDL2 -o $(MAIN_OBJ)

$(OBJECT_OBJ): $(OBJECT_DEPS)
	g++ -c $(OBJECT_SRC) -o $(OBJECT_OBJ)

$(LOCALPLAYER_OBJ): $(LOCALPLAYER_DEPS)
	g++ -c $(LOCALPLAYER_SRC) -o $(LOCALPLAYER_OBJ)

$(PLAYER_OBJ): $(PLAYER_DEPS)
	g++ -c $(PLAYER_SRC) -o $(PLAYER_OBJ)

$(KEYBOARD_OBJ): $(KEYBOARD_DEPS)
	g++ -c $(KEYBOARD_SRC) -o $(KEYBOARD_OBJ)

$(COLOR_OBJ): $(COLOR_DEPS)
	g++ -c $(COLOR_SRC) -o $(COLOR_OBJ)

$(VECTOR2_OBJ): $(VECTOR2_DEPS)
	g++ -c $(VECTOR2_SRC) -o $(VECTOR2_OBJ)

$(GAME_OBJ): $(GAME_DEPS)
	g++ -c $(GAME_SRC) -o $(GAME_OBJ)

$(CAMERA_OBJ): $(CAMERA_DEPS)
	g++ -c $(CAMERA_SRC) -o $(CAMERA_OBJ)

clean:
	rm -rf $(CLIENTBUILDDIR) build/client.rar

clear:
	rm -rf $(CLIENTBUILDDIR)/*.o
