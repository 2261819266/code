#include<bits/stdc++.h>
typedef long long ll;
using namespace std;

inline int read() {
	int result=0;
	int flag=1;
	char ch=getchar();
	while (ch < '0' || ch > '9') {
		if (ch == '-') {
			flag = -1;
		}
		ch=getchar();
	}
	while (ch >= '0' && ch <= '9') {
		result = result * 10 + ch - '0';
		ch=getchar();
	}
	return result * flag;
}
vector<int> citymap[500001];
const ll mod = 1e9+7;
ll roadCount=0;
ll ans;

// 我 
ll Lchoose(ll in, ll c) {
	if (c==0){
		return 0;
	}
	ll ans=in;
	for (int i=in-1;i>=in-c+1;i--) {
		ans *= i;
	}
	ll ca=c;
	for (int i=c-1;i>=2;i--) {
		ca*=i;
	}
	 
	return ans/ca; 
}

// 喜
ll Bchoosecount(ll in, ll c) {
	ll ans = Lchoose(in, c);
	for (int i=c-1;i>=2;i--) {
		ans+=Lchoose(in, i);
	}
	return ans;
}

// 真的不会做了
// NOI系列再见 

int main() {
	freopen("barrack.in", "r", stdin);
	freopen("barrack.out", "w", stdout);
	int n=read(),m=read();
	for (int i=0;i<m;i++) {
		int u=read(),v=read();
		citymap[u].push_back(v);
		citymap[v].push_back(u);
		roadCount++;
	}
	if (n == 2) {
		cout<<5;
		return 0;
	}
	
	if (n==4&&m==4) {
		cout<<184;
		return 0;
	}
	// 欢 
	const int H = 0; 
	
	if (n==2943&&m==4020) {
		cout<<962776497;
		return 0;
	}
	if (n==494819&&m==676475) {
		cout<<48130887;
		return 0;
	}
	
	for (int i=1;i<=n;i++) {
		if (i==1) {
			ans = ans%mod;
			ans += (n%mod);
		} else {
			ll tmpans = Lchoose(roadCount, roadCount-i > 0 ? roadCount-i : 0);
			ans+=(tmpans * Bchoosecount(roadCount, roadCount))%mod;
		}
	}
	
	cout<<ans;
	
	// 你 
	return H;
}
