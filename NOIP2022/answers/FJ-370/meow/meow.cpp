#include <bits/stdc++.h>
using namespace std;
const int MAXM=2e6+10,MAXN=310;
int n,m,k;
int a[MAXM];
int st[MAXN][3],cnt[MAXN];
int op;
int opt[MAXM<<1],s1[MAXM<<1],s2[MAXM<<1];
int main()
{
	freopen("meow.in","r",stdin);
	freopen("meow.out","w",stdout);
	int T; scanf("%d",&T);
	while(T--)
	{
		scanf("%d%d%d",&n,&m,&k);
		for(int i=1;i<=m;i++) scanf("%d",&a[i]);
		if(k==2*n-2)
		{
			op=0;
			for(int i=1;i<=n;i++) cnt[i]=0;
			for(int i=1;i<=m;i++)
			{
				int id=(a[i]+1)/2;
				if(cnt[id]==0||(cnt[id]==1&&st[id][1]!=a[i]))
				{
					op++; opt[op]=1; s1[op]=id;
					cnt[id]++; st[id][cnt[id]]=a[i];
				}
				else
					if(st[id][cnt[id]]==a[i])
					{
						op++; opt[op]=1; s1[op]=id;
						cnt[id]--;
					}
					else
					{
						op++; opt[op]=1; s1[op]=n;
						op++; opt[op]=2; s1[op]=id; s2[op]=n;
						cnt[id]=1; st[id][1]=st[id][2];
					}
			}
			printf("%d\n",op);
			for(int i=1;i<=op;i++)
				if(opt[i]==1) printf("1 %d\n",s1[i]);
				else printf("2 %d %d\n",s1[i],s2[i]);
			continue;
		}
		//k=2n-1 
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
