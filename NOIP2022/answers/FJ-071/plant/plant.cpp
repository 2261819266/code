#include<bits/stdc++.h>
using namespace std;
int mp[1002][1002];
int a[1002][1002],b[1002][1002],cc[1002][1002];
int main()
{
	freopen("plant.in","r",stdin);
	freopen("plant.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0),cout.tie(0);
	int T,id,n,m,c,f;string s;
	long long ansc=0,ansf=0,mod=998244353;
	cin>>T>>id;
	if(id==1) {
		for(int i=1;i<=T;i++) cout<<"0 0"<<"\n";
		return 0;
	}
	while(T--)
	{
		memset(a,0,sizeof a);
		memset(b,0,sizeof b);
		memset(cc,0,sizeof cc);
		ansc=ansf=0;
		cin>>n>>m>>c>>f;
		for(int i=1;i<=n;i++)
		{
			cin>>s;
			for(int j=1;j<=m;j++)
			{
				mp[i][j]=s[j-1]-'0';
			}
		}
		//c 
		for(int i=1;i<=n;i++)
		{
			for(int j=m;j>=1;j--)
			{
				if(mp[i][j]==0) a[i][j]=a[i][j+1]+1;
				else a[i][j]=0;
			}
		}
		for(int j=m;j>=1;j--)
		{
			for(int i=n;i>=1;i--)
			{
				if(mp[i][j]==0) cc[i][j]=cc[i+1][j]+1;
				else cc[i][j]=0;
			}
		}

		for(int j=1;j<=m;j++)
		{
			int cnt=0;
			for(int i=1;i<=n;i++)
			{
				if(mp[i][j]){
					cnt=0;continue;
				} 
				b[i][j]=max(0,a[i][j]-1)+cnt;
				cnt+=max(0,a[i][j]-1);
			}
		}
		for(int i=1;i<=n;i++)
		{
			for(int j=1;j<=m;j++)
			{
				if(mp[i][j]) continue;
				ansc=(ansc%mod+(long long)b[i-1][j]%mod*max(0,a[i+1][j]-1)%mod)%mod;
				ansf=(ansf%mod+(long long)cc[i+2][j]%mod*b[i-1][j]%mod*max(0,a[i+1][j]-1)%mod)%mod;
			}
		}
		cout<<ansc*c<<" "<<ansf*f<<endl;
	}

}
//freopen A wo jiu shi wan wo yao jin dai ma qi pa(yin wei shi Linux suo yi shu bu liao zhong wen)
/*
2 0
4 3 1 1
001
010
000
000
6 6 1 1
000010
011000
000110
010000
011000
000000
*/