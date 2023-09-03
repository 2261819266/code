#include<bits/stdc++.h>
using namespace std;
const int N=1010;
const int mod=998244353;
int T,id;
int n,m,c,f,a[N][N],cnt[N][N],cntt[N][N];
char A[N][N];
long long ans1,ans2;
void solve() {
	ans1=ans2=0;
	scanf("%d%d%d%d",&n,&m,&c,&f);
	for(int i=1;i<=n;i++)
		for(int j=1;j<=m;j++) {
			cin>>A[i][j];
			a[i][j]=A[i][j]-'0';
		}
	if(c==0&&f==0) {
		printf("%lld %lld\n",ans1,ans2);
		return;
	}
	for(int i=1;i<=n;i++) cnt[i][m]=!a[i][m];
	for(int i=1;i<=m;i++) cntt[n][i]=!a[n][i];
	for(int i=n-1;i>=1;i--) {
		for(int j=m;j>=1;j--) {
			if(a[i][j]) cntt[i][j]=0;
			else cntt[i][j]=cntt[i+1][j]+1;
		}
	}
	for(int i=n;i>=1;i--) {
		for(int j=m-1;j>=1;j--) {
			if(a[i][j]) cnt[i][j]=0;
			else cnt[i][j]=cnt[i][j+1]+1;
		}
	}
	for(int i=1;i<=n-2;i++) {
		for(int j=i+2;j<=n;j++) {
			for(int k=1;k<=m;k++) {
				if(a[i][k]||a[j][k]||cntt[i][k]<j-i+1) continue;
				ans1=(ans1+(cnt[i][k]-1)*(cnt[j][k]-1))%mod;
				ans2=(ans2+(cnt[i][k]-1)*(cnt[j][k]-1)*(cntt[j][k]-1))%mod;
			}
		}
	}
	printf("%lld %lld\n",ans1,ans2);
}
int main() {
	freopen("plant.in","r",stdin);
	freopen("plant.out","w",stdout);
	scanf("%d%d",&T,&id);
	while(T--) {
		solve();
	}
	return 0;
}
