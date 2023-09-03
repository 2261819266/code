#include<bits/stdc++.h>
using namespace std;
long long read()
{
	long long res=0,f=0;char c;
	while(((c=getchar())<'0'||c>'9')&&c!='-');
	if(c=='-')f=1;else res=c-'0';
	while((c=getchar())>='0'&&c<='9')res=res*10+c-'0';
	return f?-res:res;
}
const int N=310,M=1e6+10;
struct node{int fi,se;};
vector<node>ans[M];
vector<int>p[N];
int T,n,m,k,z,a[M],t[M],num,x,sz,id[M],rt,vis[M],tg[M],ls,st[2],f[2],nw[2][M<<1];
int main()
{
	freopen("meow.in","r",stdin);
	freopen("meow.out","w",stdout);
	T=read();
//	printf("%d\n",T);
	while(T--)
	{
		n=read();m=read();k=read();z=0;
//		printf("%d %d %d\n",n,m,k);
		if(n==1)
		{
			for(int i=1;i<=m;i++)read();
			printf("%d\n",m);
			for(int i=1;i<=m;i++)puts("1 1");
			continue;
		}
		for(int i=1;i<=m;i++)
		{
			a[i]=read();x=(a[i]-1)/3;
			p[x].push_back(i);
		}sz=(k-1)/3;
		for(int s=0;s<=sz;s++)
		{
			for(auto it:p[s])
			{
				t[++num]=a[it];
				id[num]=it;
			}
//			for(int i=1;i<=num;i++)
//			{
//				printf("%d ",t[i]);
//			}
			for(int i=num;i;i--)
			{
				if(vis[t[i]])
				{
					if((vis[t[i]]-i+1)&1)tg[i+1]=1;
					vis[t[i]]=0;
				}
				else vis[t[i]]=i;
			}
			for(int i=1;i<=num;i++)
			{
//				printf("%d ",tg[i]);
				if(nw[1][st[1]]==t[i])
				{
					ls=1;
					ans[id[i]].push_back((node){s<<1|1,-1});
					z++;
					st[1]--;continue;
				}
				if(nw[0][st[0]]==t[i])
				{
					ls=0;
					ans[id[i]].push_back((node){s<<1,-1});
					z++;
					st[0]--;continue;
				}
				if(st[1]==f[1]&&nw[0][f[0]+1]==t[i]&&f[0]!=st[0])
				{
					f[0]++;ls=1;
					ans[id[i]].push_back((node){s<<1|1,-1});
					ans[id[i]].push_back((node){s<<1,s<<1|1});
					++++z;
					continue;
				}
				if(st[0]==f[0]&&nw[1][f[1]+1]==t[i]&&f[1]!=st[1])
				{
					f[1]++;ls=0;
					ans[id[i]].push_back((node){s<<1,-1});
					ans[id[i]].push_back((node){s<<1|1,s<<1});
					++++z;
					continue;
				}
				nw[tg[i]^ls][++st[tg[i]^ls]]=t[i];
				ans[id[i]].push_back((node){s<<1|(tg[i]^ls),-1});
				++z;
				ls=ls^tg[i];
			}
			f[0]=f[1]=0;
			st[0]=st[1]=0;
			for(int i=1;i<=num;i++)t[i]=id[i]=vis[t[i]]=0;
			num=0;ls=0;
		}
		printf("%lld\n",z);
		for(int i=1;i<=m;i++)
		{
			for(auto it:ans[i])
			{
				if(it.se==-1)
				{
					printf("1 %lld %lld\n",it.fi+1);
//					rt++;
				}
				else printf("2 %lld %lld\n",it.fi+1,it.se+1);
			}
			ans[i].clear();
		}
		for(int i=0;i<=sz;i++)p[i].clear();
//		if(rt!=m)return !printf("%d %d No",rt,m);
//		rt=0;
	}
	return 0;
}
/*
7
2 6 3
1 2 3 1 2 3
2 6 3
1 2 3 2 1 3
2 4 2
1 2 1 2
2 4 2
1 2 2 1
2 6 3
1 2 3 3 1 2
4 12 6
1 4 2 5 3 6 2 5 1 3 4 6
1 4 1
1 1 1 1
*/
