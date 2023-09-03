#include<bits/stdc++.h>
using namespace std;
long long a[1001][1001];
long long b[1001][1001];
long long d[1001][1001];
long long ans,cnt;
long long mod=998244353;
int main(){
	freopen("plant.in","r",stdin);
	freopen("plant.out","w",stdout);
	int T,id;
	scanf("%d%d",&T,&id);
//	cin>>T>>id;
	while(T--){
		int n,m;
		ans=0;
		cnt=0;
		int c,f;
	//	cin>>n>>m>>c>>f;
		scanf("%d%d%d%d",&n,&m,&c,&f);
		if(c==0&&f==0){
			printf("0 0\n");
		//	cout<<0<<" "<<0<<endl;
			continue;
		}
		for(int i=1;i<=1000;i++)
			for(int l=1;l<=1000;l++)a[i][l]=b[i][l]=0;
		char s[10001];
		for(int i=1;i<=n;i++){
			scanf("%s",s+1);
			for(int l=1;l<=m;l++){
				if(s[l]=='0')a[i][l]=0;
				else a[i][l]=1;
			}
		}
		for(int i=1;i<=n;i++){
			int q=0;
			for(int l=m;l>=1;l--){
				if(a[i][l]==0){
					b[i][l]=q;
					q++;
				}
				else{
					b[i][l]=-1;
					q=0;
				}
			}
		}
		
		for(int l=1;l<=m;l++){
			int q=0;
			for(int i=n;i>=1;i--){
				if(a[i][l]==0){
					d[i][l]=q;
					q++;
				}
				else {
					d[i][l]=-1;
					q=0;
				}
			}
		}
		for(int i=1;i<=m;i++){
			for(int l=1;l<=n;l++){
				while(b[l+1][i]==-1||b[l][i]==-1)l++;
				for(int j=l+2;j<=n&&b[j][i]!=-1;j++){
					ans+=b[l][i]*b[j][i];
					ans%=mod;
					if(d[j][i]!=-1){
						cnt+=b[l][i]*b[j][i]*d[j][i];
						cnt%=mod;
					}
				}
			}
		}
		printf("%lld %lld\n",ans*c,cnt*f);
	}
}
