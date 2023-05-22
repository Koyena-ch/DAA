#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

struct Edge 
{
	int source, destination, weight;
};

struct Graph 
{
	int V, E;
    	struct Edge* edge;
};

struct Graph* createGraph(int V, int E) 
{
    	struct Graph* graph = (struct Graph*)malloc(sizeof(struct Graph));
  	graph->V = V;
    	graph->E = E;
    	graph->edge = (struct Edge*)malloc(E * sizeof(struct Edge));
    	return graph;
}

void printDistance(int distance[], int V) 
{
    	printf("Vertex    Distance from Source\n");
    	for (int i = 0; i < V; ++i)
      		printf("%d\t\t%d\n", i, distance[i]);
}

void BellmanFord(struct Graph* graph, int source) 
{
    	int V = graph->V;
    	int E = graph->E;
    	int distance[V];
    	for (int i = 0; i < V; ++i)
        	distance[i] = INT_MAX;
    	distance[source] = 0;
    	for (int i = 1; i <= V - 1; ++i)
        	for (int j = 0; j < E; ++j) 
		{
            		int u = graph->edge[j].source;
            		int v = graph->edge[j].destination;
            		int weight = graph->edge[j].weight;
            		if (distance[u] != INT_MAX && distance[u] + weight < distance[v])
                		distance[v] = distance[u] + weight;
        	}
    	for (int i = 0; i < E; ++i) 
	{
        	int u = graph->edge[i].source;
        	int v = graph->edge[i].destination;
        	int weight = graph->edge[i].weight;
        	if (distance[u] != INT_MAX && distance[u] + weight < distance[v]) 
		{
            		printf("Graph contains negative-weight cycle\n");
            		return;
        	}
    	}
    	printDistance(distance, V);
}

int main() 
{
	int V, E, source;
   	printf("Enter the number of vertices in the graph : ");
    	scanf("%d", &V);
    	printf("Enter the number of edges in the graph : ");
    	scanf("%d", &E);
	struct Graph* graph = createGraph(V, E);
	printf("Enter the source vertex : ");
    	scanf("%d", &source);
	printf("Enter the source, destination, and weight for each edge :\n");
    	for (int i = 0; i < E; ++i)
        	scanf("%d %d %d", &graph->edge[i].source, &graph->edge[i].destination, &graph->edge[i].weight);
	BellmanFord(graph, source);
}
