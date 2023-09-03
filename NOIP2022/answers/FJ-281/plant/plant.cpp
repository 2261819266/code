#include<cstdio>
#include<cstdlib>
#include<iostream>
#include<bitset>
#include<vector>
#include<string>
#include<algorithm>

template<class T>
struct Solution {
	static constexpr int M=2e3+10;
	void solve(int id) {
		int n,m,c,f;
		std::cin>>n>>m>>c>>f;
		std::vector<std::bitset<M>>a(n);
		std::vector<std::vector<T>>
		                         rt(n,std::vector<T>(m)),
		                         dw(n,std::vector<T>(m));
		for(int i=0; i<n; i++) {
			std::string str;
			std::cin>>str;
			std::reverse(str.begin(),str.end());
			a[i]=std::bitset<M>(str);
		}

		// 求右边和下面能抵达多少个
		for(int i=0; i<n; i++)
			for(int j=m-1,la=m; j>=0; j--) {
				if(a[i][j])la=j;
				rt[i][j]=la-j-1;
			}
		for(int j=0; j<m; j++)
			for(int i=n-1,la=n; i>=0; i--) {
				if(a[i][j])la=i;
				dw[i][j]=la-i-1;
			}

		T ans_c,ans_f;
		for(int j=0; j<m; j++) {
			T sum;
			for(int i=0; i<n; i++) {
				if(a[i][j]) {
					sum=0; // 重新计数
					continue;
				}
				if(i>=2&&!a[i-1][j]&&!a[i-2][j])
					sum+=rt[i-2][j]; // 起点数量（C的右上角）
				ans_c+=sum*rt[i][j]; // 起点数量*右边终点数量
				ans_f+=sum*rt[i][j]*dw[i][j]; //起点数量*右边终点数量*下面终点数量
			}
		}
		// 记得乘 c、f 啊啊啊啊啊！（本题最大的坑）
		ans_c*=T(c),ans_f*=T(f);
		std::cout<<ans_c.v<<' '<<ans_f.v<<'\n'; // 多组数据！！！
	}
};

struct ModInt {
	static constexpr int mod=998244353;
	long long v;

	ModInt():v(0) {}
	ModInt(const int &x):v((x%mod+mod)%mod) {}
	ModInt(const long long &x):v((x%mod+mod)%mod) {}
	ModInt(const ModInt &x):v(x.v) {}

	friend ModInt operator+(const ModInt &a,const ModInt &b) {
		return ModInt(a.v+b.v);
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
};

#define FileIO_qwq(name) \
	freopen(#name".in","r",stdin),\
	freopen(#name".out","w",stdout);

int main() {
	FileIO_qwq(plant);

	std::cin.tie(nullptr);
	std::ios::sync_with_stdio(false);

	int T,id;
	std::cin>>T>>id;
	while(T--) {
		Solution<ModInt> sol;
		sol.solve(id);
	}

	return 0;
}
