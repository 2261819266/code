#include<bits/stdc++.h>
using namespace std;
int n,m,u,v;
long long ansa=0;
int genji(int n)
{
    int yj=1;
	for(int i=1;i<=n;i++) yj*=2;
	return yj;	
}
int main()
{
	freopen("barrack.in","r",stdin);
	freopen("barrack.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=m;i++) cin>>v>>u;
    ansa+=(n*genji(n-1));
    long long summ=0;
    for(int i=1;i<=n-1;i++)
    {
         for(int j=1;j<=i;j++){
         	summ+=(j*genji(j-1));
		 }
		 ansa+=summ;
		 summ=0;
	}
	cout<<ansa%1000000007;
    return 0;
}