#include <bits/stdc++.h>
#define ll long long
using namespace std;
const int N = 1e3 + 5;
const int M = 998244353;
char a[N][N];
int suml[N][N],sumr[N][N];
void solve()
{
	memset(suml,0,sizeof(suml));
	memset(sumr,0,sizeof(sumr));
	int n,m,i,j,f,c,tot;
	ll ansc=0,ansf=0;
	cin>>n>>m>>c>>f;
	for(i=1;i<=n;i++)
		for(j=1;j<=m;j++)
			cin>>a[i][j];
			
	for(i=1;i<=n;i++)
		for(j=m;j>=1;j--)
			if(a[i][j]=='0')	suml[i][j]=suml[i][j+1]+1;
			else				suml[i][j]=0;
			
	for(j=1;j<=m;j++)
		for(i=n;i>=1;i--)
			if(a[i][j]=='0')	sumr[i][j]=sumr[i+1][j]+1;
			else				sumr[i][j]=0;

	for(i=1;i<=n;i++)
		for(j=1;j<=m;j++)
		{
			if(suml[i][j])	suml[i][j]--;
			if(sumr[i][j])	sumr[i][j]--;
		}		
	for(j=1;j<=m;j++)	
	{
		for(i=1,tot=0;i<=n;i++)
		{
			if(a[i][j]=='0')
			{
				ansc=(ansc+suml[i][j]*tot)%M;
				ansf=(ansf+suml[i][j]*tot%M*sumr[i][j])%M;
				tot=(tot+suml[i-1][j])%M;
			}
			else	tot=0;
		}
	}
	cout<<ansc*c<<" "<<ansf*f<<endl;
}
int main()
{
	freopen("plant.in","r",stdin);
	freopen("plant.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	int t,id;
	for(cin>>t>>id;t;t--)	solve();
	return 0;
}
