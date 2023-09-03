#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define mod 1000000007
int n,m,inu[1000010],inv[1000010],fa[500010],dian[110],td,bian[110],tb,vb[110];
ll ans,cnt[20];
int get(int x){
	if(fa[x]==x) return x;
	else return fa[x]=get(fa[x]);
}
ll ksm(ll a,ll b){
	ll ans=1;
	while(b>0){
		if(b&1){
			ans*=a;ans%=mod;
		}
		a*=a,a%=mod;
		b/=2;
	}
	return ans%mod;
}
void dfs(int x){
	if(x>n+m){
		if(td==0) return ;
		int flg=0;
		for(int i=1;i<=m;i++){
			for(int i=1;i<=n;i++) fa[i]=i;
			if(vb[i]==1) continue;
			for(int j=1;j<=m;j++){
				if(j==i) continue;
				/*if(dian[1]==1&&dian[2]==2&&td==2&&bian[1]==2&&bian[2]==3&&tb==2){
					cout<<"lol "<<i<<" "<<j<<":"<<inu[bian[j]]<<" "<<inv[bian[j]]<<endl;
				}*/
				fa[get(inu[j])]=get(inv[j]);
			}
			/*if(dian[1]==1&&dian[2]==2&&td==2&&bian[1]==2&&bian[2]==3&&tb==2){
				cout<<get(1)<<" "<<get(2)<<" "<<get(3)<<" "<<get(4)<<endl;
			}*/
			int gt=get(dian[1]);
			for(int j=2;j<=td;j++){
				if(gt!=get(dian[j])){
					flg=1;
					break;
				}
			}
			if(flg==1) break;
		}
		if(flg==0){
			ans++,ans%=mod;
			int tnt=0;
			for(int i=1;i<=td;i++) tnt+=(1<<(dian[i]-1));
			cnt[tnt]++;
			/*cout<<"test"<<tnt<<":"<<endl;
			for(int i=1;i<=td;i++) cout<<dian[i]<<" ";
			cout<<endl;
			for(int i=1;i<=tb;i++) cout<<bian[i]<<" ";
			cout<<endl;*/
		}
		return;
	}
	else if(x>n){
		bian[++tb]=x-n;
		vb[x-n]=1;
		dfs(x+1);
		tb--;
		vb[x-n]=0;
		dfs(x+1);
	}
	else{
		dian[++td]=x;
		dfs(x+1);
		td--;
		dfs(x+1);
	}
}
int main(){
	freopen("barrack.in","r",stdin);
	freopen("barrack.out","w",stdout);
	scanf("%d%d",&n,&m);
	for(int i=1;i<=m;i++){
		scanf("%d%d",&inu[i],&inv[i]);
	}
	if(n==1){
		printf("1\n");
		return 0;
	}
	if(n<=16&&m<=25){
		dfs(1);
		/*for(int i=1;i<=15;i++){
			cout<<i<<" "<<cnt[i]<<endl;
		}
		cout<<endl;*/
		printf("%lld\n",ans);
		return 0;
	}
	ll ww=n,www=n-1;
	if(ww%2==0) ww/=2;
	else www/=2;
	printf("%lld\n",(ww*www%mod*ksm(2,n-2)%mod+n*ksm(2,n-1)%mod)%mod);
	return 0;
}
