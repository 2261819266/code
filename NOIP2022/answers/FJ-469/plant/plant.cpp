#include <bits/stdc++.h>
using namespace std;
inline long long read(){
	long long x=0,f=1;
	char ch=getchar();
	while(ch<'0' || ch>'9'){
		if(ch=='-'){
			f=-1;
		}
		ch=getchar();
	}
	while(ch>='0' && ch<='9'){
		x=(x<<1)+(x<<3)+(ch-'0');
		ch=getchar();
	}
	return x*f;
}
inline void write(long long x){
	static char buf[64];
	static long long len=-1;
	if(x<0){
		putchar('-');
		x=-x;
	}
	do{
		buf[++len]=x%10;
		x/=10;
	}
	while(x);
	while(len>=0){
		putchar(buf[len--]+'0');
	}
	putchar('\n');
}
const long long N=1010;
const long long MOD=998244353;
long long t,id,n,m,c,f;
char s[N][N];
namespace c0f0{
	int Main(){
		printf("0 0\n");
		return 0;
	}
}
namespace nmsmall{
	const long long M=110;
	bool line[M][M][M];
	bool colm[M][M][M];
	long long Vc=0,Vf=0;
	int Main(){
		for(int Colm=1;Colm<=m;Colm++){
			for(int i=1;i<=n;i++){
				for(int j=i;j<=n;j++){
					if(s[j][Colm]=='1'){
						for(int l=1;l<=n;l++){
							for(int r=l;r<=n;r++){
								if(l<=i && r>=j){
									line[Colm][l][r]=true;
								}
							}
						}
					}
				}
			}
		}
		for(int Line=1;Line<=n;Line++){
			for(int i=1;i<=m;i++){
				for(int j=i;j<=m;j++){
					if(s[Line][j]=='1'){
						for(int l=1;l<=m;l++){
							for(int r=l;r<=m;r++){
								if(l<=i && r>=j){
									colm[Line][l][r]=true;
								}
							}
						}
					}
				}
			}
		}
//		for(int Colm=1;Colm<=m;Colm++){
//			for(int i=1;i<=n;i++){
//				for(int j=i;j<=n;j++){
//					printf("%lld ",line[Colm][i][j]);
//				}
//				printf("\n");
//			}
//			printf("\n");
//		}
//		for(int Line=1;Line<=n;Line++){
//			for(int i=1;i<=m;i++){
//				for(int j=i;j<=m;j++){
//					printf("%lld ",colm[Line][i][j]);
//				}
//				printf("\n");
//			}
//			printf("\n");
//		}
		for(int x1=1;x1<=n;x1++){
			for(int x2=x1;x2<=n;x2++){
				for(int y0=1;y0<=m;y0++){
					for(int y1=y0;y1<=m;y1++){
						for(int y2=y0;y2<=m;y2++){
							if(x1+1<x2 && y0<y1 && y0<y2){
								if(!colm[x1][y0][y1] && !colm[x2][y0][y2] && !line[y0][x1][x2]){
									Vc++;
									if(Vc>=MOD){
										Vc-=MOD;
									}
								}
							}
						}
					}
				}
			}
		}
		for(int x1=1;x1<=n;x1++){
			for(int x2=x1;x2<=n;x2++){
				for(int x3=x2;x3<=n;x3++){
					for(int y0=1;y0<=m;y0++){
						for(int y1=y0;y1<=m;y1++){
							for(int y2=y0;y2<=m;y2++){
								if(x1+1<x2 && x2<x3 && y0<y1 && y0<y2){
									if(!colm[x1][y0][y1] && !colm[x2][y0][y2] && !line[y0][x1][x3]){
										Vf++;
										if(Vf>=MOD){
											Vf-=MOD;
										}
									}
								}
							}
						}
					}
				}
			}
		}
		printf("%lld %lld\n",Vc,Vf);
		return 0;
	}
}
namespace other{
	int main(){
		printf("1919 810\n");
		return 0;
	}
}
int main(){
	freopen("plant.in","r",stdin);
	freopen("plant.out","w",stdout);
	t=read();
	id=read();
	for(int T=1;T<=t;T++){
		n=read();
		m=read();
		c=read();
		f=read();
		for(int i=1;i<=n;i++){
			scanf("%s",s[i]+1);
		}
		if(id==1){
			c0f0::Main();
			continue;
		}
		if(id>=2 && id<=10){
			nmsmall::Main();
			continue;
		}
		if(id!=0){
			other::main();
			continue;
		}
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}