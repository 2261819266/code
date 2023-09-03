/*
in:
1 0
6 6 1 1
000010
011000
000110
010000
011000
000000

ans: 36 18
*/
#include <bits/stdc++.h>
using namespace std;

struct CX {
	long long x, xx;
}sua[20005];

struct CandFY {
	long long y, yy, yyy;
}sub[20005];

struct FX {
	long long x, xx, xxx;
}nua[20005];

long long t, p;
char c[10001][10001];

int main () {
	freopen("plant.in","r",stdin);
	freopen("plant.out","w",stdout);
	scanf("%lld%lld",&t,&p);
ag:	while (t --) {
		long long sum=0,ans=0;
		long long n, m, co, fo;
		long long tot1=0,tot2=0,tot3=0;
		memset(sua, 0, sizeof(sua));
		memset(sub, 0, sizeof(sub));
		memset(nua, 0, sizeof(nua));
		scanf("%lld %lld %lld %lld",&n,&m,&co,&fo);
		for(int i=1;i<=n;i++){
			for(int j=1;j<=m;j++){
				cin>>c[i][j];
			}
		}
		if (co == 0 && fo == 0) {
			printf("0 0\n");
			goto ag;
		}
		//C
		for(int i=1;i<=n-2;i++){
			for(int j=i+2;j<=n;j++){
				tot1++;
				sua[tot1].x=i,sua[tot1].xx=j;
				//cout << sua[tot1].x <<","<<sua[tot1].xx<<endl;
			}
		}
		for(int i=1;i<=m-1;i++){
			for(int j=i+1;j<=m;j++){
				for(int k=j;k<=m;k++) {
					tot2++;
					sub[tot2].y=i,sub[tot2].yy=j,sub[tot2].yyy=k;
					//cout << sub[tot2].y <<","<<sub[tot2].yy<<","<<sub[tot2].yyy<<endl;
				}
			}
		}
		for (int i=1;i<=tot1;i++){
			for(int j=1;j<=tot2;j++){
				//x1 : y0 -> y1
				bool f1 = true;
				for(int k=sub[j].y;k<=sub[j].yy;k++){
					if(c[sua[i].x][k] == '1') {
//						cout << "yes\n";
						f1=false;
						break;
					}
				}
				if(f1 == false) continue;
				//x2: y0 -> y2
				for(int w=sub[j].y;w<=sub[j].yyy;w++){
					if(c[sua[i].xx][w] == '1') {
//						cout << "yes\n";
						f1=false;
						break;
					}
				}
				if(f1 == false) continue;
				//y0: x1 -> x2
				for(int u=sua[i].x;u<=sua[i].xx;u++){
					if(c[u][sub[j].y] == '1') {
//						cout << "yes\n";
						f1=false;
						break;
					}
				}
				if(f1 == false) continue;
				if(f1 == true) sum++;
//				cout << j << endl;
//				cout << sum << ": "<< sua[i].x <<"-"<<sua[i].xx <<endl;
//				cout << sum << ": "<< sub[j].y <<"-"<<sub[j].yy<<"-"<<sub[j].yyy <<endl;
			}
		}
		//F
		for(int i=1;i<=n-3;i++){
			for(int j=i+2;j<=n-1;j++){
				for(int k=j+1;k<=n;k++){
					tot3++;
					nua[tot3].x=i,nua[tot3].xx=j,nua[tot3].xxx=k;
				}
			}
		}
		for(int i=1;i<=tot3;i++){
			for(int j=1;j<=tot2;j++){
				//x1 : y0 -> y1
				bool f2 = true;
				for(int k=sub[j].y;k<=sub[j].yy;k++){
					if(c[nua[i].x][k] == '1') {
						f2=false;
						break;
					}
				}
				if(f2 == false) continue;
				//x2: y0 -> y2
				for(int w=sub[j].y;w<=sub[j].yyy;w++){
					if(c[nua[i].xx][w] == '1') {
						f2=false;
						break;
					}
				}
				if(f2 == false) continue;
				//y0: x1 -> x3
				for(int u=nua[i].x;u<=nua[i].xxx;u++){
					if(c[u][sub[j].y] == '1') {
						f2=false;
						break;
					}
				}
				if(f2 == false) continue;
				if(f2==true) ans++;
//				cout << j << endl;
			}
		}
		printf("%lld %lld\n", (sum*co)%998244353, (ans*fo)%998244353);
	}
	return 0;
}
/*

001
010
000
000

x1 = 1, x2 = 3
x1 = 1, x2 = 4
x1 = 2, x2 = 4

y1 = 1, y2 = 2, y3 = 2 -->**  -->**
                          *      *
                          **     *
                                 **
                          
y1 = 1, y2 = 2, y3 = 3 -->**  -->**
                          *      *
                          ***    *
                                 ***
y1 = 1, y2 = 3, y3 = 3 wa

y1 = 2, y2 = 3, y3 = 3 wa

                       

in:

1 0
16 12 1 1
000000000001
011111111111
000000000011
011111111111
010011111111
010111100011
010011101111
011111100011
111111111111
000011111111
011111111111
000000111111
011111000111
011111011111
011111000111
011111011111

ans:

114 514


*/
