#include <cstdio>
#include <cctype>
#include <vector>
#include <algorithm>
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
template<typename T1,typename T2> void cmin(T1 &a,const T2 &b){if(a>b)a=b;}
template<typename T1,typename T2> void cmax(T1 &a,const T2 &b){if(a<b)a=b;}

const int N=1005;
constexpr int P=998244353;
int T,id,n,m,C,F,a[N][N],f[N][N],s[N][N],g[N][N],t[N][N];

int main(){
	freopen("plant.in","r",stdin);
	freopen("plant.out","w",stdout);
	scanf("%d%d",&T,&id);
	while(T--){
		scanf("%d%d%d%d",&n,&m,&C,&F);
		for(int i=1;i<=n;++i)
			for(int j=1;j<=m;++j)
				scanf("%1d",a[i]+j);
		for(int i=1;i<=n;++i)
			a[i][0]=a[i][m+1]=1;
		for(int i=1;i<=m;++i)
			a[0][i]=a[n+1][i]=1;
		for(int i=1;i<=n;++i)
			f[i][m+1]=0;
		for(int i=1;i<=m;++i)
			s[n+1][i]=0;
		for(int i=1;i<=m;++i)
			g[n+1][i]=0;
		for(int i=1;i<=m;++i)
			t[n+1][i]=0;
		int sc=0,sf=0;
		for(int i=n;i>=1;--i){
			f[i][m+1]=0;
			for(int j=m;j>=1;--j){
				if(a[i][j]==0){
					f[i][j]=f[i][j+1]+1;
					s[i][j]=s[i+1][j]+(f[i][j]-1);
					if(i+2<=n && a[i+1][j]==0)
						sc=(sc+(ll)(f[i][j]-1)*s[i+2][j])%P;
					g[i][j]=g[i+1][j]+1;
					t[i][j]=(t[i+1][j]+(ll)(f[i][j]-1)*g[i+1][j])%P;
					if(i+2<=n && a[i+1][j]==0)
						sf=(sf+(ll)(f[i][j]-1)*t[i+2][j])%P;
				}else{
					f[i][j]=0;
					s[i][j]=0;
					g[i][j]=0;
					t[i][j]=0;
				}
			}
		}
		printf("%d %d\n",sc*C,sf*F);
	}
	return 0;
}
