#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<iostream>
#include<algorithm>
#include<cmath>
using namespace std;
char g[1000][1001];
int h[1000][1001];
int main()
{
	freopen("plant.in","r",stdin);
	freopen("plant.out","w",stdout);
	int a,b,c,d,e,f,i,j,k,l,m,n,o,p,q,r,s;
	scanf("%d%d",&a,&b);
	for (i=0;i<a;i++)
	{
		scanf("%d%d%d%d",&c,&d,&e,&f);
		for (j=0;j<c;j++)
		{
			scanf("%s",g[j]);
			h[j][d]=d;
			for (k=d-1;k>-1;k--)
			if (g[j][k]==48) h[j][k]=h[j][k+1];
			else h[j][k]=k;
		}
		l=0;
		m=0;
		for (n=0;n<d;n++) for (o=0;o<c;o++) if (g[o][n]==48)
		{
			for (p=o;p<c-1;p++) if (g[p+1][n]==49) break;
			q=0;
			r=0;
			for (s=p-2;s>=o;s--)
			{
				q=(q+(h[s+2][n]-n-1))%998244353;
				r=(r+(long long int)(h[s+2][n]-n-1)*(p-s-2)%998244353)%998244353;
				l=(l+(long long int)(h[s][n]-n-1)*q%998244353)%998244353;
				m=(m+(long long int)(h[s][n]-n-1)*r%998244353)%998244353;
			}
			o=p;
		}
		printf("%d %d\n",e*l,f*m);
	}
	return 0;
}
/*
1 0
4 3 1 1
001
010
000
000
*/
