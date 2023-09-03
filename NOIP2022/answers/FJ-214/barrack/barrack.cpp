#include<bits/stdc++.h>
using namespace std;
#define f(i,a,b) for(int i = a; i <= b; i++)
#define int long long
//怎么找桥啊我透！！！！！
//我应该把e-dcc的板子打一遍的。。。。。。
//啊啊啊啊啊啊啊啊啊啊啊啊啊啊啊啊！！！！ 
typedef pair<int,int> pii;
int n, m; 
int head[500010], nxt[2000010], to[2000010], br[2000010];
vector<int> t[500010]; int vcnt = 0;
int dfn[500010], low[500010]; int dcnt = 0;
int bridge = 0;
int bl[500010]; //每个点属于哪一个分量 
int ccnt=0; int sz[500010];
void add(int x, int y) {
	nxt[vcnt] = head[x]; to[vcnt] = y; head[x] = vcnt;++vcnt;
	nxt[vcnt] = head[y]; to[vcnt] = x; head[y] = vcnt;++vcnt;
	
}
/*
566228251?????????????
*/
void dfs(int x, int fa) {
	dfn[x]=++dcnt;low[x]=dfn[x];
//	for(pii jj : g[x]) {
	for(int jj = head[x]; jj!=-1;jj=nxt[jj]){
		int j = to[jj];
	//	cout <<j<<endl;
		if(!dfn[j]) {
			dfs(j, x);
			
			low[x]=min(low[x],low[j]);
		//	cout<< j<<" "<<x<< " "<<low[j]<<" "<<low[x]<<endl;
			if(low[j] > dfn[x]) {
				bridge++; 
			//	cout<<x<<" "<<j<<"bridge"<<endl;
				//jj.second = 1;
				br[jj]=br[(jj^1)]=1;
			}
		}
		else {
			if(fa != j)low[x]=min(low[x],low[j]);
		}
	}
}
void cf(int x, int k) {
//	cout<<x<<" "<<k<<endl;
	bl[x] = k;
	//for(pii jj : g[x]){
	for(int jj = head[x]; jj!=-1;jj=nxt[jj]){
	//	if(jj.second==1)continue;
		if(br[jj])continue;
		int j = to[jj];
	//	cout << x<<" "<<j<<"expand\n";
		if(!bl[j])cf(j, k);
	}
}
const int mod = 1000000007;
int dp[500010][2];
int pow2[2000010];
void ddp(int i, int fa) {
	dp[i][0]=1;
	dp[i][1] = pow2[sz[i]]-1;
	dp[i][1] = (dp[i][1] % mod + mod) % mod;
	for(int j : t[i]) {
		if(j == fa ) continue;
		ddp(j, i); 
		dp[i][0] = (dp[i][0] % mod* (dp[j][0] % mod* 2 % mod + dp[j][1] % mod* 2 % mod)) % mod;
		dp[i][1] = (dp[i][1] % mod* (dp[j][0] % mod* 2 % mod + dp[j][1] % mod) % mod) % mod;
	}
//	cout << i << " "<<fa<<" "<< dp[i][0] <<" "<<dp[i][1]<<endl;
}
signed main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	freopen("barrack.in","r",stdin);
	freopen("barrack.out","w",stdout);
	memset(head, -1, sizeof(head));
	cin >> n >> m;
	pow2[0] = 1;
	f(i,1,2*m)pow2[i]=pow2[i-1]% mod*2%mod;
//	f(i,1,100)cout<<pow2[i]<<" ";
	f(i,1,m){
		int u,v;cin>>u>>v;
//		g[u].push_back({v,0});
	//	g[v].push_back({u,0});
		add(u, v);
	}
	dfs(1, 0);
	f(i,1,n){
		if(!bl[i]){
			++ccnt;
			cf(i,ccnt);
		}
	}
	f(i,1,n){
		for(int jj = head[i]; jj!=-1;jj=nxt[jj]){
			int j=to[jj];
			if(br[jj] == 0) continue;
			int x = bl[i], y = bl[j];
			t[x].push_back(y);
		}
	}
	f(i,1,n)sz[bl[i]]++;
//	cout <<bridge<<endl;
//	f(i ,1 ,n) if(!bl[i])cout<<"shit\n";//cout << bl[i] << " \n"[i==n];
//	f(i,1,bridge+1)cout<<sz[i]<<" \n"[i==bridge+1];
	ddp(1, 0);
	int ans  = dp[1][0] + dp[1][1];
	ans %= mod;
	ans *= pow2[m - bridge];
	ans %= mod;
	ans = ((ans - pow2[m]) % mod + mod) % mod;
	cout << ans << endl;
	return 0;
}
/*
4 4
1 2
2 3
3 1
1 4

3 3
1 3
2 3
2 1

7 9
1 2
1 3
1 4
2 3
4 7
4 5
5 6
5 7
7 6

14 18
6 8
8 9
10 9
10 8
11 8
11 10
1 2
1 3
2 3
2 4
3 5
11 12
10 12
5 7
5 6
7 6
12 13
13 14

*/
