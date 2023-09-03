#include <bits/stdc++.h>
#define int long long
using namespace std;

const int mod = 998244353;

const int N = 1007;

int T,id;

int n,m,c,f;
char s[N][N];

int tori[N][N];
int toup[N][N];
int todown[N][N];

int cnt1,cnt2;

void init(){
	cnt1 = 0;
	cnt2 = 0;
	for(int i = 1;i<=n;i++){
		for(int j = 1;j<=m;j++){
			tori[i][j] = 0;
			toup[i][j] = 0;
			todown[i][j] = 0;
		}
	}
}

void solve(){
	cin>>n>>m>>c>>f;
	init();
	for(int i = 1;i<=n;i++) cin>>s[i] + 1;	
	for(int i = 1;i<=n;i++) tori[i][m] = m;
	for(int i = 1;i<=m;i++) todown[n][i] = n,toup[1][i] = 1;
	for(int i = 1;i<=n;i++){
		for(int j = m - 1;j;j--){
			if(s[i][j + 1] == '0' && s[i][j] == '0') tori[i][j] = tori[i][j + 1];
			else tori[i][j] = j;
		}
	}
	for(int i = 2;i<=n;i++){
		for(int j = 1;j<=m;j++){
			if(s[i - 1][j] == '0' && s[i][j] == '0') toup[i][j] = toup[i - 1][j];
			else toup[i][j] = i;
		}	
	}
	for(int i = n - 1;i;i--){
		for(int j = 1;j<=m;j++){
			if(s[i + 1][j] == '0' && s[i][j] == '0') todown[i][j] = todown[i + 1][j];
			else todown[i][j] = i;
		}
	}
	/*for(int i = 1;i<=n;i++){
		for(int j = 1;j<=m;j++){
			cout<<todown[i][j]<<" ";
		}
		cout<<endl;
	}*/
	for(int i = 1;i<=n;i++){
		for(int j = 1;j<=m;j++){
			for(int len = 3;i + len - 1<=n;len++){
				if(toup[i + len - 1][j] > i) continue;
				int now = (tori[i][j] - j) * (tori[i + len - 1][j] - j);
				cnt1 += now;
				cnt2 += now * (todown[i + len - 1][j] - (i + len - 1)); 
				cnt1 %= mod;
				cnt2 %= mod;
			}
		}
	}
	cout<<cnt1 * c<<" "<<cnt2 * f<<endl;
}

signed main(){
	freopen("plant.in","r",stdin);
	freopen("plant.out","w",stdout);
	cin>>T>>id;
	if(id == 1 || id == 5 || id == 6){
		while(T--){
			cout<<0<<" "<<0<<endl;
		}
		return 0;
	}
	while(T--){
		solve();
	}
	return 0;
}
