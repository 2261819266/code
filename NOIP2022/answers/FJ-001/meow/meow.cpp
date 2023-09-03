#include<bits/stdc++.h>
using namespace std;
struct node{
	long long l,r;
	long long a[1005];
	void clear()
	{
		l=0;
		r=0;
		return 0;
	}
	long long front()
	{
		return a[l];
	}
	long long end()
	{
		return a[r];
	}
	long long size()
	{
		return l-r;
	}
}q[300];
struct vc{
	long long v;
	long long val[3];
}v[1005];
long long a[1005];
long long cnt;
long long T,n,m,k;
long long _,__;
bool jdg()
{
	for(int i=1;i<=1005;i++)
	{
		if(v[i].v==2)_=v[i].val[1],__v[i].val[2];
		return true;
	}
}
void dfs(int x)
{
	if(jdg())
	{
		q[i]
	}
	else
	{
		for(int i=1;i<=n;i++)
		{
			long long mk=q[i].a[q[i].r],mrk=0;
			q[i].r++;
			q[i].a[q[i].r]=a[cnt];
			cnt++;
			if(q[i].size()==1) v[q[i].a[q[i].r]].v+=1,v[q[i].a[q[i].r]].val[v[q[i].a[q[i].r]].v]=i;
			if(q[i].size()>0&&q[i].a[q[i].r]==q[i].a[q[i].r-1])mrk=1,r-=2;
			dfs(x+1);
			cnt--;
			if(mrk==0)q[i].r--;
			else
			{
				q[i].r++;
				q[i].a[q[i].r]=mk;
			}
		}
	}
}
int main()
{
	scanf("%lld",&T);
	while(T--)
	{
		memset(a,0,sizeof(a));
		cnt=1;
		for(int i=1;i<=300;++i)
		{
			q[i].clear();
		}
		scanf("%lld%lld%lld",&n,&m,&k);
		for(int i=1;i<=m;i++)
		{
			scanf("%lld",&a[i]);
		}
		
	}
}
