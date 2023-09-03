#include<bits/stdc++.h>
#define rep(i,l,r) for(int i=(l);i<(r);i++)
#define per(i,l,r) for(int i=(r)-1;i>=(l);i--)
using i64=long long;
template<class T>void chkMin(T &x,const T &y) {if(y<x)x=y;}
template<class T>void chkMax(T &x,const T &y) {if(y>x)x=y;}
std::ifstream fin("plant.in");std::ofstream fout("plant.out");
const int N=1050,P=998244353;
int n,m,c,f;
int r[N][N],a[N][N],sum[N][N],cntc[N][N];
void solve() {
	fin>>n>>m>>c>>f;
	rep(i,1,n+1) {std::string s;fin>>s;rep(j,1,m+1) a[i][j]=s[j-1]-'0';}
	rep(i,1,n+1)
		rep(j,1,m+1) if(a[i][j]==0) {
			int x=j;
			while (!a[i][x]&&x<=m) {r[i][j]++;x++;}
		}
//	rep(i,1,n+1) rep(j,1,m+1) fout<<a[i][j]<<" \n"[j==m];fout<<"\n";
	int ansc=0,ansf=0;
	rep(i,1,n+1)
		rep(j,1,m+1) if(!a[i][j]) {
			sum[i][j]+=sum[i-1][j]+r[i][j]-1;
		}
//	rep(i,1,n+1) rep(j,1,m+1) fout<<r[i][j]<<" \n"[j==m];fout<<"\n";
//	rep(i,1,n+1) rep(j,1,m+1) fout<<sum[i][j]<<" \n"[j==m];fout<<"\n";
	rep(i,2,n+1)
		rep(j,1,m+1) if(!a[i][j]&&r[i][j]>1&&!a[i-1][j]) {
			cntc[i][j]=i64(r[i][j]-1)*sum[i-2][j]%P;
			(ansc+=cntc[i][j])%=P;
		}
//	rep(i,1,n+1) rep(j,1,m+1) fout<<cntc[i][j]<<" \n"[j==m];fout<<"\n";
	rep(i,2,n+1) rep(j,1,m+1) if(!a[i][j]) (cntc[i][j]+=cntc[i-1][j])%=P;
	rep(i,2,n+1) rep(j,1,m+1) if(!a[i][j]) (ansf+=cntc[i-1][j])%=P;
	fout<<c*ansc<<' '<<f*ansf<<"\n";
	ansc=ansf=0;
	rep(i,1,n+1) rep(j,1,m+1) sum[i][j]=r[i][j]=0;
}
int main() {
	int t,id;
	fin>>t>>id;
	while(t--) solve();
	return 0;
}
