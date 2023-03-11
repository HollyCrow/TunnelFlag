all: client server

client:

server:






# ---------- CLIENT ----------

camera: client/src/camera/camera.cpp client/src/camera/camera.h build/client/camera.o
	g++ -c client/src/camera/camera.cpp -o build/client/camera.o

game: client/src/game/game.cpp client/src/game/game.h build/client/game.o
	g++ -c client/src/game/game.cpp -o build/client/build.o


# ---------- SERVER ----------