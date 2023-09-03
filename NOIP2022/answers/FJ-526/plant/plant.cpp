#include<bits/stdc++.h>
using namespace std;
const int N=998244353;
long long t,id,n,m,c,f,cc,ff,b1,b2,l1;
int flag[1010][1010];
string s;
int main() {
	freopen("plant.in","r",stdin);
	freopen("plant.out","w",stdout);
	scanf("%lld",&t);
	for(int x=1; x<=t; x++) {
		scanf("%lld",&id);
		scanf("%d %d %d %d",&n,&m,&c,&f);
		c=c%N;
		f=f%N;
		if(c==0&&f==0) {
			cout<<"0 0"<<endl;
		} else {
			cc=ff=0;
			for(int i=1; i<=n; i++) {
				cin>>s;
				for(int j=1; j<=m; j++) {
					if(s[j-1]=='0') {
						flag[i][j]=0;
					}
					if(s[j-1]=='1') {
						flag[i][j]=1;
					}
				}
			}
			for(int x1=1; x1<=n-2; x1++) {
				for(int y1=1; y1<=m-1; y1++) {
					if((flag[x1][y1]==0)&&(flag[x1][y1+1]==0)&&
					        (flag[x1+1][y1]==0)&&(flag[x1+2][y1]==0)) {
						for(int i=y1+1; i<=m; i++) {
							if(flag[x1][i]==1) {
								b1=i-y1-1;
								i=m+1;
							}
							if(flag[x1][m]==0&&i==m) {
								b1=i-y1;
								i=m+1;
							}
						}
						for(int j=x1+2; j<=n; j++) {
							if(flag[j][y1]==1) {
								l1=j-1;
								j=n+1;
							}
							if(flag[n][y1]==0&&j==n) {
								l1=n;
								j=n+1;
							}
						}
						for(int j=x1+2; j<=l1; j++) {
							if(flag[j][y1+1]==0) {
								for(int k=y1; k<=m; k++) {
									if(flag[j][k]==1) {
										b2=k-y1-1;
										k=m+1;
									}
									if(k==m) {
										if(flag[j][m]==0) {
											b2=k-y1;
											k=m+1;
										}
									}
								}
								cc+=b1*b2;
								cc=cc%N;
								ff=ff+b1*b2*(l1-j);
								ff=ff%N;
							}
						}
					}
				}
			}
			long long vc=(cc*c)%N;
			long long vf=(ff*f)%N;
			printf("%lld %lld\n",vc,vf);
		}
	}
	return 0;
}
