#include<bits/stdc++.h>
#define ll long long
#define int ll
using namespace std;
inline int read()
{
	int x(0),f(1);char c=getchar();
	while(c<'0'||c>'9')f=c=='-'?-1:1,c=getchar();
	while(c<='9'&&c>='0')x=x*10+c-48,c=getchar();
	return f*x;
}
const int N=1010,mod=998244353,dv2=499122177;
bool ST;
bool mp[N][N];
int rht[N][N],sm[N][N];//rht:xiangyou geshu;sm:xiangxia qianzhuihe
char ch[N];
bool ED;
signed main()
{
	freopen("plant.in","r",stdin);freopen("plant.out","w",stdout);
	cerr<<(&ED-&ST)/1024.0/1024.0<<endl;
	int T=read(),id=read();
	while(T--)
	{
//		cerr<<T;
		int n=read(),m=read();bool c=read(),f=read();
		for(int i=1;i<=n;i++)
		{
			scanf("%s",ch+1);
			for(int j=1;j<=m;j++)mp[i][j]=ch[j]-'0';
		}
		for(int i=1;i<=n;i++)
		{
			for(int j=m;j>=1;j--)
			if(mp[i][j])rht[i][j]=0;
			else rht[i][j]=rht[i][j+1]+1;
		}
		for(int j=1;j<=m;j++)for(int i=1;i<=n;i++)
		{
			if(rht[i][j])rht[i][j]--,sm[i][j]=(rht[i][j]+sm[i-1][j]);
			else sm[i][j]=0;
		}
//		for(int i=1;i<=n;i++)
//		{
//			for(int j=1;j<=m;j++)cerr<<rht[i][j]<<" ";
//			cerr<<endl;
//		}
//		for(int i=1;i<=n;i++)
//		{
//			for(int j=1;j<=m;j++)cerr<<sm[i][j]<<" ";
//			cerr<<endl;
//		}
		if(c)
		{
			int ansc=0;
			for(int j=1;j<=m;j++)
			{
				int squm=0,suqe=0,smul=0;//squm:\sum (a^2) suqe:\(sum a) smul:\sum a_i*a_{i+1}
				for(int i=1;i<=n;i++)
				{
					if(mp[i][j])ansc=(ansc+((1ll*suqe*suqe%mod-squm+mod)%mod*dv2%mod-smul+mod)%mod)%mod,squm=suqe=smul=0;
					else squm=(squm+1ll*rht[i][j]*rht[i][j]%mod)%mod,suqe=(suqe+rht[i][j])%mod,smul=(smul+1ll*rht[i][j]*rht[i-1][j]%mod)%mod;	
//					cerr<<i<<" "<<j<<" "<<squm<<" "<<suqe<<" "<<smul<<endl;
				}
				ansc=(ansc+((1ll*suqe*suqe%mod-squm+mod)%mod*dv2%mod-smul+mod)%mod)%mod,squm=suqe=smul=0;
			}
			printf("%lld ",ansc);	
		}
		else printf("0 ");
		if(f)
		{
			int ansf=0;
			for(int j=1;j<=m;j++)
			{
				int cnt=0,nans=0,hans=0;
				for(int i=1;i<=n;i++)
				{
					if(mp[i][j])ansf=(ansf+(1ll*cnt*nans%mod-hans+mod)%mod)%mod,cnt=nans=hans=0;
					else 
					{
						cnt++;
						if(cnt>2)hans=(hans+1ll*rht[i][j]*sm[i-2][j]%mod*cnt%mod)%mod,nans=(nans+1ll*rht[i][j]*sm[i-2][j]%mod)%mod;
					}
//					cerr<<i<<" "<<j<<" "<<cnt<<" "<<nans<<" "<<hans<<endl;
				}
				ansf=(ansf+(1ll*cnt*nans%mod-hans+mod)%mod)%mod,cnt=nans=hans=0;
			}
			printf("%lld ",ansf);
		}
		else printf("0 ");
		puts("");
		for(int i=1;i<=n;i++)for(int j=1;j<=m;j++)rht[i][j]=sm[i][j]=0;
	}
	return 0;
}