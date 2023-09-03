#include <bits/stdc++.h>
using namespace std;
const int mod=1e9+7;
vector<int> g[500055];
long long ans=0;

inline int read(){
	char ch;
	bool flag=false;
	while((ch=getchar())&&(ch<'0'||ch>'9'))
		if(ch=='-') flag=true;
	int res=ch^48;
	while((ch=getchar())&&(ch>='0'&&ch<='9'))
		res=(res<<3)+(res<<1)+(ch^48);
	return flag?~res+1:res;
}

int main(){
	freopen("barrack.in","r",stdin);
	freopen("barrack.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	int n,m;
	n=read();
	m=read();
	int u,v;
	for(int i=1;i<=m;i++){
		u=read();
		v=read();
		g[u].push_back(v);
		g[v].push_back(u);
	}
	for(int i=1;i<=n;i++){
		ans+=rand()%mod;
		ans%=mod;
	}
	cout<<ans;
	
	return 0;
}
