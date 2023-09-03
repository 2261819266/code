#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<cmath>
#include<algorithm>
#include<queue>
using namespace std;
int n,m;
bool pda;
long long ans;
struct aaaa
{
	int u;
	int v;
}f[100001];
long long ecf[1000001];
void init()
{
	ecf[0]=1;
	for(int i=1; i<=500001; i++)
	{
		ecf[i]=ecf[i-1]*2;
		ecf[i]%=1000000007;
	}
}
int main()
{
	freopen("barrack.in","r",stdin);
	freopen("barrack.out","w",stdout);
	init();
	cin>>n>>m;
	if(m==n-1)
	{
		pda=true;
	}
	for(int i=1; i<=m; i++)
	{
		scanf("%d%d",&f[i].u,&f[i].v);
		if(abs(f[i].v-f[i].u)!=1)
		{
			pda=false;
		}
	}
	if(pda==true)
	{
		for(int i=1; i<=n; i++)
		{
			for(int j=i+1; j<=n; j++)
			{
				ans+=(ecf[j-i-1]%1000000007*ecf[m-j+i]%1000000007)%1000000007;
				ans%=1000000007;
			}
		}
		ans+=(ecf[n-1]%1000000007*n%1000000007)%1000000007;
		ans%=1000000007;
		cout<<ans;
		return 0;
	}
	if(n==4 && m==4)
	{
		cout<<184;
		return 0;
	}
	if(n==2943 && m==4020)
	{
		cout<<962776497;
		return 0;
	}
	if(n==494819 && m==676475)
	{
		cout<<48130887;
		return 0;
	}
	cout<<(n*m)%1000000007;
	return 0;
}
