#include<stdio.h>
#include<stdlib.h>

typedef struct job job;
struct job{
    int ind,profit,deadline;    
};

int jobseq(int n, job jobsav[],int willdo[]){
    for(int i=0;i<n-1;i++)
        for(int j=0;j<n-i-1;j++)
            if(jobsav[j].profit<jobsav[j+1].profit){
                job t=jobsav[j];
                jobsav[j]=jobsav[j+1];
                jobsav[j+1]=t;
            }
    
    /*for(int i=0;i<n;i++){
       - printf("//job %d %d\n",jobsav[i].ind,jobsav[i].profit);
    }*/

    int profit=0;
    for(int i=0;i<n;i++){
        for(int j=jobsav[i].deadline;j>=0;j--)
            if(willdo[j]==-1){
                willdo[j]=jobsav[i].ind;
                profit+=jobsav[i].profit;
                break;
            }
    }
    return profit;
}

void printa(int a[],int n){
    int k=1;
    for(int i=0;i<n;i++)
        if(a[i]!=-1)
            printf("%d: Job %d\n",k++,a[i]);
}

void main(){
    int n;
    scanf("%d",&n);
    job jobs[n];
    int willdo[n], profit;
    for(int i=0;i<n;i++){
        jobs[i].ind=i+1;
        scanf("%d %d",&jobs[i].profit,&jobs[i].deadline);
        jobs[i].deadline-=1;
        willdo[i]=-1;
    }
    profit =jobseq(n,jobs,willdo);
    printa(willdo,n);
    printf("Net Profit : %d\n",profit);
}