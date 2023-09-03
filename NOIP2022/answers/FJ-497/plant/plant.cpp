#include<bits/stdc++.h>
using namespace std;
const int maxn=1001,maxx=998244353;
int t,id,n,m,ansc[maxn],ansf[maxn],s,gt[maxn][maxn],fin[maxn][maxn];
bool c,f,maps[maxn][maxn];
char a;
int main(){
	freopen("plant.in","r",stdin);
	freopen("plant.out","w",stdout);
	cin>>t>>id;
	for(int x=1;x<=t;x++){
		cin>>n>>m>>c>>f;
		for(int i=1;i<=n;i++){
			for(int j=1;j<=m;j++){
				cin>>a;
				if(a=='0') maps[j][i]=1;
				else{
					maps[j][i]=0;
					gt[j][i]=0;
					fin[j][i]=0;
					s=j-1;
					while(s>0&&maps[s][i]!=0){
						gt[s][i]=j-s-1;
						s--;
					}
					s=i-1;
					while(s>0&&maps[j][s]!=0){
						fin[j][s]=i-1;
						s--;
					}
				}	
			}
		}
		for(int i=1;i<=n;i++){
			for(int j=m;j>=1;j--){
				if(maps[j][i]==0)break;
				gt[j][i]=m-j;
			}
		}
		for(int i=1;i<=m;i++){
			for(int j=n;j>=1;j--){
				if(maps[i][j]==0)break;
				fin[i][j]=n;
			}
		}	
		ansc[x]=0;
		ansf[x]=0;
		if(c||f){
			for(int i=1;i<=n-1;i++){
				for(int j1=1;j1<=m-2;j1++){
					if(maps[i+1][j1]&&maps[i][j1]&&maps[i][j1+1]){
						for(int j2=j1+2;j2<=fin[i][j1];j2++){
							s=(gt[i][j1]*gt[i][j2])%maxx;
							if(f&&j2!=fin[i][j1]) ansf[x]=(s*(fin[i][j1]-j2)%maxx+ansc[x])%maxx;
							if(c) ansc[x]=(s+ansc[x])%maxx;
						}
					}
				}
			}
		}
	}
	for(int x=1;x<=t;x++){
		cout<<ansc[x]<<" "<<ansf[x]<<"\n";
	}
	return 0;	
}
