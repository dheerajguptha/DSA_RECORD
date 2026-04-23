//Implementation of Minimum Spanning Tree (MST) 

//Prim’s Algorithm 

/*
  AIM : To write a program to implement Prim’s Algorithm to find the minimum spanning tree of a given graph.
*/


#include <stdio.h>
#include <stdlib.h>

#define V 5  // Number of vertices

// Function to find the vertex with minimum key value
int minKey(int key[], int visited[])
{
    int min = 999999;  // Initialize min value
    int min_index = 0; // Index of minimum value

    for (int i = 0; i < V; i++)
    {
        if (!visited[i] && key[i] < min)
        {
            min = key[i];
            min_index = i;
        }
    }
    return min_index;
}

// Function to print the MST
void printPrimMST(int parent[], int graph[V][V])
{
    printf("\nPrim's MST:\n");
    printf("Edge \tWeight\n");

    int total = 0;

    for (int i = 1; i < V; i++)
    {
        printf("%d - %d \t%d\n", parent[i], i, graph[i][parent[i]]);
        total += graph[i][parent[i]];
    }

    printf("Total Cost = %d\n", total);
}

// Prim's Algorithm Implementation
void primMST(int graph[V][V])
{
    int parent[V];   // Stores MST
    int key[V];      // Minimum edge weight
    int visited[V];  // Track visited vertices

    // Step 1: Initialize
    for (int i = 0; i < V; i++)
    {
        key[i] = 999999;
        visited[i] = 0;
    }

    // Step 2: Start from vertex 0
    key[0] = 0;
    parent[0] = -1;

    // Step 3: Build MST
    for (int count = 0; count < V - 1; count++)
    {
        // Pick minimum key vertex
        int u = minKey(key, visited);
        visited[u] = 1;

        // Update adjacent vertices
        for (int v = 0; v < V; v++)
        {
            // Check conditions
            if (graph[u][v] && !visited[v] && graph[u][v] < key[v])
            {
                parent[v] = u;
                key[v] = graph[u][v];
            }
        }
    }

    // Print the result
    printPrimMST(parent, graph);
}

// Main function
int main()
{
    // Graph represented as adjacency matrix
    int graph[V][V] = {
        {0, 2, 3, 0, 0},
        {2, 0, 5, 3, 0},
        {3, 5, 0, 0, 4},
        {0, 3, 0, 0, 2},
        {0, 0, 4, 2, 0}
    };

    // Run Prim's Algorithm
    primMST(graph);

    return 0;
}
