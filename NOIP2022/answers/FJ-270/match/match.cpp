#include<bits/stdc++.h>
#define rep(i,l,r) for(int i=(l);i<(r);i++)
#define per(i,l,r) for(int i=(r)-1;i>=(l);i--)
using i64=long long;
template<class T>void chkMin(T &x,const T &y) {if(y<x)x=y;}
template<class T>void chkMax(T &x,const T &y) {if(y>x)x=y;}
std::ifstream fin("match.in");std::ofstream fout("match.out");
const int N=3050;
int n;
unsigned long long a[2][N];
unsigned long long max[2][N][N],ans[N][N];
void solve() {
	rep(i,1,n+1) fin>>a[0][i];
	rep(j,1,n+1) fin>>a[1][j];
	rep(id,0,2) rep(i,1,n+1) rep(j,1,n+1) max[id][i][j]=0;
	rep(id,0,2)
		rep(j,1,n+1) {
			max[id][j][j]=a[id][j];
			rep(k,j+1,n+1)
				max[id][j][k]=std::max(max[id][j][k-1],a[id][k]);
		}
	rep(i,1,n+1) rep(j,1,n+1) ans[i][j]=max[0][i][j]*max[1][i][j];
//	std::cout<<ans[1][2]<<' '<<ans[1][1]<<' '<<ans[2][2]<<" "<<ans[2][1]<<"\n";
	rep(len,2,n+1)
		rep(j,1,n+1) {
			int r=j+len-1;
			if(r>n) break;
			ans[j][r]+=ans[j+1][r]+ans[j][r-1]-ans[j+1][r-1];
		}
	int q;fin>>q;
	while(q--) {
		int l,r;fin>>l>>r;
		fout<<ans[l][r]<<"\n";
	}
}
int main() {
	int t;fin>>t>>n;
	solve();
	return 0;
}
