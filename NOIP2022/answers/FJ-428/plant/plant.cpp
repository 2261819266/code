#include<bits/stdc++.h>
using namespace std;
char s[1001];
bool a[1001][1001];
long long f_[1001];
long long sum_c[1001],mod=998244353;
int main(){
	freopen("plant.in","r",stdin);
	freopen("plant.out","w",stdout);
	long long T,id,n,m,c,f;
	scanf("%lld%lld",&T,&id);
	while(T--)
	{
		memset(sum_c,0,sizeof(sum_c));
		scanf("%lld%lld%lld%lld",&n,&m,&c,&f);
		for(long long i=1;i<=n;i++)
		{
			scanf("%s",s+1);
			for(long long j=1;j<=m;j++)
			a[i][j]=s[j]-'0';
		}
		if(c==0&&f==0){printf("0 0\n");continue;}
		for(long long i=1;i<=n;i++)
		if(a[i][1])f_[i]=0;
		else f_[i]=f_[i-1]+1;
		long long cv=0,fv=0;
		for(long long i=3;i<=n;i++)
		{
			if(a[i][1]||a[i][2])continue;
			for(long long j=i-f_[i]+1;j<=i-2;j++)
				if(!a[j][2]){
					cv=(((cv%mod)+1)%mod+mod)%mod;
					sum_c[i]=(((sum_c[i]%mod)+1)%mod+mod)%mod;
				}
		}
		for(long long i=4;i<=n;i++)
		{
			for(long long j=i-f_[i]+1;j<=i-1;j++)
			{
				fv=((fv+sum_c[j])%mod+mod)%mod;
			}
		}
		printf("%lld %lld\n",(cv%mod+mod)%mod,(fv%mod+mod)%mod);
	}
	return 0;
}
