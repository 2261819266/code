#include<iostream>
#include<cstdio>
using namespace std;
int T,n,a[1000000],b[1000000],q,l,r;
int sta[100000][30],stb[100000][30],Log2[1000000];
unsigned long long ans;
unsigned long long querya(int l,int r){
	int k=Log2[r-l+1];
	return max(sta[l][k],sta[r-(1<<k)+1][k]);
}
unsigned long long queryb(int l,int r){
	int k=Log2[r-l+1];
	return max(stb[l][k],stb[r-(1<<k)+1][k]);
}
int main(){
	freopen("match.in","r",stdin);
	freopen("match.out","w",stdout);
	cin>>T>>n;
	for(int i=2;i<=n;i++){
		Log2[i]=Log2[i>>1]+1;
		//cout<<Log2[i]<<' ';
	}
	//cout<<endl;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		sta[i][0]=a[i];
	}
	for(int i=1;i<=n;i++){
		cin>>b[i];
		stb[i][0]=b[i];
	}
	for(int j=1;j<=Log2[n];j++){
		for(int i=1;i+j<=n;i++){
			sta[i][j]=max(sta[i][j-1],sta[i+(1<<(j-1))][j-1]);
		}
	}
	for(int j=1;j<=Log2[n];j++){
		for(int i=1;i+j<=n;i++){
			stb[i][j]=max(stb[i][j-1],stb[i+(1<<(j-1))][j-1]);
		}
	}
	/*for(int i=1;i<=n;i++){
		for(int j=i;j<=n;j++){
			cout<<i<<'~'<<j<<':';
			cout<<querya(i,j)<<endl;
		}
	}*/
	cin>>q;
	while(q--){
		ans=0;
		cin>>l>>r;
		for(int i=l;i<=r;i++){
			for(int j=i;j<=r;j++){
				ans+=querya(i,j)*queryb(i,j);
			}
		}
		cout<<ans<<endl;
	}
	return 0;
}
/*
0 2
2 1
1 2
1
1 2
*/
