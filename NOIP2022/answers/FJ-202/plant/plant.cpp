#include<cstdio>
#include<algorithm>
#include<cctype>
#include<cstring>
#include<iostream>
using namespace std;
typedef long long ll;
inline int read(){
	int f=1,num=0;
	char rd=getchar();
	while(!isdigit(rd)){
		if(rd=='-') f=-1;
		rd=getchar();
	}
	while(isdigit(rd)){
		num=num*10+rd-48;
		rd=getchar();
	}
	return f*num;
}
#define mod 998244353
char s[1030][1030];
int r[1030][1030],d[1030][1030];
void solve(){
	int n=read(),m=read(),c=read(),f=read();
	for(int i=1;i<=n;i++) scanf("%s",s[i]+1);
	for(int i=1;i<=n;i++) r[i][m+1]=m+1;
	for(int j=1;j<=m;j++) d[n+1][j]=n+1;
	for(int i=n;i>0;i--){
		for(int j=m;j>0;j--){
			if(s[i][j]=='0') r[i][j]=r[i][j+1],d[i][j]=d[i+1][j];
			else r[i][j]=j,d[i][j]=i;
		}
	}
	ll tot,temp,ans1=0,ans2=0;
	/*for(int i=1;i<=n;i++){
		for(int j=1;j<=m;j++) cout<<d[i][j]<<" ";
		puts("");
	}*/
	for(int j=1;j<=m;j++){
		tot=temp=0;
		for(int i=1;i<=n;i++){
			if(s[i][j]=='1'){
				tot=temp=0;
				continue;
			}
			ans1=(ans1+tot*(r[i][j]-j-1))%mod;
			ans2=(ans2+((tot*(r[i][j]-j-1))%mod)*(d[i][j]-i-1))%mod;
			tot+=temp;
			temp=r[i][j]-j-1;
			tot%=mod;
		}
	}
	ans1*=c;
	ans2*=f;
	printf("%lld %lld\n",ans1,ans2);
}
int main()
{
	freopen("plant.in","r",stdin);
	freopen("plant.out","w",stdout);
	int T=read(),id=read();
	while(T--) solve();
	return 0;
}
