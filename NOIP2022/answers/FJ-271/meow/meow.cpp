#include<bits/stdc++.h>
using namespace std;
int read()
{
	int c=0;
	char ch=0;
	while(ch<'0' || ch>'9') ch=getchar();
	while(ch>='0' && ch<='9')
	{
		c=(c<<3)+(c<<1)+(ch-'0');
		ch=getchar();
	}
	return c;
}
const int N=3e2+8,K=1e3+8,M=2e6+8;
int T,n,m,k,a[M],pre[K],gt[M],op;
int cz[M],xz1[M],xz2[M],tot;
int sta[N][N],tp[N],d[N];
int main()
{
	freopen("meow.in","r",stdin);
	freopen("meow.out","w",stdout);
	T=read();
	while(T--)
	{
		n=read(),m=read(),k=read();
		for(int i=1;i<=k;i++) pre[i]=-1;
		for(int i=1;i<=n;i++) tp[i]=0,d[i]=1;
		for(int i=1;i<=m;i++)
		{
			a[i]=read();
			if(pre[a[i]]==-1) pre[a[i]]=i;
			else
			{
				gt[pre[a[i]]]=i;
				gt[i]=pre[a[i]];
				pre[a[i]]=-1;
			}
			cz[i]=0;
		}
		op=0,tot=m;
		for(int i=1;i<=m;i++)
		{
			for(int j=1;j<=n;j++)
			{
				if(sta[j][tp[j]]==a[i])
				{
					cz[i]=j;
					tp[j]--;
					tot-=2;
					break;
				}
			}
			if(cz[i]!=0) continue;
			for(int j=1;j<=n;j++)
			{
				if(tp[j]<d[j])
				{
					cz[i]=j;
					sta[j][++tp[j]]=a[i];
					break;
				}
			}
			if(cz[i]==0)
			{
				for(int j=1;j<=n;j++)
				{
					if(gt[sta[j][tp[j]]]>gt[a[i]])
					{
						cz[i]=j;
						sta[j][++tp[j]]=a[i];
						break;
					}
				}
			}
			if(cz[i]==0)
			{
				int s=1,maxn=gt[sta[1][tp[1]]];
				for(int j=2;j<=n;j++)
				{
					if(maxn<gt[sta[j][tp[j]]])
					{
						s=j;
						maxn=gt[sta[j][tp[j]]];
					}
				}
				cz[i]=s;
				sta[s][++tp[s]]=a[i];
			}
		}
		int now=1;
		while(tot>0)
		{
			if(tp[now]<d[now]) continue;
			for(int i=1;i<=n;i++)
			{
				if(i==now) continue;
				if(sta[i][d[i]]==sta[now][d[now]])
				{
					op++;
					xz1[op]=now,xz2[op]=i;
					d[i]++,d[now]++;
					tot-=2;
				}
			}
			now++;
			if(now>n) now=1;
		}
		printf("%d\n",op+m);
		for(int i=1;i<=m;i++)  printf("1 %d\n",cz[i]);
		for(int i=1;i<=op;i++) printf("2 %d %d\n",xz1[i],xz2[i]);
	}
	return 0;
}
