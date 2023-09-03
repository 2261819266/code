#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<iostream>
#include<algorithm>
#include<cmath>
using namespace std;
int c[250000],d[250000],t[250000],u[250000];
int main()
{
	freopen("match.in","r",stdin);
	freopen("match.out","w",stdout);
	int a,b,e,f,g,i,j,k,l,m,n,o,q,r,s;
	unsigned long long int h,p;
	scanf("%d%d",&a,&b);
	for (i=0;i<b;i++) scanf("%d",&c[i]);
	for (j=0;j<b;j++) scanf("%d",&d[j]);
	scanf("%d",&e);
	for (k=0;k<e;k++)
	{
		scanf("%d%d",&f,&g);
		h=0;
		p=0;
		for (l=g-1;l>f-2;l--)
		{
			h+=(unsigned long long int)(c[l])*d[l];
			t[l]=c[l];
			u[l]=d[l];
			q=c[l];
			r=d[l];
			for (s=l+1;s<g;s++)
			{
				if (t[s]>c[l]&&u[s]>d[l]) break;
				q=max(q,t[s]);
				r=max(r,u[s]);
				h+=-(unsigned long long int)(t[s])*u[s]+(unsigned long long int)(q)*r;
				t[s]=q;
				u[s]=r;
			}
			p+=h;
		}
		printf("%llu\n",p);
	}
	return 0;
}
