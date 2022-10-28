all: main.o node.o myvector.o
	g++ main.o node.o myvector.o -o Lab3
	
main.o: main.cpp
	g++ -c main.cpp
	
node.o: node.cpp
	g++ -c node.cpp
	
myvector.o: myvector.cpp
	g++ -c myvector.cpp
	
clean:
	rm -rf *.o