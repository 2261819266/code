#include<bits/stdc++.h>
#define spa putchar(' ')
#define ent putchar('\n')
typedef long long ll;
using namespace std;
inline void read(int &x){
	char c=getchar();
	int f=1;x=0;
	while(c<'0'||c>'9'){if(c=='-')f=-1;c=getchar();}
	while(c>='0'&&c<='9'){x=(x<<1)+(x<<3)+c-'0';c=getchar();}
	x*=f;
}
inline void write(ll x){
	char F[65];
	int cnt=0;
	if(x<0){putchar('-');x=-x;}
	do{F[++cnt]=x%10+'0';x/=10;}while(x);
	while(cnt)putchar(F[cnt--]);
}
const int maxn=1e3+5,p=998244353;
int T,id,n,m,c,f,a[maxn][maxn],h[maxn][maxn],l[maxn][maxn],sumh[maxn][maxn],sum1[maxn][maxn];
ll ansC,ansF;
int main(){
	freopen("plant.in","r",stdin);
	freopen("plant.out","w",stdout);
	read(T);
	read(id);
	while(T--){
		read(n);
		read(m);
		read(c);
		read(f);
		ansC=0;
		ansF=0;
		for(int i=1;i<=n;i++){
			for(int j=1;j<=m;j++){
				h[i][j]=0;
				l[i][j]=0;
				sumh[i][j]=0;
				sum1[i][j]=0;
			}
		}
		for(int i=1;i<=n;i++){
			for(int j=1;j<=m;j++){
				char c=getchar();
				while(c<'0'||c>'9')c=getchar();
				a[i][j]=c-'0';
			}
			for(int j=m-1;j>=1;j--){
				if(a[i][j+1]==0&&a[i][j]==0)h[i][j]=h[i][j+1]+1;
			}
		}
		for(int j=1;j<=m;j++){
			for(int i=n-1;i>=1;i--){
				if(a[i+1][j]==0&&a[i][j]==0)l[i][j]=l[i+1][j]+1;
			}
			for(int i=1;i<=n;i++){
				sumh[i][j]=sumh[i-1][j]+h[i][j];
				sum1[i][j]=(sum1[i-1][j]+sumh[i][j])%p;
			}
		}
		for(int i=1;i<=n;i++){
			for(int j=1;j<=m;j++){
				if(l[i][j]>=2&&h[i][j]>0)ansC=(ansC+(1ll*h[i][j]*(sumh[i+l[i][j]][j]-sumh[i+1][j])%p))%p;
				if(a[i][j]==0&&h[i][j]>0&&l[i][j]>2){
					ansF=(ansF+(1ll*h[i][j]*l[i][j]*(sumh[i+l[i][j]-1][j]-sumh[i+1][j])%p)-(1ll*h[i][j]*((((1ll*(i+l[i][j]-1)*sumh[i+l[i][j]-1][j]%p)-sum1[i+l[i][j]-2][j])%p)-(((1ll*(i+1)*sumh[i+1][j]%p)-sum1[i][j])%p)-(1ll*i*(sumh[i+l[i][j]-1][j]-sumh[i+1][j])%p))%p)%p)%p;
				}
			}
		}
		if(c==0)putchar('0');
		else write(ansC);
		spa;
		if(f==0)putchar('0');
		else write(ansF);
		ent;
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
