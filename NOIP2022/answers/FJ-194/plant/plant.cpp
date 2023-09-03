#include<bits/stdc++.h>
#define mod 998244353
#define MAXN 1010
using namespace std;
typedef long long ll;
int t,id,n,m,c,f,mape[MAXN][MAXN],con1_0[MAXN][MAXN],con2_0[MAXN][MAXN];ll vc[MAXN][MAXN];
void pre_procedure()
{
	   for(int i=1;i<=n;i++)
	     for(int j=m;j>=1;j--)
	     {
	     	if(mape[i][j])continue;
	         if(mape[i][j+1])con1_0[i][j]=1;
	         else con1_0[i][j]=con1_0[i][j+1]+1;
		 }
		for(int j=1;j<=m;j++)
		  for(int i=n;i>=1;i--)
		  {
		  	if(mape[i][j])continue;
		  	 if(mape[i+1][j])con2_0[i][j]=1;
		  	   else con2_0[i][j]=con2_0[i+1][j]+1;
		  	   
		  }
}
ll get_c()
{
   ll ans=0;
   for(int i=1;i<=n-2;i++)
    for(int j=1;j<=m-1;j++)
    {
    	if(mape[i][j])continue;
    	if(mape[i+1][j])continue;
    	if(mape[i][j+1])continue;
    	//printf("%d %d\n",i,j);
    	for(int k=i+2;k<=n;k++)  
    	{
    		if(mape[k][j])break;
    	//	printf("1");
    	 
    		vc[k][j]=(con1_0[k][j]-1)*(con1_0[i][j]-1);
    		ans=ans+vc[k][j]%mod;
		}
	}
	return ans%mod;
}
ll get_f()
{
	ll ans=0;
	for(int i=3;i<=n-1;i++)
	 for(int j=1;j<=m-1;j++)
	 {
	 	if(mape[i][j])continue;
	 	if(mape[i+1][j])continue;
	 	if(!vc[i][j])continue;
	 	 ans=ans+(vc[i][j]*con2_0[i+1][j])%mod;
	  } 
	  return ans%mod;
}
int main()
{
	
    freopen("plant.in","r",stdin);
    freopen("plant.out","w",stdout);
    scanf("%d%d",&t,&id);
    while(t--)
    {
    	memset(vc,0,sizeof(vc));
    	memset(con1_0,0,sizeof(con1_0));
    	memset(con2_0,0,sizeof(con2_0));
    	scanf("%d%d%d%d",&n,&m,&c,&f);
     	for(int i=1;i<=n;i++)
	     for(int j=1;j<=m;j++)
	     	scanf("%1d",&mape[i][j]);
        pre_procedure();
        printf("%lld ",get_c()*c);
	  /*  for(int i=1;i<=n;i++)
	    {
	     for(int j=1;j<=m;j++)
	     printf("%d",con1_0[i][j]);
	     printf("\n");
	    }*/
	    printf("%lld",get_f()*f);
  	}  
	return 0;
	
}
