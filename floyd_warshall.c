#include <stdio.h>

#define INF 999

void print(int n,int matrix[n][n]) 
{
  	for (int i = 0; i < n; i++) 
  	{
	    for (int j = 0; j < n; j++) 
			if (matrix[i][j] == INF)
				printf("%4s", "INF");
			else
				printf("%4d", matrix[i][j]);
	    printf("\n");
	}
}

void floydwarshall(int n, int graph[n][n]) 

{

  	int matrix[n][n];

  	for (int i = 0; i < n; i++)

    		for (int j = 0; j < n; j++)

      			matrix[i][j] = graph[i][j];

	for (int k = 0; k < n; k++) 

	{

	    print(n,matrix);

	    printf("\n");

		for (int i = 0; i <n; i++) 

			for (int j = 0; j < n; j++) 

				if (matrix[i][k] + matrix[k][j] < matrix[i][j])

				  	matrix[i][j] = matrix[i][k] + matrix[k][j];

	}

	printf("The shortest distance matrix :\n");

  	print(n,matrix);

}


int main() 
{
  	int n;
	printf("Enter the number of vertices : ");
	scanf("%d",&n);
	int graph[n][n];
	printf("Enter the adjacency matrix :\n");
	printf("Enter -1 when the nodes are not connected.\n");
	for(int i=0;i<n;i++)
		for(int j=0;j<n;j++)
		{
			scanf("%d",&graph[i][j]);
			if(graph[i][j] == -1)
				graph[i][j] = INF;
		}
  	floydwarshall(n, graph);
}

