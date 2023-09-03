#include<bits/stdc++.h>
using namespace std;
long long t,n,m,k,a[700],d[700],f[700],p,q,u,v[10],w;
long long tot,cnt[2000],b[2000],c[2000];
int main()
{
	freopen("meow.in","r",stdin);
	freopen("meow.out","w",stdout);
	scanf("%lld",&t);
	while(t--)
	{
		tot=0;
		scanf("%lld%lld%lld",&n,&m,&k);
		for(int i=1;i<=n;i++) a[i]=0;
		p=0;
		for(int i=1;i<=m;i++)
		{
			scanf("%lld",&q);
			if(!d[q])
			{
				p++;
				d[q]=p;
				tot++;
				cnt[tot]=1;
				b[tot]=p;
			}
			else
			{
				p=d[q]-1;
				tot++;
				cnt[tot]=1;
				b[tot]=d[q];
				d[q]=0;
			}
		}
		for(int i=1;i<=tot;i++)
		{
			if(cnt[i]==1) printf("1 %lld\n",b[i]);
			else
			{
				if(b[i]>c[i]) swap(b[i],c[i]);
				printf("2 %lld %lld\n",b[i],c[i]);
			}
		}
	}
	return 0;
}
