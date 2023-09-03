#include<bits/stdc++.h>
using namespace std;
template<typename T>void rd(T&x){
	x=0;int f=1;char c=getchar();
	while(c<'0'||c>'9'){if(c=='-')f=-1;c=getchar();}
	while(c>='0'&&c<='9'){x=x*10+c-48;c=getchar();}
	x*=f;
}
typedef long long ll;
const int N=300,M=2e6;
int T,n,m,k,s[N][2],t[N],op[M],b[M],tot;
int main(){
	freopen("meow.in","r",stdin);
	freopen("meow.out","w",stdout);
	rd(T);
	while(T--){
		rd(n);rd(m);rd(k);tot=m;
		for(int i=1,a;i<=m;++i){
			rd(a);b[i]=--a>>1;op[i]=0;
			if(!t[b[i]])s[b[i]][t[b[i]]++]=a;
			else if(s[b[i]][t[b[i]]-1]==a)--t[b[i]];
			else if(s[b[i]][0]==a)s[b[i]][0]=s[b[i]][1],--t[b[i]],op[i]=1,++tot;
			else s[b[i]][t[b[i]]++]=a;
		}
		for(int i=1;i<=n;++i)assert(!t[i]);
		printf("%d\n",tot);
		for(int i=1;i<=m;++i){
			if(op[i])printf("1 %d\n2 %d %d\n",n,b[i]+1,n);
			else printf("1 %d\n",b[i]+1);
		}
	}
	
}

