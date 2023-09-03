#include<bits/stdc++.h>
using namespace std;
#define f(i,a,b) for(int i = a; i <= b; i++)
#define int long long
char c[1010][1010];
int dwn[1010][1010], rgt[1010][1010];
const int mod =  998244353;
signed main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	freopen("plant.in","r",stdin);
	freopen("plant.out","w",stdout);
	int T,id;cin>>T>>id;
	while(T--) {
		int n,m,C,F;cin>>n>>m>>C>>F;
		int cans=0,fans=0;
		f(i,0,n+9)f(j,0,m+9)rgt[i][j]=dwn[i][j]=0;
		f(i,1,n)f(j,1,m)cin>>c[i][j];
		//为0直接输出0就是了
		f(i,1,n)for(int j=m;j>=1;j--){
			if(c[i][j]=='1'){
				rgt[i][j]=0;
			}
			else {
				rgt[i][j] = rgt[i][j+1]+1;
			}
		}
		f(j,1,m)for(int i=n;i>=1;i--){
			if(c[i][j]=='1'){
				dwn[i][j]=0;
			}
			else {
				dwn[i][j]=dwn[i+1][j]+1;
			}
		}
	//	f(i,1,n)f(j,1,m)cout<<rgt[i][j]<<" \n"[j==m];
		f(j,1,m){
			int qz=0;
			for(int i=n;i>=1;i--){
				if(c[i][j]=='1'){
					qz=0; 
					continue;
				}
				if(i+1<=n&&c[i+1][j]=='0')cans += ((qz-(rgt[i+1][j]-1))*(rgt[i][j]-1)%mod);
				cans%=mod;
				qz+=(rgt[i][j]-1);
			}
		}
		f(j,1,m){
			int qzz=0;
			for(int i=n;i>=1;i--){
				if(c[i][j]=='1'){
					qzz=0;
					continue;
				}
				if(i+1<=n&&c[i+1][j]=='0')fans+=((qzz-((rgt[i+1][j]-1)*(dwn[i+1][j]-1)))*(rgt[i][j]-1)%mod);
				fans%=mod;
				qzz+=(rgt[i][j]-1)*(dwn[i][j]-1);
			}
		}
	//	f(i,1,n)f(j,1,m)cout<<rgt[i][j]<<" \n"[j==m];
	
		cout<<(C*cans)<<" "<<(F*fans)<<endl;
	}
	return 0;
}

