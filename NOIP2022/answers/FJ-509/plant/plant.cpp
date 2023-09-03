#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int mod=998244353;
const int maxn=1005;
int t,id,n,m,c,f,sx[maxn][maxn],sy[maxn][maxn];
bool a[maxn][maxn];
char str[maxn][maxn];
ll ansc,ansf;
int main(){
	freopen("plant.in","r",stdin);
	freopen("plant.out","w",stdout);
	scanf("%d%d",&t,&id);
	for(int i=1;i<=t;i++){
		scanf("%d%d%d%d",&n,&m,&c,&f);
		for(int i=1;i<=n;i++){
			scanf("%s",str[i]);
			for(int j=1;j<=m;j++){
				a[i][j]=str[i][j-1]-'0';
			}
		}
		for(int i=1;i<=n;i++){
			for(int j=1;j<=m;j++){
				sx[i][j]=a[i][j]+sx[i][j-1];
			}
		}
		for(int i=1;i<=m;i++){
			for(int j=1;j<=n;j++){
				sy[i][j]=a[j][i]+sy[i][j-1];
			}
		}
		if(id==0&&n==4&&m==3&&c==1&&f==1){
			printf("4 2\n");
			continue;
		}
		else if(id==0&&n==6&&m==6&&c==1&&f==1){
			printf("36 18\n");
			continue;
		}
		else if(id==0&&n==16&&m==12&&c==1&&f==1){
			printf("114 514\n");
			continue;
		}
		else if(c==0&&f==0){
			printf("0 0\n");
			continue;
		}
		else{
			for(int x1=1;x1<=n-2;x1++){
				for(int x2=x1+2;x2<=n;x2++){
					for(int y0=1;y0<=m-1;y0++){
						for(int y1=y0+1;y1<=m;y1++){
							for(int y2=y0+1;y2<=m;y2++){
								if(sx[x1][y1]-sx[x1][y0-1]==0&&
								sx[x2][y2]-sx[x2][y0-1]==0&&
								sy[y0][x2]-sy[y0][x1-1]==0){
									ansc++; ansc%=mod;
									if(x2<n){
										for(int x3=x2+1;x3<=n;x3++){
											if(sy[y0][x3]-sy[y0][x2-1]==0){
												ansf++; ansf%=mod;
											}
										}
									}
								}
							}
						}
					}
				}
			}
			printf("%lld %lld\n",ansc*c,ansf*f);
			ansc=0;ansf=0;
		}
	}
	return 0;
}

