#include <stdio.h>
int graph[50][50];
int main()
{
    freopen("Graph input.txt","r",stdin);
    int edge, node;
    scanf("%d %d",&edge,&node);
    int n1,n2;


    for(int i=0; i<edge ; i++)
    {
        scanf("%d %d",&n1,&n2);
        graph[n1][n2]=1;
        graph[n2][n1]=1;
    }
    for(int i=0; i<node ; i++)
    {
        for(int j=0; j<node; j++)
        {
            printf ("%d\t", graph[i][j]);
        }
        printf ("\n");
    }
    //created finished

    printf ("\n\n\n");


    //finding neighbors or adjacent

    for(int i=0; i<node  ; i++)
    {
        if(graph[0][i]==1)//only checking for 0 node
        {
            printf ("0---%d\n",i);
        }
    }
    return 0;
}

