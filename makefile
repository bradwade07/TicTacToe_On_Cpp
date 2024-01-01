all: gameRuner

gameRunner: cell.o game.o main.o
	g++ -o gameRunner -Wall cell.o game.o main.o
	
main.o: main.cpp 
	g++ -c -Wall main.cpp
	
game.o: game.cpp 
	g++ -c -Wall game.cpp

cell.o: cell.cpp 
	g++ -c -Wall cell.cpp

clean:	
	rm -f gameRunner *.o