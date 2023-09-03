#include<cstdio>
using namespace std;
int T,id,n,m;
long long c,f;
char a[10000];
int map[1001][1001];
long long cans=0,fans=0;
int main(){
	freopen("plant.in","r",stdin);
	freopen("plant.out","w",stdout);
	scanf("%d%d",&T,&id);
	while(T--){
		scanf("%d%d%lld%lld",&n,&m,&c,&f);
		for(int i=1;i<=n;i++){
			scanf("%s",&a);
			//printf("%s\n",a);
			for(int j=0;j<m;j++)map[i][j+1]=a[j]-'0';
		}
		if(c==0&&f==0){
			printf("0 0\n");
			continue;
		}
		if(c!=0){
			for(int i=1;i<=n-2;i++){
				for(int j=1;j<m;j++){
					long long c1=0,cans2=0;
					bool ff=false;
					if(map[i][j]==0&&map[i+1][j]==0&&map[i+2][j]==0){
						if(map[i][j+1]==0){
							c1=1;
							for(int y=j+2;y<=m&&map[i][y]==0;y++)c1++;
							long long c2=0;
							for(int x2=i+2;x2<=n&&map[x2][j]==0;x2++){
								if(map[x2][j+1]==0){
									ff=true;
									c2=1;
									for(int y1=j+2;y1<=m&&map[x2][y1]==0;y1++)c2++;
									cans2=(cans2+c1*c2)%998244353;
									c2=0;
								}
							}
						}
					}
					if(ff)cans=(cans+cans2)%998244353;
				}
			}
		}
		if(f!=0){
			for(int i=1;i<=n-3;i++){
				for(int j=1;j<m;j++){
					long long f1=0,fans2=0;
					bool ff=false;
					int x33=i;
					while(map[x33][j]==0&&x33<=n)x33++;
					x33--;
					if(map[i][j+1]==0){
						f1=1;
						for(int y=j+2;y<=m&&map[i][y]==0;y++)f1++;
					}else continue;
					if(x33-i>2){
						long long f2=0;
						for(int x2=i+2;x2<x33;x2++){
							if(map[x2][j+1]==0){
								ff=true;
								f2=1;
								for(int y1=j+2;y1<=m&&map[x2][y1]==0;y1++)f2++;
								long long f3=x33-x2;
								fans2=(fans2+f1*f2*f3)%998244353;
								f2=0;
							}
						}
					}
					if(ff)fans=(fans+fans2)%998244353;
				}
			}
		}
		cans=c*cans%998244353;
		fans=f*fans%998244353;
		printf("%lld %lld\n",cans,fans);
		cans=0;
		fans=0;
	}
	return 0;
}