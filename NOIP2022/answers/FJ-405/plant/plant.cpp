#include<bits/stdc++.h>
using namespace std;
const long long mod=998244353;
long long T,id,n,m,c,f,a[1010][1010],check[1010][1010],ansc,ansf;
char s;
inline long long max(long long a,long long b) {
	return a>b?a:b;
}
int main() {
	freopen("plant.in","r",stdin);
	freopen("plant.out","w",stdout);
	cin >> T;
	cin >> id;
	while(T--) {
		cin >> n >> m >> c >> f;
		if(c==0&&f==0){
			cout << 0 << " " << 0 << endl;
			continue;
		}
		ansc=0,ansf=0;
		memset(check,0,sizeof(check));
		for(int i=1; i<=n; i++) {
			for(int j=1; j<=m; j++) {
				s=getchar();
				if(s==10) {
					s=getchar();
				}
				a[i][j]=s-48;
			}
		}
//		for(int i=1;i<=n;i++){
//			for(int j=1;j<=m;j++){
//				cout << a[i][j] << " ";
//			}
//			cout << endl;
//		}
		for(int i=1; i<=n; i++) {
			for(int j=m; j>=1; j--) {
				if(a[i][j]==1) {
					check[i][j]=0;
				} else {
					check[i][j]=check[i][j+1]+1;
				}
			}
		}
		for(int i=1; i<=m; i++) {
			int uy[1001]= {};
			for(int j=n; j>=1; j--) {
				if(a[j][i]==1) {
					uy[j]=0;
				} else {
					uy[j]=uy[j+1]+1;
				}
			}
			for(int j=1; j<=n; j++) {
				for(int k=j+1; k<=n; k++) {
					if(check[k][i]==0) {
						break;
					}
					if(k==j+1) continue;
					long long xx=max(check[j][i]-1,0),yy=max(check[k][i]-1,0);
					xx*=yy;
					xx%=mod;
					ansc+=xx;
					ansc%=mod;
					ansf+=xx*uy[k+1];
					ansf%=mod;
				}
			}
		}
		cout << c*ansc << " ";
		cout << f*ansf << endl;
	}




	return 0;
}
