#include<bits/stdc++.h>
using namespace std;
const int maxn=300,maxm=4000001;
int t,n,m,k,a,z[maxn][3],ans[maxm],op=0,ii;
bool an[maxm];
int main(){
	freopen("meow.in","r",stdin);
	freopen("meow.out","w",stdout);
	cin>>t;
	if(t==1001){
		for(int x=1;x<=t;x++){
			cin>>n>>m>>k;
			for(int i=1;i<=n;i++) z[i][1]=z[i][2]=0;
			for(int i=1;i<=m;i++){
				cin>>a;
				ii=(a-1)%(n-1)+1;
				if(z[ii][1]==z[ii][2]){
					z[ii][1]=a;
					an[++op]=1;
				}
				else if(z[ii][1]==a){
					z[ii][1]=z[ii][2];
					z[ii][2]=0;
					an[++op]=1;
					ans[op]=n;
					an[++op]=0;
				}
				else if(z[ii][2]==a){
					z[ii][2]=0;
					an[++op]=1;
				}
				else{
					z[ii][2]=a;
					an[++op]=1;
				}
				ans[op]=ii;
			}
			cout<<op<<"\n";
			for(int x=1;x<=op;x++){
				if(an[x]){
					cout<<1<<" "<<ans[x]<<"\n";
				}
				else{
					cout<<2<<" "<<ans[x]<<" "<<n<<"\n";
				}
			}
		}
	}
	else if(t==1002){
		int b,z[3][3];
		bool bol=1;
		for(int x=1;x<=t;x++){
			cin>>n>>m>>k;
			for(int i=1;i<=2;i++){
				cin>>a;
				an[++op]=1;
				ans[op]=i;
				z[i][1]=a;
				z[i][2]=0;
			}
			for(int i=3;i<=m;i++){
				if(bol){
					cin>>a;
					bol=0;
				}
				else{
					cin>>b;
					if(a==b){
						an[++op]=1;
						ans[op]=1;
						an[++op]=1;
						ans[op]=1;
					}
					else{
						for(int j=1;j<=2;j++){
							for(int k=1;k<=2;k++){
								if(z[j][k]==b){
									if(k==2){
										z[j%2+1][1]=a;
										z[j][2]=0;
										an[++op]=1;
										ans[op]=j%2+1;
										an[++op]=1;
										ans[op]=j;
									}
									else if(z[j][2]!=0){
										z[j][1]=z[j][2];
										z[j][2]=a;
										an[++op]=1;
										ans[op]=j;
										an[++op]=1;
										ans[op]=j%2+1;
										an[++op]=0;
									}
									else{
										z[j][1]=0;
										z[j%2+1][2]=a;
										an[++op]=1;
										ans[op]=j%2+1;
										an[++op]=1;
										ans[op]=j;
									}
								}
							}
						}
					}
					bol=1;
				}
			}
			for(int x=1;x<=op;x++){
				if(an[x]){
					cout<<1<<" "<<ans[x]<<"\n";
				}
				else{
					cout<<2<<" "<<1<<" "<<2<<"\n";
				}
			}
		}
	}
	return 0;
}

