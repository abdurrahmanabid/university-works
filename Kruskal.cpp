#include <bits/stdc++.h>
using namespace std;

int V, E;
int parent[100];
int cost[100][100];

int find(int i)
{
    while (parent[i] != i)
        i = parent[i];
    return i;
}

void union1(int i, int j)
{
    int a = find(i);
    int b = find(j);
    parent[a] = b;
}

void kruskalMST()
{
    int mincost = 0; // Cost of min MST.
    int edge_count = 0;
    while (edge_count < V - 1)
    {
        int min = INT_MAX, a = -1, b = -1;
        for (int i = 1; i <= V; i++)
        {
            for (int j = 1; j <= V; j++)
            {
                if (find(i) != find(j) && cost[i][j] < min)
                {
                    min = cost[i][j];
                    a = i;
                    b = j;
                }
            }
        }

        union1(a, b);
        if (a != -1 && b != -1)
        {
            cout << "Edge " << edge_count++ << ": (" << a << " " << b << ") cost: " << min << endl;
            mincost += min;
        }
    }
    cout << endl << "Minimum cost= " << mincost<<endl;
}

int main()
{
    freopen("input.txt","r",stdin);
    cin >> V >> E;
    for (int i = 1; i <= V; i++)
    {
        for (int j = 1; j <= V; j++)
        {
            cost[i][j] = INT_MAX;
        }
    }

    for (int j = 0; j < E; j++)
    {
        int m, n, weight;
        cin >> m >> n >> weight;
        cost[m][n] = cost[n][m] = weight;
    }

    for (int i = 1; i <= V; i++)
        parent[i] = i;

    kruskalMST();
    return 0;
}
