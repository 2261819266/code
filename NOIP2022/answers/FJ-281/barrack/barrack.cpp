/*思路
记录每个边双的点数 k1,k2...kn
令 xi=2^ki-1
答案为 ∑{i=1...n} ∑任选 i 个 x 之积*2^(m-树上路径长) （但是不会求啊啊啊）
*/


// 这份代码时间复杂度不对并且写法假了，只有边双个数不超过 2 时正确。。 
#include<cstdio>
#include<cstdlib>
#include<iostream>
#include<bitset>
#include<vector>
#include<string>
#include<algorithm>
#include<stack>

template<class T>
struct Solution {
	static constexpr int N=5e5+10,M=3e6+10;
	Solution():hd(N),to(M),nx(M),dfn(N),low(N) {}

	std::vector<int>hd,to,nx;
	int etot=2;  // 便于标记割边
	void addEdge(int u,int v) {
		nx[etot]=hd[u];
		to[etot]=v;
		hd[u]=etot;
		etot++;
	}

	std::vector<int>dfn,low;
	std::bitset<M>evis; // 不能走反向边，所以要标记
	std::bitset<M>cut; // 割边标记
	int tartot=0;
	void tarjan(int u) {
		dfn[u]=low[u]=++tartot;
		for(int e=hd[u],v=to[e]; e; v=to[e=nx[e]])
			if(!evis[e]) {
				evis[e^1]=1; // 反向边标记（无向图 Tarjan 真麻烦）
				if(dfn[v])
					low[u]=std::min(low[u],dfn[v]);
				else {
					tarjan(v);
					low[u]=std::min(low[u],low[v]);
					if(low[v]>dfn[u])  // 不是割点！是割边！！不能 >=！！！
						cut[e]=cut[e^1]=1;
				}
			}
	}

	std::bitset<N>pvis; // dfs 连通块的 vis 标记
	std::vector<T>bs;  // 2^边双的点数-1
	int dfs(int u) {
		pvis[u]=1;
		int res=1;
		for(int e=hd[u],v=to[e]; e; v=to[e=nx[e]])
			if(!cut[e]&&!pvis[v]) // 割边不能走
				res+=dfs(v);
		return res;
	}

	// 这分治像极了线段树，干脆叫 build 算了
	std::vector<T> build(int l,int r) { // 左闭右开
		std::vector<T> res(r-l+1);
		res[0]=1;
		if(r-l==1)
			res[1]=bs[l];
		else {
			int mid=l+r>>1;
			auto v1=build(l,mid),v2=build(mid,r);
			for(int i=1; i<=r-l; i++) //这里怎么优化啊啊啊啊
				for(int j=std::max(0,i-(r-mid)); j<=mid-l; j++)
					res[i]+=v1[j]*v2[i-j];
		}
		return res;
	}

	void solve() {
		int n,m;
		std::cin>>n>>m;

		for(int i=1; i<=m; i++) {
			int u,v;
			std::cin>>u>>v;
			addEdge(u,v),addEdge(v,u);
		}
		tarjan(1);  // 题目保证图连通，良心（
		for(int i=1; i<=n; i++)
			if(!pvis[i]) // 发现新连通块（边双）
				bs.push_back(T(2).pow(dfs(i))-T(1));
		auto v=build(0,bs.size());
		T ans;
		for(int i=1; i<=bs.size(); i++)
			ans+=v[i]*T(2).pow(m-i+1);
		std::cout<<ans.v;
	}
};

struct ModInt {
	static constexpr int mod=1e9+7;
	long long v;

	ModInt():v(0) {}
	ModInt(const int &x):v((x%mod+mod)%mod) {}
	ModInt(const long long &x):v((x%mod+mod)%mod) {}
	ModInt(const ModInt &x):v(x.v) {}

	friend ModInt operator+(const ModInt &a,const ModInt &b) {
		return ModInt(a.v+b.v);
	}
	friend ModInt operator-(const ModInt &a,const ModInt &b) {
		return ModInt(a.v-b.v);
	}
	friend ModInt operator*(const ModInt &a,const ModInt &b) {
		return ModInt(a.v*b.v);
	}

	void operator=(const int &x) {
		v=(x%mod+mod)%mod;
	}
	void operator+=(const ModInt &x) {
		v=(v+x.v)%mod;
	}
	void operator*=(const ModInt &x) {
		v=(v*x.v)%mod;
	}

	ModInt pow(int b) {
		ModInt res(1);
		for(ModInt tmp(v); b; tmp*=tmp,b>>=1)
			if(b&1)
				res*=tmp;
		return res;
	}
};

#define FileIO_qwq(name) \
	freopen(#name".in","r",stdin),\
	freopen(#name".out","w",stdout);

int main() {
	FileIO_qwq(barrack);

	std::cin.tie(nullptr);
	std::ios::sync_with_stdio(false);

	Solution<ModInt> sol;
	sol.solve();

	return 0;
}
