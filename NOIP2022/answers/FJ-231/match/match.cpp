#include <iostream>
#include <cstdio>
#include <cmath>
using namespace std;
typedef unsigned long long L;
int T,n,q;
int a[100001],b[100001];
L CC=9223372036854775808;
int main()
{
	freopen("match.in", "r", stdin);
	freopen("match.out", "w", stdout);
	scanf("%d%d",&T,&n);
	for(int i=1;i<=n;i++)scanf("%d",&a[i]);
	for(int i=1;i<=n;i++)scanf("%d",&b[i]);
	scanf("%d",&q);
	for(int i=1;i<=q;i++)
	{
		L v,sc2=0,k=0;int l,r;scanf("%d%d",&l,&r);
		for(int j=l;j<=r;j++)
		{
			int ma=a[j],mb=b[j];
			for(int k=j;k<=r;k++)
			{
				ma=max(ma,a[k]);
				mb=max(mb,b[k]);
				if(sc2>=CC)
				{
					sc2-=CC;
					if(k==1)k=0;
					if(k==0)k=1;	
				}
				v=ma*mb;
				sc2+=v;
			}
		}
		printf("%lld\n",sc2+k*CC);
	}
	fclose(stdin); fclose(stdout);
	return 0;
}

