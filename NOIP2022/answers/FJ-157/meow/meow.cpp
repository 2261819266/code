#include<iostream>
#include<cstdio>
#include<cstring>
#include<cmath>
#include<vector>
#include<queue>
#include<deque>
using namespace std;
const int N=600+5,M=2e6+5;
int T,n,m,k,t,a[M],b[M],p[M],mn[M];
bool vis[M];
deque<int> q[N];
vector<int> vc[N];
void solve(int x)
{	int pp=p[b[x]];
	if(a[x]==a[q[pp].back()])
	{	printf("1 %d\n",pp);
		q[pp].pop_back();
		return;
	}
	else{
		printf("1 %d\n",n);
		printf("2 %d %d\n",n,pp);
		q[pp].pop_front(),mn[pp]=b[q[pp].back()];
	}
}
int main()
{	freopen("meow.in","r",stdin);
	freopen("meow.out","w",stdout);
	scanf("%d",&T);
	while(T--)
	{	scanf("%d%d%d",&n,&m,&k);
		for(int i=1;i<=k;i++)p[i]=0,vis[i]=0,vc[i].clear();
		for(int i=1;i<=n;i++)mn[i]=0;
		for(int i=1;i<=m;i++)
		{	scanf("%d",&a[i]);
			vc[a[i]].push_back(i);
		}
		for(int i=1;i<=k;i++)
			for(int j=0;j<(int)vc[i].size();j+=2)
				b[vc[i][j]]=vc[i][j+1],b[vc[i][j+1]]=vc[i][j];
		for(int i=1;i<=m;i++)
		{	if(vis[a[i]]){solve(i);vis[a[i]]=0;continue;}
			vis[a[i]]=1;
			for(int j=1;j<=n;j++){
				if(!mn[j]||mn[j]>b[i])
				{	mn[j]=b[i],p[i]=j,q[j].push_back(i);
					printf("1 %d\n",j);break;
				}
			}
		}
	}
	return 0;
}
