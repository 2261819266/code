#include "bits/stdc++.h"
using namespace std;

int T,id,n,m;
long long Vc,Vf;
int a[1010][1010],he[1010][1010],zo[1010][1010];
const long long mod=998244353;

long long read() {
	char c=getchar();
	long long re=0;
	while (c<'0' || c>'9') c=getchar();
	while (c>='0' && c<='9') re=re*10+c-'0',c=getchar();
	return re; 
}

int main() {
	freopen("plant.in","r",stdin);
	freopen("plant.out","w",stdout);
	
	T=read(),id=read();
	while (T--) {
		Vc=0,Vf=0,n=read(),m=read();
		int c=read(),f=read();
		for (int i=1;i<=n;i++) {
			string str;
			cin>>str;
			for (int j=0;j<m;j++) a[i][j+1]=str[j]-'0';
		}
		for (int i=n;i>=1;i--) {
			for (int j=m;j>=1;j--) {
				if (j==m || a[i][j]==1) {
					he[i][j]=0;
				} else {
					if (a[i][j+1]==0) he[i][j]=he[i][j+1]+1;
					else he[i][j]=0;
				}
				if (i==n || a[i][j]==1) {
					zo[i][j]=0;
				}  else {
					if (a[i+1][j]==0) zo[i][j]=zo[i+1][j]+1;
					else zo[i][j]=0;
				}
			}
		}
				
		for (int j=1;j<=m-1;j++) {
			int totc=0;
			for (int i=1;i<=n-2;i++) {
				if (zo[i][j]<2) {
					totc=0;
					continue;
				}
				totc+=he[i][j];
				Vc=(Vc+totc*he[i+2][j]%mod)%mod;
				Vf=(Vf+totc*he[i+2][j]*zo[i+2][j]%mod)%mod;
			}
		}
		printf("%lld %lld\n",Vc*c,Vf*f);
	}
	
	return 0;
}
