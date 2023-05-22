#include<stdio.h>
#include<stdlib.h>

struct Edge{
    int u, v, w;
};
typedef struct Edge Edge;

void bFord(Edge e[], int d[], int pi[], int s, int v, int ed){
    for(int i=1;i<v;i++){
        d[i]=INT_MAX;
        pi[i]=i;
    }
    d[s]=0;
    for(int i=1;i<v-1;i++)
        for(int j=0;j<ed;j++){
            if(d[e[j].u]!=INT_MAX && (d[e[j].u] + e[j].w)<d[e[j].v]){
                d[e[j].v]=d[e[j].u] + e[j].w;
                pi[e[j].v]=e[j].u;
            }
        }
}

void printA(int a[],int n){
    printf("\n");
    for(int i=1;i<n;i++)
        printf("%d ",a[i]);
    printf("\n");
}

void printPath(int s, int v, int pi[]){
    if(s==v){
        printf("%d",s);
        return;
    }
    else if(s==pi[v]){
        printf("%d>%d",s,v);
        return;
    }
    printPath(s,pi[v],pi);
    printf(">%d",v);
}

void main(){
    int n,ed=0,u,v,w;
    printf("Enter no. of vertices : ");
    scanf("%d",&n);
    Edge e[n*(n-1)/2];
    int dist[n+1], pi[n+1];
    printf("Enter edges : u v weight (-1 -1 -1 to exit)\n");
    while(1){
        printf("Enter : ");
        scanf("%d %d %d",&u,&v,&w);
        if(u==-1 && v==-1 && w==-1) break;
        e[ed].u=u;
        e[ed].v=v;
        e[ed++].w=w;
    }
    printf("Enter source node : ");
    scanf("%d",&u);
    bFord(e,dist,pi,u,n+1,ed);
    /*printf("\nMin Dist : ");
    printA(dist,n+1);
    printf("\nPredecessor : ");
    printA(pi,n+1);*/

    printf("To Edge\tDist\tPath\n");
    for(int i=1;i<n+1;i++){
        printf("%d\t%d\t",i,dist[i]);
        printPath(u,i,pi);
        printf("\n");
    }
}
