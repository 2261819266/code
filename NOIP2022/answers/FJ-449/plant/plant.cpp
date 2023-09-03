#include<bits/stdc++.h>
using namespace std;
#define file(in,out) freopen(in,"r",stdin);\
					 freopen(out,"w",stdout);
#define ll long long
#define ull unsigned long long
#define rint register int
#define mod  998244353 
int a[1005][1005]={1},f[1005][1005][2]={0};
int main()
{
	int t,id;
	file("plant.in","plant.out")
	cin>>t>>id;
	while(t--)
	{
		int n,m,c,fa;
		cin>>n>>m>>c>>fa;
		ll fc=0,ff=0;
		for(rint i=1;i<=n;i++)
		{
			char c[1005];
			scanf("%s",c+1);
			for(rint j=1;j<=m;j++)a[i][j]=(int)(c[j]-'0');	
		}
		for(rint i=1;i<=n;i++)
		{
			int num=0;
			for(rint j=m;j>=1;j--)
			{
				num++;
				if(a[i][j])
				{
					num=0;
					continue;
				}
				f[i][j][0]=num;
				int sum=0;
				while(sum+i<=n && a[i+sum][j]==0)sum++;
				f[i][j][1]=sum;
			}
		}
		for(int i=1;i<=n-2;i++)for(int j=1;j<=m-1;j++)
		{
			if(a[i][j] || f[i][j][0]<2 || f[i][j][1]<3)continue;
			for(int k=3;k<=f[i][j][1];k++)
			{
				if(f[i+k-1][j][0]<2)continue;
				fc=(fc+(f[i+k-1][j][0]-1)*(f[i][j][0]-1)%mod)%mod;
			}
		}
		for(int i=1;i<=n-3;i++)for(int j=1;j<=m-1;j++)
		{
			if(a[i][j] || f[i][j][0]<2 || f[i][j][1]<4)continue;
			for(int k=3;k<=f[i][j][1];k++)
			{
				if(f[i+k-1][j][0]<2 || f[i+k-1][j][1]<2)continue;
				ff=(ff+((f[i+k-1][j][0]-1)*(f[i][j][0]-1)%mod)*(f[i+k-1][j][1]-1)%mod)%mod;
			}
		}
		cout<<c*fc<<" "<<fa*ff<<endl;
	}
	return 0;
}
