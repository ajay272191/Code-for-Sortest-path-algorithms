#include<stdio.h>
void insert(int **graph,int **mst, int n);
void sorting(int a[],int n,int i,int index[]);
void heapsort(int a[],int n,int index[]);

int main()
{
    int n,i,j,size=0,negetive;
    int **graph,**mst;

    int *index,*a,*sol,*itr;
    int temp,min,src,src1,weight,count=0;
    printf("no of vertex in the graph\n");
    scanf(" %d",&n);

    if(n==0)
     {
          printf("number of vertex can't be 0\n");
          exit(0);
     }
     else if(n==1)
     {
          printf("give the graph of one vertex\n");
          scanf("%d",&i);
          printf("mst is %d\n",i);
          exit(0);
     }


    index=(int *)malloc(n*sizeof(int));
    a=(int *)malloc(n*sizeof(int));
    itr=(int *)malloc(n*sizeof(int));
    sol=(int *)malloc(n*sizeof(int));

    graph=(int **)malloc(n*sizeof(int *));
    mst=(int **)malloc(n*sizeof(int *));
    for(i=0;i<n;i++)
     {
        graph[i]=(int *)malloc(n*sizeof(int));
        mst[i]=(int *)malloc(n*sizeof(int));
     }
    insert(graph,mst,n);
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
     printf("source :: %d\n",src);
     sol[src]=src;
     itr[size]=src;
     size++;
      for(i=0;i<n;i++)
      {
      index[i]=i;
      a[i]=graph[src][i];
      }
      a[src]=100;
      heapsort(a,n,index);
      src1=index[0];
      sol[src1]=src1;
      itr[size]=src1;
      mst[src1][src]=a[0];
      mst[src][src1]=a[0];
     int it=0;
    while(size!=n-1)
    {
         i=0;
        printf("i=%d-------itr=%d\t",i,itr[i]);
        for(j=0;j<n;j++)
          {
               if(sol[j]==j||itr[i]==j)
                 {
                  a[j]=100;
                  index[j]=j;
                 }
               else
                {
                 a[j]=graph[itr[i]][j];
                 index[j]=j;
                }
          }
          heapsort(a,n,index);
          min=index[0];
          weight=a[0];
          src=itr[i];

       for(itr[++i];i<=size;itr[++i])
       {
            //printf("i=%d-------itr=%d\t",i,itr[i]);
          for(j=0;j<n;j++)
            {
             if(sol[j]==j||itr[i]==j)
               {
               a[j]=100;
               index[j]=j;
               }
             else
               {
               a[j]=graph[itr[i]][j];
               index[j]=j;
               }
            }
           heapsort(a,n,index);
           if(weight>a[0])
             {
              src=itr[i];
              min=index[0];
              weight=a[0];
             }
      }
      printf("\n");
      src1=min;
      sol[src1]=src1;
      mst[src1][src]=weight;
      mst[src][src1]=weight;
      itr[size+1]=src1;
      size++;

    }
    printf("minimal spanning tree is::\n\n");
    for(i=0;i<n;i++)
    {
         for(j=0;j<n;j++)
         {
          printf(" %d \t",mst[i][j]);
         }
         printf("\n");
    }
}
void insert(int **graph,int **mst,int n)
{
     int i,j,weight;
     char ch;

    for(i=0;i<n;i++)
    {
        for(j=0;j<n;j++)
        {
             if(i==j)
             {
                  graph[i][j]=0;
                  mst[i][j]=0;
             }
           else
               {
                  graph[i][j]=100;
                  mst[i][j]=100;
             }
        }
    }

     printf("enter edge in the graph:\n\n");
     printf(" for insert an edge :: enter any key \n for not insert edge :: enter 'n' \n");
     scanf(" %c",&ch);
     while(ch!='n')
     {
          printf("enter first vertex\n");
          scanf("%d",&i);
          printf("enter second vertex\n");
          scanf("%d",&j);
          printf("enter weight between first and second vertex\n\n");
          scanf("%d",&weight);
             graph[i][j]=weight;
             graph[j][i]=weight;
          printf(" for insert an edge :: enter any key \n for not insert edge :: enter 'n' \n");
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






