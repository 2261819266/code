#include <bits/stdc++.h>
using namespace std;
#define writesp(x) write(x), putchar(' ')
#define writeln(x) write(x), putchar('\n')

inline int read(){
	int x=0;
	bool f=0;
	char ch=getchar();
	while (ch<'0' || ch>'9'){
		if (ch=='-') f=1;
		ch=getchar();
	}
	while (ch>='0' && ch<='9'){
		x=x*10+(ch^48);
		ch=getchar();
	}
	return (f?-x:x);
}

inline void write(int x){
	if (x<0) putchar('-'), x=-x;
	if (x>9) write(x/10);
	putchar(x%10+48);
}

bool ST;

const int N=310,M=2e6+10,inf=0x7fffffff;
int t,n,m,k,a[N];
int sta[N];
int opcnt,op[N],x[N],y[N];

bool ED;

int main(){
//	cerr<<(&ST-&ED)/1024.0/1024.0<<endl;
	freopen("meow.in","r",stdin);
	freopen("meow.out","w",stdout);
	t=read();
	int i;
	while (t--){
		opcnt=0;
		memset(sta,0,sizeof(sta));
		n=read(), m=read(), k=read();
		for (i=1;i<=m;i++) a[i]=read();
		for (i=1;i<=m;i++){
			int id;
			if (a[i]<=n-1) id=a[i];
			else id=a[i]-n+1;
			if (sta[id]==0){
				opcnt++;
				op[opcnt]=1;
				x[opcnt]=id;
				if (a[i]<=n-1) sta[id]=1;
				else sta[id]=2;
			}
			else if (sta[id]==1){
				opcnt++;
				op[opcnt]=1;
				x[opcnt]=id;
				if (a[i]<=n-1) sta[id]=0;
				else sta[id]=3;
			}
			else if (sta[id]==2){
				opcnt++;
				op[opcnt]=1;
				x[opcnt]=id;
				if (a[i]<=n-1) sta[id]=4;
				else sta[id]=0;
			}
			else if (sta[id]==3){
				if (a[i]<=n-1){
					opcnt++;
					op[opcnt]=1;
					x[opcnt]=n;
					opcnt++;
					op[opcnt]=2;
					x[opcnt]=id, y[opcnt]=n;
					sta[id]=2;
				}
				else{
					opcnt++;
					op[opcnt]=1;
					x[opcnt]=id;
					sta[id]=1;
				}
			}
			else{
				if (a[i]>n-1){
					opcnt++;
					op[opcnt]=1;
					x[opcnt]=n;
					opcnt++;
					op[opcnt]=2;
					x[opcnt]=id, y[opcnt]=n;
					sta[id]=1;
				}
				else{
					opcnt++;
					op[opcnt]=1;
					x[opcnt]=id;
					sta[id]=2;
				}
			}
		}
		writeln(opcnt);
		for (i=1;i<=opcnt;i++){
			writesp(op[i]);
			if (op[i]==1) writeln(x[i]);
			else writesp(x[i]), writeln(y[i]);
		}
	}
	return 0;
}
