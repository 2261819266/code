#include<bits/stdc++.h>
using namespace std;
int a[10000][10000],w[10000];
main()
{
    freopen("plant.in","r",stdin);
	freopen("plant.out","w",stdout);
	long long T,id,m,n,c,f;
	long long ans1=0,ans2=0;
	cin>>T>>id;
	cin>>n>>m>>c>>f;
	
	for(int j=1;j<=n;j++)
	{
	cin>>w[j];
    }
	for(int j=1;j<=n;j++)
	{
	for(int i=m;i>=1;i--)
	  {
		a[i][j]=w[j]%10;
		w[j]=w[j]/10;
	  }
	}
	
	
	for(int i=1;i<=m;i++)
	{
	
		for(int j=2;j<=n;j++)
		{   
			for(int g=1;g<=m-i;g++)
			{
			for(int b=1;b<=n-j;b++)
			{
			for(int r=1;r<=j-1;r++)
			{
				if(a[i][j]!=1&&a[i+g][j+b]!=1&&a[i][j+b]!=1&&a[i][j-r]!=1&&a[i+g][j-r]!=1)
			ans1++;
			}
	      	}
			
			}
		
		}
		
	}
	
	
		for(int i=1;i<=m;i++)
	{
	
		for(int j=3;j<=n;j++)
		{  
			for(int g=1;g<=m-i;g++)
			{
			for(int r=1;r<=m-i;r++)
			{
			
			for(int b=1;b<=n-j;b++)
			{
				for(int d=2;d<=j-1;d++)
				{
			if(a[i][j]!=1&&a[i+g][j]!=1&&a[i][j+b]!=1&&a[i][j-d]!=1&&a[i+r][j-d]!=1)
			ans2++;
			}
			}
			}
	}
		 }
		
		}
	
	ans1= (ans1*c)%998244353;
	ans2= (ans2*f)%998244353;
	cout<<ans1<<' '<<ans2;
	fclose(stdin);
	fclose(stdin);

	return 0;
}
