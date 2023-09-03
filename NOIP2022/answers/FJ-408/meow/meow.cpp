#include<bits/stdc++.h>
using namespace std;
int t,n,m,k,a[2000005],s=0;
int st[305][200005];
struct out
{
	int a,b,c;
}o[4000005];
int l[305],r[305];
int main()
{
	freopen("meow.in","r",stdin);
	freopen("meow.out","w",stdout);
	scanf("%d",&t);
	while(t--)
	{
		memset(r,0,sizeof(r));
		scanf("%d%d%d",&n,&m,&k);
		for(int i=1;i<=n;i++)
			l[i]=1;
		for(int i=1;i<=m;i++)
			scanf("%d",&a[i]);
		int now=1;
		for(int i=1;i<=m;i++)
		{
			bool f=1;
			while(f)
			{
				f=0;
				for(int j=1;j<=n;j++)
				{
					if(l[j]<=r[j]&&i<m&&st[j][r[j]]==a[i])
					{
						s++;
						o[s]={1,j,0};
						r[j]--;
						f=1;
						i++;
						break;
					}
				}
			}
			st[now][++r[now]]=a[i];
			o[++s]={1,now,0};
			f=1;
			while(f)
			{
				f=0;
				for(int j=1;j<=n;j++)
				for(int k=j+1;k<=n;k++)
				{
					while(st[j][l[j]]==st[k][l[k]]&&l[j]<=r[j]&&l[k]<=r[k])
					{
						s++;
						l[j]++;
						l[k]++;
						o[s]={2,j,k};
						f=1;
					}
				}
			}
			now=rand()%n+1;
//			now++;
//			if(now>n)
//				now-=n;
		}
		printf("%d\n",s);
		for(int i=1;i<=s;i++)
		{
			printf("%d %d",o[i].a,o[i].b);
			if(o[i].a==2)
				printf(" %d",o[i].c);
			printf("\n");
		}
	}
	return 0;
}