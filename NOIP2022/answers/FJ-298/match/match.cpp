#include<cstdio>
#include<iostream>
#include<cmath>
#include<cstring>
#include<string>
#include<queue>
using namespace std;
int n,a[1000001],b[1000001];
int main()
{
	freopen("match.in","r",stdin);
	freopen("match.out","w",stdout);
	int T;scanf("%d",&T);
	scanf("%d",&n);
	for(int i=1;i<=n;i++)scanf("%d",&a[i]);
	for(int i=1;i<=n;i++)scanf("%d",&b[i]);
	int Q;scanf("%d",&Q);
	for(int i=1;i<=Q;i++)
	{
		int l,r;scanf("%d%d",&l,&r);
		int ans=0;
		for(int p=l;p<=r;p++)
		{
			int maxna=0,maxnb=0;
			for(int q=p;q<=r;q++)
			{
				for(int j=p;j<=q;j++)maxna=max(maxna,a[j]),maxnb=max(maxnb,b[j]);
				ans=ans+maxna*maxnb;
			}
		}
		printf("%d\n",ans);
	}
	return 0;
}
/*
0 2
2 1
1 2
1
1 2
*/
