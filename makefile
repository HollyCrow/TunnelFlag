# Build
CLIENTBUILDDIR=build/client


all: main.o objects utils game camera
	g++ build/client/*.o -o build/client.rar -lSDL2


main.o: client/src/main.cpp
	mkdir -p build
	mkdir -p build/client
	g++ -c client/src/main.cpp -lSDL2 -o $(CLIENTBUILDDIR)/main.o

objects: object localplayer player

object: client/src/objects/object.cpp client/src/objects/object.cpp
	g++ -c client/src/objects/object.cpp -o $(CLIENTBUILDDIR)/object.o
localplayer: client/src/objects/localplayer.cpp client/src/objects/localplayer.h
	g++ -c client/src/objects/localplayer.cpp -o $(CLIENTBUILDDIR)/localplayer.o
player: client/src/objects/player.cpp client/src/objects/player.h
	g++ -c client/src/objects/player.cpp -o $(CLIENTBUILDDIR)/player.o


utils: keyboard color vector2

keyboard: client/src/utils/keyboard.cpp client/src/utils/keyboard.h
	g++ -c client/src/utils/keyboard.cpp -o $(CLIENTBUILDDIR)/keyboard.o
color: client/src/utils/color.cpp client/src/utils/color.h
	g++ -c client/src/utils/color.cpp -o $(CLIENTBUILDDIR)/color.o
vector2: client/src/utils/vector2.cpp client/src/utils/vector2.h
	g++ -c client/src/utils/vector2.cpp -o $(CLIENTBUILDDIR)/vector2.o


game: client/src/game/game.cpp client/src/game/game.h
	g++ -c client/src/game/game.cpp -o $(CLIENTBUILDDIR)/game.o

camera: client/src/camera/camera.cpp client/src/camera/camera.h
	g++ -c client/src/camera/camera.cpp -o $(CLIENTBUILDDIR)/camera.o

# Additional Scripts
clean:
	rm client/build/*.o client/bin/output

clear:
	rm client/build/*.o
