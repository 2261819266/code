#include <bits/stdc++.h>
using namespace std;
#define ll long long
const int N   = 5e5+10;
const int p = 1e9+7;
vector<int> g[N];

int main(){
	
	freopen("barrack.in","r",stdin);
	freopen("barrack.out","w",stdout);
	int n, m;
	scanf("%d%d", &n, &m);
	for(int i=0;i<m;i++){
		int u, v;
		scanf("%d%d", &u, &v);
		g[u].push_back(v), g[v].push_back(u);
	}
	if(m==(n-1)){
		
		
	}else{//baoli
		
	}
	return 0;
}
