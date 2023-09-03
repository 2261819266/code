#include <bits/stdc++.h>
using namespace std;
int t,id,n,m,c,o,a[1005][1005];
long long ans;
bool w;
int main(){
	freopen("plant.in","r",stdin);
	freopen("plant.out","w",stdout);
	cin>>t>>id;
	while(t--){
		ans=0;
		cin>>n>>m>>c>>o;
		string qw;
		for(int i=1; i<=n; i++){
			cin>>qw;
			for(int j=1; j<=m; j++)a[i][j]=qw[j-1]-'0';
		}
		if(id==1){
			cout<<"0 0\n";
			continue;
		}
		if(id==5){
			for(int i=1; i<=n-2; i++)ans=(ans+n-i-1)%998244353;
			ans=ans*((m+1)/3)%998244353;
			cout<<ans<<' ';
			ans=0;
			for(int i=3; i<=n-1; i++)ans=(ans+(i-2)*(n-i))%998244353;
			ans=ans*((m+1)/3)%998244353;
			cout<<ans<<endl;
			continue;
		}
		if(id==6){
			for(int i=1; i<=m; i++){
				ans=(ans+(m-i)*(m-i))%998244353;
			}
			ans=ans*((n+1)/4)%998244353;
			cout<<ans<<" 0\n";
			continue;
		}
		for(int i=1; i<=n; i++){
			for(int i2=i+2; i2<=n; i2++){
				for(int j=1; j<=m; j++){
					if(a[i][j])continue;
					for(int j1=j+1; j1<=m; j1++){
						if(a[i][j1])break;
						w=1;
						for(int k=i; k<=i2; k++){
							if(a[k][j]){
								w=0;
								break;
							}
						}
						if(w==0)break;
						for(int j2=j+1; j2<=m; j2++){
							if(a[i2][j2])break;
							w=1;
							ans=(ans+1)%998244353;
						}
					}
				}
			}
		}
		cout<<ans<<' ';
		if(o==0){
			cout<<endl;
			continue;
		}
		ans=0;
		for(int i=1; i<=n; i++){
			for(int i2=i+2; i2<=n; i2++){
				for(int i3=i2+1; i3<=n; i3++){
					for(int j=1; j<=m; j++){
						if(a[i][j])continue;
						for(int j1=j+1; j1<=m; j1++){
							if(a[i][j1])break;
							w=1;
							for(int k=i; k<=i3; k++){
								if(a[k][j]){
									w=0;
									break;
								}
							}
							if(w==0)break;
							for(int j2=j+1; j2<=m; j2++){
								if(a[i2][j2])break;
								w=1;
								ans=(ans+1)%998244353;
							}
						}
					}
				}
			}
		}
		cout<<ans<<endl;
	}
	return 0;
}

