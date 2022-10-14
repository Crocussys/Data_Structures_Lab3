all: main.o node.o
	g++ main.o node.o -o Lab3
	
main.o: main.cpp
	g++ -c main.cpp
	
node.o: node.cpp
	g++ -c node.cpp
	
clean:
	rm -rf *.o