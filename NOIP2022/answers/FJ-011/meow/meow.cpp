#include<bits/stdc++.h>
using namespace std;
long long T,n,m,k,a[2000005],vis[1005],vis2[1005],pos,pos2,cnt,minn,ans1,ans2;
deque<long long>q[305];
long long siz[305];
struct Node
{
	long long opt;
	long long s1;
	long long s2;
};
vector<Node>ans; 
long long op;
char ch;
inline void read(long long &x)
{
	op=1,x=0,ch=getchar();
	while(!isdigit(ch))
	{
		if(ch=='-')op=-1;
		ch=getchar();
	}
	while(isdigit(ch))
	{
		x=(x<<1)+(x<<3)+(ch^48);
		ch=getchar();
	}
	x*=op;
}
inline void out(long long x)
{
	if(x<0)
		putchar('-'),x=-x;
	if(x>9)
		out(x/10);
	putchar(x%10+48);
}
int main()
{
	freopen("meow.in","r",stdin);
	freopen("meow.out","w",stdout);
	read(T);
	while(T--)
	{
		read(n),read(m),read(k);
		pos=1,cnt=m;
		memset(vis,0,sizeof(vis));
		memset(vis2,0,sizeof(vis2));
		memset(siz,0,sizeof(siz));
		ans.clear();
		for(long long i=1;i<=m;i++)
		{
			read(a[i]);
		}
		while(pos<=m)
		{
			if(vis[a[pos]]==0)
			{
				minn=1145141919810;
				for(long long i=1;i<=n;i++)
				{
					if(siz[i]<minn)
					{
						minn=siz[i];
						pos2=i;
					}
				}
				if(!q[pos2].empty())
				{
					vis[q[pos2].back()]--;
				}
				q[pos2].push_back(a[pos]);
				siz[pos2]++;
				vis[a[pos]]++;
				ans.push_back((Node){1,pos2,0});
			}
			else
			{
				for(long long i=1;i<=n;i++)
				{
					if(!q[i].empty() && q[i].back()==a[pos])
					{
						vis[a[pos]]--;
						q[i].pop_back();
						siz[i]--;
						ans.push_back((Node){1,i,0});
						cnt-=2;
						break; 
					}
				}
			}
			pos++;
		}
		for(long long i=1;i<=n;i++)
		{
			if(q[i].empty())
			{
				continue;
			}
			vis2[q[i].front()]++;
		}
		while(cnt)
		{
			for(long long i=1;i<=k;i++)
			{
				if(vis2[i]>=2)
				{
					vis2[i]-=2;
					cnt-=2;
					long long x=2;
					for(long long j=1;j<=n && x;j++)
					{
						if(q[j].empty())
						{
							continue;
						}
						if(q[j].front()==i)
						{
							x--;
							if(x)
							{
								ans1=j;
							}
							else
							{
								ans2=j;
							}
							q[j].pop_front();
							if(!q[j].empty())
							{
								vis2[q[j].front()]++;
							}
						}
					}
					ans.push_back((Node){2,ans1,ans2});
				}
			}
		}
		out(ans.size()),putchar('\n');
		for(long long i=0;i<ans.size();i++)
		{
			if(ans[i].opt==1)
			{
				printf("1 %lld\n",ans[i].s1);
			}
			else
			{
				printf("2 %lld %lld\n",ans[i].s1,ans[i].s2);
			}
		}
	}
	return 0;
}
