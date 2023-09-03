/*The truth is with you!*/
# include <bits/stdc++.h>
# define MAX (1009)
# define ll long long
# define inf (0x3f3f3f3f)
const int mod=998244353;
int n,m,c,f,mp[MAX][MAX],nx[MAX][MAX],mu[MAX][MAX];
ll vc,vf,sm[MAX][MAX],fsm[MAX][MAX];
char ch[MAX];
int read() {
	int f=1,x=0;
	char ch=0;
	while('0'>ch||ch>'9') {
		if(ch=='-')f=-1;
		ch=getchar();
	}
	while('0'<=ch&&ch<='9') {
		x=x*10+ch-'0';
		ch=getchar();
	}
	return f*x;
}
ll upd(ll a) {
	if(a<0)return 0;
	return a;
}
int main() {

	freopen("plant.in","r",stdin);
	freopen("plant.out","w",stdout);

	int _=read();
	read();
	while(_--) {
		n=read();
		m=read();
		c=read();
		f=read();
		vc=vf=0;
		memset(mp,0,sizeof(mp));
		memset(nx,0,sizeof(nx));
		memset(mu,0,sizeof(mu));
		memset(sm,0,sizeof(sm));
		memset(fsm,0,sizeof(fsm));
		int i,j;
		for(i = 1; i <= n; i++) {
			scanf("%s",ch+1);
			for(j = 1; j <= m; j++) {
				if(ch[j]=='0')mp[i][j]=0;
				else mp[i][j]=1;
			}
		}
		if(c==0&&f==0) {
			puts("0 0");
			continue;
		}
		for(i = 1; i <= n; i++) {
			for(j = m-1; j >= 1; j--) {
				if(mp[i][j]||mp[i][j+1])nx[i][j]=0;
				else nx[i][j]=nx[i][j+1]+1;
			}
		}
		for(j = 1; j <= m; j++) {
			for(i = n-1; i >= 1; i--) {
				if(mp[i][j]||mp[i+1][j])mu[i][j]=0;
				else mu[i][j]=mu[i+1][j]+1;
			}
		}
		for(i = 1; i <= n+1; i++) {
			for(j = 1; j <= m; j++) {
				sm[i][j]=(sm[i-1][j]+nx[i][j])%mod;
				fsm[i][j]=(fsm[i-1][j]+1ll*nx[i][j]*mu[i][j])%mod;
			}
		}
		for(i = 1; i <= n; i++) {
			for(j = 1; j <= m; j++) {
				(vc+=upd(sm[i+mu[i][j]][j]-sm[i+1][j])*nx[i][j]%mod)%=mod;
				(vf+=upd(fsm[i+mu[i][j]-1][j]-fsm[i+1][j])*nx[i][j]%mod)%=mod;
			}
		}
		vc=((vc%mod)+mod)%mod;
		vf=((vf%mod)+mod)%mod;
		printf("%lld %lld\n",vc*c,vf*f);
	}

	fclose(stdin);
	fclose(stdout);

	return 0;
}
