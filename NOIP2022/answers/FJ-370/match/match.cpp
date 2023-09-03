#include <bits/stdc++.h>
using namespace std;
const int MAXN=250010;
int n;
int a[MAXN],b[MAXN];
int q;
int main()
{
	freopen("match.in","r",stdin);
	freopen("match.out","w",stdout);
	register int id; scanf("%d%d",&id,&n);
	for(register int i=1;i<=n;i++) scanf("%d",&a[i]);
	for(register int i=1;i<=n;i++) scanf("%d",&b[i]);
	scanf("%d",&q);
	while(q--)
	{
		register int l,r; scanf("%d%d",&l,&r);
		register unsigned long long res=0;
		for(register int i=l;i<=r;i++)
			for(register int j=i;j<=r;j++)
			{
				register unsigned long long mxa=0,mxb=0;
				for(register int k=i;k<=j;k++)
				{
					if(a[k]>mxa) mxa=a[k];
					if(b[k]>mxb) mxb=b[k];
				}
				res+=mxa*mxb;
			}
		printf("%u\n",res);
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
