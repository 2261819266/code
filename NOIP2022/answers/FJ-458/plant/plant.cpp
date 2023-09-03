#include <bits/stdc++.h>
using namespace std;
long long c,f,vc,vf;
int t,id;
int n,m;
int d,e;
int a[1005],k,l;
char s[1005][1005] = {""};
int main(){
	freopen("plant.in","r",stdin);
	freopen("plant.out","w",stdout);
	scanf("%d%d",&t,&id);
	if(id == 1){
		for( ; t; t--){
			printf("0 0\n");
		}
	}
	for( ; t; t--){
		scanf("%d%d%d%d",&n,&m,&vc,&vf);
		for(int i = 1; i <= n; i++){
			for(int j = 1; j <= m; j++){
				cin >> s[i][j];
			}
		}
		/*for(int i = 0; i <= n; i++){
			for(int j = 0; j <= m; j++){
				cout << s[i][j];
			}
			cout << endl;
		}//*/
		for(int i = 1; i < m; i++){
			memset(a,0,sizeof(a));
			for(int j = 1; j <= n; j++){
				if(s[j][i] == '1'){
					continue;
				}
				k = i + 1;
				while(s[j][k] == '0'){
					a[j] += 1;
					k += 1;
				}
			}/*
			for(int j = 1; j <= n; j++){
				printf("%d ",a[j]);
			}
			printf("\n");
			//*/
			for(int j = 1; j <= n; j++){
				while(s[j][i] == '1' && a[j]){
					j += 1;
					if(j == n){
						break;
					}
				}
				d = j;
				e = j;
				while(s[e + 1][i] == '0'){
					e += 1;
					if(e == n){
						break;
					}
				}
				//printf("%d %d\n",d,e);
				for(l = j + 2; l <= e; l++){
					if(a[l] > 0){
						//printf("%d %d  %d\n",a[j],a[l],e - l);
						c += a[j] * a[l];
						f += a[j] * a[l] * (e - l);
						//c %= 998244353;
						//f %= 998244353;
					}
				}
			}//O(n^2)
		}//O(n^3)
		c = c * vc % 998244353;
		f = f * vf % 998244353;
		printf("%lld %lld\n",c,f);
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}//ÑùÀý 3 ºÃ³ô°¡°¡°¡°¡°¡°¡£¨ÄÕ
