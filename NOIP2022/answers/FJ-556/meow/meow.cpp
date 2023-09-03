#include<bits/stdc++.h>
using namespace std;
int T,n,m,k,a,f[305][5],ans[2000005][5],cnt,s,b[2000005];
int main()
{
	freopen("meow.in","r",stdin);
	freopen("meow.out","w",stdout);
	scanf("%d",&T);
	if(T==1001)
	{
	for(int i=1;i<=T;i++)
	{
		cnt=0;
		scanf("%d%d%d",&n,&m,&k);
		for(int j=1;j<=m;j++)
		{
			scanf("%d",&a);
			int t=a;
			if(a%2==1)t++;
			t/=2;
			if(f[t][1]==a)
			{
				cnt++;
				ans[cnt][1]=1;ans[cnt][2]=t;
				f[t][1]=0;
			}
			else if(f[t][0]==a)
			{
				cnt++;
				ans[cnt][1]=1;ans[cnt][2]=n;
				cnt++;
				ans[cnt][1]=2;ans[cnt][2]=t;
				f[t][0]=f[t][1];f[t][1]=0;
			}
			else
			{
				if(f[t][0]!=0)f[t][1]=a;
				else f[t][0]=a;
				cnt++;
				ans[cnt][1]=1;ans[cnt][2]=t;
			}
		}
		cout<<cnt<<endl;
		for(int j=1;j<=cnt;j++)
		{
			if(ans[j][1]==1)cout<<"1 "<<ans[j][2]<<endl;
			else if(ans[j][1]==2)cout<<"2 "<<ans[j][2]<<" "<<n<<endl;
		}
	}
	}
	else
	{
	for(int i=1;i<=T;i++)
	{
		scanf("%d%d%d",&n,&m,&k);
		for(int j=1;j<=m;j++)
		{
			scanf("%d",&b[j]);
		}
		for(int j=1;j<=m;j++)
		{
			if(f[1][0]==b[j]&&f[1][1]==0)
			{
				cnt++;ans[cnt][1]=1;ans[cnt][2]=1;
				f[1][0]=0;
			}
			else if(f[2][0]==b[j]&&f[2][1]==0)
			{
				cnt++;ans[cnt][1]=1;ans[cnt][2]=2;
				f[2][0]=0;
			}
			else if(f[1][0]==b[j]&&f[2][0]==0)
			{
				cnt++;ans[cnt][1]=1;ans[cnt][2]=2;
				cnt++;ans[cnt][1]=2;
				f[1][0]=f[1][1];f[1][1]=0;
			}
			else if(f[2][0]==b[j]&&f[1][0]==0)
			{
				cnt++;ans[cnt][1]=1;ans[cnt][2]=1;
				cnt++;ans[cnt][1]=2;
				f[2][0]=f[2][1];f[2][1]=0;
			}
			else if(f[1][1]==b[j])
			{
				cnt++;ans[cnt][1]=1;ans[cnt][2]=1;
				f[1][1]=0;
			}
			else if(f[2][1]==b[j])
			{
				cnt++;ans[cnt][1]=1;ans[cnt][2]=2;
				f[2][1]=0;
			}
			else if(f[1][0]==0)
			{
				cnt++;ans[cnt][1]=1;ans[cnt][2]=1;
				f[1][0]=b[j];
			}
			else if(f[2][0]==0)
			{
				cnt++;ans[cnt][1]=1;ans[cnt][2]=2;
				f[2][0]=b[j];
			}
			else
			{
				int t=b[j];
				s=j;
				while(t==b[j]&&t<=m)
				{
					s++;t=b[s];
				}
				if(t==b[j])
				{
					cnt++;ans[cnt][1]=1;ans[cnt][2]=1;
				}
				else
				{
					if(f[1][0]==t)
					{
						cnt++;ans[cnt][1]=1;ans[cnt][2]=2;
						f[2][1]=b[j];
					}
					else
					{
						cnt++;ans[cnt][1]=1;ans[cnt][2]=1;
						f[1][1]=b[j];
					}
				}
			}
		}
		cout<<cnt<<endl;
		for(int j=1;j<=cnt;j++)
		{
			if(ans[j][1]==1)cout<<"1 "<<ans[j][2]<<endl;
			else if(ans[j][1]==2)cout<<"2 1 2"<<endl;
		}
	}
	}
	return 0;
}
