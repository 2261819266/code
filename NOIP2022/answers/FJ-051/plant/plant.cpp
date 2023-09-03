#include<stdio.h>
#include<string.h>
const int mod=998244353;
int t,id;
int n,m,c,f;
char a[1005][1005];
int top[1005],last[1005],hang[1005][1005],lie[1005][1005],ans1,ans2;
int sc[1005][1005],sf[1005][1005];
int main(){
	freopen("plant.in","r",stdin),freopen("plant.out","w",stdout);
	scanf("%d%d",&t,&id);
	while(t--){
		memset(top,0,sizeof top),memset(hang,0,sizeof hang),memset(lie,0,sizeof lie);
		memset(sc,0,sizeof sc),memset(sf,0,sizeof sf);
		scanf("%d%d%d%d",&n,&m,&c,&f);
		for(int i=1;i<=n;++i)scanf("%s",a[i]+1);
		for(int i=n;i;--i)for(int j=m;j;--j){
			hang[i][j]=a[i][j]^48^1?hang[i][j+1]+1:0;
			lie[i][j]=a[i][j]^48^1?lie[i+1][j]+1:0;
		}
		for(int i=n;i;--i)for(int j=m;j;--j){
			if(a[i][j]^48){
				sc[i][j]=0;
				sf[i][j]=0;
				top[j]=0;
				last[j]=0;
			}
			else {
				int k=top[j]-i==1?last[j]:top[j];
				sc[i][j]=(sc[top[j]][j]+hang[i][j]-1)%mod;
				sf[i][j]=(sf[top[j]][j]+(hang[i][j]-1ll)*(lie[i][j]-1ll)%mod)%mod;
				ans1=(ans1+(sc[k][j]*(hang[i][j]-1ll))%mod)%mod;
				ans2=(ans2+(sf[k][j]*(hang[i][j]-1ll))%mod);
				if(hang[i][j]!=1)last[j]=top[j],top[j]=i;
			}
		}
		printf("%d %d\n",ans1*c,ans2*f);
	}
}
