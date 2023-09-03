#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int mod=1e9+7;
int n,m;
int main()
{
	freopen("barrack.in","r",stdin);
	freopen("barrack.out","w",stdout);
	cin>>n>>m;
	cout<<((ll)n*(n+1)/2)%mod<<endl;
	return 0;
}
