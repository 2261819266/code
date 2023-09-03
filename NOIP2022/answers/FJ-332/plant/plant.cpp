#include <iostream>
#include <cstdio>
using namespace std;
const int N=1100,mod=998244353;
int n,m,C,F;
bool a[N][N];
int b[N],c[N],sumc,ansc,sumf,ansf;
inline bool read(){
	char c=getchar();
	while(c<'0'||c>'9')
		c=getchar();
	return c-'0';
}
int main(){
	freopen("plant.in","r",stdin);
	freopen("plant.out","w",stdout);
	int T,id;
	scanf("%d%d",&T,&id);
while(T--){
	ansc=ansf=0;
	scanf("%d%d%d%d",&n,&m,&C,&F);
	for(int i=1;i<=n;i++)
		for(int j=1;j<=m;j++)
			a[i][j]=read();
	for(int i=1;i<=n;i++)
		a[i][0]=1;
	for(int i=1;i<=m;i++)
		a[0][i]=1;
	for(int i=1;i<=m;i++){
		for(int j=1;j<=n;j++)
			if(a[j][i])
				b[j]=0;
			else
				if(a[j][i-1]){
					b[j]=0;
					for(int k=i+1;k<=m;k++){
						if(a[j][k])
							break;
						b[j]++;
					}
				}
				else
					b[j]--;
		for(int j=1;j<=n;j++){
			if(a[j][i]){
				c[j]=0;
				sumc=0;
			}
			else
				if(a[j-1][i]){
					c[j]=0;
					sumc=0;
					for(int k=j+1;k<=n;k++){
						if(a[k][i])
							break;
						c[j]++;
						if(k!=j+1)
							sumc+=b[k];
					}
				}
				else{
					sumc-=b[j+1];
					c[j]=c[j-1]-1;
				}
			ansc=(ansc+1ll*b[j]*sumc)%mod;
		}
		for(int j=1;j<=n;j++){
			if(a[j][i])
				sumf=0;
			else
				if(a[j-1][i]){
					sumf=0;
					for(int k=j+1;k<=n;k++){
						if(a[k][i])
							break;
						if(k!=j+1)
							sumf=(sumf+1ll*b[k]*c[k])%mod;
					}
				}
				else
					sumf=((sumf-1ll*b[j+1]*c[j+1])%mod+mod)%mod;
			ansf=(ansf+1ll*b[j]*sumf)%mod;
		}
	}
	printf("%d %d\n",C*ansc,F*ansf);
}
	return 0;
}
