#include <bits/stdc++.h>
using namespace std;
long long n,m;
pair<long long,long long> a[50];
long long fa[50];
long long find(long long x){
	if(fa[x]!=0){
		fa[x]=find(fa[x]);
		return fa[x];
	}
	return x;
}
long long cnt[50];
long long num;
long long ans=0;
int flag[50][50];
int p[50][50];
int tmp[50][50];
int main(){
	freopen("barrack.in","r",stdin);
	freopen("barrack.out","w",stdout);
	scanf("%lld%lld",&n,&m);
	for(long long i=1;i<=m;i++){
		long long uu,vv;
		scanf("%lld%lld",&uu,&vv);
		a[i]=make_pair(uu,vv);
		p[uu][vv]=p[vv][uu]=1;
	}
	for(long long i=0;i<(1<<m);i++){
		memset(flag,0,sizeof(flag));
		memset(fa,0,sizeof(fa));
		fill(cnt+1,cnt+n+1,1);
		num=n;
		for(long long j=1;j<=m;j++){
			if(i&(1<<(j-1))){
				long long t1,t2;
				t1=find(a[j].first);
				t2=find(a[j].second);
				if(t1!=t2){
					fa[t2]=t1;
					num--;
					cnt[t1]+=cnt[t2];
					cnt[t2]=-1;
				}
			}
		}
//		cout<<find(3)<<endl;
		memset(tmp,0,sizeof(tmp));
//		for(long long l=1;l<=n;l++){
			for(long long j=1;j<=n;j++){
				for(long long k=j+1;k<=n;k++){
					if(p[j][k]==1){
						tmp[find(j)][find(k)]++;
						if(tmp[find(j)][find(k)]+tmp[find(k)][find(j)]>=2){
							if(find(j)!=find(k)){
	//							cout<<find(k)<<" "<<find(j)<<" "<<cnt[find(k)]<<" "<<cnt[find(j)]<<endl;
								cnt[find(k)]+=cnt[find(j)];
								cnt[find(j)]=-1;
								fa[find(j)]=find(k);
								num--;
							}
						}
					}
				}
			}
//		}
		
		for(long long j=1;j<=n;j++){
			if(cnt[j]!=-1){
//				cout<<j<<":"<<cnt[j]<<endl;
				long long tmp=(1<<cnt[j])-1;
				tmp%=1000000007;
				ans+=tmp;
				ans%=1000000007;
//				cout<<"-->"<<j<<" "<<tmp<<endl;
			}
		}
//		cout<<"/"<<i<<" "<<ans<<endl;
	}
	printf("%lld\n",ans);
	return 0;
}
