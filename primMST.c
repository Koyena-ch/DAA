//Prims
#include<stdio.h>
#include<stdlib.h>

struct Edge{
    int a,b,weight;
};
typedef struct Edge Edge;

void freeEdge(Edge *edges[],int i){
    free(edges[i]);
    edges[i]=NULL;
}

int min(Edge *edges[],int incl[],int n){
    int min=INT_MAX,minp=-1;
    for(int i=0;i<n;i++){
        if(edges[i]==NULL) continue;
        if(edges[i]->weight<min && (incl[edges[i]->a] || incl[edges[i]->b])){
            if(incl[edges[i]->a] && incl[edges[i]->b])
                freeEdge(edges,i);
            else{
                min=edges[i]->weight;
                minp=i;
            }
        }
    }
    return minp;
}

void main(){
    int n,a,b,w,netw=0;
    printf("Enter number of nodes : ");
    scanf("%d",&n);
    
    Edge *edges[n*(n-1)/2];
    int incl[n+1],i=0;
    for(int k=0;k<=n;k++){
        incl[k]=0;
    }

    printf("Enter : edge edge weight (-1 -1 -1 to exit)\n");
    while(1){
        printf("Enter : ");
        scanf("%d %d %d",&a,&b,&w);
        if(a==-1 || b==-1 || w==-1) break;
        Edge *e = (Edge*)malloc(sizeof(Edge));
        edges[i]=e;
        edges[i]->a=a;
        edges[i]->b=b;
        edges[i]->weight=w;
        i++;
    }

    printf("\nIncluded Edges : \n");
    incl[0]=1;
    while(1){
        int next=min(edges,incl,i);
        if(next==-1) break;
        printf("%d--%d -> %d\n",edges[next]->a,edges[next]->b,edges[next]->weight);
        incl[edges[next]->a]=1;
        incl[edges[next]->b]=1;
        netw+=edges[next]->weight;
        freeEdge(edges,next);
    }
    printf("Net Weight : %d\n",netw);
}