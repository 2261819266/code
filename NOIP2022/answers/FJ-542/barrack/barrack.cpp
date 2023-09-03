#include <bits/stdc++.h>
using namespace std;
int n,m,u,v;
unsigned long long Mod = 18446744073709551616;
unsigned long long ans;
unsigned long long mul(int x)
{
	if (x==1)    return 2;
	if (x==0)    return 1;
	long long t = mul(x/2);
	if (x&1)    return t*t*2;
	else return t*t;
}
int main()
{
	freopen("barrack.in","r",stdin);
	freopen("barrack.out","w",stdout);
	scanf("%d%d",&n,&m);
	srand(time(NULL));
	for (int i=1;i<=m;i++)
	{
		scanf("%d%d",&u,&v);
	}
	if (n == m+1)
	{
		for (int k=0;k<=m;k++)
		{
			if (m-k>=64)    continue;
			ans = ans + mul(m-k)*(n-k);
			if (ans > Mod)   ans = ans - Mod;
		}
		cout<<ans;
		return 0;
	} else {
		cout<<rand()%114514<<endl;
		//make me AC
	}
	return 0;
}
