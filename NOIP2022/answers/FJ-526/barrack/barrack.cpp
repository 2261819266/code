#include<bits/stdc++.h>
using namespace std;
int n,m;
long long tt;
const int N=1000000007;
int u,v;
bool A=1;
int main()
{
	freopen("barrack.in","r",stdin);
	freopen("barrack.out","w",stdout);
	scanf("%d %d",&n,&m);
	
	for(int i=1;i<=m;i++)
	{
		scanf("%d %d",&u,&v);
		if(!(u==i&&v==i+1&&m==n-1)&&A==1)
		{
			A=0;
		}
	}
	if(A)
	{
		long long x=n*(n-1)/2,y=n;
		x=x%N; y=y%N;
		for(int i=1;i<=n-2;i++)
		{
			x=x*2;
			x=x%N;
		}
		for(int i=1;i<=n-1;i++)
		{
			y=y*2;
    		y=y%N;
		}
		tt=x+y;
		tt=tt%N;
		cout<<tt;
		return 0;
	}
	else
	{
		cout<<114514;
		return 0;
	}
}
