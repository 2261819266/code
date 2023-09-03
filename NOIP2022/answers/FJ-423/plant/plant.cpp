#include<bits/stdc++.h>
using namespace std;
int a[2000][2000];
string g[2000];
int main(){
	freopen("plant.in","r",stdin);
	freopen("plant.out","w",stdout);
	long long vc=0,vf=0;
	int t,id,m,n,c,f;
	cin>>t>>id;
	for(int i=1;i<=t;i++){
		cin>>n>>m>>c>>f;
		for(int j=1;j<=n;j++)cin>>g[j];
		for(int j=1;j<=n;j++)for(int k=m-1;k>=0;k--)if(g[j][k]=='0')a[j][k]=a[j][k+1]+1;
		for(int j=0;j<=m-1;j++)
			for(int k=n;k>=3;k--)
				if(a[k][j]>1){
					for(int l=k;l>=1;l--){
						if(a[l][j]==0)break;
						if(k-l>1&&a[l][j]>0){
							vc=(vc+(a[l][j]-1)*(a[k][j]-1))%998244353;
							if(g[k+1][j]=='0')for(int o=k+1;g[o][j]=='0'&&o<=n;o++)vf=(vf+(a[l][j]-1)*(a[k][j]-1))%998244353;	
						}
					}
				}
		cout<<vc*c%998244353<<' '<<vf*c%998244353<<endl;
		if(i<t){
			for(int j=1;j<=n;j++)
				for(int k=0;k<=m-1;k++)a[j][k]=0;
		}
	}
}
