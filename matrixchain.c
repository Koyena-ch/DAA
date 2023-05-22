//ChainMatrixMultiplication
#include<stdio.h>
#include<stdlib.h>
#define MAX 20

int net[MAX][MAX]={0},partition[MAX][MAX]={0};

int netp(int s[],int p, int q){
    if((p+1)==q) return 0;
    if(net[p][q]!=0) return net[p][q];

    int min=INT_MAX,minp;
    for(int k=p+1;k<q;k++){
        int cur=netp(s,p,k)+netp(s,k,q)+s[p]*s[k]*s[q];
        if(cur<min){
            min=cur;
            minp=k;
        }
    }
    net[p][q]=min;
    partition[p][q]=minp;
    return min;
}

void printa(int n,int k,int arr[][MAX]){
    for(int i=0;i<n-1;i++){
        for(int j=1;j<k;j++)
            printf("%d\t",arr[i][j]);
        printf("\n");
    }
}

void printdiv(int p,int q){
    if((p)==q ) printf(" A%d ",p);
    else{
        printf("(");
        printdiv(p,partition[p-1][q]);
        printdiv(partition[p-1][q]+1,q);
        printf(")");
    }
}

void main(){
    printf("Enter no. of arrays : ");
    int n;
    scanf("%d",&n);
    n=n+1;
    int s[n];
    printf("Enter %d dimensions... \n",n);
    for(int i=0;i<n;i++)
        scanf("%d",&s[i]);
    printf("Min p : %d\n",netp(s,0,n-1));
    printa(n,n,net);
    printf("\n////////////////////////////////////////////////////////////////////////\n");
    printa(n,n,partition);
    printdiv(1,n-1);
}
