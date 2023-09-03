#include<cstdio>
#define N 1010
#define ll long long
#define mod 998244353
int t,id;
int n,m;
int a1[N][N];
char ke;
ll rt[N][N];
ll c1,f1;
ll a,b,c,lsta;
ll ansc,ansf;
int i,j,k;
int main(){
	freopen("plant.in","r",stdin);
	freopen("plant.out","w",stdout);
	scanf("%d%d",&t,&id);
	while(t--){
		ansc=ansf=0;
		scanf("%d%d",&n,&m);
		scanf("%lld%lld",&c1,&f1);
		for(i=1;i<=n;++i){
		scanf("%c",&ke);
			for(j=1;j<=m;++j){
				scanf("%c",&ke);
				a1[i][j]=ke-'0';
			}
		}
		//for(i=1;i<=n;++i){
		//	for(j=1;j<=m;++j){
		//		printf("%d",a1[i][j]);
		//	}printf("\n");
		//}
		for(i=1;i<=n;++i){
			a1[i][0]=a1[i][m+1]=1;
		}
		for(j=1;j<=m;++j){
			a1[0][j]=a1[n+1][j]=1;
		}
		for(i=1;i<=n;++i){
			for(j=m;j>=1;--j){
				if(a1[i][j]==1){
					rt[i][j]=0;
				}
				else{
					rt[i][j]=rt[i][j+1]+1;
				}
			}
		}//init
		
		for(j=1;j<=m;++j){
			b=0;lsta=0;a=0;
			k=1;c=0;
			while(a1[k][j]!=1){
				++c;
				++k;
			}
			
			for(i=1;i<=n;++i){
				if(a1[i][j]==1){
					b=0;lsta=0;
					k=i+1;
					while(a1[k][j]!=1){
						++c;
						++k;
					}
				}
				else{
					a=rt[i][j]-1;
					--c;
					ansc+=(a*b);
					ansf+=(a*b*c);
					//printf("%d %d %d %d %d\n",i,j,a,b,c);
					b+=lsta;
					lsta=a;
				}
			}
			ansc%=mod;ansf%=mod;
		}
		printf("%lld %lld\n",ansc*c1,ansf*f1);
		
		//clear
		for(i=1;i<=n;++i){
			for(j=1;j<=m;++j){
				a1[i][j]=rt[i][j]=0;
			}
		}
		c=0;k=0;
			b=0;lsta=0;a=0;
	}
	return 0;
}

