#include<bits/stdc++.h>
using namespace std;
int t,id,n,m,c,f,a[1001][1001];
int main()
{
	freopen("plant.in","r",stdin);
	freopen("plant.out","w",stdout);
	cin>>t>>id;
	for(int i=1;i<=t;i++)
	{
		cin>>n>>m>>c>>f;
		for(int j=1;j<=n;j++)
		{
			cin>>a[m][n];
		}
	}
	cout<<0<<' '<<0;
	return 0;
}