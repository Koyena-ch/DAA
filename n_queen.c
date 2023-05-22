#include<stdio.h>

int board[20], count;

void print(int n)
{
	int soln[n];
	printf("\nSolution %d: \n", ++count);
	printf("   ");
	for(int i = 1; i <= n; i++) 
		printf("%d  ", i);
	for(int i = 1; i <= n; i++) 
	{
		printf("\n%d", i);
		for(int j = 1; j <= n; j++)
			if(board[i] == j)
			{
				printf("  Q");
				soln[i-1]=j;
			}
			else printf("  -");
	}
	printf("\n");
	printf("The solution vector : ");
	for(int i=0;i<n;i++)
		printf("%d ",soln[i]);
	printf("\n");
}


int place(int row, int column) 
{
	for(int i = 1; i <= row - 1; i++)
		if(board[i] == column)
			return 0;
		else if(abs(board[i] - column) == abs(i - row))
			return 0;
	return 1;
}

void queen(int row, int n) 
{
	for(int column = 1; column <= n; column++) 
		if(place(row, column))
		{
			board[row] = column; 
			if(row == n) 
				print(n);
			else
				queen(row + 1, n);
		}
}

int main()
{
	int n;
	printf("Enter the number of queens: ");
	scanf("%d", &n);
	queen(1, n);
}
