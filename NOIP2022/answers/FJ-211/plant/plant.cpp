#include<bits/stdc++.h>
using namespace std;
const int maxn=1005;
char a[maxn][maxn];
int mod=998244353;
int main()
{
	freopen("plant.in","r",stdin);
	freopen("plant.out","w",stdout);
	int t,id;
	cin>>t>>id;
	while(t--)
	{
		memset(a,0,sizeof(a));
		int n,m,c,f;
		cin>>n>>m>>c>>f;
		for(int i=1;i<=n;i++)
		{
			for(int j=1;j<=m;j++)
			{
				cin>>a[i][j];
			}
		}
		int num[maxn][maxn];
		for(int i=1;i<=n;i++)
		{
			for(int j=1;j<=m;j++)
			{
				for(int k=j+1;k<=m;k++)
				{
					if(a[i][k]=='0')
					{
						num[i][j]++;
					}
					else if(a[i][k]=='1')
					{
						break;
					}
				}
			}
		}
		/*for(int i=1;i<=n;i++)
		{
			for(int j=1;j<=m;j++)
			{
				cout<<num[i][j]<<" ";
			}
			cout<<endl;
		}
		cout<<endl;*/
		int sumc=0;
		int sumf=0;
		if(m==2)
		{
			for(int i=1;i<=n;i++)
			{
				bool bj=false;
				for(int j=i+1;j<=n;j++)
				{
					if(a[j][1]=='1')
					{
						bj=true;
					}
					if(a[i][1]=='0'&&a[i][2]=='0'&&a[j][1]=='0'&&a[j][2]=='0'&&j-i>=2&&bj==false)
					{
						sumc=(sumc+1)%mod;
						for(int k=j+1;k<=n;k++)
						{
							if(a[k][1]=='0')
							{
								sumf=(sumf+1)%mod;
							}
							else if(a[k][1]=='1')
							{
								break;
							}
						}
					}
				}
			}
		}
		else
		{
			for(int i=1;i<=n;i++)
			{
				bool bj[maxn]={false};
				for(int j=i+1;j<=n;j++)
				{
					for(int k=1;k<=m;k++)
					{
						if(a[j][k]=='1')
						{
							bj[k]=true;
						}
						if(a[i][k]=='0'&&num[i][k]>0&&a[j][k]=='0'&&num[j][k]>0&&j-i>=2&&bj[k]==false)
						{
							sumc=(sumc+(num[i][k]*num[j][k]))%mod;
							for(int p=j+1;p<=n;p++)
							{
								if(a[p][k]=='0')
								{
									sumf=(sumf+(num[i][k]*num[j][k]))%mod;
								}
								else if(a[p][k]=='1')
								{
									break;
								}
							}
						}
					}
				}
			}
		}
		cout<<(sumc*c)%mod<<" "<<(sumf*f)%mod<<endl;
	}
	
	return 0;
}
