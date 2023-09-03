#include<cstdio>
#include<cstdlib>
#include<iostream>
#include<bitset>
#include<vector>
#include<string>
#include<algorithm>
#include<cstdint>
#include<bitset>

struct Solution {
	void solve() {
		int id,n;
		std::cin>>id>>n;
		std::vector<std::uint64_t>a(n+1),b(n+1);
		for(int i=1; i<=n; i++) std::cin>>a[i];
		for(int i=1; i<=n; i++) std::cin>>b[i];
		int q;
		std::cin>>q;
		while(q--) {
			std::uint64_t ans=0;
			int l,r;
			std::cin>>l>>r;
			for(int p=l; p<=r; p++)
				for(int q=p; q<=r; q++)
					ans+=
					    *std::max_element(a.begin()+p,a.begin()+q+1)*
					    *std::max_element(b.begin()+p,b.begin()+q+1);
			std::cout<<ans<<'\n';
		}
	}
};

#define FileIO_qwq(name) \
	freopen(#name".in","r",stdin),\
	freopen(#name".out","w",stdout);

int main() {
	FileIO_qwq(match);

	Solution sol;
	sol.solve();

	return 0;
}
