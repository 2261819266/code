#include<bits/stdc++.h>
using namespace std;
void read(){}
template <typename T,typename ... T2>
inline void read(T &x,T2 &... oth)
{
	register bool opt=1;x=0;
	register char ch=getchar();
	while(!isdigit(ch)){if(ch=='-')opt=0;ch=getchar();}
	while(isdigit(ch))x=(x<<3)+(x<<1)+(ch^48),ch=getchar();
	x=opt?x:-x;
	read(oth...);
}
const int N=610,M=1000010;
int n,m,k;
int a[M];
int ans[M*2][3],vis[N];
deque<int> q[N];
void Solve()
{
	for(int i=1;i<=n;i++)while(!q[i].empty())q[i].pop_back();
	int opt=0;
	if(k==2*n-2)
	{
		for(int i=1;i<=m;i++)
		{
			int cnt=(a[i]-1)/2+1;
			if(q[cnt].empty())
			{
				q[cnt].push_back(a[i]);
				ans[++opt][0]=1;ans[opt][1]=cnt;
			}
			else if(q[cnt].back()==a[i])
			{
				q[cnt].pop_back();
				ans[++opt][0]=1;ans[opt][1]=cnt;
			}
			else if(q[cnt].front()==a[i])
			{
				q[cnt].pop_front();
				ans[++opt][0]=1;ans[opt][1]=n;
				ans[++opt][0]=2;ans[opt][1]=cnt;ans[opt][2]=n;
			}
			else
			{
				q[cnt].push_back(a[i]);
				ans[++opt][0]=1;ans[opt][1]=cnt;
			}
		}
		printf("%d\n",opt);
		for(int i=1;i<=opt;i++)
		{
			if(ans[i][0]==1)printf("%d %d\n",ans[i][0],ans[i][1]);
			else printf("%d %d %d\n",ans[i][0],ans[i][1],ans[i][2]);
		}
	}
	else
	{
		int flag=0;
		for(int i=1;i<=m;i++)
		{
			if(a[i]==k)
			{
				if(!flag)
				{
					flag=++opt;ans[opt][0]=1;
					memset(vis,0,sizeof(vis));
				}
				else
				{
					for(int i=1;i<=n;i++)
					{
						if(vis[i]==0)
						{
							ans[flag][1]=ans[++opt][1]=i;
							ans[opt][0]=1;
						}
						flag=0;
						break;
					}
				}
				continue;
			}
			int cnt=(a[i]-1)/2+1;
			if(q[cnt].empty())
			{
				q[cnt].push_back(a[i]);
				vis[cnt]=1;
				ans[++opt][0]=1;ans[opt][1]=cnt;
			}
			else if(q[cnt].back()==a[i])
			{
				q[cnt].pop_back();
				vis[cnt]=1;
				ans[++opt][0]=1;ans[opt][1]=cnt;
			}
			else if(q[cnt].front()==a[i])
			{
				q[cnt].pop_front();
				ans[++opt][0]=1;ans[opt][1]=n;
				ans[++opt][0]=2;ans[opt][1]=cnt;ans[opt][2]=n;
				vis[n]=1;
			}
			else
			{
				q[cnt].push_back(a[i]);
				vis[cnt]=1;
				ans[++opt][0]=1;ans[opt][1]=cnt;
			}
		}
		printf("%d\n",opt);
		for(int i=1;i<=opt;i++)
		{
			if(ans[i][0]==1)printf("%d %d\n",ans[i][0],ans[i][1]);
			else printf("%d %d %d\n",ans[i][0],ans[i][1],ans[i][2]);
		}
	}
}
signed main()
{
	freopen("meow.in","r",stdin);
	freopen("meow.out","w",stdout);
	int T;
	read(T);
	while(T--)
	{
		read(n,m,k);
		for(int i=1;i<=m;i++)read(a[i]);
		Solve();
	}
	return 0;
}
