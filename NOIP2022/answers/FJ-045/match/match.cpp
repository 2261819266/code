#include<bits/stdc++.h>
#define int unsigned long long
using namespace std;
const int N=1e6+1;
int ans;
int dl[N],w[N];
int a[N],b[N],ra[N],rb[N],la[N],lb[N];
int hd,tl;
int T,n;
inline int read(){
	int x=0,f=1;char c=getchar();
	while(c>'9'||c<'0') {if(c=='0') f=-1;c=getchar();}
	while(c>='0'&&c<='9'){x=(x<<3)+(x<<1)+c-'0';c=getchar();}
	return x*f;
}
void pre(){
	dl[0]=INT_MAX;
	for(int i=1;i<=n;i++){
		while(a[i]>dl[tl]) ra[w[tl]]=i-1,tl--;
		dl[++tl]=a[i];w[tl]=i;
	}
	while(tl) ra[w[tl]]=n,tl--;
	for(int i=1;i<=n;i++){
		while(b[i]>dl[tl]) rb[w[tl]]=i-1,tl--;
		dl[++tl]=b[i];w[tl]=i;
	}
	while(tl) rb[w[tl]]=n,tl--;
	for(int i=n;i>=1;i--){
		while(a[i]>dl[tl]) la[w[tl]]=i+1,tl--;
		dl[++tl]=a[i];w[tl]=i;
	}
	while(tl) la[w[tl]]=1,tl--;
	for(int i=n;i>=1;i--){
		while(b[i]>dl[tl]) lb[w[tl]]=i+1,tl--;
		dl[++tl]=b[i];w[tl]=i;
	}
	while(tl) lb[w[tl]]=1,tl--;
	return;
}
signed main(){
	freopen("match.in","r",stdin);
	freopen("match.out","w",stdout);
	T=read(),n=read();
	for(int i=1;i<=n;i++) a[i]=read();
	for(int i=1;i<=n;i++) b[i]=read();
	pre();
	int q=read();
	for(int i=1;i<=q;i++){
		int l=read(),r=read();ans=0;
		for(int j=l;j<=r;j++){
		 int ma=0,mb=0,sum=0;
		 for(int k=j;k<=r;k++){
		 	ma=max(a[k],ma);mb=max(b[k],mb);
		    ans+=ma*mb*(min(ra[k],rb[k])-k+1);
		    k=min(ra[k],rb[k]);
	     }
//	     ans+=sum*(min(ra[j],rb[j])-j+1);
//	     j=min(ra[j],rb[j]);
	    }
		cout<<ans<<'\n';
	}
	return 0;
}
