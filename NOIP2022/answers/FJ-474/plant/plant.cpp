#include<bits/stdc++.h>
using namespace std;
int t,n,m,c,f,id,flag;
int g[1120][1120],kh[1120][1120];
long long dp[1120][1120];
int h,mod,d;
long long cans,fans,fshu;
char ch;
int main() {
	freopen("plant.in","r",stdin);
	freopen("plant.out","w",stdout);
	mod=998244353;
	scanf("%d%d",&t,&id);
	for(int y=1;y<=t;y++){
	cans=0;
	fans=0;
	fshu=0;
	scanf("%d%d%d%d",&n,&m,&c,&f);
	for(int i=1;i<=n;i++){
		for(int j=m-1; j>=1; j--) {
			dp[i][j]=0;
		}
	}
	for(int i=1; i<=n; i++) {
		for(int j=1; j<=m; j++) {
			ch=getchar();
			for(; ch=='\n'||ch=='\r'||ch==' ';) {
				ch=getchar();
			}
			g[i][j]=ch-'0';
		}
	}
	for(int i=1; i<=n; i++) {
		for(int j=m-1; j>=1; j--) {
			if(g[i][j]==0&&g[i][j+1]==0) {
				dp[i][j]=dp[i][j+1]+1;
			}
		}
	}
	for(int j=1; j<=m-1; j++) {
		for(int i=1; i<=n; i++) {
			if(g[i][j]) {
				h++;
				kh[j][h]=i;
			}
		}
		h++;
		kh[j][h]=n+1;
		h=0;
	}
	if(c) {
		for(int j=1; j<=m-1; j++) {
			d=1;
			for(int i=1; i<=n-2; i++) {
				if(!g[i+1][j]) {
					while(i+2>=kh[j][d]) {
						d++;
					}
					for(int k=i+2; k<kh[j][d]; k++) {
						cans+=dp[i][j]*dp[k][j];
					}
				}
			}
			cans=(cans+mod)%mod;
		}
		printf("%lld ",cans);
	} else {
		printf("0 ");
	}
	if(f) {
		for(int j=1; j<=m-1; j++) {
			d=1;
			for(int i=1; i<=n-3; i++) {
				if((!g[i+1][j])&&(dp[i][j])) {
					while(i+2>=kh[j][d]) {
						d++;
					}
					for(int k=i+2; k<kh[j][d]-1; k++) {
						fshu+=dp[i][j]*dp[k][j];
					}
					fshu=fshu*(kh[j][d]-i-3);
					fans+=fshu;
					fshu=0;				
					fans=(fans+mod)%mod;
				}	
			}
		}
		printf("%lld\n",fans);
	} else {
		printf("0\n");
	}}
	return 0;
}
