#include<bits/stdc++.h>
using namespace std;
int read()
{
	char c=getchar();int x=0,f=1;
	while(c>'9'||c<'0'){if(c=='-')f=-f;c=getchar();}
	while(c>='0'&&c<='9'){x=x*10+c-'0';c=getchar();}
	return x*f;
}
#define ll long long
const int N=310,M=2e6+10;
int a[M],cnt,flag[M],b[M],nxt[M],pos[N*2],p[N*2],vis[N];
vector<int>G[M],P[M];
struct point
{
	int op,S1,S2;
}ans[M*2];
void solve()
{
	cnt=0;
	int n=read(),m=read(),k=read(),num=0;
	for(int i=1;i<=m;i++)
		a[i]=read(),flag[i]=1;
	for(int i=1;i<m;i++)
	{
		if(!flag[i])continue;
		if(a[i]==a[i+1])
			flag[i]=flag[i+1]=0;
	}
	for(int i=1;i<=n*2;i++)
		pos[i]=-1;
	G[0].clear();
	for(int i=1;i<=m;i++)
		if(flag[i])
		{
			num++;G[num].clear();
			b[num]=i;
		}
		else G[num].push_back(i);	
	for(int i=1;i<=num;i++)
	{
		if(pos[a[b[i]]]!=-1)
			nxt[pos[a[b[i]]]]=i;
		pos[a[b[i]]]=i;
	}
	for(int i=1;i<=n*2;i++)
		pos[i]=0;
	for(int i=1;i<=n*2;i++)
		pos[i]=0;
	for(int i=1;i<=n;i++)
		P[i].clear();
	for(int i=0;i<G[0].size();i++)
		ans[++cnt]={1,1,0};
	for(int i=1;i<=num;i++)
	{
		if(pos[a[b[i]]])
		{	
			if(p[a[b[i]]]==1)
			{
				ans[++cnt]={1,1,0};
				ans[++cnt]={2,1,pos[a[b[i]]]};
				for(int j=1;j<P[pos[a[b[i]]]].size();j++)
				{
					P[pos[a[b[i]]]][j-1]=P[pos[a[b[i]]]][j];
					p[a[P[pos[a[b[i]]]][j]]]--;
				}
			}
			else 
				ans[++cnt]={1,pos[a[b[i]]],0};
			P[pos[a[b[i]]]].pop_back();
			pos[a[b[i]]]=0;
		}
		else
		{
			int ok=0,maxn=-1e9,maxpos1;
			for(int j=2;j<=n;j++)
			{
				if(P[j].size()<2)
				{
					P[j].push_back(b[i]);
					pos[a[b[i]]]=j;
					p[a[b[i]]]=P[j].size();
					ans[++cnt]={1,j,0};
					ok=1;
					break;
				}
				if(nxt[P[j][P[j].size()-1]]>maxn)
				{
					maxn=nxt[P[j][P[j].size()-1]];
					maxpos1=j;
				}
			}
			if(!ok)
			{
				pos[a[b[i]]]=maxpos1;
				p[a[b[i]]]=3; 
				P[maxpos1].push_back(b[i]);
				ans[++cnt]={1,maxpos1,0};
			}
		}
		for(int j=0;j<G[i].size();j++)
			ans[++cnt]={1,1,0};
	}
	printf("%d\n",cnt);
	for(int i=1;i<=cnt;i++)
		if(ans[i].op==1)
			printf("%d %d\n",ans[i].op,ans[i].S1);
		else printf("%d %d %d\n",ans[i].op,ans[i].S1,ans[i].S2);
	return;
}
int main()
{
	freopen("meow.in","r",stdin);
	freopen("meow.out","w",stdout);
	int T=read();
	while(T--)solve();
	return 0;
}
