# Build
output: main.o objects utils game camera
	mkdir -p bin
	mv *.o ./build
	g++ build/*.o -o bin/output -lSDL2

main.o: src/main.cpp
	mkdir -p build
	g++ -c src/main.cpp -lSDL2

objects: src/objects/*.cpp src/objects/*.h
	g++ -c src/objects/*.cpp

utils: src/utils/*.cpp src/utils/*.h
	g++ -c src/utils/*.cpp

game: src/game/*.cpp src/game/*.h
	g++ -c src/game/*.cpp

camera: src/camera/*.cpp src/camera/*.h
	g++ -c src/camera/*.cpp

# Additional Scripts
clean:
	rm build/*.o bin/output

clear:
	rm build/*.o
