#include<stdio.h>
#include<stdlib.h>
#include<time.h>

void print(int arr[],int n)
{
	for(int i=0;i<n;i++)
		printf("%d ",arr[i]);
	printf("\n");
}

void merge(int arr[],int low, int mid, int high)
{
	int i, j,k;
	int n1 = mid-low+1;
	int n2 = high-mid;
	int a1[n1],a2[n2];
	for(int i=0;i<n1;i++)
		a1[i] = arr[low+i];
	for(int j = 0;j<n2;j++)
		a2[j] = arr[mid+j+1];
	i=0;
	j=0;
	k=low;
	while(i<n1 && j<n2)
	{
		if(a1[i]<=a2[j])
		{
			arr[k] = a1[i];
			i++;
		}
		else
		{
			arr[k] = a2[j];
			j++;
		}
		k++;
	}
	while(i<n1)
	{
		arr[k] = a1[i];
		i++;
		k++;
	}
	while(j<n2)
	{
		arr[k] = a2[j];
		j++;
		k++;
	}
}

void merge_sort(int arr[],int low,int high)
{
	if (low<high)
	{
		int mid = (low+high-1)/2;
		merge_sort(arr,low,mid);
		merge_sort(arr,mid+1,high);
		merge(arr,low,mid,high);
	}
}

int main()
{
	int n;
	clock_t start, end;
	double total;
	printf("Enter the length of the array : ");
	scanf("%d",&n);
	int arr[n];
	for(int i=0;i<n;i++)
		arr[i] = rand()%100;
	printf("The original array : ");
	print(arr,n);
	start = clock();
	merge_sort(arr,0,n-1);
	end=clock();
	total = (double)(end-start)/CLOCKS_PER_SEC;
	printf("The sorted array : ");
	print(arr,n);
	printf("Duration in seconds : %lf\n",total);
}