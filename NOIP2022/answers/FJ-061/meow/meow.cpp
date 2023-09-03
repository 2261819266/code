//expect /hs /bs expect
#include<bits/stdc++.h>
#define int long long
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
const int N=305,M=2e6+6;
int a[M],n,m,k;

struct Out{
	int cnt,op[M<<1],x[M<<1],y[M<<1];
	void print() {
		printf("%lld\n",cnt);
		rep(i,1,cnt) {
			if(op[i]==1) printf("1 %lld\n",x[i]);
			else printf("2 %lld %lld\n",x[i],y[i]);
		}
		cnt=0;
	}
}out;

void out1(int x) {
	out.cnt++;
	out.op[out.cnt]=1;out.x[out.cnt]=x;
}
void out2(int x,int y) {
	out.cnt++;
	out.op[out.cnt]=2;out.x[out.cnt]=x;out.y[out.cnt]=y;
}
void canc() {
	out.cnt--;
}

namespace work1 {
	int in[N<<1],dep[N];
	signed Main() {
		rep(i,1,m) {
			int x=(a[i]+1)/2;
			if(in[a[i]]) {
				if(in[a[i]]==2) out1(x);
				else out1(n),out2(x,n);
				dep[x]--;
			}
			else {
				in[a[i]]=++dep[x];
				out1(x);
			}
		}
		return 0;
	}
}

namespace work2 {
	
	int opt[M],in[10];
	
	int sta[4][4],top[3];
	
	bool dfs(int u) {
		if(u==m+1) return true;
		if(!opt[u]) {
			rep(i,1,n) if(top[i]!=3) {
				out1(i);sta[i][++top[i]]=a[u];
				if(dfs(u+1)) return true;
				canc();top[i]--;
			}
		}
		else {
			rep(i,1,n) if(sta[i][top[i]]==a[u]) {
				out1(i);top[i]--;
				if(dfs(u+1)) return true;
				canc();sta[i][++top[i]]=a[u];
			}
			int e=0;
			rep(i,1,n) if(!top[i]) e=i;
			if(e) {
				rep(i,1,n) if(top[i]&&sta[i][1]==a[u]) {
					out1(e);out2(i,e);
					rep(j,1,top[i]) sta[i][j]=sta[i][j+1];
					top[i]--;
					
					if(dfs(u+1)) return true;
					
					canc();canc();
					drp(j,top[i],1) sta[i][j+1]=sta[i][j];
					sta[i][1]=a[u];
				}
			}
		}
		return false;
	}
	
	
	signed Main() {
		rep(i,1,m) {
			opt[i]=in[a[i]];
			in[a[i]]^=1;
		}
		dfs(1);
		return 0;
	}
}

signed main() {
	freopen("meow.in","r",stdin);
	freopen("meow.out","w",stdout);
	int T=read();
	rep(ttt,1,T) {
		n=read(),m=read(),k=read();
		rep(i,1,m) a[i]=read();
		if(T%10==1) 
		  work1::Main();
		else 
		  work2::Main();
		out.print();
	}
	return 0;
}
