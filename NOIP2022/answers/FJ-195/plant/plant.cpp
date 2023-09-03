#include<bits/stdc++.h>
using namespace std;
#define mod 998244353
int a[1010][1010],lon[1010][1010],len[1010][1010],n,m,T,p,ans,down[1010][1010],r[1010][1010],l[1010][1010];
long long int ans1,ans2;
char ch;
int c,f;
void init(){
	for(int i=n;i>=1;i--){
			for(int j=m;j>=1;j--){
				if(a[i][j]==1)
				continue;
				r[i][j]=j;
				down[i][j]=i;
				if(a[i][j+1]==0&&j+1<=m){
					r[i][j]=r[i][j+1];
				}
				if(a[i+1][j]==0&&i+1<=n){
					down[i][j]=down[i+1][j];
				}
			}
		}
}
int main(){
	freopen("plant.in","r",stdin);
	freopen("plant.out","w",stdout);
	ios::sync_with_stdio(false);
	cin>>T>>p;
	while(T--){
		ans1=0;
		ans2=0;
		memset(down,0,sizeof(down));
		memset(r,0,sizeof(r));
		memset(a,0,sizeof(a));
		cin>>n>>m>>c>>f;
		for(int i=1;i<=n;i++){
			for(int j=1;j<=m;j++){
				cin>>ch;
				if(ch=='0'){
					a[i][j]=0;
				}
				else{
					a[i][j]=1;
				}
			}
		}
		init();
		for(int i=1;i<=n;i++){
			for(int j=1;j<=m;j++){
				if(down[i][j]-i>=2&&r[i][j]>j&&a[i][j]==0){
					int cnt=0;
					for(int k=i+2;k<=down[i][j];k++){
						cnt+=r[k][j]-j;
						cnt%=mod;
					}
					ans1+=((r[i][j]-j)*cnt)%mod;
					ans1%=mod;
				}
			}
		}
		for(int i=1;i<=n;i++){
			for(int j=1;j<=m;j++){
				if(down[i][j]-i>=3&&r[i][j]>j&&a[i][j]==0){
					int cnt=0;
					for(int k=i+2;k<down[i][j];k++){
						cnt+=((r[k][j]-j)*(down[i][j]-k))%mod;
					}
					ans2+=((r[i][j]-j)*cnt)%mod;
					ans2%=mod;
				}
			}
		}
		ans1=(int)(c*ans1)%mod;
		ans2=(int)(f*ans2)%mod;
		cout<<ans1<<" "<<ans2<<endl;
	}
	return 0;
}
