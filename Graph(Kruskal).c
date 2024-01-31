#include <stdio.h>
#include <stdlib.h>

#define MAX_NODES 20

struct Edge {
    int src, dest, weight;
};

struct Graph {
    int V, E;
    struct Edge edges[MAX_NODES];
};

struct Subset {
    int parent;
    int rank;
};

int find(struct Subset subsets[], int i);
void unionSet(struct Subset subsets[], int x, int y);
int compareEdges(const void* a, const void* b);
int find(struct Subset subsets[], int i) {
    if (subsets[i].parent != i)
        subsets[i].parent = find(subsets, subsets[i].parent);
    return subsets[i].parent;
}

void unionSet(struct Subset subsets[], int x, int y) {
    int xroot = find(subsets, x);
    int yroot = find(subsets, y);

    if (subsets[xroot].rank < subsets[yroot].rank)
        subsets[xroot].parent = yroot;
    else if (subsets[xroot].rank > subsets[yroot].rank)
        subsets[yroot].parent = xroot;
    else {
        subsets[yroot].parent = xroot;
        subsets[xroot].rank++;
    }
}

 int compareEdges(const void* a, const void* b) {
    return ((struct Edge*)a)->weight - ((struct Edge*)b)->weight;
}

void kruskal(struct Graph graph) {
    struct Subset subsets[MAX_NODES];
    struct Edge result[MAX_NODES];
    int e = 0; // Index for the result array
    int i = 0; // Index for the sorted edges array

    for (int v = 0; v < graph.V; v++) {
        subsets[v].parent = v;
        subsets[v].rank = 0;
    }

    qsort(graph.edges, graph.E, sizeof(struct Edge), compareEdges);

    while (e < graph.V - 1 && i < graph.E) {
        struct Edge nextEdge = graph.edges[i++];

        int x = find(subsets, nextEdge.src);
        int y = find(subsets, nextEdge.dest);

        if (x != y) {
            result[e++] = nextEdge;
            unionSet(subsets, x, y);
        }
    }

    printf("Edges in the Minimum Spanning Tree:\n");
    for (int i = 0; i < e; i++) {
        printf("%d - %d Weight: %d\n", result[i].src, result[i].dest, result[i].weight);
    }
}

int main() {
    struct Graph graph;
    graph.V = 7; // Number of nodes
    graph.E = 9; // Number of edges

    // Edge list (source, destination, weight)
    int edges[][3] = {
        {1, 6, 10},
        {1, 2, 28},
        {2, 7, 14},
        {2, 3, 16},
        {3, 4, 12},
        {4, 5, 22},
        {4, 7, 18},
        {5, 6, 25},
        {5, 7, 24}
    };

    // Copy the edges into the graph structure
    for (int i = 0; i < graph.E; i++) {
        graph.edges[i].src = edges[i][0];
        graph.edges[i].dest = edges[i][1];
        graph.edges[i].weight = edges[i][2];
    }

    kruskal(graph);

    return 0;
}
