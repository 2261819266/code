#include<bits/stdc++.h>
using namespace std;
#define ll long long

const int N=3e3+5;
int T,n,m,Q;
unsigned ll zd1[N][N],zd2[N][N],a[N],b[N],dp[N][N];

int read(){
	int x=0,fs=1; char ch=getchar();
	while(ch<'0'||ch>'9'){if(ch=='-') fs=-1; ch=getchar();}
	while(ch>='0'&&ch<='9') x=x*10+ch-'0',ch=getchar(); 
	return x*fs;
}



int main(){
	freopen("match.in","r",stdin);
	freopen("match.out","w",stdout);
	T=read(); n=read();
	for(int i=1;i<=n;i++) a[i]=read();
	for(int i=1;i<=n;i++) b[i]=read();
	Q=read();
	for(int i=1;i<=n;i++){
		for(int j=i;j<=n;j++){
			zd1[i][j]=max(zd1[i][j-1],a[j]);
		}
	}
	for(int i=1;i<=n;i++){
		for(int j=i;j<=n;j++){
			zd2[i][j]=max(zd2[i][j-1],b[j]);
		}
	}
//	for(int len=1;len<=n;len++){
//		for(int i=1;i+len-1<=n;i++){
//			int j=i+len-1;
//			dp[i][j]=zd1[i][j]*zd2[i][j];
//		}
//	}
//	for(int len=2;len<=n;len++){
//		for(int i=1;i+len-1<=n;i++){
//			int j=i+len-1;
//			dp[i][j]=zd1[i][j]*zd2[i][j];
//		}
//	}
	for(int i=1;i<=Q;i++){
		unsigned ll res=0;
		int l=read(),r=read();
		for(int p=l;p<=r;p++){
			for(int q=p;q<=r;q++){
				res=(res+zd1[p][q]*zd2[p][q]);
			}
		}
//		cout<<res<<"\n";
		printf("%llu\n",res);
	}
	return 0;
}
