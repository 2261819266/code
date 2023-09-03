#include <bits/stdc++.h>

using namespace std;

const int N = 4e6 + 3;

int T,n,m,k;
int a[N];
int opt[N],optc[N],optv[N];

void solve(){
	//int cnt = 0;
	cin>>n>>m>>k;
	for(int i = 1;i<=m;i++){
		cin>>a[i];
	}
	cout<<m<<endl;
	for(int i = 1;i<=m;i++){
		cout<<1<<" "<<1<<endl;
	}
}

int main(){
	freopen("meow.in","r",stdin);
	freopen("meow.out","w",stdout);
	cin>>T;
	while(T--){
		solve();
	}
	return 0;
}
