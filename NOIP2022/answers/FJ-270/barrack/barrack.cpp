#include<bits/stdc++.h>
#define rep(i,l,r) for(int i=(l);i<(r);i++)
#define per(i,l,r) for(int i=(r)-1;i>=(l);i--)
using i64=long long;
template<class T>void chkMin(T &x,const T &y) {if(y<x)x=y;}
template<class T>void chkMax(T &x,const T &y) {if(y>x)x=y;}
const int N=5e5+5;
std::vector<int>g[N];
int n,m;
const int P=1e9+7;
std::ifstream fin("barrack.in");std::ofstream fout("barrack.out");
int power(int a,int p) {int res=1;for(;p;p>>=1,a=i64(a)*a%P)if(p&1)res=i64(res)*a%P;return res;}
namespace Subtask1 {
const int NN=18;
bool used[NN];
int d[NN][NN];
int u[30],v[30];
void solve() {
	rep(i,0,m) {
		fin>>u[i]>>v[i];d[u[i]][v[i]]=d[v[i]][u[i]]=1;
		g[u[i]].push_back(v[i]);g[v[i]].push_back(u[i]);
	}
	int lim=1<<n,ans=0;
	rep(i,1,lim) {
		int st=0;
		std::vector<int> point;
		rep(j,0,n) if(i>>j&1) {st=j+1;point.push_back(j+1);}
		int cnt=0;
		rep(j,0,m) {
			d[u[j]][v[j]]=d[v[j]][u[j]]=0;
			std::queue<int> que;
			memset(used,0,sizeof(used));
			que.push(st);used[st]=true;
			while(!que.empty()) {
				int uu=que.front();que.pop();
				for(int vv:g[uu])
					if(!used[vv]&&d[uu][vv]) {
						used[vv]=true;que.push(vv);
					}
			}
			d[u[j]][v[j]]=d[v[j]][u[j]]=1;
//			std::cout<<i<<' '<<u[j]<<' '<<v[j]<<"\n";
//			rep(k,1,n+1) std::cout<<used[k]<<' ';
//			std::cout<<"\n";
			for(int x:point) if(!used[x]) {cnt++;break;}
		}
//		std::cout<<i<<' '<<cnt<<' '<<power(2,m)-power(2,m-cnt)+1<<"\n";
		(ans+=power(2,m-cnt))%=P;
	}
	fout<<ans<<"\n";
}
}
int main() {
	fin>>n>>m;
	if(n<=16) Subtask1::solve();
	return 0;
}
