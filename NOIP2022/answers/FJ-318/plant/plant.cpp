#include<iostream>
#include<cstring>
#include<cstdio>
#define ll long long
using namespace std;
const int N=1e3;
const ll mod=998244353;
ll c0[N+5][N+5],c1[N+5][N+5],c2[N+5][N+5];
ll f0[N+5][N+5],f1[N+5][N+5],f2[N+5][N+5],f3[N+5][N+5];
char a[N+5][N+5];
int main(){
	freopen("plant.in","r",stdin);
	freopen("plant.out","w",stdout);
	int T,opt;
	scanf("%d%d",&T,&opt);
	while(T--){
		int n,m,c,f;
		scanf("%d%d%d%d",&n,&m,&c,&f);
		for(int i=1;i<=n;i++)
			scanf("%s",a[i]+1);
		ll ansc=0,ansf=0;
		for(int i=n;i;i--)
			for(int j=m;j;j--){
				c0[i][j]=0;
				c1[i][j]=0;
				c2[i][j]=0;
				f0[i][j]=0;
				f1[i][j]=0;
				f2[i][j]=0;
				f3[i][j]=0;
				if(a[i][j]=='0'){
					c0[i][j]=(c0[i][j+1]+(a[i][j+1]=='0'))%mod;
					c1[i][j]=(c1[i+1][j]+c2[i+1][j])%mod;
					c2[i][j]=(c2[i][j+1]+(a[i][j+1]=='0'))%mod;
					ansc=(ansc+c0[i][j]*c1[i+1][j]);
					f0[i][j]=(f0[i][j+1]+(a[i][j+1]=='0'))%mod;
					f1[i][j]=(f1[i+1][j]+f2[i+1][j+1]*f3[i+2][j])%mod;
					f2[i][j]=(f2[i][j+1]+1)%mod;
					f3[i][j]=(f3[i+1][j]+1)%mod;
					ansf=(ansf+f0[i][j]*f1[i+1][j])%mod;
				}
			}
		ansc=ansc*c%mod;
		ansf=ansf*f%mod;
		printf("%lld %lld\n",ansc,ansf);
	}
	return 0;
}
