#include<bits/stdc++.h>
using namespace std;
#define int __int128
const int MAX=3e5+10;
bool fi;
int T,n,q,a[MAX],b[MAX],mod=1;
int Log2[MAX];
int f[MAX][21],g[MAX][21];
int sum[3010][3010];
int tot[3010][3010];
int ans;
bool se;
inline int read(){
	int x=0,f=1; char ch=getchar();
	while(ch<'0'||ch>'9'){if(ch=='-') f=-1; ch=getchar();}
	while(ch>='0'&&ch<='9'){x=(x<<1)+(x<<3)+ch-48; ch=getchar();}
	return x*f;
}
void write(int x){
	if(x<0)
	    x=-x,putchar('-');
	if(x/10)
	    write(x/10);
	putchar(x%10+'0');
}
int getmaxf(int l,int r){
	int k=Log2[r-l+1];
	return max(f[l][k],f[r-(1<<k)+1][k]);
}
int getmaxg(int l,int r){
	int k=Log2[r-l+1];
	return max(g[l][k],g[r-(1<<k)+1][k]);
}
signed main(){
//	system("fc match.out match3.ans");
	freopen("match.in","r",stdin);
	freopen("match.out","w",stdout);
//    cerr<<(&se-&fi)/1024.0/1024.0;
    for(register int i=1; i<=64; i++){
        mod*=2;
	}
	T=read(),n=read();
    Log2[0]=-1;
	for(register int i=1; i<=n; i++)
	    a[i]=read(),f[i][0]=a[i],Log2[i]=Log2[i>>1]+1;
	for(register int i=1; i<=n; i++)
	    b[i]=read(),g[i][0]=b[i];
	for(register int i=1; i<=20; i++)
	    for(register int j=1; j+(1<<i)-1<=n; j++)
	        f[j][i]=max(f[j][i-1],f[j+(1<<(i-1))][i-1]),
	        g[j][i]=max(g[j][i-1],g[j+(1<<(i-1))][i-1]);
	for(register int i=1; i<=n; i++)
	    for(register int j=i; j<=n; j++)
	        sum[i][j]=getmaxf(i,j)*getmaxg(i,j)%mod,
	        tot[i][j]=(tot[i][j-1]+sum[i][j])%mod;
	q=read();
	while(q--){
		ans=0;
		int l=read(),r=read();
		for(register int i=l; i<=r; i++){
			ans=(ans+tot[i][r]-tot[i][l-1]+mod)%mod;
		}
		write(ans);
		puts("");
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
