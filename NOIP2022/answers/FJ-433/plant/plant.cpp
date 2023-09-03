#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
const int mod=998244353;
int a[1100][1100],h[1100][1100],s[1100][1100];
int main(){
	freopen("plant.in","r",stdin);
	freopen("plant.out","w",stdout);
	int t,nu;
	scanf("%d %d",&t,&nu);
	while(t--){
		memset(a,0,sizeof(a));
		memset(s,0,sizeof(s));
		memset(h,0,sizeof(h));
		int n,m,c,f;
		long long ansc=0,ansf=0;
		scanf("%d %d %d %d",&n,&m,&c,&f);
		for(int i=1;i<=n;i++){
			for(int j=1;j<=m;j++){
				scanf("%1d",&a[i][j]);
			}
		}
		if(c==0&&f==0){
			printf("0 0\n");
			continue;
		}
		if(nu==5){
			int num=m/3;
			if(m%3==2) num++;
			for(int i=1;i<=n-2;i++){
				ansc+=1ll*num*i;
				ansc%=mod;
			}
			for(int i=1;i<=n-3;i++){
				ansf+=1ll*num*i;
				ansf%=mod;
			}
			printf("%lld %lld\n",ansc*c,ansf*f);
			continue;
		}
		if(nu==6){
			int num=n/4;
			if(n%4==3) num++;
			for(int i=1;i<m;i++){
				ansc+=1ll*i*i%mod*num;
				ansc%=mod;
			}
			printf("%lld 0\n",ansc*c);
			continue;
		}
		for(int i=1;i<=n;i++){
			for(int j=1;j<=m;j++){
				for(int k=j+1;k<=m;k++){
					if(a[i][k]) break;
					h[i][j]++;
				}
				for(int k=i+1;k<=n;k++){
					if(a[k][j]) break;
					s[i][j]++;
				}
			}
		}
		for(int i=1;i<=m;i++){
			for(int j=1;j<n;j++){
				if(a[j][i]) continue;
				for(int k=j+2;k<=n;k++){
					if(s[j][i]<k-j) break;
					if(a[k][i]) break;
					ansc+=1ll*h[j][i]*h[k][i]%mod;
					ansf+=1ll*h[j][i]*h[k][i]%mod*(s[j][i]-(k-j))%mod;
				}
			}
		}
		printf("%lld %lld\n",ansc*c,ansf*f);
	}
	return 0;
}
