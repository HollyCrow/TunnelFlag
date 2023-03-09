output: main.o objects utils game
	g++ *.o -o bin/output -lSDL2

main.o: src/main.cpp
	g++ -c src/main.cpp -lSDL2

objects: src/objects/*.cpp src/objects/*.h
	g++ -c src/objects/*.cpp

utils: src/utils/*.cpp src/utils/*.h
	g++ -c src/utils/*.cpp

game: src/game/*.cpp src/game/*.h
	g++ -c src/game/*.cpp


clean:
	rm *.o bin/output

clear:
	rm *.o
