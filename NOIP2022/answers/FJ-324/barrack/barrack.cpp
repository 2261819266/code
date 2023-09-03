#include<bits/stdc++.h>
#define MOD 1000000007
using namespace std;

int n,m;

int main()
{
	freopen("barrack.in","r",stdin);
	freopen("barrack.out","w",stdout);
	cin>>n>>m;
	unsigned long long k=1;
	unsigned long long cnt=(2*n-2)%MOD;
	for(int i=1;i<=n-1;i++)
	{
		k*=2;
		k%=MOD;
	}
	cout<<k*cnt%MOD+1<<endl;
	return 0;
}
/*
rp++
让我拿10分吧  求求你了 
		by 吴含章 hispy 
		2022.11.26
*/
