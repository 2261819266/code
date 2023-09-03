#include<bits/stdc++.h>
#define rep(i,j,k) for(ll i=(j),_i=(k);i<=_i;i++) 
#define drp(i,j,k) for(ll i=(j),_i=(k);i>=_i;i--)
#define ll long long
#define Nx 1050
using namespace std;
const ll Mod=998244353;
char s[Nx];
ll T,id,n,m,c,f,sum_C,sum_F,Map[Nx][Nx];
ll r[Nx][Nx],u[Nx][Nx],d[Nx][Nx],tot;
void ini_r(){
	memset(r,0,sizeof(r));
	rep(i,1,n){
		tot=0;
		drp(j,m,1){
			if(Map[i][j]) r[i][j]=(tot=0);
			else r[i][j]=tot++;
			r[i][j]%=Mod;
		}
	} 
	return ;
}
void ini_u(){
	memset(u,0,sizeof(u));
	rep(j,1,m){
		tot=0;
		rep(i,1,n){
			if(Map[i][j]) u[i][j]=(tot=0);
			else tot+=r[i][j],u[i][j]=tot;
			u[i][j]%=Mod;
		}
	}
	return ;
} 
void ini_d(){
	memset(d,0,sizeof(d));
	rep(j,1,m){
		tot=0;
		drp(i,n,1){
			if(Map[i][j]) d[i][j]=(tot=0);
			else d[i][j]=tot++;
			d[i][j]%=Mod;
		}
	}
	return ;
}
int main()
{
	freopen("plant.in","r",stdin);
	freopen("plant.out","w",stdout);
	scanf("%lld%lld",&T,&id);
	while(T--){
		scanf("%lld%lld%lld%lld",&n,&m,&c,&f);
		rep(i,1,n){
			scanf("%s",s);
			rep(j,1,m)
				Map[i][j]=(s[j-1]-'0');
		}
		ini_r();ini_u();ini_d();
		sum_C=0;sum_F=0;
		rep(i,3,n){
			rep(j,1,m){
				if(!Map[i-1][j]){
					ll use=u[i-2][j]*r[i][j]%Mod;
					sum_C=(sum_C+use)%Mod;
					sum_F=(sum_F+(use*d[i][j]%Mod))%Mod;
				}	
			}
		}
		sum_C=(sum_C*c)%Mod;
		sum_F=(sum_F*f)%Mod;
		printf("%lld %lld\n",sum_C,sum_F);
	}
	return 0;
}
