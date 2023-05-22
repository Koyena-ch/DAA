//NQueens
#include<stdio.h>
#include<stdlib.h>

int max, s=0;

void printA(int a[],int n){
    printf("<");
    for(int i=1;i<n;i++)
        printf(" (%d,%d) ",i,a[i]);
    printf(">");
}

int place(int x[],int n,int pos){
    if(n==1) return 1;
    for(int i=1;i<n;i++)
        if(pos==x[i] || abs(i-n)==abs(x[i]-pos))
            return 0;
    return 1;
}

void queenSolve(int x[],int n){
    for(int i=1;i<=max;i++)
        if(place(x,n,i)==1){
            x[n]=i;
            if(n==max){
                printf("Soln %d : ",++s);
                printA(x,max+1);
                printf("\n");
            }
            else
                queenSolve(x,n+1);
        }
}

void main(){
    int n;
    printf("Enter no. of queens : ");
    scanf("%d",&n);
    int x[n+1];
    max=n;
    queenSolve(x,1);
}
