#include<cstdio>
#include<cmath>
#include<cstring>
#include<algorithm>
#include<iostream>
using namespace std;
typedef long long ll;
const int inf = 0x3f3f3f3f, R = 998244353;

int id, n, m, c, f;
ll dp[1009][1009], dp2[1009][1009], p_sum[1009][1009], p_sum2[1009][1009];
bool unav[1009][1009];

int main(){
	freopen("plant.in", "r", stdin); freopen("plant.out", "w", stdout);

	int T;
	cin>>T>>id;
	while(T--){
		cin>>n>>m>>c>>f;
		for(int i=1; i<=n; i++){
			for(int j=1; j<=m; j++){
				char inp;
				cin>>inp;
				unav[i][j] = inp=='1';
			}
		}
		for(int i=1; i<=n; i++){
			dp[i][m+1]=0;
			for(int j=m; j>=1; j--){
				if(unav[i][j]){
					dp[i][j] = 0;
				} else{
					dp[i][j] = dp[i][j+1]+1;
				}
			}
		}
		for(int i=1; i<=n; i++){
			for(int j=1; j<=m; j++){
				p_sum[i][j]=(p_sum[i-1][j]+dp[i][j])%R;
			}
		}
		for(int i=1; i<=m; i++){
			dp2[n+1][i]=0;
		}
		for(int i=n; i>=1; i--){
			for(int j=1; j<=m; j++){
				if(unav[i][j]){
					dp2[i][j] = 0;
				} else{
					dp2[i][j] = dp2[i+1][j]+1;
				}
			}
		}
		for(int k=1; k<=n; k++){
			for(int j=1; j<=m; j++){
				p_sum2[k][j] = (p_sum2[k-1][j] + dp[k][j+1]*dp2[k+1][j]%R)%R;
			}
		}
		ll res_c=0, res_f=0;
		for(int i=1; i<=n; i++){
			for(int j=1; j<=m; j++){
				if(dp2[i][j]<=2){
					continue;
				}
				res_c=(res_c + (p_sum[i+dp2[i][j]-1][j+1] - p_sum[i+1][j+1] + R)%R * dp[i][j+1]%R)%R;
//				for(int k=i+2; k<=i+dp2[i][j]-1; k++){
//					res_f=(ll)(res_f + dp[i][j+1]*dp[k][j+1]%R * dp2[k+1][j]%R)%R;
//				}
				res_f=(res_f + (p_sum2[i+dp2[i][j]-1][j] - p_sum2[i+1][j] + R)%R * dp[i][j+1]%R)%R;
			}
		}
		cout<<c*res_c%R<<" "<<f*res_f%R<<"\n";
	}
	
	return 0;
}
// 10:23 通过所有样例。 
