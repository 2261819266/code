#include<iostream>
#include<cstdio>
#include<queue>
#include<cstring>
#include<set>
using namespace std;
template<class T>
void rd(T &x)
{
	char ch=getchar();
	for(;ch>'9'||ch<'0';ch=getchar());
	for(x=0;ch<='9'&&ch>='0';ch=getchar())
		x=x*10+(ch^48);
}
const int N=605,M=2e6+5;
struct node{int sz,lst,id;};
bool operator<(const node &x,const node &y)
{
	if(x.sz>2 && y.sz<2)return 0;
	if(x.sz<2 && y.sz>2)return 1;
	if(x.id!=y.id)return x.lst>y.lst;
	return x.id<y.id;
}
int T,n,m,K,a[M],nx[M],nxc[N];
int Cnt,O[M*2],X[M*2],Y[M*2];
deque<int>q[N];
typedef pair<int,int> pii;
set<int>SB[N],SF[N],SE;
set<node>SV;


void Del(int w)
{
	if(q[w].empty())SE.erase(w);
	else 
	{
		SB[a[q[w].back()]].erase(w);
		SF[a[q[w].front()]].erase(w);
		SV.erase(node{(int)q[w].size(),nx[q[w].back()],w});
	}
}

void Add(int w)
{
	if(q[w].empty())SE.insert(w);
	else
	{
		SB[a[q[w].back()]].insert(w);
		SF[a[q[w].front()]].insert(w);
		SV.insert(node{(int)q[w].size(),nx[q[w].back()],w});
	}
}

void Put(int w,int x)
{
	Del(w);
	O[++Cnt]=1,X[Cnt]=w;
	if(!q[w].empty() && a[q[w].back()]==a[x])q[w].pop_back();
	else q[w].push_back(x);
	Add(w);
}

void Pop(int w)
{
	Del(w);
	q[w].pop_front();
	Add(w);
}

void Xiao(int A)
{
	if((int)SF[A].size()>1)
	{
		int x=*SF[A].begin(),
			y=*++SF[A].begin();
		Pop(x),Pop(y);
		O[++Cnt]=2,X[Cnt]=x,Y[Cnt]=y;
		if(!q[x].empty())Xiao(a[q[x].front()]);
		if(!q[y].empty())Xiao(a[q[y].front()]);
	}
}

void Push(int x)
{
	if(!SB[a[x]].empty())return Put(*SB[a[x]].begin(),x);
	if(!SE.empty())return Put(*SE.begin(),x),Xiao(a[x]);
	Put((*SV.begin()).id,x);
}

int main()
{
	freopen("meow.in","r",stdin);
	freopen("meow.out","w",stdout);
	rd(T);
	while(T--)
	{
		rd(n),rd(m),rd(K),Cnt=0,SE.clear(),SV.clear();
		for(int i=1;i<=K;++i)SF[i].clear(),SB[i].clear(),nxc[i]=m+1;
		for(int i=1;i<=n;++i)SE.insert(i);
		for(int i=1;i<=m;++i)rd(a[i]);
		for(int i=m;i>=1;--i)nx[i]=nxc[a[i]],nxc[a[i]]=i;
		for(int i=1;i<=m;++i)Push(i);
		/*for(int i=1;i<=n;++i)
			{
				printf("sz=%d %d : ",(int)q[i].size(),i);
				deque<int>qq=q[i];
				while(!qq.empty())
					printf("%d ",a[qq.front()]),qq.pop_front();
				printf("\n");
			}
			printf("------\n");*/
		printf("%d\n",Cnt);
		for(int i=1;i<=Cnt;++i)
			if(O[i]==1)printf("1 %d\n",X[i]);
			else printf("2 %d %d\n",X[i],Y[i]);
	}
	return 0;
}
