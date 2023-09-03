#include<bits/stdc++.h>
#define int long long
using namespace std;
int h[1010][1010]={0},l[1010][1010]={0},ac[1010][1010]={0},lx[1010][1010]={0};
bool t[1010][1010]={0};
int inf=998244353;
signed main()
{
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	freopen("plant.in","r",stdin);freopen("plant.out","w",stdout);
	int t1,id;cin>>t1>>id;
	while(t1--)
	{
		int n,m,c,f;cin>>n>>m>>c>>f;
		for(int i=1;i<=n;i++)
		{
			string a;cin>>a;
			for(int j=1;j<=m;j++)
			{
				if(a[j-1]=='1')continue;
				t[i][j]=1;
			}
		}
		int cd=0,cd1=0;
		for(int i=n;i>=1;i--)
			for(int j=m;j>=1;j--)
				if(t[i][j])
				{
					h[i][j]=h[i][j+1]+1,l[i][j]=l[i+1][j]+1;
					ac[i][j]=ac[i+1][j]+h[i][j+1];ac[i][j]%=inf;
					lx[i][j]=lx[i+1][j]+h[i][j+1]*l[i+1][j]%inf;lx[i][j]%=inf;
					if(t[i+1][j])cd=cd+h[i][j+1]*ac[i+2][j]%inf,cd%=inf,cd1=cd1+h[i][j+1]*lx[i+2][j]%inf,cd1%=inf;
				}
		cout<<cd*c%inf<<' '<<cd1*f%inf<<endl;
	}
	return 0;
}
