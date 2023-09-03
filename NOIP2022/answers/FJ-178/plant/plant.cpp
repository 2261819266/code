#include<bits/stdc++.h>
#define ll long long
using namespace std;
const ll N=1005,mod=998244353;
ll T,id,n,m,c,f,vc,vf,len_m[N][N],len_n[N][N];
char a[N][N];
void ab(){
//	for(int i=1;i<=n;i++)
//		for(int j=1;j<=m;j+=3){
//			if(a[i][j]=='1') continue;
//			vc=(vc+len_m[i][j]*len_m[i][j+1]*)%mod;
//		}
//	}
}
void init(){
	for(int i=1;i<=n;i++){
		int pos=1;
		for(int j=1;j<=m;j++){
			if(a[i][j]=='0'&&j!=m) continue;
			for(int k=pos;k<=j;k++){
				len_m[i][k]=j-k-1;
				if(j==m&&a[i][j]=='0') len_m[i][k]++;
			}
			if(a[i][j]=='1') len_m[i][j]=0;
			pos=j+1;
		}
	}
	for(int j=1;j<=m;j++){
		int pos=1;
		for(int i=1;i<=n;i++){
			if(a[i][j]=='0'&&i!=n) continue;
			for(int k=pos;k<=i;k++){
				len_n[k][j]=i-k-1;
				if(i==n&&a[i][j]=='0') len_n[k][j]++;
			}
			if(a[i][j]=='1') len_n[i][j]=0;
			pos=i+1;
		}
	}
}
void work(){
	for(int i=1;i<=n-1;i++){
		for(int j=1;j<=m-1;j++){
			if(a[i][j]=='1'||a[i+1][j]=='1') continue;
//			cout<<i<<" "<<j<<endl;
			for(int k=i+2;a[k][j]!='1'&&k<=n;k++){
//				cout<<i<<" "<<j<<" "<<k<<" "<<endl;
				vc=(vc+len_m[k][j]*len_m[i][j])%mod;
				vf=(vf+len_m[k][j]*len_m[i][j]*len_n[k][j])%mod;
			}
		}
	}
}
int main(){
	freopen("plant.in","r",stdin);
	freopen("plant.out","w",stdout);
	cin>>T>>id;
	while(T--){
		vc=vf=0;
		cin>>n>>m>>c>>f;
		for(int i=1;i<=n;i++)
			for(int j=1;j<=m;j++){
				cin>>a[i][j];
			}
	init();
	if(n>300||m>300) ab();
	else work();
//	for(int i=1;i<=n;i++){
//		for(int j=1;j<=m;j++) cout<<len_m[i][j]<<" ";
//		cout<<endl;
//	}
//	cout<<endl;
//	for(int i=1;i<=n;i++){
//		for(int j=1;j<=m;j++) cout<<len_n[i][j]<<" ";
//		cout<<endl;
//	}
	printf("%lld %lld\n",c*vc,f*vf);
	}
	return 0;
}
