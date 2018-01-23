#include<stdio.h>
void insert(int **graph,int **mst, int n,int **edg);
void bubblesort(int **edg,int n);
int main()
{
    int n,i,j,size;
    int **graph,**mst;
    int **edg;
    int v1,v2,flag;
    int weight,count=0;
    int indx;
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
          printf("mst is \n %d\n",i);
          exit(0);
     }

     graph=(int **)malloc(n*sizeof(int *));
     mst=(int **)malloc(n*sizeof(int *));
     indx=2*n;
     edg=(int **)malloc(2*sizeof(int *));
     edg[0]=(int *)malloc(indx*sizeof(int));
     edg[1]=(int *)malloc(indx*sizeof(int));

    for(i=0;i<n;i++)
     {
        graph[i]=(int *)malloc(n*sizeof(int));
        mst[i]=(int *)malloc(n*sizeof(int));
     }
     insert(graph,mst,n,edg);
     bubblesort(edg,n);

     weight=edg[0][0];
     v1=edg[1][0];
     v2=edg[1][1];

     mst[v1][v2]=weight;
     mst[v2][v1]=weight;

    for(i=0;i<n-1;i++)
    {
        edg[0][i]=edg[0][i+1];

        edg[1][2*i]=edg[1][2*i+2];
        edg[1][2*i+1]=edg[1][2*i+3];
    }
    size=n-1;
    count++;
    while(count!=n)
    {
          bubblesort(edg,n);

          weight=edg[0][0];
          v1=edg[1][0];
          v2=edg[1][1];
          for(i=0;i<n;i++)//to chack wheathr circuit form or not
           {
            if(mst[v1][i]<100 && mst[v2][i]<100)
             {
               flag=1;
             }
           }
          for(i=0;i<size;i++)
          {
           edg[0][i]=edg[0][i+1];

           edg[1][2*i]=edg[1][2*i+2];
           edg[1][2*i+1]=edg[1][2*i+3];
          }
          count++;
          size--;
          if(flag!=1)
          {
           mst[v1][v2]=weight;
           mst[v2][v1]=weight;
          }
    }
    printf("minimal spanning tree is::\n\n");
    for(i=0;i<n;i++)
    {
         for(j=0;j<n;j++)
         {
          if(j==i)
           {
            mst[i][j]=0;
            printf(" %d \t",mst[i][j]);
           }
          else
           {
            printf(" %d \t",mst[i][j]);
           }
         }
         printf("\n");
    }
}
void insert(int **graph,int **mst, int n,int **edg)
{
     int l ;
     char ch;
     int i,j,weight;

    for(i=0;i<n;i++)
     {
          for(j=0;j<n;j++)
           {
            if(i==j)
             {
              graph[i][j]=0;
              mst[i][j]=100;
             }
            else
             {
              graph[i][j]=100;
              mst[i][j]=100;
             }
           }
     }
     l=0;
     printf("enter edge in the graph:\n");
     printf(" to stop inserting edge in the graph enter 1 three times \n");
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

             edg[0][l]=weight;
             edg[1][2*l]=i;
             edg[1][2*l+1]=j;

          l++;
          if(i=1 && j==1 && weight==1)
          	{
          	     ch='n';
               }
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
void bubblesort(int **edg, int n)
{
     int i,j,temp;
     for(i=0;i<n;i++)
     {
          for(j=i;j<n-i;j++)
          {
           if(edg[0][j]>edg[0][j+1])
            {
             temp=edg[0][j];
             edg[0][j]=edg[0][j+1];
             edg[0][j+1]=temp;

             temp=edg[1][2*j];
             edg[1][2*j]=edg[1][2*(j+1)];
             edg[1][2*(j+1)]=temp;

             temp=edg[1][2*j+1];
             edg[1][2*j+1]=edg[1][2*(j+1)+1];
             edg[1][2*(j+1)+1]=temp;
            }
          }
     }
}





