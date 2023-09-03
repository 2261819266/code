#include<bits/stdc++.h>
#define int long long
using namespace std;
const int mod=998244353;
int n,m,c,f;
int T,id;
int a[1010][1010];
char s[1010][1010];
int sum[501][501][501];
int flag1[1010][1010];
int flag2[501][501];
signed main()
{
	freopen("plant.in","r",stdin);
	freopen("plant.out","w",stdout);
	cin>>T>>id;
	while(T--)
	{
		cin>>n>>m>>c>>f;
		for(int i=1;i<=n;i++)
		{
			cin>>s[i];
			for(int j=0;j<m;j++)
			{
				a[i][j+1]=s[i][j]-'0';
			}
		}
		if(c==0&&f==0)
		{
			cout<<"0 0\n";
			continue;
		}
		else if(m==2)
		{
			int cnt[1001][1001];
			int flag[1001];
			memset(cnt,0,sizeof(cnt));
			for(int i=1;i<=n;i++)
			{
				for(int j=i;j<=n;j++)
				{
					if(a[j][1]==0)
					{
						cnt[i][j]=1;
						flag[i]++;
						//cout<<i<<" "<<j<<endl;
					}
					else
					{
						break;
					}
				}
			}
			int ans=0;
			int anss=0;
			for(int i=1;i<=n;i++)
			{
				for(int j=i+2;j<=n;j++)
				{
					if(cnt[i][j]==1&&a[i][2]==0&&a[j][2]==0)
					{
						ans++;
						ans%=mod;
						anss+=flag[i]-(j-i+1);
					}
				}
			}
			cout<<ans*c%mod<<" ";
			cout<<anss*f%mod<<endl;
		}
		else
		{
			for(int k=1;k<=m-1;k++)
			{
				for(int i=1;i<=n;i++)
				{
					for(int j=i;j<=n;j++)
					{
						//cout<<j<<" "<<k<<" "<<a[j][k]<<endl;
						if(a[j][k]==0)
						{
							sum[i][j][k]=1;
							flag1[i][k]++;
						}
						else
						{
							break;
						}
					}
				}
			}
			for(int i=1;i<=n;i++)
			{
				for(int j=1;j<=m;j++)
				{
					for(int k=j;k<=m;k++)
					{
						if(sum[i][i][k]==1)
						{
							flag2[i][j]++;
							
						}
						else
						{
							break;
						}
					}
				}
			}
			for(int i=1;i<=n;i++)
			{
				if(a[i][m]==0)
				{
					int j=m;
					while(j>0&&a[i][j-1]==0)
					{
						flag2[i][j]++;
						j--;
					}
					//cout<<i<<" ";
				}
			}
		/*	for(int i=1;i<=n;i++)
			{
				for(int j=1;j<=m;j++)
				{
					cout<<flag2[i][j]<<" ";
				}
				cout<<endl;
			}*/
			
			int ans=0;
			int anss=0;
			for(int i=1;i<=m;i++)
			{
				for(int j=1;j<=n;j++)
				{
					for(int k=j+2;k<=n;k++)
					{
						if(sum[j][k][i]==1)
						{
						//	cout<<i<<" "<<j<<" "<<k<<endl;
							ans=(ans+(flag2[j][i]-1)*(flag2[k][i]-1))%mod;
							anss=(anss+(flag1[j][i]-(k-j+1))*(flag2[j][i]-1)*(flag2[k][i]-1))%mod;
						//	cout<<ans<<" "<<flag2[j][i]-1<<" "<<flag2[k][i]-1<<endl;
						}
					}
				}
			}
			cout<<ans%mod*c%mod<<" "<<anss%mod*f%mod<<endl;
		}
	}
	return 0;
}
