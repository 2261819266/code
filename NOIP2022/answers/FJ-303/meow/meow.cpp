#include<bits/stdc++.h>
#define IL inline
#define reg register
#define N 2000200
#define M 2020
IL int read()
{
	reg int x=0; reg char ch=getchar();
	while(ch<'0'||ch>'9')ch=getchar();
	while(ch>='0'&&ch<='9')x=x*10+ch-'0',ch=getchar();
	return x;
}

int n,m,k;
bool type[N];
int tim[N],id[N],x[N];
std::deque<int>q[M];

IL int root(reg int x){return tim[q[x].front()];}
IL int apex(reg int x){return tim[q[x].back()];}
IL int croot(reg int p){return x[q[p].front()];}
IL int capex(reg int p){return x[q[p].back()];}

struct Opt{int op,x,y;}stk[N+N];
int top;

IL void work()
{
	n=read(),m=read(),k=read(),top=0;
	for(reg int i=1;i<=k;++i)id[i]=0;
	for(reg int i=1;i<=n;++i)q[i].clear();
	for(reg int i=1;i<=m;++i)
	{
		x[i]=read();
		if(id[x[i]])type[id[x[i]]]=1,tim[id[x[i]]]=i,type[i]=id[x[i]]=0;
		else id[x[i]]=i;
	}
	for(reg int i=1,j,p;i<=m;++i)if(type[i])
	{
		for(j=1,p=0;j<=n;++j)if(q[j].size()&&(!p||root(j)<root(p)))p=j;
		if(!p||tim[i]<root(p))
		{
			for(j=1;j<=n;++j)if(q[j].size()&&tim[i]<apex(j))
			{
				q[j].push_back(i),stk[++top]={1,j,0}; goto skip;
			}
			for(j=1;j<=n;++j)if(!q[j].size())
			{
				q[j].push_back(i),stk[++top]={1,j,0}; goto skip;
			}
		}
		for(j=1;j<=n;++j)if(j!=p&&q[j].size()&&q[j].size()<2)
		{
			q[j].push_back(i),stk[++top]={1,j,0}; goto skip;
		}
		if(q[p].size()<3&&apex(p)>=root(p))
		{
			q[p].push_back(i),stk[++top]={1,p,0}; goto skip;
		}
		for(j=1;j<=n;++j)if(q[j].size()&&apex(j)>tim[i])
		{
			q[j].push_back(i),stk[++top]={1,j,0}; goto skip;
		}
		for(j=1;j<=n;++j)if(!q[j].size())
		{
			q[j].push_back(i),stk[++top]={1,j,0}; goto skip;
		}
		skip:;
	}else
	{
		for(j=1;j<=n;++j)if(q[j].size()&&capex(j)==x[i])
		{
			stk[++top]={1,j,0},q[j].pop_back();
			goto skip2;
		}
		for(j=1,p=0;j<=n;++j)if(!q[j].size()){p=j; break;}
		if(!p)assert(0);
		for(j=1;j<=n;++j)if(q[j].size()&&croot(j)==x[i])
		{
			stk[++top]={1,p,0},stk[++top]={2,p,j},q[j].pop_front();
			goto skip2;
		}
		skip2:;
	}
	printf("%d\n",top);
	for(reg int i=1;i<=top;++i)if(stk[i].op==1)printf("1 %d\n",stk[i].x); else printf("2 %d %d\n",stk[i].x,stk[i].y);
}

main()
{
	freopen("meow.in","r",stdin),freopen("meow.out","w",stdout);
	for(reg int t=read();t--;work());
}
