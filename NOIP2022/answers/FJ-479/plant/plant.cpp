#include<bits/stdc++.h>
#define int long long
//#define int unsigned long long
#define For(w,x,y,z) for(int w=(x);w<=(y);w+=(z))
#define foR(w,x,y,z) for(int w=(x);w>=(y);w-=(z))
using namespace std;
inline int read(){
	int x=0,f=1;
	char c=getchar();
	while(c<'0'||c>'9') {if(c=='-') f=-1;c=getchar();}
	while(c>='0'&&c<='9') {x=(x<<1)+(x<<3)+(c-48);c=getchar();}
	return x*f;
}
inline void write(int x){
	if(x<0) {putchar('-');x=-x;}
	if(x>9) write(x/10);
	putchar(x%10+'0');
}
inline void fl(){
	freopen("plant.in","r",stdin);
	freopen("plant.out","w",stdout);
}
const int N=1010;
const int mod=998244353;
int T,id,n,m,c,f,a[N][N],ansc=0,ansf=0;
int mx[2][N][N];
signed main(){
	fl();
	T=read(),id=read();
	while(T--){
		n=read(),m=read(),c=read(),f=read();
		ansc=ansf=0;
		memset(a,0,sizeof(a));
		For(i,1,n+1,1) For(j,1,m+1,1) mx[0][i][j]=mx[1][i][j]=0;
		if((!c)&&(!f)) {puts("0 0");continue;}
		For(i,1,n,1){
			char s[N];
			scanf("%s",s);
			For(j,0,m-1,1) if(s[j]=='1') a[i][j+1]=1;
		}
		For(i,1,n,1){
			foR(j,m,1,1){
				if(a[i][j]) mx[0][i][j]=0;
				else mx[0][i][j]=mx[0][i][j+1]+1;
			}
		}
		For(i,1,m,1){
			foR(j,n,1,1){
				if(a[j][i]) mx[1][j][i]=0;
				else mx[1][j][i]=mx[1][j+1][i]+1;
			}
		}
		For(i,1,m,1){
			int j=1;
			while(j<=n){
				while(mx[0][j][i]<2||mx[1][j][i]<2){
					++j;
					if(j>n) break;
				}
				if(j>n) break;
				int sum=0;
				For(k,j,j+mx[1][j][i]-1,1) sum+=mx[0][k][i]-1;
				For(k,j,j+mx[1][j][i]-3,1){
					sum-=(mx[0][k][i]-1);
					int summ=sum-mx[0][k+1][i]+1;
					if(!mx[0][k+1][i]) summ=sum; 
					ansc=(ansc+summ*(mx[0][k][i]-1)%mod)%mod;
				}
				j+=mx[1][j][i]-1;
			}
		}
		write(ansc),putchar(' ');
		if(!f){
			puts("0");
			continue;
		}
		For(i,1,m,1){
			int j=1;
			while(j<=n){
				while(mx[0][j][i]<2||mx[1][j][i]<2){
					++j;
					if(j>n) break;
				}
				if(j>n) break;
				int sum=0;
				For(k,j,j+mx[1][j][i]-2,1) sum+=mx[0][k][i]-1;
				foR(k,j+mx[1][j][i]-2,j,1){
					sum-=(mx[0][k][i]-1);
					int summ=sum-mx[0][k-1][i]+1;
					if(!mx[0][k-1][i]) summ=sum; 
					ansf=(ansf+summ*(mx[0][k][i]-1)%mod*(j+mx[1][j][i]-1-k)%mod)%mod;
					//cout<<k<<' '<<j+mx[1][j][i]-2<<' '<<i<<' '<<ansf<<' '<<summ<<endl;
				}
				j+=mx[1][j][i]-1;
			}
		}
		write(ansf),putchar('\n');
	}
	return 0;
}
