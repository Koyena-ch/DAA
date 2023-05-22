#include<stdio.h>
#include<stdlib.h>
#include<time.h>

int size;

void arraydo(int n,int A[][n],int B[][n],int C[][n],int op){
    for(int i=0;i<n;i++)
        for(int j=0;j<n;j++)
            C[i][j] = (!op)?A[i][j] + B[i][j] : A[i][j] - B[i][j];
}

void strassens(int n,int A[][n],int B[][n],int C[][n]){
    if(n==1){
        C[0][0] = A[0][0] * B[0][0];
        return;
    }
    int ns=n/2;
    int a1[ns][ns],a2[ns][ns],a3[ns][ns],a4[ns][ns],
        b1[ns][ns],b2[ns][ns],b3[ns][ns],b4[ns][ns],
        c1[ns][ns],c2[ns][ns],c3[ns][ns],c4[ns][ns];
    int s1[ns][ns],s2[ns][ns],s3[ns][ns],
        s4[ns][ns],s5[ns][ns],s6[ns][ns],
        s7[ns][ns],s8[ns][ns],s9[ns][ns],
        s10[ns][ns];
    int p1[ns][ns],p2[ns][ns],p3[ns][ns],
        p4[ns][ns],p5[ns][ns],p6[ns][ns],
        p7[ns][ns];
    
    for(int i=0;i<ns;i++)
        for(int j=0;j<ns;j++){
            a1[i][j]=A[i][j];
            a2[i][j]=A[i][j+ns];
            a3[i][j]=A[i+ns][j];
            a4[i][j]=A[i+ns][j+ns];

            b1[i][j]=B[i][j];
            b2[i][j]=B[i][j+ns];
            b3[i][j]=B[i+ns][j];
            b4[i][j]=B[i+ns][j+ns];
        }

    arraydo(ns,b2,b4,s1,1);          //b12-b22
    arraydo(ns,a1,a2,s2,0);          //a11+a12
    arraydo(ns,a3,a4,s3,0);          //a21+a22
    arraydo(ns,b3,b1,s4,1);          //b21-b11
    arraydo(ns,a1,a4,s5,0);          //a11+a22
    arraydo(ns,b1,b4,s6,0);          //b11+b22
    arraydo(ns,a2,a4,s7,1);          //a12-a22
    arraydo(ns,b3,b4,s8,0);          //b21+b22
    arraydo(ns,a1,a3,s9,1);          //a11-a21
    arraydo(ns,b1,b2,s10,0);         //b11+b12

    strassens(ns,a1,s1,p1);         //a11*s1
    strassens(ns,s2,b4,p2);         //s2*b22
    strassens(ns,s3,b1,p3);         //s3*b11
    strassens(ns,a4,s4,p4);         //a22*s4
    strassens(ns,s5,s6,p5);         //s5*s6
    strassens(ns,s7,s8,p6);         //s7*s8
    strassens(ns,s9,s10,p7);        //s9*s10

    //c11+p5+p4-p2+p6
    arraydo(ns,p5,p4,s1,0);
    arraydo(ns,s1,p6,s2,0);
    arraydo(ns,s2,p2,c1,1);

    //c12+p1+p2
    arraydo(ns,p1,p2,c2,0);

    //c21+p3+p4
    arraydo(ns,p3,p4,c3,0);

    //c22+p5+p1-p3-p7
    arraydo(ns,p5,p1,s1,0);
    arraydo(ns,p3,p7,s2,0);
    arraydo(ns,s1,s2,c4,1);

    for(int i=0;i<ns;i++)
        for(int j=0;j<ns;j++){
            C[i][j]=c1[i][j];
            C[i][j+ns]=c2[i][j];
            C[i+ns][j]=c3[i][j];
            C[i+ns][j+ns]=c4[i][j];
        }
}

int next2pow(int k){
    int i=1;
    while(i<k)
        i*=2;
    return i;
}

void fillArray(int arr[][size],int f){
    srand(clock());
    for(int i=0;i<size;i++)
        for(int j=0;j<size;j++)
            arr[i][j] = (i>=f || j>=f)? 0 : (rand())%10+1;
}

void print2d(int asize,int a[][asize]){
    for(int i=0;i<asize;i++){
        for(int j=0;j<asize;j++)
            printf("%d\t",a[i][j]);
        printf("\n");
    }
}

void print2df(int a[][size],int f){
    for(int i=0;i<f;i++){
        for(int j=0;j<f;j++)
            printf("%d\t",a[i][j]);
        printf("\n");
    }
    printf("\n");
}

void initiate(){
    int n;
    printf("Enter value of n : ");
    scanf("%d",&n);
    size=next2pow(n);

    int a[size][size],b[size][size],c[size][size];
    fillArray(a,n);
    fillArray(b,n);
    printf("\nArray A : \n\n");
    print2df(a,n);
    printf("\nArray B : \n\n");
    print2df(b,n);

    strassens(size,a,b,c);
    printf("A x B : \n\n");
    print2df(c,n);
}

void main(){
    /*int a[4][4]={{3,3,3,3},
            {6,3,7,3},
            {1,3,3,3},
            {3,3,3,3}},
        b[4][4]={{3,1,3,3},
            {3,6,3,3},
            {6,3,2,3},
            {3,3,3,3}},
        c[4][4];
    size=4;
    //int a[2][2]={{3,3},{4,4}},
      //  b[2][2]={{3,3},{4,4}},
        //c[2][2];
    //size=2;

    strassens(size,a,b,c);
    print2d(size,c);*/
    initiate();
}