#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll t,id,c,f,ansc,ansf,tot,sum1,z,sum2; 
char s[1086];
int a[1086][1086],n,m;
int main()
{
	freopen("plant.in","r",stdin);
	freopen("plant.out","w",stdout);
	scanf("%lld%lld",&t,&id);
	while(t--)
	{
		ansc=0;ansf=0;tot=0;sum1=0;z=0;sum2=0;
		scanf("%lld%lld%lld%lld",&n,&m,&c,&f);
	for(int i=0;i<=n+10;i++)
	 for(int j=0;j<=m+10;j++)
	 a[i][j]=1;
	for(int i=1;i<=n;i++)
	{
		scanf("%s",s+1);
		for(int j=1;j<=m;j++)
		{
			a[i][j]=s[j]-'0';
		}
	}
	 for(int i=1;i<=n;i++)
	  for(int j=1;j<=m;j++)
	  if(a[i][j]==0)
	  {
	  	tot=0;sum1=0;sum2=0;z=0;
	  	if(a[i][j+1]==0&&a[i+1][j]==0&&a[i+2][j]==0)
	  	{
	  		for(int o=j+1;o<=m;o++)
	  		{
	  			if(a[i][o]==0) tot++;
	  			else break;
			}
			for(int k=i+2;k<=n;k++)
			{
		  		if(a[k][j]==0)
	  		    {
	  		    if(a[k][j+1]==1) continue;
	  			sum2=0;z=0;
	  			for(int o=j+1;o<=m;o++)
	  			{
	  				if(a[k][o]==0)
				  {
				  	sum1++;sum2++;
				  } 
				  else break;
				}

	  			for(int b=k+1;b<=n;b++)
	  			{
	  				if(a[b][j]==0) z++;
	  				else break;
				  }
	  			ansf+=sum2*z*tot;
	  			ansf=ansf%998244353;
			    }
			    else break;
			}
			ansc+=tot*sum1;
			ansc=ansc%998244353;
		}
		
	  }
	  printf("%lld %lld",c*ansc,f*ansf);
	  printf("\n");
	}
	  return 0;
}
