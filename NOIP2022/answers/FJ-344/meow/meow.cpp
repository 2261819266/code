#include <bits/stdc++.h>
using namespace std;
const int M=2e6+10,N=650;
int n,m,k,T,a[M],nxt[N],vis[N],op;
vector<int> putans[N<<1];
deque<int> stac[N];
int main()
{
	freopen("meow.in","r",stdin);
	freopen("meow.out","w",stdout);
	cin>>T;
	if (T%10==1)
	{
		while (T--)
		{
			op=0;
			for (int i=0;i<(N<<1);i++)
				while (!putans[i].empty())
					putans[i].pop_back();
			for (int i=0;i<N;i++)
				stac[i].clear();
			scanf("%d%d%d",&n,&m,&k);
			for (int i=1;i<=m;i++)
				scanf("%d",a+i);
			
			for (int i=1;i<=m;i++)
			{
				op++;
				int wi=a[i]+1>>1;
				if (stac[wi].empty())
					putans[op].push_back(1),putans[op].push_back(wi),stac[wi].push_front(i);
				else
				{
					if (a[stac[wi].front()]==a[i])
						putans[op].push_back(1),putans[op].push_back(wi),stac[wi].pop_front();
					else
					{
						putans[op].push_back(1),putans[op].push_back(n);
						op++;
						stac[wi].pop_back();
						putans[op].push_back(2),putans[op].push_back(wi),putans[op].push_back(n);
					}
				}
			}
			
			printf("%d\n",op);
			for (int i=1;i<=op;i++)
			{
				for (auto it:putans[i])
					printf("%d ",it);
				puts("");
			}
		}
		return 0;
	}
	while (T--)
	{
		memset(nxt,-1,sizeof(nxt));
		memset(vis,-1,sizeof(vis));
		for (int i=0;i<(N<<1);i++)
			while (!putans[i].empty())
				putans[i].pop_back();
		for (int i=0;i<N;i++)
			stac[i].clear();
		op=0;
		
		scanf("%d%d%d",&n,&m,&k);
		for (int i=1;i<=m;i++)
			scanf("%d",a+i);
		
		for (int i=m;i;i--)
			if (vis[a[i]]!=-1) nxt[i]=vis[a[i]],vis[a[i]]=i;
			else vis[a[i]]=i,nxt[i]=1e7;
		
		for (int i=1;i<=m;i++)
		{
			op++;
			int spc=-1;
			for (int j=1;j<=n;j++)
				if (stac[j].empty())
					{spc=j; break; }
			
			bool flag=0;
			for (int j=1;j<=n;j++)
			{
				if (stac[j].empty()) continue;
				if (a[stac[j].front()]==a[i])
				{
					stac[j].pop_front();
					putans[op].push_back(1),putans[op].push_back(j);
					flag=1;
					break;
				}
				else if (a[stac[j].back()]==a[i]&&spc>0)
				{
					stac[j].pop_back();
					putans[op].push_back(1),putans[op].push_back(spc);
					op++;
					putans[op].push_back(2),putans[op].push_back(spc),putans[op].push_back(j);
					flag=1;
					break;
				}
			}
			if (!flag)
			{
				for (int j=1;j<=n;j++)
				{
					if (!stac[j].empty()&&nxt[i]<nxt[stac[j].front()])
					{
						putans[op].push_back(1),putans[op].push_back(j);
						stac[j].push_front(i);
						flag=1;
						break;
					}
				}
				if (!flag) putans[op].push_back(1),putans[op].push_back(1),stac[1].push_front(i);
			}
//			cout<<i<<endl;
		}
		while (!stac[1].empty()||!stac[2].empty()||!stac[3].empty())
		{
			for (int i=1;i<=n;i++)
				for (int j=i+1;j<=n;j++)
					if (!stac[i].empty()&&!stac[j].empty()&&a[stac[i].back()]==a[stac[j].back()])
						op++,putans[op].push_back(2),putans[op].push_back(i),putans[op].push_back(j);
		}
		
		printf("%d\n",op);
		for (int i=1;i<=op;i++)
		{
			for (auto it:putans[i])
				printf("%d ",it);
			puts("");
		}
	}
	
	return 0;
}
