#include<bits/stdc++.h>
#define LL long long
#define Un unsigned
#define For1(i,a,b) for(i=(a);i<=(b);++i)
#define For2(i,a,b) for(i=(a);i<(b);++i)
#define FoR1(i,a,b) for(i=(a);i>=(b);--i)
#define FoR2(i,a,b) for(i=(a);i>(b);--i)
#define For_L(i,x) for(i=ft[x];i;i=nt[i])
#define mkp make_pair
#define fir first
#define sec second
template<class T1>
void cmax(T1 &x,T1 y){if(x<y)x=y;}
template<class T1>
void cmin(T1 &x,T1 y){if(x>y)x=y;}
const int N=1011,mod=998244353;
char a[N][N];
int r[N][N],d[N][N],c[N][N],f[N][N],T,id,n,m,C,F,ansc,ansf;
int add(int x,int y){return (x+=y)<mod?x:x-mod;}
void addd(int &x,int y){if((x+=y)>=mod)x-=mod;}
int sub(int x,int y){return (x-=y)<0?x+mod:x;}
void subb(int &x,int y){if((x-=y)<0)x+=mod;}
int mul(int x,int y){return 1ll*x*y%mod;}
void mull(int &x,int y){x=1ll*x*y%mod;}
signed main(){int i,j;
	freopen("plant.in","r",stdin);
	freopen("plant.out","w",stdout);
	scanf("%d%d",&T,&id);
	while(T--){ansc=ansf=0;
		scanf("%d%d%d%d",&n,&m,&C,&F);
		memset(a,0,sizeof(a));
		memset(r,0,sizeof(r));
		memset(d,0,sizeof(d));
		memset(c,0,sizeof(c));
		memset(f,0,sizeof(f));
		For1(i,1,n){
			while((a[i][1]=getchar())<48);
			For1(j,2,m)a[i][j]=getchar();
		}
		For1(i,1,n){
			a[i][m+1]=a[i][m+2]='1';
			r[i][m+1]=r[i][m+2]=-1;
			FoR1(j,m,1){
				if(a[i][j]=='1')r[i][j]=-1;
				else r[i][j]=add(r[i][j+1],1);
			}
		}
		For1(j,1,m){
			a[n+1][j]=a[n+2][j]='1';
			d[n+1][j]=d[n+2][j]=-1;
			FoR1(i,n,1){
				if(a[i][j]=='1')d[i][j]=-1;
				else d[i][j]=add(d[i+1][j],1);
			}
		}
		For1(j,1,m){
			f[n+1][j]=f[n+2][j]=c[n+1][j]=c[n+2][j]=0;
			FoR1(i,n,1){
				if(a[i][j]=='1'||a[i+1][j]=='1'||a[i+2][j]=='1'){f[i][j]=c[i][j]=0;continue;}
				c[i][j]=add(c[i+1][j],r[i+2][j]);
				f[i][j]=add(f[i+1][j],mul(r[i+2][j],d[i+2][j]));
			}
		}
		For1(i,1,n){
			For1(j,1,m){
				addd(ansc,mul(r[i][j],c[i][j]));
				addd(ansf,mul(r[i][j],f[i][j]));
			}
		}
		/*For1(i,1,n){
			For1(j,1,m){
				printf("%d ",r[i][j]);
			}
			printf("R\n");
		}
		For1(i,1,n){
			For1(j,1,m){
				printf("%d ",d[i][j]);
			}
			printf("D\n");
		}
		For1(i,1,n){
			For1(j,1,m){
				printf("%d ",c[i][j]);
			}
			printf("C\n");
		}
		For1(i,1,n){
			For1(j,1,m){
				printf("%d ",f[i][j]);
			}
			printf("F\n");
		}*/
		printf("%d %d\n",mul(C,ansc),mul(F,ansf));
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
