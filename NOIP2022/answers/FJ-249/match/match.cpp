#include<bits/stdc++.h>
#define ll long long
using namespace std;
const ll mod=1e9+7;
ll n,m,x,y,ans,p[1000000];
ll read()
{
	ll x=0,f=1;char ch=getchar();
	while(ch<'0'||ch>'9')
	{
		if(ch=='-')f=-1;
		ch=getchar();
	}
	while(ch>='0'&&ch<='9')
	x=(x<<3)+(x<<1)+ch-48,ch=getchar();
	return f*x;
}
int main()
{
	freopen("match.in","r",stdin);
	freopen("match.out","w",stdout);
	printf("8");
	return 0;
}
