#include<bits/stdc++.h>
using namespace std;
const int p=1e9+7;
long long n,m,s[1000010],ans,a[1010],b[1010],s1[1000010],s2[1010][1010];

bool check(int x,int y){
	if(x==y) return true;
	s1[x]=1;
	for(int i=1;i<=n;i++){
		if(s1[i]==1||i==x) continue;
		if(s2[x][i]==1&&check(i,y)) return true;
	}
	return false;
}

void h(){
	long long flag=0,cnt=1;
	for(int i=1;i<=n;i++){
		if(s[i]==1){
			flag=1;
			break;
		}
	}
	if(!flag) return;
	for(int i=1;i<=m;i++){
		flag=0;
		s2[a[i]][b[i]]=0;
		s2[b[i]][a[i]]=0;
		
		for(int j=1;j<=n;j++){
			for(int k=j+1;k<=n;k++){
//				cout<<j<<" "<<k<<endl;
				memset(s1,0,sizeof s1);
				if(s[j]==1&&s[k]==1&&!check(j,k)){
					flag=1;
					break;
				}
			}
		}
		s2[a[i]][b[i]]=1;
		s2[b[i]][a[i]]=1;
		if(!flag) cnt*=2;
		cnt%=p;
	}
	ans+=cnt;
	ans%=p;
}
		

void dfs(int u){
	if(u==n+1){
		h();
//		for(int i=1;i<=n;i++){
//			cout<<s[i]<<" ";
//		}
//		cout<<endl;
//		cout<<ans<<endl;
		return;
	}
	dfs(u+1);
	s[u]=1;
	dfs(u+1);
	s[u]=0;
}

int main(){
	freopen("barrack.in","r",stdin);
	freopen("barrack.out","w",stdout);
	scanf("%lld%lld",&n,&m);
	for(int i=1;i<=m;i++){
		scanf("%lld%lld",&a[i],&b[i]);
		s2[a[i]][b[i]]=1;
		s2[b[i]][a[i]]=1;
	}
	dfs(1);
	printf("%lld",ans%p);
	return 0;
}
