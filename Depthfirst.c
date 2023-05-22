//DFS
#include<stdio.h>
#include<stdlib.h>
#define MAX 20

int adj[MAX][MAX]={0},col[MAX]={0},pi[MAX]={0},time[MAX][2]={0};
int stk[MAX],top=0,now=1;

void push(int n){
    stk[top++]=n;
}

int pop(){
    if(top==0) return -1;
    return stk[--top];
}

void addEdge(int a,int b){
    adj[a][b]=1;
}

void DFSvisit(int n, int s){
    printf("%d ",s);
    time[s][0]=now++;
    for(int i=1;i<=n;i++){
        if(col[i]==0 && adj[s][i]==1){
            col[i]=1;
            pi[i]=s;
            DFSvisit(n,i);
            col[i]=2;
        }
    }
    time[s][1]=now++;
}

void DFS(int n){
    for(int i=1;i<=n;i++){
        if(col[i]==0){
            col[i]=1;
            //time[i][0]=now++;
            DFSvisit(n,i);
            //time[i][1]=now++;
            col[i]=2;
        }
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

    DFS(n);

    printf("\nNode\tStart\tEnd\n\n");
    for(int i=1;i<=n;i++)
        printf("%d\t%d\t%d\n",i,time[i][0],time[i][1]);
}