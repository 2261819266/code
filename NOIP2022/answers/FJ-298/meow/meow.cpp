#include<cstdio>
#include<iostream>
#include<cmath>
#include<cstring>
#include<string>
#include<queue>
#include<deque>
using namespace std;
deque<int>Q[301];
int n,m,k;
void special()
{
	scanf("%d%d%d",&n,&m,&k);
	for(int i=1;i<=n;i++)
	{
		Q[i].clear();
		//while(!Q[i].empty())Q.pop();
	}
	for(int i=1;i<=m;i++)
	{
		int x;scanf("%d",&x);
		int id=(x-1)/2+1;
		if((!Q[id].empty())&&Q[id].front()==x)
		{
			printf("1 %d\n2 %d %d\n",n,n,id);
			Q[id].pop_front();
		}
		else
		{
			printf("1 %d\n",id);
			if((!Q[id].empty())&&Q[id].back()==x)Q[id].pop_back();
			else Q[id].push_back(x);
		}
	}
}
int a[1000001],f[1000001];
void fortune()
{
	scanf("%d%d%d",&n,&m,&k);
	for(int i=1;i<=n;i++)Q[i].clear();
	for(int i=1;i<=m;i++)scanf("%d",&a[i]);
	f[m]=0;
	for(int i=m-1;i>0;i--)
	{
		if(a[i]==a[i+1])f[i]=f[i+1];
		else f[i]=a[i+1];
	}
	for(int i=1;i<=m;i++)
	{
		int x=a[i];
		int id;
		bool ok=false;
		for(int j=1;j<=n;j++)
		{
			if(!Q[j].empty()&&Q[j].back()==x){printf("1 %d\n",j);Q[j].pop_back();ok=true;break;}
		}
		if(ok)continue;
		int emp=-1,tag=-1;
		for(int j=1;j<=n;j++)
		{
			if(Q[j].empty()){emp=j;break;}
		}
		for(int j=1;j<=n;j++)
		{
			if(!Q[j].empty()&&Q[j].front()==x){tag=j;break;}
		}
		if(emp!=-1&&tag!=-1)
		{
			printf("1 %d\n",emp);
			printf("2 %d %d\n",tag,emp);
			Q[tag].pop_front();continue;
		}
		if(n==2)
		{
			if(x<=2)id=x;
			else
			{
				if(f[i]==0)id=1;
				else id=3-f[i];
			}
		}
		else id=(x-1)/2+1;
		printf("1 %d\n",id);
		if((!Q[id].empty())&&Q[id].back()==x)
		{
			Q[id].pop_back();continue;
		}
		if(Q[id].empty())
		{
			bool fd=false;
			for(int j=1;j<=n;j++)
			{
				if(j==id)continue;
				if(!Q[j].empty()&&Q[j].front()==x)
				{
					printf("2 %d %d\n",id,j);
					Q[j].pop_front();fd=true;break;
				}
			}
			if(fd)continue;
		}
		Q[id].push_back(x);
	}
}
int t[1000001];
struct node{
	int op,x,y;
}ans[1000001];
bool fdans=false;
bool check()
{
	for(int i=1;i<=n;i++)
	{
		Q[i].clear();
		//while(!Q[i].empty())Q.pop();
	}
	int cnt=0;
	for(int i=1;i<=m;i++)
	{
		int x=a[i],id=t[i];
		ans[++cnt].op=1;
		ans[cnt].x=id;
		if((!Q[id].empty())&&Q[id].back()==x)
		{
			Q[id].pop_back();continue;
		}
		if(Q[id].empty())
		{
			bool fd=false;
			for(int j=1;j<=n;j++)
			{
				if(j==id)continue;
				if(!Q[j].empty()&&Q[j].front()==x)
				{
					ans[++cnt].op=2;
					ans[cnt].x=id;ans[cnt].y=j;
					Q[j].pop_front();fd=true;break;
				}
			}
			if(fd)continue;
		}
		Q[id].push_back(x);
	}
	for(int i=1;i<=n;i++){if(!Q[i].empty())return false;}
	for(int i=1;i<=cnt;i++)
	{
		printf("%d %d ",ans[i].op,ans[i].x);
		if(ans[i].op==2)printf("%d",ans[i].y);
		printf("\n");
	}
	return true;
}
void dfs(int now)
{
	if(now==m+1)
	{
		if(check())
		{
			fdans=true;
		}
		return;
	}
	for(int i=1;i<=n;i++)
	{
		t[now]=i;dfs(now+1);
		if(fdans)return;
	}
}
void force()
{
	scanf("%d%d%d",&n,&m,&k);
	for(int i=1;i<=m;i++)scanf("%d",&a[i]);
	dfs(1);
}
int main()
{
	freopen("meow.in","r",stdin);
	freopen("meow.out","w",stdout);
	int T;scanf("%d",&T);
	if(T%10==1)
	{
		for(int i=1;i<=T;i++)special();
		return 0;
	}
	if(T%10==3)for(int i=1;i<=T;i++)force();
	else for(int i=1;i<=T;i++)fortune();
	return 0;
}
/*
1
2 4 2
1 2 1 2
*/
