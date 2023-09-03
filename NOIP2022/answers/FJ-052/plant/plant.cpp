#include<bits/stdc++.h>
using namespace std;
const int N=1010,mod=998244353;
int t,id,n,m,c,f,ro[N][N],co[N][N];
long long ans1,ans2,s1[N][N],s2[N][N];
bool mp[N][N];
int main(){
	freopen("plant.in","r",stdin);
	freopen("plant.out","w",stdout);
	scanf("%d%d",&t,&id);
	while(t--){
		scanf("%d%d%d%d",&n,&m,&c,&f),ans1=ans2=0;
		for(int i=1;i<=1005;i++)
			for(int j=1;j<=1005;j++)
				ro[i][j]=co[i][j]=s1[i][j]=s2[i][j]=0;
		for(int i=1;i<=n;i++){
			char ch;
			scanf("%c",&ch);
			for(int j=1;j<=m;j++){
				scanf("%c",&ch);
				if(ch=='1') mp[i][j]=1; 
				else mp[i][j]=0;
			}
		}
		if(!c&&!f){
			printf("0 0");
			break;
		}
		if(c)
		for(int i=n;i>0;i--)
			for(int j=m;j>0;j--)
				if(!mp[i][j]) ro[i][j]=ro[i][j+1]+1;
		if(f)
		for(int j=m;j>0;j--)
			for(int i=n;i>0;i--)
				if(!mp[i][j]) co[i][j]=co[i+1][j]+1;
		for(int j=m;j>0;j--)
			for(int i=n;i>0;i--)
				if(!mp[i][j]){
					s1[i][j]=s1[i+1][j];
					if(ro[i][j]>=2) {
						if(c)s1[i][j]+=ro[i][j]-1;
						if(f&&co[i][j]>=2) s2[i][j]+=(ro[i][j]-1)*(co[i][j]-1);
					}
				}
		for(int i=1;i<=n-2;i++)
			for(int j=1;j<=m;j++)
				if(ro[i][j]>=2&&!mp[i+1][j]){
					if(c)ans1=(ans1+(ro[i][j]-1)*s1[i+2][j])%mod;
					if(f)ans2=(ans2+(ro[i][j]-1)*s2[i+2][j])%mod;
				}
		/*for(int i=1;i<=n-2;i++)
			for(int j=1;j<=m;j++)
				if(ro[i][j]>=2)
					for(int k=i+2;k<=min(n,i+co[i][j]-1)&&!mp[k][j];k++){
						if(ro[k][j]>=2) {
							if(co[k][j]>=2) ans2+=(ro[i][j]-1)*(ro[k][j]-1)*(co[k][j]-1);
							ans1+=(ro[i][j]-1)*(ro[k][j]-1);
						}
					}*/
		printf("%lld %lld",c*ans1,f*ans2);
	}
	return 0;
}
