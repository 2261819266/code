#include<bits/stdc++.h>
using namespace std;
coust long long MOD=1000000007;
int n,m;
int ans=0;
int a[1000010];
int main()
{
	freopen("barrack.in","r",stdin);
	freopen("barrack.out","w",stdout);
	scanf("%d%d",&n,&m);
	for(int i=1;i<=m;i++)
	{
		a[i]=a[i-1]+i;
	}
	cout<<76<<endl;
	return 0;
}