#include<bits/stdc++.h>
using namespace std;
const int mod=998244353;
string s[1010];
int a[1010][1010],b[1010][1010];
int main(){
	freopen("plant.in","r",stdin);
	freopen("plant.out","w",stdout);
	ios::sync_with_stdio(0);
	int t,id;
	cin>>t>>id;
	while(t--){
		if(id==1){
			cout<<0<<" "<<0<<endl;
			continue;
		}
		int n,m,c,f;
		cin>>n>>m>>c>>f;
		for(int i=1;i<=n;i++){
			cin>>s[i];
			s[i]="0"+s[i];
			b[n+1][i]=n+1;
			a[i][m+1]=m+1;
		}
		for(int i=n;i>=1;i--){
			for(int j=m;j>=1;j--){
				b[i][j]=b[i+1][j];
				if(s[i][j]=='1'){
					b[i][j]=i;
				}
				a[i][j]=a[i][j+1];
				if(s[i][j]=='1'){
					a[i][j]=j;
				}
			}
		}
		long long C=0,F=0;
		for(int i=1;i<=n-2;i++){
			for(int j=i+2;j<=n;j++){
				for(int k=1;k<=m-1;k++){
					if(b[i][k]==b[j][k]&&(a[j][k]-k-1)>0&&(a[i][k]-k-1)>0&&(b[j][k]-j-1)>0){
						C=(C+(1ll*(a[i][k]-k-1)*(a[j][k]-k-1)%mod))%mod;
						F=(F+((1ll*(a[i][k]-k-1)*(a[j][k]-k-1)%mod)*(b[j][k]-j-1)%mod))%mod;
						//cout<<(a[i][k]-k-1)<<" "<<(a[j][k]-k-1)<<" "<<(b[j][k]-j-1)<<endl;
					}
				}
			}
		}
		/*
		for(int i=1;i<=n;i++){
			for(int j=1;j<=m;j++){
				cout<<a[i][j]<<" ";
			}
			cout<<endl;
		}
		for(int i=1;i<=n;i++){
			for(int j=1;j<=m;j++){
				cout<<b[i][j]<<" ";
			}
			cout<<endl;
		}
		*/
		cout<<C*c%mod<<" "<<F*f%mod<<'\n';
	}
	return 0;
}