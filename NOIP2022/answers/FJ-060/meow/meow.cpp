#include<bits/stdc++.h>
#define rep(i,j,k) for(ll i=(j),_i=(k);i<=_i;i++) 
#define drp(i,j,k) for(ll i=(j),_i=(k);i>=_i;i--)
#define ll long long
#define Nx 100500
using namespace std;
ll T,n,m,k,a[20],sta[4][20],down[4],top[4],order[50][2];
bool flag;
void dfs(ll x)
{
	if(flag) return ;
	if(x>m){
		ll pos=x;
		bool use=true;
		while(use){
			use=false;
			rep(i,1,3){
				rep(j,i+1,3){
					if(sta[i][down[i]]==sta[j][down[j]]){
						use=true;
						down[i]++;
						down[j]++;	
						order[++pos][0]=i,order[pos][1]=j;
					}
				}
			}
		}
		if(down[1]>top[1]&&down[2]>top[2]&&down[3]>top[3]){
			rep(i,1,pos){
				if(!order[i][1]) printf("1 %lld\n",order[i][0]);
				else printf("2 %lld %lld\n",order[i][0],order[i][1]);
			}
			flag=true;
		}
		return ;
	}
	ll _sta[4][20];
	rep(i,1,3){
		rep(j,1,top[i]){
			_sta[i][j]=sta[i][j];
		}
	}
	rep(i,1,3){
		order[x][0]=i,sta[i][top[i]]==a[x]?top[i]--:sta[i][++top[i]]=a[x],dfs(x+1);
		rep(j,1,3){
			rep(k,1,top[i]){
				sta[j][k]=_sta[j][k];
			}
		}
		if(flag) return ;
	}
}
int main()
{
	freopen("meow.in","r",stdin);
	freopen("meow.out","w",stdout);
	scanf("%lld",&T);
	while(T--){
		scanf("%lld%lld%lld",&n,&m,&k);
		rep(i,1,m) scanf("%lld",&a[i]);
		down[1]=down[2]=down[3]=1;
		top[1]=top[2]=top[3]=0;
		flag=false;
		dfs(1);
	}
	return 0;
}
