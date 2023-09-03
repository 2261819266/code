#include<bits/stdc++.h>
using namespace std;
int main(){
	//freopen("plant.in","r",stdin);
	//freopen("plant.out","w",stdout);
	int tt,dd;
	scanf("%d%d",&tt,&dd);
	while(tt--){
		long long n,c,d,m,mod=998244353,ans=0,anss=0;
		bool a[1004][1004]={};
		string b;
		scanf("%d%d%d%d",&n,&m,&c,&d);
		for(int i=1;i<=n;i++){
			cin>>b;
			for(int j=0;j<m;j++){
				if(b[j]=='0'){
					a[i][j+1]=true;
				}
			}
			a[i][m+1]=false;
		}
		for(int i=1;i<=m;i++)a[n+1][i]=false;
		for(int i=1;i<n-1;i++){//cout<<u<<" "<<g<<endl;
			for(int j=1;j<m;j++){
				bool l=true;
				if(!a[i][j]||!a[i+1][j]||!a[i+2][j]||!a[i][j+1])continue;
				int u,g,t;
				for(int k=j+1;k<=m+1;k++){
					if(!a[i][k]){
						u=k-j-1;
						break;
					}
				}//
				for(int h=3;i+h-1<=n;h++){
					if(!a[i+h-1][j])l=false;
					if(!l)break;
					for(int k=j+1;k<=m+1;k++){
						if(!a[i+h-1][k]){
							g=k-j-1;
							break;
						}
					}
					ans+=u*g;
					if(ans>=mod)ans%=mod;
					for(int k=i+h;k<=n+1;k++){
						if(!a[k][j]){
							t=k-i-h;
						}
					}
					anss+=u*g*t;
					if(anss>=mod)anss%=mod;
				}
			}
		}
		ans=(ans*c)%mod,anss=(anss*d)%mod;
		printf("%d %d",ans,anss);
	}
	return 0;
}
