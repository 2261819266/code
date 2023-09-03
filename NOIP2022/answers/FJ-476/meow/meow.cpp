#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll N=2e5+5;
struct node
{
	int t,s1,s2;
};
int T,n,m,k,a[N],s[305][N],ed[305],hd[305],ans=1;
queue<node> que;
int main()
{
	freopen("meow.in","r",stdin);
	freopen("meow.out","w",stdout);
	scanf("%d",&T);
	while(T--)
	{
		memset(a,0,sizeof(a));
		memset(s,0,sizeof(s));
		memset(ed,0,sizeof(ed));
		memset(hd,0,sizeof(hd));
		ans=1;
		
		scanf("%d%d%d",&n,&m,&k);
		scanf("%d",&a[1]);
		s[1][++ed[1]]=a[1];
		++hd[1];
		que.push({1,1,0});
		
		for(int i=2;i<=m;i++)
		{
			scanf("%d",&a[i]);
			bool tag=0;int flag=0;
			for(int j=1;j<=n;j++)
			{
				if(a[i]==s[j][ed[j]])
				{
					s[j][ed[j]]=0;
					ed[j]--;
					que.push({1,j,0});
					ans++;
					tag=1;break;
				}
				if(!flag&&(ed[j]==hd[j]&&s[j][ed[j]]==0))flag=j;
				if(s[j][hd[j]]==a[i]&&flag)
				{
					s[j][hd[j]]=0;
					hd[j]++;
					que.push({1,flag,0});
					que.push({2,flag,j});
					ans+=2;
					tag=1;break;
				}
			}
			if(!tag)
			{
				if(flag)
				{
					s[flag][++ed[flag]]=a[i];
					que.push({1,flag,0});
					ans++;
				}
				else
				{
					s[1][++ed[1]]=a[i];
					que.push({1,1,0});
					ans++;
				}
			}
		}
		for(int j=1;j<=n;j++)
		{
			for(int i=j+1;i<=n;i++)
			{
				if(s[j][hd[j]]==s[i][hd[i]]&&ed[j]!=0&&ed[i]!=0)
				{
					s[j][hd[j]]=0;hd[j]++;
					s[i][hd[i]]=0;hd[i]++;
					que.push({2,i,j});
					ans++;
				}
			}
		}
		printf("%d\n",ans);
		while(!que.empty())
		{
			node q=que.front();
			que.pop();printf("%d ",q.t);
			if(q.t==1)printf("%d\n",q.s1);
			else printf("%d %d\n",q.s1,q.s2);
		}
	}
	
	return 0;
}
