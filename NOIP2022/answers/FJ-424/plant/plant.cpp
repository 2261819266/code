#include<bits/stdc++.h>
using namespace std;
int a[1010][1010],x[1010][1010],y[1010][1010],t,id,n,m,c,f;
long long ansc=0,ansf=0,mod=998244353;
int main()
{
	freopen("plant.in","r",stdin);
	freopen("plant.out","w",stdout);
	ios::sync_with_stdio(false);
	cin>>t>>id>>n>>m>>c>>f;
	if(id==1) 
	{
		cout<<0;
		return 0;
	}
	for(int i=1;i<=n;i++)
	for(int j=1;j<=m;j++)
	{
		char ch;
		cin>>ch;
		a[i][j]=ch-'0';
	}
	for(int i=1;i<=n;i++)
	{
		int cnt=0;
	    for(int j=m;j>=1;j--)
	    {
	    	if(a[i][j]==0)
	    	{
	    		cnt++;
	    		x[i][j]=cnt;
			}
			else
			{
				cnt=0;
			}
		}
	}
	for(int j=1;j<=m;j++)
	{
		int cnt=0;
		for(int i=n;i>=1;i--)
		{
			if(a[i][j]==0)
			{
				cnt++;
				y[j][i]=cnt;
			}
			else
			cnt=0;
		}
	}
	for(int j=1;j<=m;j++)
	{
		int u=1;
		while(u<n)
		{
			if(y[j][u]>=3&&x[u][j]>=2)
			{
				long long tot=0,cc=x[u][j]-1,tot1=0;
				for(int i=u+2;i<=u+y[j][u]-1;i++)
				{
					
					if(x[i][j]>1) 
					{
						tot+=(x[i][j]-1);
						tot1+=(x[i][j]-1)*(u+y[j][u]-1-i);
					}
					if(i==u+y[j][u]-2)
					{
						ansf+=tot1*cc;
						ansf%=mod;
					}
					
				}
				ansc+=tot*cc;
				ansc%=mod;
			}
			u++;
		}
	}
	
/*	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=m;j++)
		cout<<y[j][i]<<" ";
		cout<<endl;
	}
	cout<<endl<<endl;
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=m;j++)
		cout<<x[i][j]<<" ";
		cout<<endl;
	}*/
	
    cout<<ansc*c%mod<<" "<<ansf*f%mod;
	return 0;                                          
}
