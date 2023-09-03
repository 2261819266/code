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
	freopen("meow.in","r",stdin);
	freopen("meow.out","w",stdout);
}
const int M=2e6+10;
const int K=610;
int T,n,m,k,a[M],c[2*M][3],cnt=0;
int b[K][2];
signed main(){
	fl();
	T=read();
		while(T--){
			n=read(),m=read(),k=read();
			For(i,1,m,1) a[i]=read();
			For(i,1,m,1){
				int x=(a[i]+1)/2;
				if(!b[x][0]){
					c[++cnt][0]=1,c[cnt][1]=x;
					b[x][0]=a[i];
				}
				else if(b[x][0]&&(!b[x][1])&&b[x][0]!=a[i]){
					c[++cnt][0]=1,c[cnt][1]=x;
					c[++cnt][0]=1,c[cnt][1]=x;
					b[x][1]=b[x][0];
					b[x][0]=a[i];
				}
				else if(b[x][0]&&b[x][1]&&b[x][0]!=a[i]){
						c[++cnt][0]=1,c[cnt][1]=n;
						c[++cnt][0]=2,c[cnt][1]=x,c[cnt][2]=n;
					b[x][1]=0;
				}
				else if(b[x][0]&&(!b[x][1])&&b[x][0]==a[i]){
						c[++cnt][0]=1,c[cnt][1]=x;
					b[x][0]=0;
				}
				else if(b[x][0]&&b[x][1]&&b[x][0]==a[i]){
						c[++cnt][0]=1,c[cnt][1]=x;
					b[x][0]=0;
				}
			}
		}
		cout<<cnt<<endl;
	For(i,1,cnt,1){
		if(c[i][0]==1){
			cout<<c[i][0]<<' '<<c[i][1]<<endl;
		}
		else cout<<c[i][0]<<' '<<c[i][1]<<' '<<c[i][2]<<endl;
	}
	return 0;
}

