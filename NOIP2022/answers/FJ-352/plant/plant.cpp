#include<bits/stdc++.h>
using namespace std;
const long long mod=998244353; 
int T,id,n,m,c,f;
long long ansc,ansf,b[1006][1006],bs[1006];
bool a[1006][1006];
string s;
void g()
{
	long long sumgc=0,sumgf=0,sumfg=0,sumg=0,sumgg=0,sumcg=0;
	for(int x=1;x<=m;x++)
	{
		bs[n+1]=0;
		for(int y=n;y>=1;y--)
		{
			if(a[y][x])bs[y]=0;
			else bs[y]=bs[y+1]+1;
		}
		sumg=0,sumgg=0;
		for(int y=1;y<=n;y++)
		{
			if(!b[y][x])ansc=(ansc+sumg)%mod,sumg=0,sumgg=0;
			if(b[y][x]>1)
			{
				if(sumgg>0)
				{
					sumg+=((sumgg-b[y-1][x]+1)*1ll*(b[y][x]-1))%mod;
					ansf+=((((sumgg-b[y-1][x]+1)*1ll*(b[y][x]-1))%mod)*1ll*bs[y+1])%mod;
				}
				sumgg+=b[y][x]-1;
				sumg%=mod,sumgg%=mod,ansf%=mod;
			}
		}
		if(b[n][x]>=1)ansc=(ansc+sumg)%mod;
	}
	return;
}
int main()
{
	freopen("plant.in","r",stdin);
	freopen("plant.out","w",stdout);
	scanf("%d%d",&T,&id);
	while(T--)
	{
		ansc=ansf=0;
		scanf("%d%d%d%d",&n,&m,&c,&f);
		for(int i=1;i<=n;i++)
		{
			cin>>s;
			for(int j=0;j<s.size();j++)a[i][j+1]=s[j]-48;
			b[i][m+1]=0;
			for(int j=m;j>=1;j--)
			{
				if(!a[i][j])b[i][j]=b[i][j+1]+1;
				else b[i][j]=0;
			}
		}
		if(!c)printf("0 ");
		else g(),printf("%lld ",ansc);
		if(!f)printf("0");
		else printf("%lld",ansf);
		cout<<endl;
	}
	return 0;
}
