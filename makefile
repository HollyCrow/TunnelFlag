all: client server


# ---------- CLIENT ----------

client: client_main network utils game camera
	g++ build/client/*.o -o build/client.rar -lSDL2 -pthread

client_main: client/src/main.cpp
	mkdir -p build
	mkdir -p build/client
	g++ -c client/src/main.cpp -o build/client/main.o -lSDL2 -pthread

#camera: client/src/camera/camera.cpp client/src/camera/camera.h
#	g++ -c client/src/camera/camera.cpp -o build/client/camera.o

game: client/src/game/game.cpp client/src/game/game.h
	g++ -c client/src/game/game.cpp -o build/client/build.o

utils: client/src/utils/color.cpp client/src/utils/color.h client/src/utils/keyboard.cpp client/src/utils/keyboard.h client/src/utils/vector2.cpp client/src/utils/vector2.h
	g++ -c client/src/utils/color.cpp -o build/client/color.o
	g++ -c client/src/utils/keyboard.cpp -o build/client/keyboard.o
	g++ -c client/src/utils/vector2.cpp -o build/client/vector2.o

network: client/src/network/network.cpp client/src/network/network.h
	g++ -c client/src/network/network.cpp -o build/client/network.o

camera: client/src/camera/camera.cpp client/src/camera/camera.h
	g++ -c client/src/camera/camera.cpp -o build/client/camera.o

# ---------- SERVER ----------