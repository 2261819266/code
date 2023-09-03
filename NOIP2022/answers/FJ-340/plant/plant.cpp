#include<bits/stdc++.h>
#define int long long
#define reg register
using namespace std;
const int N=1e3+10,mod=998244353;
int n,m,c,f,ans1,ans2;
int len[N][N],down[N][N];
char a[N][N];
signed main(){
	freopen("plant.in","r",stdin);freopen("plant.out","w",stdout);
	reg int _,id; scanf("%lld%lld",&_,&id);
	while (_--){
		ans1=ans2=0;
		scanf("%lld%lld%lld%lld",&n,&m,&c,&f); 
		for (reg int i=1;i<=n;i++) scanf("%s",a[i]+1);
		for (reg int i=1;i<=n+1;i++) for (reg int j=1;j<=m+1;j++) len[i][j]=down[i][j]=0;
		for (reg int j=m;j;j--) for (reg int i=1;i<=n;i++) if (a[i][j]=='0') len[i][j]=len[i][j+1]+1;
		for (reg int i=n;i;i--) for (reg int j=1;j<=m;j++) if (a[i][j]=='0') down[i][j]=down[i+1][j]+1;
	//	for (reg int i=1;i<=n;i++,puts("")) for (reg int j=1;j<=m;j++) cout<<len[i][j]<<" ";
		for (reg int j=1;j<=m;j++){
			reg int sum=0,cnt=0;
		    for (reg int i=1;i<=n;i++) if (a[i][j]=='1') cnt=sum=0; else{
				ans1=(ans1+(len[i][j]-1)*sum%mod)%mod;
				if (cnt) sum+=len[i-1][j]-1,sum%=mod; cnt++;
			}
		}
		for (reg int j=1;j<=m;j++){
			reg int sum=0,cnt=0;
		    for (reg int i=1;i<=n;i++) if (a[i][j]=='1') cnt=sum=0; else{
				ans2=(ans2+(len[i][j]-1)*sum%mod*(down[i][j]-1)%mod)%mod;
				if (cnt) sum+=len[i-1][j]-1,sum%=mod; cnt++;
			}
		}
		printf("%lld %lld\n",(ans1*c%mod+mod)%mod,(ans2*f%mod+mod)%mod);
	}
	return 0;
}