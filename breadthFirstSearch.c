//BFS
#include<stdio.h>
#include<stdlib.h>
#define MAX 20

int adj[MAX][MAX]={0},col[MAX]={0},pi[MAX]={0};
int que[MAX],ll=0,rl=0;

int pop(){
    if(ll==rl) return -1;
    return que[ll++];
}

int push(int n){
    que[rl++]=n;
}

void addEdge(int a,int b){
    adj[a][b]=adj[b][a]=1;
}

void BFS(int n,int s){
    push(s);
    col[s]=1;
    int parent = 0;
    while(1){
        int node = pop();
        if(node == -1) break;

        if(pi[node]!=parent){
            printf(" | ");
            parent = pi[node];
        }
        printf("%d ",node);

        for(int i=1;i<=n;i++)
            if(adj[node][i]==1 && col[i]==0){
                col[i]=1;
                push(i);
                pi[i]=node;
            }

        for(int i=1;i<=n;i++)
            if(adj[i][node]==1 && col[i]==0){
                col[i]=1;
                push(i);
                pi[i]=node;
            }
        
        col[node]=2;
    }
}

void main(){
    int n,s;
    scanf("%d",&n);

    int a, b;
    printf("Connect Edge : a b (-1 -1 to exit) : \n");
    printf("Connect Edge : ");
    scanf("%d %d",&a,&b);
    while(!(a<0 || b<0)){
        addEdge(a,b);
        printf("Connect Edge : ");
        scanf("%d %d",&a,&b);
    }

    printf("Enter starting node : ");
    scanf("%d",&s);
    BFS(n,s);
}