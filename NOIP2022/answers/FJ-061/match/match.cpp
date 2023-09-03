//expect /hs /bs expect
#include<bits/stdc++.h>
#define int unsigned long long
#define rep(i,j,k) for(int i=(j),_i=(k);i<=_i;++i)
#define drp(i,j,k) for(int i=(j),_i=(k);i>=_i;--i)
using namespace std;
inline int read() {
	int x=0,f=0;char ch;
	while(!isdigit(ch=getchar())) f|=ch=='-';
	while(isdigit(ch)) x=(x<<3)+(x<<1)+(ch^48),ch=getchar();
	return f?-x:x;
}
//-----------------------------------------------//
const int N=3e5+5;
int n,q,a[N],b[N],ans;


void solve(int L,int R) {
	if(L>R) return ;
	int amx=0,pos;
	rep(i,L,R) if(a[i]>amx) amx=a[i],pos=i;
	solve(L,pos-1);solve(pos+1,R);
	
	int l=pos,r=pos,bmx=b[pos],tot=0;
	
	while(l!=L&&b[l-1]<bmx) l--;
	while(r!=R&&b[r+1]<bmx) r++;
	tot=(r-pos+1)*(pos-l+1)*bmx;
	
	while(l!=L||r!=R) {
		int len=0;
		if(l!=L&&(r==R||b[l-1]<=b[r+1])) {
			bmx=b[l-1];
			while(b[l-1]<=bmx&&l!=L) l--,len+=r-pos+1;
		}
		else if(r!=R&&(l==L||b[l-1]>b[r+1])) {
			bmx=b[r+1];
			while(b[r+1]<=bmx&&r!=R) r++,len+=pos-l+1;
		} 
		tot+=bmx*len;
	}
	ans+=tot*amx;
	
}

signed main() {
	freopen("match.in","r",stdin);
	freopen("match.out","w",stdout);
	int T=read();
	n=read();
	rep(i,1,n) a[i]=read();
	rep(i,1,n) b[i]=read();
	
	q=read();
	rep(i,1,q) {
		int l=read(),r=read();ans=0;
		solve(l,r);
		printf("%llu\n",ans);
	}
	return 0;
}
