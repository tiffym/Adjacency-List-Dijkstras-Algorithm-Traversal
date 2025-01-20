graph: main.o graph_functions.o
    gcc main.o graph_functions.o -lm -o graph

main.o: main.c graph.h
    gcc -Wall -std=c99 -c main.c

graph_functions.o: graph_functions.c graph.h
    gcc -Wall -std=c99 -c graph_functions.c

clean:
    rm -f *.o graph
