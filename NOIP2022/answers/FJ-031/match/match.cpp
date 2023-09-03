#include<bits/stdc++.h>
#define N 250010
#define pii pair<int,int>
#define fi first
#define se second
#define ull unsigned long long
#define ls k*2
#define rs k*2+1
#define mid (l+r)/2
using namespace std;
int read() {
	int x=0,f=1;char ch=getchar();
	while(!isdigit(ch)) f=ch=='-'?-1:1,ch=getchar();
	while(isdigit(ch)) x=x*10+ch-'0',ch=getchar();
	return x*f;
}
int T,n,Q,a[N],b[N];
ull val[N],ans[N];
struct node{
	int l,r,id;
	bool operator <(node o) {return r<o.r;}
};
vector<node> q[N];
int main() {
	freopen("match.in","r",stdin);
	freopen("match.out","w",stdout);
	T=read(),n=read();
	for(int i=1; i<=n; i++) a[i]=read();
	for(int i=1; i<=n; i++) b[i]=read();
	Q=read();
	for(int i=1; i<=Q; i++) {
		int l=read(),r=read();
		q[r].push_back(node{l,r,i});
	}
	for(int i=1; i<=n; i++) {
		int mxa=0,mxb=0;
		for(int j=i; j; j--) {
			mxa=max(mxa,a[j]),mxb=max(mxb,b[j]);
			val[j]+=1ull*mxa*mxb;
		}
		for(node j:q[i]) 
			for(int k=j.l; k<=j.r; k++) ans[j.id]+=val[k];
	}
	for(int i=1; i<=Q; i++) printf("%llu\n",ans[i]);
}
