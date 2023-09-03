#include<bits/stdc++.h>
using namespace std;
long long n,t,a[250001],b[250001],l,r,f,q,p,ans;
long long sta[25][250001],stb[25][250001];
int lg[250001];
void pre()
{
	for(int i=2;i<=n;i++)
	{
		lg[i]=lg[i/2]+1;
	}
	for(int i=1;i<=n;i++)
	{
		sta[0][i]=a[i];
		stb[0][i]=b[i];
	}
	for(int i=1;i<=lg[n];i++)
	for(int j=1;j<=n;j++)
	{
		sta[i][j]=max(sta[i-1][j],sta[i-1][j+(1<<(i-1))]);
		stb[i][j]=max(stb[i-1][j],stb[i-1][j+(1<<(i-1))]);
	}
}
int main()
{
	freopen("match.in","r",stdin);
	freopen("match.out","w",stdout);
	cin>>t>>n;
	for(int i=1;i<=n;i++)
	scanf("%lld",&a[i]);
	for(int i=1;i<=n;i++)
	scanf("%lld",&b[i]);
	pre();
	cin>>f;
	while(f--)
	{
		ans=0;
		scanf("%lld%lld",&l,&r);
		for(p=l;p<=r;p++)
		{
			for(q=p;q<=r;q++)
			{
				long long h=lg[q-p+1];
				long long ma=max(sta[h][p],sta[h][q-(1<<h)+1]);
				long long mb=max(stb[h][p],stb[h][q-(1<<h)+1]);
				ans+=ma*mb;	
			}
		}
    	printf("%lld\n",ans);
	}
	return 0;
}
/*
0 2
2 1
1 2
1 
1 2
*/
