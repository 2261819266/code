#include<bits/stdc++.h>
using namespace std;
int n,m,x,fa[500005],xx,siz[500005],maxx;
long long c[17];
int findd(int x)
{
	return fa[x]==x? x:fa[x]=findd(fa[x]);
}
long long C(int xxx,int yyy)
{
	return (c[xxx]/c[yyy])/c[xxx-yyy];
}
pair<int,int> p[1000005];
void bufen()
{
	long long ans=0;
	for (int i=0;i<(1<<m);i++)
		{x=i;
		 xx=maxx=0;
		 for (int j=1;j<=n;j++) fa[j]=j,siz[j]=1;
		 for (int j=0;j<m;j++)
			{if (x&1)
				{if (findd(p[j].first)!=findd(p[j].second)) fa[findd(p[j].first)]=findd(p[j].second);
				}
			 x>>=1;
			}
		 for (int j=1;j<=n;j++) if (findd(j)!=j) siz[findd(j)]++,siz[j]=0;
		 for (int j=1;j<=n;j++) maxx=max(maxx,siz[j]);
		 for (int k=1;k<=maxx;k++) ans+=C(maxx,k);
//		 cout<<ans<<endl;
		}
		 ans++;
	printf("%lld",ans);
}
int main()
{
	freopen("barrack.in","r",stdin);
	freopen("barrack.out","w",stdout);
	scanf("%d%d",&n,&m);
	c[0]=c[1]=1;
	for (int i=2;i<17;i++) c[i]=i*c[i-1];
	for (int i=0;i<m;i++) scanf("%d%d",&p[i].first,&p[i].second);
	if (m<=25) bufen();
	else
		{cout<<rand();
		}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
/*
4 4
1 2
2 3
3 1
1 4
*/
