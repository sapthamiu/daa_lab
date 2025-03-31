#include<stdio.h>
#include<stdlib.h>
#define MAX 100
#define max(a,b)(a>b ? a:b)

int opcount=0;
int dp[MAX][MAX];

int knapsack(int* v, int* w, int mx,int n)
{
    int i,j;

    for(i=0;i<=n;i++){
        for(j=0;j<=mx;j++){
            if(j>0 && i>0) opcount++;

            if(i==0 || j==0){dp[i][j]=0;}
            else if(w[i] <= j){dp[i][j]=max(dp[i-1][j], v[i]+dp[i-1][j-w[i]]);}
            else {dp[i][j]= dp[i-1][j];}
        }
    }
    return dp[n][mx];
}

void main()
{
    int v[MAX], w[MAX];
    int n,mx,i,j;

    printf("Enter max capacity of the knapsack: "); scanf("%d",&mx);
    printf("Enter no.of available elements: "); scanf("%d",&n);

    printf("Enter weights of %d elements: ",n);
    for(i=1;i<=n;i++)    scanf("%d",&w[i]);

    printf("Enter value of %d elements: ",n);
    for(i=1;i<=n;i++)    scanf("%d",&v[i]);

    printf("Maximum value of knapsack is : %d\n", knapsack(v,w,mx,n));

    for(int i=0;i<=n;i++){
        for(int j=0;j<=mx;j++)  printf("%d\t", dp[i][j]);
        printf("\n");
    }

    printf("\nopcount: %d\n",opcount);
}
