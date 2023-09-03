/*
114514114514114514114514114514114514114514114514114514114514
114514114514114514114514114514114514114514114514114514114514
114514114514114514114514114514114514114514114514114514114514
114514114514114514114514114514114514114514114514114514114514
114514114514114514114514114514114514114514114514114514114514
114514114514114514114514114514114514114514114514114514114514
114514114514114514114514114514114514114514114514114514114514
114514114514114514114514114514114514114514114514114514114514
114514114514114514114514114514114514114514114514114514114514
114514114514114514114514114514114514114514114514114514114514

[62,80] + 0 + [15,25] + 20 = [97, 135]
*/


#include <bits/stdc++.h>

using namespace std;

#define rep(i,l,r) for(int i=(l);i<=(r);i++)
const int N = 1005;
const int mod = 998244353;

int T,id;
bool a[N][N];
int s1[N][N],s2[N][N];
int okmx[N][N];

int main() {
	freopen("plant.in", "r", stdin);
	freopen("plant.out", "w", stdout);
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	cin>>T>>id;
	long long ans1=0,ans2=0;
	while (T--) {
		int n, m, c, f;
		cin>>n>>m>>c>>f;
		rep(i,1,n){
			rep(j,1,m){
				char ch;cin>>ch;
				a[i][j]=ch-'0';
			}
		}
		memset(okmx,0,sizeof(okmx));
		ans1=ans2=0;
	//	rep(i,1,n)rep(j,1,m)s1[i][j]=s1[i][j-1]+a[i][j];
	//	rep(i,1,m)rep(j,1,n)s2[j][i]=s2[j-1][i]+a[j][i];
		rep(i,1,n)rep(j,1,m) {
			int tmpj=j;
			if(okmx[i][j-1]&&a[i][j]==0) {
				okmx[i][j]=okmx[i][j-1]-1;
				continue;
			}
			while(tmpj<=m&&a[i][tmpj]==0) okmx[i][j]++, tmpj++;
		}
		rep(i,1,n)rep(j,1,m){ // zuoshang
			if(a[i][j])continue;
			int tmpi=i;
			int ok1 = okmx[i][j]-1;
			while(tmpi<=n&&a[tmpi][j]==0)tmpi++;
			tmpi--;
			for(int k=i+2;k<=tmpi;k++){
				int ok2 = okmx[k][j]-1;
				int ok3=tmpi-k;
				ans1=(ans1+ok1*ok2%mod)%mod;
				ans2=(ans2+(1ll*ok1*ok2%mod)*ok3%mod)%mod;
//				cout << ok1 << " " <<  ok2 << " " << ok3 << endl;
//				cout << ans1*c << " " << ans2*c << endl;
			}
		}
		cout << ans1*c << " " << ans2*f << '\n';
	}
	
	return 0;
}
