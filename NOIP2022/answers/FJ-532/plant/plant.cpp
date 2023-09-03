#include <bits/stdc++.h>
using namespace std;
const int maxn=1005,mod=998244353;
typedef long long ll;
char a[maxn][maxn];
ll t,n,m,id,c,f,line[maxn][maxn],col[maxn][maxn],sum[maxn][maxn];
ll ans1,ans2;
int main(){
	freopen("plant.in","r",stdin);
	freopen("plant.out","w",stdout);
	scanf("%d%d",&t,&id);
	while(t--){
		ans1=0;
		ans2=0;
		memset(line,0,sizeof(line));
		memset(col,0,sizeof(col));
		memset(sum,0,sizeof(sum));
		scanf("%d%d%d%d",&n,&m,&c,&f);
		for(int i=1;i<=n;i++){
			for(int j=1;j<=m;j++){
				cin >>a[i][j];
			}
		}
		if(c==0&&f==0){
			printf("0 0\n");
		}
		for(int i=1;i<=n;i++){
			for(int j=m;j>=1;j--){
				if(j==m) continue;
				if(a[i][j]=='1'||a[i][j+1]=='1') continue;
				line[i][j]=line[i][j+1]+1;
			}
		}
		for(int j=1;j<=m;j++){
			for(int i=n;i>=1;i--){
				sum[i][j]=sum[i+1][j]+line[i][j];
//				cout <<i<<" "<<j<<" "<<sum[i][j]<<endl;
				if(i==n) continue;
				if(a[i][j]=='1') continue;
				col[i][j]=col[i+1][j]+1;
				//cout <<i<<" "<<j<<" "<<col[i][j]<<endl;
			}
		}
		//cout <<endl;
		for(int i=1;i<=n;i++){
			for(int j=1;j<=m;j++){
				ll r_max=line[i][j],d_max=col[i][j];
				//cout <<i<<" "<<j<<" ";
//				cout <<sum[i+2][j]-sum[d_max+i+1][j]<<" ";
				ll cnt=(r_max*(sum[i+2][j]-sum[d_max+i+1][j]))%mod;
				ll cnt2=(r_max*(sum[i+2][j]-sum[d_max+i][j]))%mod;
				if(d_max<=1) cnt=0;
				if(d_max<=1) cnt2=0;
				//cout <<cnt<<endl;
				if(c==1) ans1=(ans1+cnt)%mod;
				if(f==1) ans2=(ans2+cnt2)%mod;
			}
		}
		cout <<ans1<<" "<<ans2<<endl;
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
