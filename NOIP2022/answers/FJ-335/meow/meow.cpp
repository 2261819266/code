#include<bits/stdc++.h>
struct node
{
	int op,x,y;
}an[4000005];
int T;
int n,m,k,ans,pos,mn;
int a[2000005];
int s[305][200005],top[305],un[305];
bool fl[305];
int main()
{
	freopen("meow.in","r",stdin);
	freopen("meow.out","w",stdout);
	scanf("%d",&T);
	while(T--)
	{
		scanf("%d%d",&n,&m,&k);
		for(int i=1;i<=m;i++)
			scanf("%d",&a[i]);
		ans=0;
		memset(top,0,sizeof(top));
		memset(un,1,sizeof(un));
		memset(s,0,sizeof(s));
		for(int x=1;x<=m;x++)
		{
			while(1)
			{
				bool fg=1;
				for(int i=1;i<=n;i++)
				{
					for(int j=1;j<=n;j++)
					{
						if(s[i][un[i]]==s[j][un[j]]&&un[i]<top[i]&&un[j]<top[j]&&i!=j)
						{
							fg=0;
							an[++ans].op=2;
							an[ans].x=i;
							an[ans].y=j;
							un[i]++,un[j]++;
						}
					}
				}
				if(fg)break;
			}
			bool flag=0;
			for(int i=1;i<=n;i++)
			{
				if(a[x]==s[i][top[i]])
				{
					top[i]--;
					flag=1;
					an[++ans].op=1;
					an[ans].x=i;
					break;
				}
			}
			if(flag)continue;
			pos=0;
			mn=10000000;
			for(int i=1;i<=n;i++)
				if(top[i]-un[i]+1<mn)
				{
					pos=i;
					mn=top[i]-un[i]+1;
				}
			s[pos][++top[pos]]=a[x];
			an[++ans].op=1;
			an[ans].x=pos;
		}
		printf("%d\n",ans);
		for(int i=1;i<=ans;i++)
		{
			if(an[i].op==1)printf("1 %d\n",an[i].x);
			else printf("2 %d %d\n",an[i].x,an[i].y);
		}
	}
	return 0;
}
