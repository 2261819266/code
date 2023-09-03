#include<bits/stdc++.h>
#define mod 998244353
#define N 1004
using namespace std;
int t,id,n,m,c,f,ans1,ans2;
bool a[N][N];
int lng[N][N],vc[N];

inline int getop(){
	char ch=getchar();
	while(ch!='0'&&ch!='1')ch=getchar();
	return ch^48;
}
int main(){
	freopen("plant.in","r",stdin);
	freopen("plant.out","w",stdout);
	
	scanf("%d%d",&t,&id);
	while(t--){
		ans1=ans2=0;
		memset(lng,0,sizeof(lng));
		scanf("%d%d%d%d",&n,&m,&c,&f);
		for(int i=1;i<=n;i++)
			for(int j=1;j<=m;j++)
				a[i][j]=getop();
		for(int i=1;i<=n;i++)
			for(int j=m;j;j--)
				if(!a[i][j])lng[i][j]=lng[i][j+1]+1;
		if(!c&&!f){
			printf("0 0\n");
			continue;
		}
		for(int j=1;j<m;j++){
			memset(vc,0,sizeof(vc));
			for(int i=1,cnt=0,f=0,s=0,fs=0;i<=n;i++){
				if(a[i][j]){
					cnt=f=s=fs=0;
					continue;
				}
				if(a[i][j+1]){
					f=fs=0;
					continue;
				}
				if(f){
					ans1=(ans1+1ll*lng[i][j+1]*(s-fs)%mod)%mod;
					vc[i]=1ll*lng[i][j+1]*(s-fs)%mod;
				}
				else{
					ans1=(ans1+1ll*lng[i][j+1]*s%mod);
					vc[i]=1ll*lng[i][j+1]*s%mod;
				}
				cnt++,f=1,s=(s+lng[i][j+1])%mod,fs=lng[i][j+1];
			}
			for(int i=n,cnt=0;i;i--){
				if(a[i][j]){
					cnt=0;
					continue;
				}
				cnt++;
				ans2=(ans2+1ll*cnt*vc[i-1]%mod)%mod;
			}
		}
		
		printf("%d %d\n",ans1*c,ans2*f);
	}
}
