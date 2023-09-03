#include <bits/stdc++.h>
using namespace std;
const int N=250005;
int T,n,q,a[N],b[N],mx[N][20][2],sqn;
unsigned long long ans,Ans[N];
inline int read(){
	int x=0; char ch;
	bool bz=0;
	while(((ch=getchar())<'0'||ch>'9')&&ch!='-') ;
	if(ch=='-') bz=1;
	else x=(x<<1)+(x<<3)+(ch^48);
	while((ch=getchar())>='0'&&ch<='9') x=(x<<1)+(x<<3)+(ch^48);
	return bz?-x:x;
}
inline long long ask(int l,int r){
	int k=log(r-l+1)/log(2);
	return (long long)max(mx[l][k][0],mx[r-(1<<k)+1][k][0])*(long long)max(mx[l][k][1],mx[r-(1<<k)+1][k][1]);
}
struct xw{
	int l,r,id;
	bool operator<(const xw &x)const{
		if(l/sqn!=x.l/sqn) return l<x.l;
		return ((l/sqn)&1)?(r<x.r):(r>x.r);
	}
}s[N];
void add(int bz,int l,int r){
	if(bz) for(int i=l;i<=r;i++) ans+=ask(i,r);
	else for(int i=l;i<=r;i++) ans+=ask(l,i);
}
void del(int bz,int l,int r){
	if(bz) for(int i=l;i<=r;i++) ans-=ask(i,r);
	else for(int i=l;i<=r;i++) ans-=ask(l,i);
}
int main(){
	freopen("match.in","r",stdin);
	freopen("match.out","w",stdout);
	T=read(),n=read();
	sqn=sqrt(n);
	for(int i=1;i<=n;i++) a[i]=read(),mx[i][0][0]=a[i];
	for(int i=1;i<=n;i++) b[i]=read(),mx[i][0][1]=b[i];
	int t=log(n)/log(2)+1,g=1;
	for(int j=1;j<t;j++){
		for(int i=1;i<=n-g;i++) mx[i][j][0]=max(mx[i][j-1][0],mx[i+g][j-1][0]),mx[i][j][1]=max(mx[i][j-1][1],mx[i+g][j-1][1]);
		g=g*2;
	}
	q=read();
	while(q--){
		int l=read(),r=read();
		ans=0;
		for(int i=l;i<=r;i++){
			for(int j=i;j<=r;j++) ans+=ask(i,j);
		}
		cout<<(unsigned long long)ans<<"\n";
	}
	return 0;
}
