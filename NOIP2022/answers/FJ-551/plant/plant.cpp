#include<iostream>
using namespace std;
char a[1001][1001];
int main(){
	freopen("plant.in","r",stdin);
	freopen("plant.out","w",stdout);
	int T,id;
	scanf("%d%d",&T,&id);
	while(T--){
		int n,m,c,f;
		long long ansc=0,ansf=0;
		scanf("%d%d%d%d",&n,&m,&c,&f);
		getchar();
		for(int i=1;i<=n;i++){
			for(int j=1;j<=m;j++) a[i][j]=getchar();
			getchar();
		}
		if(!c&&!f){
			printf("0 0\n");
			continue;
		}
		for(int jxwx1=1;jxwx1<=n;jxwx1++)
			for(int jxwx2=jxwx1+2;jxwx2<=n;jxwx2++)
				for(int jxwy0=1;jxwy0<=m;jxwy0++)
					for(int jxwy1=jxwy0+1;jxwy1<=m;jxwy1++)
						for(int jxwy2=jxwy0+1;jxwy2<=m;jxwy2++){
							bool f=0;
							for(int i=jxwy0;i<=jxwy1;i++) if(a[jxwx1][i]=='1'){
								f=1;
								break;
							}
							if(f) continue;
							for(int i=jxwy0;i<=jxwy2;i++) if(a[jxwx2][i]=='1'){
								f=1;
								break;
							}
							if(f) continue;
							for(int i=jxwx1;i<=jxwx2;i++) if(a[i][jxwy0]=='1'){
								f=1;
								break;
							}
							if(f) continue;
							ansc++;
						}
		for(int jxwx1=1;jxwx1<=n;jxwx1++)
			for(int jxwx2=jxwx1+2;jxwx2<=n;jxwx2++)
				for(int jxwx3=jxwx2+1;jxwx3<=n;jxwx3++)
					for(int jxwy0=1;jxwy0<=m;jxwy0++)
						for(int jxwy1=jxwy0+1;jxwy1<=m;jxwy1++)
							for(int jxwy2=jxwy0+1;jxwy2<=m;jxwy2++){
								bool f=0;
								for(int i=jxwy0;i<=jxwy1;i++) if(a[jxwx1][i]=='1'){
									f=1;
									break;
								}
								if(f) continue;
								for(int i=jxwy0;i<=jxwy2;i++) if(a[jxwx2][i]=='1'){
									f=1;
									break;
								}
								if(f) continue;
								for(int i=jxwx1;i<=jxwx3;i++) if(a[i][jxwy0]=='1'){
									f=1;
									break;
								}
								if(f) continue;
								ansf++;
							}
		printf("%lld %lld\n",ansc*c%998244353,ansf*f%998244353);
	}
	return 0;
}
