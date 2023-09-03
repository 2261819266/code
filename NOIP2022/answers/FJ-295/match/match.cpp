#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#define N 250005
using namespace std;
typedef long long ll;
inline ll read(){
	ll x=0,f=1;char ch=getchar();
	while(ch<'0'||ch>'9'){if(ch=='-')f=-1;ch=getchar();}
	while(ch>='0'&&ch<='9'){x=(x<<1)+(x<<3)+(ch^48);ch=getchar();}
	return x*f;
}
int T,n,a[N],b[N];
unsigned long long ans=0;
int main(){
	freopen("match.in","r",stdin);
	freopen("match.out","w",stdout);
	T=read();n=read();
	for(int i=1;i<=n;i++)a[i]=read();
	for(int i=1;i<=n;i++)b[i]=read();
	for(int Q=read();Q--;){
		int l=read(),r=read(),A=0,B=0;ans=0;
		for(int i=l;i<=r;i++){
			for(int j=i;j<=r;j++){
				A=max(A,a[i]);B=max(B,b[i]);
				ans+=(unsigned long long)A*B;
			}
		}
		printf("%llu\n",ans);
	}
	return 0;
}
