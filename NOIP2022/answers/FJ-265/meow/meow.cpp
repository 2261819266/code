#include<cstdio>
#include<iostream>
#include<algorithm>
#include<cstring>
#include<queue>
#include<vector>
#include<bits/stdc++.h>
using namespace std;

int read()
{
	int x=0,f=1;
	char c=getchar();
	while(c<'0'||c>'9')
	{
		if(c=='-')f=-1;
		c=getchar();
	}
	while(c>='0'&&c<='9')
	{
		x=x*10+c-'0';
		c=getchar();
	}
	return x*f;
}

struct node{
	int x;
	friend bool operator<(node a,node b)
	{
		return a.x>b.x;
	}
};

const int MX=2*1000*1000+10;
int T,n,smax,k;
int a[MX];
int ccheck[MX];
int st[310][3];
deque<int> q[310];
int topmax[MX];
int tope[MX];
int topmaxf[MX];
priority_queue<int> sizemin;
int topvis[MX];
int nvis[MX];
int win[310];


void mycheck()
{
	for(int i=1;i<=n;++i)
	{
		printf("%d ",ccheck[i]);
	}
}

void init()
{
	smax=read(),n=read(),k=read();
	for(int i=1;i<=n;++i)
	{
		a[i]=read();
	}
	for(int i=1;i<=n;++i)
	{
		if(nvis[i]) continue;
		for(int j=i+1;j<=n;++j)
		{
			if(a[j]==a[i])
			{
				ccheck[i]=j;
				ccheck[j]=i;
				nvis[j]=1;
				break;
			}
		}
	}
	
	return;
}

void check1(int x)
{
	for(int i=1;i<=n;++i)
	{
		if(q[i].back()==a[x])
		{
			q[i].pop_back();
			printf("%d %d\n",1,i);
			return;
		}
	}
	for(int i=1;i<=n;++i)
	{
		if(!q[i].empty()&&q[i].front()==a[x])
		{
			for(int j=1;j<=n;++j)
			{
				if(q[j].empty())
				{
					q[i].pop_front();
					printf("%d %d %d\n",2,j,i);
					return;
				}
			
			}
			return;
		}
	}
	int nowmax;
	for(int i=1;i<=n;++i)
	{
		if(q[i].empty()) continue;
		nowmax = max(nowmax,q[i].back());
		q[nowmax].push_back(x);
	}
	
	return;
}

void solve()
{

	for(int i=1;i<=n;++i)
	{
		if(ccheck[i]>i)
		{
			check1(i);
		}
	}
}

int main()
{
	freopen("meow.in","r",stdin);
	freopen("meow.out","w",stdout);
	T=read();
	for(int i=1;i<=T;++i)
	{
		init();
		solve();
	}
	
	
	return 0;
}
