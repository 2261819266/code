#include<bits/stdc++.h>
using namespace std;
long long u[1005][1005],d[1005][1005],r[1005][1005];
long long t,n,m,l,cx,fx,c,f,mod=998244353ll;
string a;
bool pt[1005][1005];
int main(){
	freopen("plant.in","r",stdin);
	freopen("plant.out","w",stdout);
	cin>>t>>n;
	for(int orz=1;orz<=t;orz++){
		cin>>n>>m>>cx>>fx;c=f=0;
		for(int i=1;i<=n;i++){
			cin>>a;
			pt[i][m+1]=1;
			for(int j=0;j<m;j++)
				pt[i][j+1]=(a[j]=='1');
		}
		for(int j=1;j<=m;j++)
			pt[n+1][j]=pt[0][j]=1;
		for(int i=1;i<=n;i++)
			for(int j=m+1;j>=1;j--){
				if(pt[i][j]){l=-1;}
				r[i][j]=l;l++;
			}
		for(int j=1;j<=m;j++)
			for(int i=n+1;i>=1;i--){
				if(pt[i][j]){l=-1;}
				d[i][j]=l;l++;
			}
		for(int j=1;j<=m;j++)
			for(int i=0;i<=n;i++){
				u[i][j]=l;
				if(pt[i][j]){l=i+1;u[i][j]=114514;}
			}
		/*for(int i=1;i<=n;i++){
			for(int j=1;j<=m;j++)
				cout<<setw(3)<<r[i][j];
			cout<<endl;
		}*/
		for(int j=1;j<=m;j++){
			for(int i=1;i<=n;i++)
				r[i][j]+=r[i-1][j];
		}
		for(int j=1;j<=m;j++)
			for(int i=3;i<=n;i++)
				if(u[i][j]+1<i){
					//cout<<i<<' '<<j<<' '<<(r[i-2][j]-r[u[i][j]-1][j])*(r[i][j]-r[i-1][j])<<endl;
					c=(c+cx*(r[i-2][j]-r[u[i][j]-1][j])*(r[i][j]-r[i-1][j]))%mod;
					f=(f+fx*(r[i-2][j]-r[u[i][j]-1][j])*(r[i][j]-r[i-1][j])*d[i][j])%mod;
				}
		cout<<c<<' '<<f<<endl;
	}
	return 0;
}

