#include<stdio.h>
void insert(int **graph, int n);
void sorting(int a[],int n,int i,int index[]);
void heapsort(int a[],int n,int index[]);

int main()
{
    int n,i,j,size,negetive;
    int **graph;

    int *index,*a,*d;
    int temp,score,src,src1,weight,count=0;
    printf("no of vertex in the graph\n");
    scanf(" %d",&n);
    if(n==0)
     {
          printf("number of vertex can't be 0\n");
          exit(0);
     }
     else if(n==1)
     {
          printf("distance from 0 to 0 is 0\n");
          exit(0);
     }

    graph=(int **)malloc(n*sizeof(int *));
    index=(int *)malloc(n*sizeof(int));
    a=(int *)malloc(n*sizeof(int));
    d=(int *)malloc(n*sizeof(int));

    for(i=0;i<n;i++)
     {
        graph[i]=(int *)malloc(n*sizeof(int));
     }
    insert(graph,n);

     while(1)
     {
          printf("enter the source:\n\n");
          scanf("%d",&src);
          if(src>=0 && src<n)
               break;
          else
          {    printf("enter source between 0 and %d\n",n-1);
               continue;
          }
     }
    for(i=0;i<n;i++)
      {index[i]=i;}//it will store index of present in vertex

    for(i=0;i<n;i++)
      {a[i]=graph[src][i];}

     weight=a[src];
     d[src]=weight;
    for(i=src;i<n-1;i++)
    {
         a[i]=a[i+1];
         index[i]=index[i+1];
    }


    size=n-1;
    sorting(a,size,0,index);

    while(size!=0)
    {
       weight=a[0];
       src1=index[0];
       d[src1]=weight;
       for(i=1;i<size;i++)
       {
           score=weight+graph[src1][index[i]];
           if(a[i]>score)
               {a[i]=score;}
       }
       temp=a[0];
       a[0]=a[size-1];
       a[size-1]=temp;


       temp=index[0];
       index[0]=index[size-1];
       index[size-1]=temp;
       size--;
       sorting(a, size, 0,index);
    }


    printf("all the distances from::\n\n");
    for(i=0;i<n;i++)
    {
        printf("from source : %d to node : %d the distance is : %d\n\n",src,i,d[i]);
    }
}
void insert(int **graph, int n)
{
     int i,j,weight;
     char ch,ch1;
    /*for(i=0;i<n;i++)
    {
        for(j=0;j<n;j++)
        {
            printf("between %d and %d\n",i,j);
            scanf("%d",&graph[i][j]);
        }
    }*/

    for(i=0;i<n;i++)
    {
        for(j=0;j<n;j++)
        {
             if(i==j)
               graph[i][j]=0;
           else
               graph[i][j]=100;
        }
    }
    printf("for indirected graph enter  y otherwise enter any character\n");
    scanf(" %c",&ch1);
     printf("\tpress 'y' to enter an edge in graph and press 'n' to not enter any edge in the graph further\n\n");
     printf("\t enter edge in the graph:\n");
     printf("\t want to enter an edge then enter y else enter any key\n");
     scanf(" %c",&ch);
     while(ch=='y')
     {
          printf("enter first vertex\n");
          scanf("%d",&i);
          printf("enter second vertex\n");
          scanf("%d",&j);
          printf("enter weight between first and second vertex\n\n");
          scanf("%d",&weight);
          if(ch1=='y')
          {
             graph[i][j]=weight;
             graph[j][i]=weight;
          }
          else
          {
               graph[i][j]=weight;
          }

          printf("\t want to enter another edge then enter y else enter any key\n");
          scanf(" %c",&ch);
     }

    printf("matrix representation of the graph is\n\n");
    for(i=0;i<n;i++)
    {
        for(j=0;j<n;j++)
        {
            printf("%d\t",graph[i][j]);
        }
        printf("\n");
    }
}
void sorting(int a[], int n, int i,int index[])
{
    int root = i;
    int lchild = 2*i+1;//because heap start at 0th position
    int rchild = 2*i+2;
    int temp;

    if (n>lchild && a[root]>a[lchild])
        root=lchild;

    if (n>rchild && a[root]>a[rchild])
        root=rchild;

    if (root!=i)
    {
        temp=a[i];
        a[i]=a[root];
        a[root]=temp;

        temp=index[i];
        index[i]=index[root];
        index[root]=temp;

        sorting(a,n,root,index);
    }
}
void heapsort(int a[], int n,int index[])
{
    int i;

    for (i = n/2 - 1; i >= 0; i--)
        sorting(a, n, i,index);
}






