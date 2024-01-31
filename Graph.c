#include <stdio.h>
int graph[50][50];
int main()
{
    int edge , node;
    scanf("%d %d",&edge,&node);
    int n1,n2;
    printf ("enter two vertexes that are connected by edge\n");
    for(int i=0;i<edge ;i++)
    {
        scanf("%d %d",&n1,&n2);
        graph[n1][n2]=1;
        graph[n2][n1]=1;
    }
    for(int i=0;i<node ;i++)
    {
        for(int j=0;j<node;j++)
        {
            printf ("%d\t", graph[i][j]);
        }
        printf ("\n");
    }
    return 0;
}
