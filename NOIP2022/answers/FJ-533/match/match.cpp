#include<bits/stdc++.h>
#define int unsigned long long
using namespace std;
const int N=2.5e5+1;
int a[N],b[N],n,l,r,Q,T,ans;
struct node{int l,r,id,ans;}q[N];
inline bool cmp1(node x,node y){return (x.l==y.l)?(x.r<y.r):(x.l<y.l);}
inline bool cmp2(node x,node y){return x.id<y.id;}
inline int read(){
	int x=0;char c=getchar();
	while(c<'0'||c>'9'){c=getchar();}
	while(c>='0'&&c<='9'){x=x*10+c-'0';c=getchar();}
	return x;
}
void pre(){
	int t=sqrt(n);
	for(int i=1;i<=t+1;i++);
}
void work(){
	for(int i=1;i<=n;i++)a[i]=read();
	for(int i=1;i<=n;i++)b[i]=read();
	pre();
	//?
	Q=read();
	for(int i=1;i<=Q;i++)q[i].l=read(),q[i].r=read(),q[i].id=i;
	sort(q+1,q+1+Q,cmp1);
	//.
	l=1,r=n;
	//try to fenkuai...but failed.
	sort(q+1,q+1+Q,cmp2);
	for(int i=1;i<=Q;i++)cout<<q[i].ans<<endl;
}
signed main(){
	freopen("match.in","r",stdin);
	freopen("match.out","w",stdout);
	T=read(),n=read();
		for(int i=1;i<=n;i++)a[i]=read();
		for(int i=1;i<=n;i++)b[i]=read();
		Q=read();
		while(Q--){
			l=read(),r=read(),ans=0;
			for(int p=l;p<=r;p++){
				for(int q=p;q<=r;q++){
					int maxa=0,maxb=0;
					for(int i=p;i<=q;i++){
						maxa=max(maxa,a[i]);
						maxb=max(maxb,b[i]);
						//......
					}
					ans+=maxa*maxb;
				}
			}
			cout<<ans<<endl;
		}
	return 0;
}
//ST is not good :/
//I cannot deal with it :/
//try seg ment tree
