#include <cstdio>
#include <iostream>
#include <cstring>
using namespace std;
const int N=1006;
int T,n,m,k,a[N],b[N][N],h[N];
int main(){
	freopen ("meow.in","r",stdin);
	freopen ("meow.out","w",stdout);
	register int i,t,sum;
	for (scanf ("%d",&T);T;--T){
		scanf ("%d%d%d",&n,&m,&k);
		if (!(k&1)){
			memset (b,0,sizeof (b)),sum=0;
			for (i=1;i<=m;++i){
				scanf ("%d",&a[i]),t=(a[i]+1)>>1;
				if (!b[t][0])b[t][0]=a[i];
				else if (!b[t][1]&&b[t][0]!=a[i])b[t][1]=a[i];
				else if (!b[t][1]&&b[t][0]==a[i])b[t][0]=0;
				else if (a[i]==b[t][1])b[t][1]=0;
				else ++sum,b[t][0]=b[t][1],b[t][1]=0;
			}
			cout <<m+sum<<'\n';
			memset (b,0,sizeof (b));
			for (i=1;i<=m;++i){
				t=(a[i]+1)>>1;
				if (!b[t][0])b[t][0]=a[i],cout <<'1'<<' '<<t<<'\n';
				else if (!b[t][1]&&b[t][0]!=a[i])b[t][1]=a[i],cout <<'1'<<' '<<t<<'\n';
				else if (!b[t][1]&&b[t][0]==a[i])b[t][0]=0,cout <<'1'<<' '<<t<<'\n';
				else if (a[i]==b[t][1])b[t][1]=0,cout <<'1'<<' '<<t<<'\n';
				else b[t][0]=b[t][1],b[t][1]=0,cout <<'1'<<' '<<n<<'\n'<<'2'<<' '<<t<<' '<<n<<'\n';
			}
		}
		else{
			
		}
	}
	return 0;
} 
