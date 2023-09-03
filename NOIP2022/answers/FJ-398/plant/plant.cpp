#include<bits/stdc++.h>
#define ULL unsigned long long
using namespace std;
const int MAX=1005,MOD=998244353;
ULL t,id,n,m,c,f,ansc,ansf,a[MAX][MAX],ycl[MAX][MAX],fcl[MAX][MAX],qzh[MAX][MAX],fzh[MAX][MAX];
/*
ycl[i][j]表示[i,j]往右数连续几个没有土坑
flc[i][j]表示[i,j]往下数连续几个没有土坑 
*/
string str;
int main(){
	freopen("plant.in","r",stdin);
	freopen("plant.out","w",stdout);
	cin>>t>>id;
	for(int s=1;s<=t;s++){
		ansc=0,ansf=0;
		cin>>n>>m>>c>>f;
		for(int i=1;i<=n;i++){
			cin>>str;
			for(int j=0;j<m;j++){
				a[i][j+1]=str[j]-'0';
			}
		}
		for(int i=1;i<=n;i++){
			int cnt=m+1;
			for(int j=m;j>=1;j--){
				if(a[i][j])cnt=j;
				ycl[i][j]=cnt-j;
			}
		}
		for(int j=1;j<=m;j++){
			int cnt=n+1;
			for(int i=n;i>=1;i--){
				if(a[i][j])cnt=i;
				fcl[i][j]=cnt-i;
			}
		}
		for(int i=1;i<=n;i++){
			for(int j=1;j<=m;j++){
				qzh[i][j]=qzh[i-1][j];
				if(ycl[i][j]>0)qzh[i][j]+=ycl[i][j]-1;
			}
		}
		for(int i=1;i<=n;i++){
			for(int j=1;j<=m;j++){
				fzh[i][j]=fzh[i-1][j];
				if(ycl[i][j]>0&&fcl[i][j]>0)fzh[i][j]+=(ycl[i][j]-1)*(fcl[i][j]-1);
			}
		}
		for(int j=1;j<=m;j++){
			for(int i=1;i<=n-2;i++){
				int x2=i+fcl[i][j]-1;
				if(x2<i+2)continue;
				if(ycl[i][j]>0)ansc=(ansc+(ycl[i][j]-1)*(qzh[x2][j]-qzh[i+1][j]))%MOD;
			}
		}
		for(int j=1;j<=m;j++){
			for(int i=1;i<=n-3;i++){
				int x2=i+fcl[i][j]-1;
				if(x2<i+3)continue;
				if(ycl[i][j]>0)ansf=(ansf+(ycl[i][j]-1)*(fzh[x2-1][j]-fzh[i+1][j]))%MOD;
			}
		}
		cout<<(ansc*c)%MOD<<' '<<(ansf*f)%MOD<<endl;
	}
	return 0;
}
