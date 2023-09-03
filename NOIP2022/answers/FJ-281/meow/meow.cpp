#include<cstdio>
#include<cstdlib>
#include<iostream>
#include<bitset>
#include<vector>
#include<string>
#include<algorithm>
#include<bitset>

struct Solution {
	static constexpr int K=1e3+10,No=1,Up=2,Down=3;
	void solve() {
		int n,m,k;
		scanf("%d%d%d",&n,&m,&k);
		std::vector<int>stat(k+1);
		std::vector<std::pair<int,int>>ans;
		while(m--) {
			int a;
			scanf("%d",&a);
			if(stat[a]==Up) {
				stat[a]=No;
				ans.push_back(std::make_pair((a-1)%(n-1)+1,0));
			} else if(stat[a]==Down) {
				stat[a]=No;
				ans.push_back(std::make_pair(n,0));
				ans.push_back(std::make_pair((a-1)%(n-1)+1,n));
			} else {
				stat[a]=Up;
				ans.push_back(std::make_pair((a-1)%(n-1)+1,0));
				int ano=a>=n?a-(n-1):a+(n-1);
				if(stat[ano]==Up)
					stat[ano]=Down;
			}
		}
		printf("%d\n",ans.size());
		for(auto i:ans)
			if(i.second)
				printf("2 %d %d\n",i.first,i.second);
			else
				printf("1 %d\n",i.first);
	}
};

#define FileIO_qwq(name) \
	freopen(#name".in","r",stdin),\
	freopen(#name".out","w",stdout);

int main() {
	FileIO_qwq(meow);

	int T;
	std::cin>>T;
	while(T--) {
		Solution sol;
		sol.solve();
	}

	return 0;
}
