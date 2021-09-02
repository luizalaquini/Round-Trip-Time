# Makefile

all: compile

compile: main.o rtt.o adjacencyMatrix.o dijkstra.o PQ.o graph.o io.o vertex.o
	gcc -o trab2 main.o rtt.o adjacencyMatrix.o dijkstra.o PQ.o graph.o io.o vertex.o -lm 

main.o: ./src/main.c
	gcc -o main.o -c ./src/main.c -lm

adjacencyMatrix.o: ./src/adjacencyMatrix.c ./headers/adjacencyMatrix.h
	gcc -o adjacencyMatrix.o -c ./src/adjacencyMatrix.c -lm

dijkstra.o: ./src/dijkstra.c ./headers/dijkstra.h
	gcc -o dijkstra.o -c ./src/dijkstra.c -lm  

graph.o: ./src/graph.c ./headers/graph.h
	gcc -o graph.o -c ./src/graph.c -lm  

io.o: ./src/io.c ./headers/io.h
	gcc -o io.o -c ./src/io.c -lm

PQ.o: ./src/PQ.c ./headers/PQ.h
	gcc -o PQ.o -c ./src/PQ.c -lm

rtt.o: ./src/rtt.c ./headers/rtt.h
	gcc -o rtt.o -c ./src/rtt.c -lm

vertex.o: ./src/vertex.c ./headers/vertex.h
	gcc -o vertex.o -c ./src/vertex.c -lm

clean:
	rm -rf *.o *~ trab2