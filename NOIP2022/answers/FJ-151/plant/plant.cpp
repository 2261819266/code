#include<bits/stdc++.h>
using namespace std;
#define ll long long

const int N=1e3+5,mod=998244353;
int T,id,n,m;
ll ylc[N][N],g[N][N][2],h[N][N],c,f,ansc,ansf;
bool a[N][N];

int read(){
	int x=0,fs=1; char ch=getchar();
	while(ch<'0'||ch>'9'){if(ch=='-') fs=-1; ch=getchar();}
	while(ch>='0'&&ch<='9') x=x*10+ch-'0',ch=getchar(); 
	return x*fs;
}

int main(){
	freopen("plant.in","r",stdin);
	freopen("plant.out","w",stdout);
	T=read(); id=read();
	while(T--){
		n=read(); m=read(); c=read(); f=read();
		ansc=0; ansf=0;
		for(int i=1;i<=n;i++){
			char ch=getchar();
			while(ch<'0'||ch>'1') ch=getchar();
			for(int j=1;j<=m;j++) a[i][j]=ch-'0',ch=getchar();
			
			ylc[i][m+1]=0;
			for(int j=m;j>=1;j--){
				if(a[i][j]){ylc[i][j]=0; continue;}
				else ylc[i][j]=ylc[i][j+1]+1;
				if(ylc[i][j]){
					g[i+1][j][0]=ylc[i][j]-1; g[i+1][j][1]=(g[i][j][0]+g[i][j][1])%mod; h[i+1][j]=h[i][j];
					ansc=(ansc+g[i][j][1]*(ylc[i][j]-1))%mod;
					h[i+1][j]=(h[i+1][j]+g[i][j][1]*(ylc[i][j]-1))%mod;
					ansf=(ansf+h[i][j])%mod;
				}
			}
		}
		printf("%lld %lld\n",c*ansc%mod,f*ansf%mod);
		for(int i=1;i<=n;i++) for(int j=1;j<=m;j++) ylc[i][j]=g[i][j][0]=g[i][j][1]=h[i][j]=0,a[i][j]=0;
	}
	return 0;
}
