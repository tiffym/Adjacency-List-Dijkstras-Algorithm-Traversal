# Adjacency List Dijsktra's Algorithm Traversal

This is a program in C that works with graphs. It reads a graph from a file and represents it as an adjacency list. The program provides a menu-driven interface that allows users to interact with the graph in several ways. Users can display the graph as an adjacency list, perform Breadth-First Search (BFS) or Depth-First Search (DFS) to explore its structure, and use Dijkstra's algorithm to find the shortest path from a starting vertex to all other vertices.

## Skill Focus
- **Graph Theory**: Understanding graph representations (Adjacency Matrix, Adjacency List).
- **Algorithm Implementation**: Breadth-First Search (BFS), Depth-First Search (DFS), and Dijkstra's Algorithm.
- **File Handling**: Reading a graph from a file.
- **Memory Management**: Efficiently using dynamic memory in C (linked lists).
- **Command-Line Arguments**: Using arguments to pass file names.

## Capabilities
The program performs the following:
1. Reads a graph's adjacency matrix from a `.txt` file.
2. Provides options to display the graph's adjacency list, perform BFS, DFS, and find the shortest path using Dijkstra’s algorithm.
3. Ensures robust file handling, input validation, and proper memory management.

## Transactions
### Menu Options:
1. **Display Adjacency List**: Convert the adjacency matrix into an adjacency list and display the list for all vertices.
2. **Breadth-First Search (BFS)**: Traverse the graph using BFS starting from vertex 1.
3. **Depth-First Search (DFS)**: Traverse the graph using DFS starting from vertex 1.
4. **Dijkstra’s Algorithm**: Compute and display the shortest path from vertex 1 to all other vertices using Dijkstra’s algorithm.
5. **Exit**: Quit the program.

## Program Quit
The program continues showing the menu after performing an action until the user selects the "Exit" option. Memory is cleaned up before quitting.

## Files
The project consists of the following files:
1. **graph.h**: Header file containing function declarations and data structure definitions.
2. **main.c**: The main program that handles the menu, reads the graph from the file, and calls the appropriate functions.
3. **graph_functions.c**: File containing the implementations of the graph-related functions (e.g., BFS, DFS, Dijkstra, adjacency list creation).
4. **Makefile**: Makefile for compiling your program.
5. **README.md**: A brief explanation of the project and instructions for compiling and running it.

## Compiling the program
To compile and run the program, follow these steps:

1. In the directory where the files are saved, type:
	make 

This will compile all necessary files into an executable.
