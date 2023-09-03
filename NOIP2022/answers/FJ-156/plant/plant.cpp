//#include<bits/stdc++.h>
//#define F(i,a,b) for(int i=a;i<=b;++i)
//#define D(i,a,b) for(int i=a;i>=b;--i)
//#define ll long long
//using namespace std;
//bool st;
//mt19937 rnd(chrono::steady_clock::now().time_since_epoch().count());
//inline int read(){
//	int x=0,w=1;char ch=getchar();
//	for(;ch>'9'||ch<'0';ch=getchar()) if(ch=='-') w=-1;
//	for(;ch>='0'&&ch<='9';ch=getchar()) x=(x<<1)+(x<<3)+ch-'0';
//	return x*w;
//}
//const int N=1e3+10;
//const int mod=998244353;
//int T,id,f[N][N],d[N][N],a[N][N],n,m,c,ff;ll sum[N][N];
//inline void sol(){
//	n=read(),m=read(),c=read(),ff=read();
//	ll C=0,F=0;
//	memset(f,0,sizeof(f));
//	memset(d,0,sizeof(d));
//	memset(sum,0,sizeof(sum));
//	if(id==1){puts("0 0");return;}
//	F(i,1,n) {
//		char s[N];
//		scanf("%s",s);
//		F(j,1,m)a[i][j]=s[j-1]-'0';
////		F(j,1,m) printf("%d ",a[i][j]);
////		puts("");
//	}
////	printf("%d\n",a[1][3]);
//	F(i,1,n){
//		D(j,m,1){
//			if(a[i][j]==1) f[i][j]=0;
//			else f[i][j]=f[i][j+1]+1;
////			printf("%d ",f[i][j]);
//		}
////		puts("");
//	}
////	printf("%d\n",f[1][3]);
////	F(j,1,m)F(i,1,n) {
////		if(a[i][j]) d[i][j]=0;
////		else d[i][j]=d[i-1][j]+1;
////	} 
//	F(j,1,m){
//		F(i,1,n){
//			if(f[i][j]){
//				sum[i][j]=(sum[i-1][j]+f[i][j]-1)%mod;
//				if(f[i][j]>1) d[i][j]=d[i-1][j]+1;
//				else d[i][j]=d[i-1][j];
//			}
//			else sum[i][j]=0,d[i][j]=0;
//		}
//		D(i,n,2) if(f[i][j]&&d[i-1][j]>1) F=(F+(sum[i-1][j]-sum[i-2][j])*sum[i-2][j]%mod)%mod;
//	}
//	F(j,1,m) D(i,n,2) if(f[i][j]>1) C=(C+(f[i][j]-1)*sum[i-2][j]%mod)%mod;
//	printf("%lld %lld\n",C*c,F*ff);
//}
//bool ed;
//signed main(){
////	cerr<<(&st-&ed)/1024.0/1024.0<<endl;
////	freopen("plant.in","r",stdin);
////	freopen("plant.out","w",stdout);
//	T=read(),id=read();
//	while(T--) sol();
//	return 0;
//}
/*
1 0
4 3 1 1
001
010
000
000
*/
#include<bits/stdc++.h>
#define F(i,a,b) for(int i=a;i<=b;++i)
#define D(i,a,b) for(int i=a;i>=b;--i)
#define ll long long
using namespace std;
bool st;
mt19937 rnd(chrono::steady_clock::now().time_since_epoch().count());
inline int read(){
	int x=0,w=1;char ch=getchar();
	for(;ch>'9'||ch<'0';ch=getchar()) if(ch=='-') w=-1;
	for(;ch>='0'&&ch<='9';ch=getchar()) x=(x<<1)+(x<<3)+ch-'0';
	return x*w;
}
const int N=1e3+10;
const int mod=998244353;
int T,id,f[N][N],d[N][N],a[N][N],n,m,c,ff;ll sum[N][N];
inline void sol(){
	n=read(),m=read(),c=read(),ff=read();
	ll C=0,F=0;
	memset(f,0,sizeof(f));
	memset(d,0,sizeof(d));
	memset(sum,0,sizeof(sum));
	if(id==1){puts("0 0");return;}
	F(i,1,n) {
		char s[N];
		scanf("%s",s);
		F(j,1,m)a[i][j]=s[j-1]-'0';
//		F(j,1,m) printf("%d ",a[i][j]);
//		puts("");
	}
//	printf("%d\n",a[1][3]);
	F(i,1,n){
		D(j,m,1){
			if(a[i][j]==1) f[i][j]=0;
			else f[i][j]=f[i][j+1]+1;
//			printf("%d ",f[i][j]);
		}
//		puts("");
	}
//	printf("%d\n",f[1][3]);
//	F(j,1,m)F(i,1,n) {
//		if(a[i][j]) d[i][j]=0;
//		else d[i][j]=d[i-1][j]+1;
//	} 
	F(j,1,m){
		F(i,1,n){
			if(f[i][j]){
				sum[i][j]=(sum[i-1][j]+f[i][j]-1)%mod;
				if(f[i][j]>1) d[i][j]=d[i-1][j]+1;
				else d[i][j]=d[i-1][j];
			}
			else sum[i][j]=0,d[i][j]=0;
		}
		int cnt=0;
		if(!ff) break;
		D(i,n,2){
			if(f[i][j])++cnt;
			if(cnt>1&&f[i][j]>1&&d[i][j]>1) {
				F=(F+(f[i][j]-1)*sum[i-2][j]%mod*(cnt-1)%mod)%mod;
//				printf("%lld %lld %lld\n",f[i][j]-1,sum[i-2][j],cnt-1);
			}
			if(!f[i][j]) cnt=0;
		}
	}
	F(j,1,m) D(i,n,2) if(f[i][j]>1&&d[i-1][j]>0) C=(C+(f[i][j]-1)*sum[i-2][j]%mod)%mod;
	printf("%lld %lld\n",C*c,F*ff);
}
bool ed;
signed main(){
//	cerr<<(&st-&ed)/1024.0/1024.0<<endl;
	freopen("plant.in","r",stdin);
	freopen("plant.out","w",stdout);
	T=read(),id=read();
	while(T--) sol();
	return 0;
}
/*
2 0
6 6 1 1
000010
011000
000110
010000
011000
000000
4 3 1 1
001
010
000
000
*/
