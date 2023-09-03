#include<bits/stdc++.h>
#define ll long long
using namespace std;
ll read(){
	ll X = 0, f = 1;
	char ch = getchar();
	while(!isdigit(ch) && ch != '-') ch = getchar();
	if(ch == '-'){
		ch = getchar();
		f = -1;
	}
	while(isdigit(ch)){
		X = (X<<1)+(X<<3)+ch-'0';
		ch = getchar();
	}
	return f*X;
}
const int mod = 998244353;
const int N = 1010;
int n,m,c,f;
int a[N][N];
ll x[N][N],y[N][N];

int main(){
	freopen("plant.in","r",stdin);
	freopen("plant.out","w",stdout);
	int T = read(),id = read();
	while(T--){
		ll ansc  = 0 , ansf = 0;
		memset(a,0,sizeof(a));
		memset(x,0,sizeof(x));
		memset(y,0,sizeof(y));
		if(id == 1){
			puts("0 0");
			continue;
		}
		n = read(); m = read();
		c = read(); f = read();
		for(int i=1;i<=n;i++)
			for(int j=1;j<=m;j++){
				char ch;
				cin >> ch;
				a[i][j] = ch-'0';
			}
		for(int i=n;i>=1;i--){
			for(int j=m;j>=1;j--){
				if(a[i][j] == 1) continue;
				x[i][j] = x[i][j+1]+1;
				y[i][j] = y[i+1][j]+1;
			}
		}
		for(int i=1;i<=n;i++){
			for(int j=1;j<=m;j++){
				if(a[i][j] == 1) continue;
				if(a[i+1][j] == 1) continue;
				for(int k=i+2;k<=n;k++){
					if(a[k][j] == 1) break;
					ansc = (ansc+(x[i][j]-1)*(x[k][j]-1))%mod;
				}
			}
		}
		for(int i=1;i<=n;i++){
			for(int j=1;j<=m;j++){
				if(a[i][j] == 1) continue;
				if(a[i+1][j] == 1) continue;
				for(int k=i+2;k<=n;k++){
					if(a[k][j] == 1) break;
					if(a[k+1][j] == 1) break;
					ansf = (ansf+(x[i][j]-1)*(x[k][j]-1)*(y[k][j]-1))%mod;
				}
			}
		}
		cout << c*ansc%mod << " " << f*ansf%mod << "\n";
	}
	
	return 0;
}
