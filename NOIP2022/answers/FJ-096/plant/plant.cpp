#include <cstdio>
#include <iostream>
const int N=1e3+1,M=998244353; 
using namespace std;
bool a[N][N];
int T,id,n,m,c,f,tor[N][N],tod[N][N],sr[N][N],s[N][N],t[N][N],s2[N][N],sr2[N][N];
long long s22[N][N];
int main(){
	freopen ("plant.in","r",stdin);
	freopen ("plant.out","w",stdout);
	register int i,j,k,l;
	register long long vc,vf;
	for (scanf ("%d%d",&T,&id);T;--T){
		scanf ("%d%d%d%d",&n,&m,&c,&f);
		for (i=1;i<=n;++i){
			for (j=1;j<=m;++j)
				scanf (" %1d",&a[i][j]);
		}
		for (j=1;j<=m;++j)
			for (i=1;i<=n;++i){
				if (!a[i][j]&&((a[i+1][j]&&i<n)||i==n))
					t[j][++t[j][0]]=i;
				if (a[i][j]&&!a[i+1][j]&&i<n)
					s[j][++s[j][0]]=i+1;
				if (i==1&&!a[1][j])
					s[j][0]=s[j][1]=1;
			}
		for (i=1;i<=n;++i){
			if (!a[i][m])tor[i][m]=1;
			for (j=m-1;j;--j)
				if (!a[i][j])
					tor[i][j]=tor[i][j+1]+1;
			for (j=m;j;--j)
				if (tor[i][j]>0)
					--tor[i][j];
		}
		for (j=1;j<=m;++j){
			if (!a[n][j])tod[n][j]=1;
			for (i=n-1;i;--i)
				if (!a[i][j])
					tod[i][j]=tod[i+1][j]+1;
			for (i=n;i;--i)
				if (tod[i][j]>0)
					--tod[i][j];
		}
		for (j=1;j<=m;++j)
			for (i=1;i<=n;++i)
				sr[j][i]=sr[j][i-1]+tor[i][j];
		for (j=1;j<=m;++j)
			for (i=1;i<n;++i)
				s2[j][i]=s2[j][i-1]+sr[j][i+1]*tor[i][j];
		vc=vf=0;
		for (j=1;j<=m;++j){
			for (i=1;i<=s[j][0];++i){
				k=s[j][i],l=t[j][i];
				vc=((vc+sr[j][l]*(sr[j][l-2]-sr[j][k-1]))%M-s2[j][l-2]+s2[j][k-1])%M;
				if (vc<0)vc+=M;
			}
		}
		for (j=1;j<=n;++j)
			for (i=1;i<=n;++i)
				sr2[j][i]=sr2[j][i-1]+tor[i][j]*tod[i][j];
		for (j=1;j<=m;++j)
			for (i=1;i<n;++i)
				s22[j][i]=s22[j][i-1]+sr2[j][i+1]*tor[i][j];
		for (j=1;j<=m;++j){
			for (i=1;i<=s[j][0];++i){
				k=s[j][i],l=t[j][i];
				vf=((vf+sr2[j][l]*(sr[j][l-2]-sr[j][k-1]))%M-s22[j][l-2]+s22[j][k-1])%M;
				if (vf<0)vf+=M; 
			}
		}
		cout <<(vc*c)%M<<' '<<(vf*f)%M<<'\n';
	}
	return 0;
} 
