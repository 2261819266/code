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
const ll mod = pow(2,64);
vector<int> ai, bi, ci;
int maxAi, maxBi;

// goodbye ccf
// from a senior 3 student;

int main() {
	freopen("match.in", "r", stdin);
	freopen("match.out", "w", stdout);
	int T=read();
	int n=read();
	for (int i = 0 ; i < n ; i++) {
		ai.push_back(read());
	}
	for (int i = 0 ; i < n ; i++) {
		bi.push_back(read());
	}
	int q=read();
	for (int iiiii = 0;iiiii<q;iiiii++) {
		int l=read(),r=read();
		ll ans = 0;
		for (int p=l;p<=r;p++) {
			for (int q=p;q<=r;q++) {
				ci = vector<int>(ai);
				sort(ci.begin()+p-1, ci.begin()+q);
				maxAi=ci[q-1];
				ci = vector<int>(bi);
				sort(ci.begin()+p-1, ci.begin()+q);
				maxBi=ci[q-1];
				//cout<<"A"<<maxAi<<"B"<<maxBi<<endl;
				ans = ans % mod;
				ans += ((maxAi*maxBi) % mod);
			}
		}
		cout<<ans%mod<<endl;
	}
	
	
	return 0;
}
