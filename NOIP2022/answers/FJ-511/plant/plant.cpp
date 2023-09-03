#include <bits/stdc++.h>
using namespace std;
int T,id,c,f,n,m,a[1002][1002],sumx[1002][1002];
const int shu=998244353;
int main(){
	freopen("plant.in","r",stdin);
	freopen("plant.out","w",stdout);
	cin>>T>>id;
	while(T--){
		char q;
		cin>>n>>m>>c>>f;
		for(int i=1;i<=n;i++)
			for(int j=1;j<=m;j++){
				cin>>q;
				if(q=='0') a[i][j]=0;
				else a[i][j]=1;
			}
		for(int i=1;i<=n;i++){
			int pos=m;
			for(int j=m;j>=1;j--){
				if(a[i][j]==0) sumx[i][j]=pos-j+1;
				else sumx[i][j]=0,pos=j-1;
			}
		}
		if(c==0) cout<<0<<' ';
		else{
			long long ans=0,num=0;
			for(int j=1;j<=m;j++){
				for(int i=n-2;i>=1;i--){
					if(a[i][j]==0&&a[i+1][j]==0&&a[i+2][j]==0) num+=sumx[i+2][j+1],num%=shu,ans+=num*sumx[i][j+1],ans%=shu;
					else num=0;
				}
			}
			cout<<ans<<' ';
		}
		if(f==0) cout<<0<<endl;
		else{
			long long ans=0,num=0,cnt=0;
			for(int j=1;j<=m;j++){
				for(int i=n-3;i>=1;i--){
					if(a[i][j]==0&&a[i+1][j]==0&&a[i+2][j]==0&&a[i+3][j]==0) cnt++,num+=sumx[i+2][j+1]*cnt,num%=shu,ans+=num*sumx[i][j+1],ans%=shu;
					else num=0,cnt=0;
				}
			}
			cout<<ans<<endl;
		}
	}
	return 0;
}
