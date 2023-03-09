


output: main.o objects utils
	g++ main.o vector2.o -o bin/output -lSDL2

main.o: src/main.cpp
	g++ -c src/main.cpp -lSDL2

objects: src/objects/*.cpp src/objects/*.h
	g++ -c src/objects/*.cpp

utils: src/utils/*.cpp src/utils/*.h
	g++ -c src/utils/*.cpp




clean:
	rm *.o bin/output

clear:
	rm *.o
