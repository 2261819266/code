#include<bits/stdc++.h>
using namespace std;
#define ll long long
const int mod=998244353;
int t,id,n,m,c,f,k[1001][1002],l[1002][1001];
ll asc,asf,kc[1001][1001];
char a[1001][1001];
int main()
{
	freopen("plant.in","r",stdin);
	freopen("plant.out","w",stdout);
	cin>>t>>id;
	while(t--)
	{
		cin>>n>>m>>c>>f;
		asc=asf=0;
		for(int i=1;i<=n;i++)
			for(int j=1;j<=m;j++)
			{
				cin>>a[i][j];
				k[i][j]=l[i][j]=kc[i][j]=0;
			}
		for(int i=1;i<=n;i++)
			for(int j=m;j>=1;j--)
				if(a[i][j]=='1')
					k[i][j]=0;
				else
					k[i][j]=k[i][j+1]+1;
		for(int j=1;j<=m;j++)
			for(int i=n;i>=1;i--)
				if(a[i][j]=='1')
					l[i][j]=0;
				else
					l[i][j]=l[i+1][j]+1;
		for(int i=3;i<=n;i++)
			for(int j=1;j<=m-1;j++)
				if(a[i][j]=='0'&&a[i-1][j]=='0'&&a[i-2][j]=='0')
				{
					kc[i][j]=kc[i-1][j]+k[i-2][j]-1;
					asc+=kc[i][j]*(k[i][j]-1);
					asf+=kc[i][j]*(k[i][j]-1)*(l[i][j]-1);
				}
		cout<<asc*c%mod<<' '<<asf*f%mod<<'\n';
	}
	return 0;
}
//1
//1
//4
//5
//1
//4
//
//1
//9
//1
//9
//8
//1
//0
//
//xzh AK NOIp
//hyx AK NOIp
//wkc AK NOIp
//jxw AK NOIp
//wk AK NOIp
//sbh AK NOIp
//cyc AK NOIp
//ycz AK NOIp
