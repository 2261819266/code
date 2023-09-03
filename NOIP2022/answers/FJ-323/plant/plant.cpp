#include <bits/stdc++.h>
using namespace std;
#define writesp(x) write(x), putchar(' ')
#define writeln(x) write(x), putchar('\n')
#define int long long

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

const int N=1e3+10,inf=0x7fffffff,mod=998244353;
int t,id,n,m,tc,tf,ansc,ansf;
char mmap[N][N];
int right_114514[N][N],down_114514[N][N],sum1[N][N],sum2[N][N];

bool ED;

signed main(){
//	cerr<<(&ST-&ED)/1024.0/1024.0<<endl;
	freopen("plant.in","r",stdin);
	freopen("plant.out","w",stdout);
	t=read(), id=read();
	int i,j;
	while (t--){
		ansc=ansf=0;
		memset(right_114514,0,sizeof(right_114514)), memset(down_114514,0,sizeof(down_114514)), memset(sum1,0,sizeof(sum1)), memset(sum2,0,sizeof(sum2));
		n=read(), m=read(), tc=read(), tf=read();
		for (i=1;i<=n;i++){
			scanf("%s",mmap[i]+1);
		}
		for (i=1;i<=n;i++){
			for (j=m-1;j>=0;j--){
				if (mmap[i][j+1]=='1') right_114514[i][j]=0;
				else right_114514[i][j]=(right_114514[i][j+1]+1)%mod;
			}
		}
		for (j=1;j<=m;j++){
			for (i=n-1;i>=0;i--){
				if (mmap[i+1][j]=='1') down_114514[i][j]=0;
				else down_114514[i][j]=(down_114514[i+1][j]+1)%mod;
			}
		}
		for (j=1;j<=m;j++){
			for (i=1;i<=n;i++){
				sum1[i][j]=(sum1[i-1][j]+right_114514[i][j])%mod;
				sum2[i][j]=(sum2[i-1][j]+right_114514[i][j]*(n-i+1)%mod)%mod;
			}
		}
		for (i=1;i<=n;i++){
			for (j=1;j<=m;j++){
				if (mmap[i][j]=='0' && mmap[i+1][j]=='0' && mmap[i+2][j]=='0'){
					ansc=(ansc+right_114514[i][j]*((sum1[i+down_114514[i][j]][j]-sum1[i+1][j]+mod)%mod)%mod)%mod;
					if (mmap[i+3][j]=='0'){
						ansf=(ansf+right_114514[i][j]*(((sum2[i+down_114514[i][j]-1][j]-sum2[i+1][j]+mod)%mod-((n-i-down_114514[i][j]+1)*((sum1[i+down_114514[i][j]-1][j]-sum1[i+1][j]+mod)%mod)%mod)+mod)%mod)%mod)%mod;
					}
				}
			}
		}
		writesp(ansc*tc), writeln(ansf*tf);
	}
	return 0;
}
