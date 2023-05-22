//Kruskal
#include<stdio.h>
#include<stdlib.h>

struct Edge{
    int weight, a, b;
};
typedef struct Edge Edge;

struct Node{
    int e;
    struct Node *next;
};
typedef struct Node Node;

void add(Node *nodes[],Edge *edge){
    //printf("%d--%d -> %d\n",edge->a,edge->b,edge->weight);
    Node *n1=(Node*)malloc(sizeof(Node)),*n2=(Node*)malloc(sizeof(Node));
    n1->e=edge->a;
    n2->e=edge->b;
    n1->next=n2->next=NULL;
    if(nodes[n1->e]==NULL)
        nodes[n1->e]=n2;
    else{
        Node *t=nodes[n1->e];
        while(t->next!=NULL)
            t=t->next;
        t->next=n2;
    }
    if(nodes[n2->e]==NULL)
        nodes[n2->e]=n1;
    else{
        Node *t=nodes[n2->e];
        while(t->next!=NULL)
            t=t->next;
        t->next=n1;
    }
}

int checkLoop(Node *nodes[],int a,int p,int b){
    //printf("\nckl(%d,%d,%d)\n",a,p,b);
    if(a==b) return 1;
    Node *t=nodes[a];
    while(t!=NULL){
        if(t->e!=p){
            int cl=checkLoop(nodes,t->e,a,b);
            if(cl==1) return 1;
        }
        t=t->next;
    }
    return 0;
}

void sort(Edge *edges[],int n){
    for(int i=0;i<n-1;i++)
        for(int j=0;j<n-i-1;j++)
            if(edges[j]->weight>edges[j+1]->weight){
                Edge *t=edges[j];
                edges[j]=edges[j+1];
                edges[j+1]=t;
            }
}

int findParent(int p[],int n){
    if(p[n]==n) return n;
    return p[n]=findParent(p,p[n]);
}

void unionSet(int p[],int a,int b){
    p[findParent(p,a)]=findParent(p,b);
}

/*void main(){
    int n,a,b,w,netw=0;
    printf("Enter number of nodes : ");
    scanf("%d",&n);
    
    Edge *edges[n*(n-1)/2];
    Node *nodes[n+1];
    int incl[n+1],i=0;
    for(int k=0;k<=n;k++){
        incl[k]=0;
        nodes[k]=NULL;
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

    sort(edges,i);

    printf("\n\nIncluded Edges : \n");
    for(int k=0;k<i;k++){
        int ckl=checkLoop(nodes,edges[k]->a,-1,edges[k]->b);
        if(ckl!=1){
            add(nodes,edges[k]);
            printf("%d--%d -> %d\n",edges[k]->a,edges[k]->b,edges[k]->weight);
            netw+=edges[k]->weight;
        }
    }
    printf("Net Weight : %d\n",netw);
}*/

void main(){
    int n,a,b,w,netw=0;
    printf("Enter number of nodes : ");
    scanf("%d",&n);
    
    Edge *edges[n*(n-1)/2];
    int incl[n+1],i=0;
    for(int k=0;k<=n;k++){
        incl[k]=k;
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

    sort(edges,i);

    printf("\n\nIncluded Edges : \n");
    for(int k=0;k<i;k++){
        if(findParent(incl,edges[k]->a)!=findParent(incl,edges[k]->b)){
            unionSet(incl,edges[k]->a,edges[k]->b);
            printf("%d--%d -> %d\n",edges[k]->a,edges[k]->b,edges[k]->weight);
            netw+=edges[k]->weight;
        }
    }
    printf("Net Weight : %d\n",netw);
}