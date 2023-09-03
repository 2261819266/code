#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define ull unsigned long long
#define rint register int
int n,m;
int a[1500][1500];//hl
const int p=998244353;
int row(int k,int q) {//ÐÐ
	int cnt=1;
	if(a[k][q]==1)return 0;
	for(int i=q; i<=m; i++) {
		if(a[k][i]==0&&a[k][i+1]==0&&i+1<=m)cnt++;
		else break;
	}
	return cnt;
}
inline int col(int q,int k) {//ÁÐ
	int cnt=1;
	if(a[q][k]==1||k==m)return 0;
	for(int i=q; i<=n; i++) {
		if(a[i][k]==0&&a[i+1][k]==0&&i<=n-1)cnt++;
		else break;
	}
	return cnt;
}
inline int power_row(int x) {
	return x-1;
}
inline int power_col(int x) {
	if(x==1||x==0)return x;
	return (x-1)*(x-2)/2;
}
int main() {
	freopen("plant.in","r",stdin);
	freopen("plant.out","w",stdout);
	int c,f,T,id;
	string s;
	scanf("%d%d",&T,&id);
	while(T--) {
		int ansc=0,ansf=0;
		scanf("%d%d%d%d",&n,&m,&c,&f);
		for(int i=1; i<=n; i++) {
			cin>>s;
			for(int j=1; j<=m; j++) {
				a[i][j]=s[j-1]-'0';
			}
		}
		for(int k=1; k<=m; k++)
			for(int i=1; i<=n; i++) {
				int tmp=row(i,k);
				if(tmp>=2)
					for(int j=i+2; j<=n; j++) {
						bool flag=0;
						for(int lg=i; lg<=j; lg++)if(a[lg][k]==1)flag=1;
						if(row(j,k)>=2 and flag==0)
							ansc+=((power_row(tmp)%p)*((row(j,k)-1)%p))%p,ansc%=p;
					}
			}
		printf("%d ",c*ansc%p);
		for(int k=1; k<=m; k++)
			for(int i=1; i<=n; i++) {
				int tmp=row(i,k);
				if(tmp>=2)
					for(int j=i+2; j<=n; j++) {
						bool flag=0;
						for(int lg=i; lg<=j; lg++)if(a[lg][k]==1)flag=1;
						if(row(j,k)>=2&&flag==0&&col(j+1,k)!=0) {
							ansf+=((power_row(tmp)%p))*((power_row(row(j,k)))%p)*((col(j,k)-1)%p) %p,ansf%=p;
						}
					}
			}
		printf("%d",ansf*f%p);
	}

	return 0;
}
//10:40 finish
