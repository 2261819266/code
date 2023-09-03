#include<cstdio>
#include<cstring>
const int mod=998244353;
typedef long long ll;
const ll Mod=mod;
char a[1007][1007];
int r[1007][1007],d[1007][1007];
int main()
{
	freopen("plant.in","r",stdin);
	freopen("plant.out","w",stdout);
	int T,n,m,c,f;
	scanf("%d%*d",&T);
	while(T--)
	{
		memset(r,0,sizeof r);
		memset(d,0,sizeof d);
		int Ansc=0,Ansf=0;
		scanf("%d%d%d%d",&n,&m,&c,&f);
		for(int i=1;i<=n;++i)scanf("%s",a[i]+1);
		for(int i=1;i<=n;++i)for(int j=m;j;--j)if(a[i][j]=='0')r[i][j]=r[i][j+1]+1;
		for(int i=n;i;--i)for(int j=1;j<=m;++j)if(a[i][j]=='0')d[i][j]=d[i+1][j]+1;
		for(int j=1;j<=m;++j)
		{
			for(int i=1,s=0,sq=0;i<=n;++i)
			{
				if(a[i][j]=='0')
					Ansc=(Ansc+(r[i][j]-1LL)*s)%Mod,
					Ansf=(Ansf+(r[i][j]-1LL)*(d[i][j]-1LL)%Mod*s)%Mod,
					s+=sq,sq=r[i][j]-1;
				else s=sq=0;
			}
		}
		printf("%lld %lld\n",(ll)c*Ansc%Mod,(ll)f*Ansf%Mod);
	}
	return 0;
}
