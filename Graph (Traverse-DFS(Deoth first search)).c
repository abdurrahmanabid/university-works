#include <stdio.h>
#define WHITE 1
#define GRAY 2
#define BLACK 3
int edge , node;
int graph[50][50];
int color[50];
void DFS(){
    for(int i=0;i<node ;i++)
    {
        color[i]=WHITE;
    }
    for(int i=0;i<node  ;i++)
    {
        if(color[i]==WHITE){
            visitDFS(i);
        }
    }
}



void visitDFS(int x){
    color[x]=GRAY;
    for(int i=0;i<node ;i++)
    {
        if(graph[x][i]==1){
                if(color[i]==WHITE){
                    visitDFS(i);
                }

        }
    }

    color[x]=BLACK;
    printf ("%d\t",x);
}



int main()
{
    freopen("Graph input.txt","r",stdin);

    scanf("%d %d",&edge,&node);
    int n1,n2;


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
    DFS();
    return 0;
}

