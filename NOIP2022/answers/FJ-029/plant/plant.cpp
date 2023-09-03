#include<cstdio>
#include<cstring>
//#define reg //register
#define mod 998244353
//#define meow(bronya...) fprintf(stderr,bronya)
int T,id,n,m,c,f;
char ch[1003][1003];
int cnt[1003][1003],sum[1003][1003];
int main()
{
	freopen("plant.in","r",stdin);
	freopen("plant.out","w",stdout);
	scanf("%d%d",&T,&id);
	while(T--)
	{
		scanf("%d%d%d%d",&n,&m,&c,&f);
		memset(cnt,0,sizeof(cnt));
		for(int i=1;i<=n;++i)
		{
			scanf("%s",ch[i]+1);
			for(int j=m;j>0;--j) if(ch[i][j]=='0') cnt[i][j]=cnt[i][j+1]+1;
		}
		int resc=0,resf=0;
		if(c==1)
		{
			memset(sum,0,sizeof(sum));
			for(int j=1;j<=m;++j)
			for(int i=n;i>0;--i)
			if(ch[i][j]=='0') sum[i][j]=(sum[i+1][j]+cnt[i][j+1])%mod;
			for(int i=1;i+1<n;++i)
			{
				for(int j=1;j<m;++j)
				{
					if(ch[i][j]=='0'&&ch[i+1][j]=='0')
					{
						resc=((long long)cnt[i][j+1]*sum[i+2][j]+resc)%mod;
					}
				}
			}
		}
		if(f==1)
		{
			memset(sum,0,sizeof(sum));
			for(int j=1;j<=m;++j)
			{
				int len=0;
				for(int i=n;i>0;--i)
				{
					if(ch[i][j]=='0')
					{
						sum[i][j]=((long long)cnt[i][j+1]*len+sum[i+1][j])%mod;
						++len;
					}
					else len=0;
				}
			}
			for(int i=1;i<n;++i)
			{
				for(int j=1;j<m;++j)
				{
					if(ch[i][j]=='0'&&ch[i+1][j]=='0')
					{
						resf=((long long)cnt[i][j+1]*sum[i+2][j]+resf)%mod;
					}
				}
			}
		}
		printf("%d %d\n",resc,resf);
	}
	return 0;
}
