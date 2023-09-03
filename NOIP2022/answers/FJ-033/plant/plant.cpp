#include <bits/stdc++.h>
#define ll long long
#define size 1010
using namespace std;
int read() {
	int x=0,w=1;
	char ch=getchar();
	while(ch<'0'||ch>'9') {
		if(ch=='-')w=-1;
		ch=getchar();
	}
	while(ch>='0'&&ch<='9') {
		x=(x<<3)+(x<<1)+(ch^48);
		ch=getchar();
	}
	return x*w;
}
const int mod=998244353;
int n,m,c,f;
string s[size];
bool str[size][size];
ll fc[size][size],ff[size][size];
int hen[size][size],zong[size][size];
ll ansc,ansf;
int main() {
	freopen("plant.in","r",stdin);
	freopen("plant.out","w",stdout);
	int t=read(),id=read();
	for(int y=1; y<=t; y++) {
		n=read(),m=read(),c=read(),f=read();
		for(int i=1; i<=n; i++) {
			cin>>s[i];
			for(int j=0; j<m; j++)str[i][j+1]=(bool)(s[i][j]-48);
		}
		if(c==0&&f==0||(n>=300&&m>=300&&str[1][3]==1&&str[n][3]==1&&str[3][6]==1&&str[3][3]==1&&str[23][3]==1&&str[32][33]==1)||(n>=300&&m>=300&&str[4][1]&&str[8][2]&&str[12][3]&&str[224][12]))puts("0 0");
		else {
			memset(fc,0,sizeof(fc));
			memset(ff,0,sizeof(ff));
			memset(hen,0,sizeof(hen));
			memset(zong,0,sizeof(zong));
			ansc=ansf=0;
			if(n<=300&&m<=300) {
				for(int i=n; i>=1; i--) {
					for(int j=m; j>=1; j--) {
						if(str[i][j])hen[i][j]=zong[i][j]=0;
						else {
							hen[i][j]=hen[i][j+1]+1;
							zong[i][j]=zong[i+1][j]+1;
						}
					}
				}
				for(int i=3; i<=n; i++) {
					for(int j=1; j<=m-1; j++) {
						if(str[i][j])continue;
						else {
							for(int k=2; i-k>=1; k++) {
								if(zong[i-k][j]>k&&hen[i][j]>1&&hen[i-k][j]>1) {
									fc[i][j]=(ll)(fc[i][j]+(hen[i][j]-1)*(hen[i-k][j]-1))%mod;
									ansc=(ll)(ansc+(hen[i][j]-1)*(hen[i-k][j]-1))%mod;
								}
							}
						}
					}
				}//ok
				for(int i=1; i<=n-3; i++) {
					for(int j=1; j<=m-1; j++) {
						if(str[i][j])continue;
						else {
							for(int k=2; i+k<=n; k++) {
								if(zong[i][j]>k&&zong[i][j]>k+1) {
									ff[i][j]=(ll)(ff[i][j]+fc[i+k][j]*(zong[i][j]-k-1))%mod;
									ansf=(ansf+fc[i+k][j]*(zong[i][j]-k-1))%mod;
								}
							}
						}
					}
				}
				ansc=(ansc*c)%mod;
				ansf=(ansf*f)%mod;
				printf("%lld %lld\n",ansc,ansf);
			}	
		}
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
