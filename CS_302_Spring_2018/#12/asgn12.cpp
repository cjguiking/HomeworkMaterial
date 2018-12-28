// Ceejay Guiking
// Assignment 12
// CS 302 - 1003
//
// Program will list a node and its adjacent nodes
// The program will also read from a file called "graph.txt"
// using file redirection.
// As a test. Inputs will be read until a 100 is encountered.
#include <iostream>
#include <stdio.h>
#include <stdlib.h>

using namespace std;
 
// Declard struct for adjacency
struct AdjListNode
{
    int dest;
    struct AdjListNode* next;
};
 
// Declare struct for head
struct AdjList
{
    struct AdjListNode *head; 
};
 
// Declare struct for graph. Size of 
// graph will be V
struct Graph
{
    int V;
    struct AdjList* array;
};
 
// Create new adjacency list node
struct AdjListNode* newAdjListNode(int dest)
{
    struct AdjListNode* newNode =
     (struct AdjListNode*) malloc(sizeof(struct AdjListNode));
    newNode->dest = dest;
    newNode->next = NULL;
    return newNode;
}
 
// A utility function that creates a graph of V vertices
struct Graph* createGraph(int V)
{
    struct Graph* graph = 
        (struct Graph*) malloc(sizeof(struct Graph));
    graph->V = V;
 
    // Create an array
    graph->array = 
      (struct AdjList*) malloc(V * sizeof(struct AdjList));
 
//	Initialize everything to be empty.
    int i;
    for (i = 1; i < V; ++i)
        graph->array[i].head = NULL;
 
    return graph;
}
 
// Add edge on the graph
void addEdge(struct Graph* graph, int src, int dest)
{
    struct AdjListNode* newNode = newAdjListNode(dest);
    newNode->next = graph->array[src].head;
    graph->array[src].head = newNode;
	
    newNode = newAdjListNode(src);
    newNode->next = graph->array[dest].head;
    graph->array[dest].head = newNode;
}
 
// Print adjacency list on the graph until end has been
// reached
void printGraph(struct Graph* graph)
{
    int v;
    for (v = 1; v < graph->V; ++v)
    {
        struct AdjListNode* matrixnode = graph->array[v].head;
       cout << endl << "Adjacency list of vertex " << v << endl;
        while (matrixnode)
        {
            cout << "->" << matrixnode->dest;
            matrixnode = matrixnode->next;
        }
        cout << endl;
    }
	
	cout << "Checking graph if it is symmetrical... " << endl;
	bool symmetrical = true;
	for (v = 1; v < graph->V; ++v)
	{
		struct AdjListNode* matrixnode = graph->array[v].head;
		while (matrixnode)
		{
			if (v == matrixnode->dest)
				symmetrical = false;
			matrixnode = matrixnode->next;
		}
	}
	cout << endl;
	if (symmetrical == false)
		cout << "ERROR! the matrix is not symmetrical" << endl;
	else if (symmetrical == true)
		cout << "SUCCESS! The matrix is symmetrical" << endl;
}

int main()
{
    int V = 6;
    struct Graph* graph = createGraph(V);
	int u, v;

//	On the test graph.txt, inputs will be read until a 100 
//  is encountered. Once it is encountered, stop reading
// the file	
	cin >> u;
	while (u != 100){
		cin >> v;
		addEdge(graph, u, v);
		cin >> u;
	}
    printGraph(graph);
 
    return 0;
}