#include<bits/stdc++.h>
#define ll long long
using namespace std;
int T,n,m,k1;
int top1[1010],top2[1010],a[1000010],st[1010][1010];
int b[4][20];
int k[4][20];
int dfs(int k)
{
	if(k>m)
	{
		for(int i=1;i<=n;i++)
		{
			for(int j=top1[i];j>=1;j--)
			{
				b[i][j]=k[i][j];
			}
			top2[i]=top1[i];
			while(b[i][top2[i]]==b[i][top2[i]-1])
			{
				top2[i]-=2;
			}
		}
		int top=max(max(top2[1],top2[2]),top2[3]);
		for(int i=1;i<=top;i++)
		{
			if(b[1][1]==b[2][1]||b[1][1]==b[3][1]||b[2][1]=b[3][1])
			{
				cout<<1;
			}
		}
	}
	for(int i=1;i<=n;i++)
	{
		top1[i]++;top2[i]++;
		k[i][top1[i]]=a[k];
		dfs(k+1);
		top[i]--;
	}
}
int main()
{
	freopen("meow.in","r",stdin);
	freopen("meow.out","w",stdout);
	scanf("%d",&T);
	if(T==3)
	{
		while(T--)
		{
			scnaf("%d %d %d",&n,&m,&k);
			for(int i=1;i<=m;i++)
			{
				scanf("%d",&a[i]);
			}
			dfs(1);
		}
	}
	else
	while(T--)
	{
		memset(top,0,sizeof(top));
		scnaf("%d %d %d",&n,&m,&k1);
		for(int i=1;i<=m;i++)
		{
			scanf("%d",&a[i]);
			for(int j=1;j<=n;j++)
			{
				if()
			}
		}
	}
	return 0;
}
