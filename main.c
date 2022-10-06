#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
int V;
int distMin(int length[], int Spath[]);

void display(int length[]);

void dijkstra(int graph[V][V], int source);

int main()
{
    printf("Enter number of vertices\n");
    scanf("%d", &V);
    int graph[V][V];
    printf("Enter adjacency matrix\n", V);

    for (int i = 0; i < V; i++)
    {
        for (int j = 0; j < V; j++)
        {
            scanf("%d", &graph[i][j]);
        }
    }

    dijkstra(graph, 0);

    return 0;
}

int distMin(int length[], int Spath[])
{
    int min = INT_MAX, min_index;

    for (int v = 0; v < V; v++)
        if (Spath[v] == 0 && length[v] <= min)
            min = length[v], min_index = v;

    return min_index;
}

void display(int length[])
{
    printf("Vertex No \t\t Distance from starting Source\n");
    for (int i = 0; i < V; i++)
        printf("%d \t\t\t %d\n", i, length[i]);
}

void dijkstra(int graph[V][V], int source)
{
    int length[V];

    int Spath[V];

    for (int i = 0; i < V; i++)
        length[i] = INT_MAX, Spath[i] = 0;

    length[source] = 0;

    for (int count = 0; count < V - 1; count++)
    {

        int u = distMin(length, Spath);

        Spath[u] = 1;

        for (int v = 0; v < V; v++)

            if (!Spath[v] && graph[u][v] && length[u] != INT_MAX && length[u] + graph[u][v] < length[v])
                length[v] = length[u] + graph[u][v];
    }

    display(length);
}

