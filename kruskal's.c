#include <stdio.h>
#include <stdlib.h>

// Structure to represent an edge
struct Edge
{
    int src, dest, weight;
};

// Function to find the parent of a vertex
int findParent(int parent[], int vertex)
{
    if (parent[vertex] == vertex)
        return vertex;
    return findParent(parent, parent[vertex]);
}

// Function to perform union of two sets
void unionSets(int parent[], int rank[], int x, int y)
{
    int xRoot = findParent(parent, x);
    int yRoot = findParent(parent, y);

    if (rank[xRoot] < rank[yRoot])
        parent[xRoot] = yRoot;
    else if (rank[xRoot] > rank[yRoot])
        parent[yRoot] = xRoot;
    else
    {
        parent[yRoot] = xRoot;
        rank[xRoot]++;
    }
}

// Function to find the minimum spanning tree using Kruskal's algorithm
void kruskalMST(int V, int E, struct Edge* edges)
{
    int* parent = (int*)malloc(V * sizeof(int));
    int* rank = (int*)malloc(V * sizeof(int));

    // Initialize parent and rank arrays
    for (int i = 0; i < V; i++)
    {
        parent[i] = i;
        rank[i] = 0;
    }

    struct Edge* result = (struct Edge*)malloc((V - 1) * sizeof(struct Edge));
    int resultIndex = 0;

    int i = 0;
    while (resultIndex < V - 1 && i < E)
    {
        struct Edge nextEdge = edges[i++];

        int x = findParent(parent, nextEdge.src);
        int y = findParent(parent, nextEdge.dest);

        if (x != y)
        {
            result[resultIndex++] = nextEdge;
            unionSets(parent, rank, x, y);
        }
    }

    printf("Edges of MST:\n");
    for (int i = 0; i < V - 1; i++)
    {
        printf("%d -- %d == %d\n", result[i].src, result[i].dest, result[i].weight);
    }

    free(parent);
    free(rank);
    free(result);
}

int main()
{
    int V = 4;  // Number of vertices in the graph
    int E = 5;  // Number of edges in the graph

    struct Edge* edges = (struct Edge*)malloc(E * sizeof(struct Edge));

    // Add edge 0-1
    edges[0].src = 0;
    edges[0].dest = 1;
    edges[0].weight = 10;

    // Add edge 0-2
    edges[1].src = 0;
    edges[1].dest = 2;
    edges[1].weight = 6;

    // Add edge 0-3
    edges[2].src = 0;
    edges[2].dest = 3;
    edges[2].weight = 5;

    // Add edge 1-3
    edges[3].src = 1;
    edges[3].dest = 3;
    edges[3].weight = 15;

    // Add edge 2-3
    edges[4].src = 2;
    edges[4].dest = 3;
    edges[4].weight = 4;

    kruskalMST(V, E, edges);

    free(edges);

    return 0;
}
