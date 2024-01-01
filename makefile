all: a.out

a.out: cell.o game.o main.o
	g++ -Wall cell.o game.o main.o -o a.out
	
main.o: main.cpp 
	g++ -c -Wall main.cpp
	
game.o: game.cpp 
	g++ -c -Wall game.cpp

cell.o: cell.cpp 
	g++ -c -Wall cell.cpp

clean:	
	rm -f a.out *.o