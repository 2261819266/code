#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#define N 305
#define M 2000005
using namespace std;
typedef long long ll;
inline int read(){
	int x=0,f=1;char ch=getchar();
	while(ch<'0'||ch>'9'){if(ch=='-')f=-1;ch=getchar();}
	while(ch>='0'&&ch<='9'){x=(x<<1)+(x<<3)+(ch^48);ch=getchar();}
	return x*f;
}
inline void print(int x){
	if(x>=10)print(x/10);
	putchar(x%10+'0');
}
int n,m,k,a[M],b[N<<1],p[M],c1[N],c2[N];
int op,c[N],vis[N];
inline int back(int x){
	if(c2[x])return c2[x];
	else return c1[x];
}
inline int front(int x){
	if(c1[x])return c1[x];
	else return c2[x];
}
inline int sz(int x){
	if(c2[x])return 2;
	if(c1[x])return 1;
	return 0;
}
inline void pb(int x,int y){
	if(!c1[x])c1[x]=y;
	else c2[x]=y;
}
inline void po(int x){
	if(c2[x])c2[x]=0;
	else c1[x]=0;
}
inline void pf(int x){
	c1[x]=c2[x],c2[x]=0;
}
void solve(){
	n=read();m=read();k=read();
	for(int i=1;i<=m;i++)a[i]=read();
	for(int i=1;i<=m;i++){
		if(!b[a[i]])b[a[i]]=i;
		else p[i]=b[a[i]],p[b[a[i]]]=i,b[a[i]]=0;
	}
	for(int i=1,fl=0,ps=0;i<=m;i++,fl=0){
		if(vis[a[i]]){
			int j=vis[a[i]];vis[a[i]]=0;
			if(back(j)==i)c[++op]=j,po(j);
			else for(int l=1;l<=n;l++)if(!sz(l)){c[++op]=l,c[++op]=j*1000+l,pf(j);break;}
		}else{
			for(int j=1;j<=n;j++)if(sz(j)==1&&back(j)>p[i]){
				fl=1;vis[a[i]]=j;c[++op]=j;pb(j,p[i]);break;
			}
			if(fl)continue;
			for(int j=1;j<=n;j++)if(!sz(j)){
				fl=1;vis[a[i]]=j;c[++op]=j;pb(j,p[i]);break;
			}
			if(fl)continue;
			for(int j=1;j<=n;j++)if(sz(j)==1&&(!ps||back(j)>back(ps)))ps=j;
			c[++op]=ps;vis[a[i]]=ps;pb(ps,p[i]);
		}
	}
	print(op);putchar('\n');
	for(int i=1;i<=op;i++)if(c[i]>1000)print(2),putchar(' '),print(c[i]/1000),putchar(' '),print(c[i]%1000),putchar('\n');
	else print(1),putchar(' '),print(c[i]),putchar('\n');
}
int main(){
	freopen("meow.in","r",stdin);
	freopen("meow.out","w",stdout);
	for(int tt=read();tt--;solve());
	return 0;
}
