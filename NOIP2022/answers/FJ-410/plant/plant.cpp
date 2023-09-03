#include<bits/stdc++.h>
#define ll long long
using namespace std;
const ll mod=998244353;
const int N=1005;
int n,m,a[N][N],shang[N][N],fa[N*N],sum[N][N],b[N*N],num[N][N],T,id,bb[N*N];
ll c,f,ansc,ansf;
char s[N];
inline void dd(int &ss){
	ss=0;int ff=1;
	char ch=getchar();
	while(ch<'0'||ch>'9'){
		if(ch=='-') ff=-1;
		ch=getchar();
	}
	while(ch>='0'&&ch<='9'){
		ss=ss*10+ch-'0',ch=getchar();
	}
	ss*=ff;
}
int find(int x){
	return fa[x]==x?x:fa[x]=find(fa[x]);
}
void work(){
	dd(n),dd(m);scanf("%lld%lld",&c,&f);
	
	int cnt=0;
	for(int i=1;i<=n;++i){
		scanf("%s",s);
		for(int j=1;j<=m;++j){
			num[i][j]=++cnt;
			a[i][j]=(s[j-1]=='1');
			fa[num[i][j]]=num[i][j];
		}
	}
	for(int i=1;i<=n;++i){
		for(int j=m;j>=1;--j){
			if(j+1<=m&&!a[i][j]&&!a[i][j+1]){
				sum[i][j]=sum[i][j+1]+1;
			}
		}
	}
	for(int i=1;i<=n;++i){
		for(int j=1;j<=m;++j){
			if(!a[i][j])
			shang[i][j]=1;
			if(!a[i-1][j]&&!a[i][j]){
				if(i-1){
					fa[find(num[i-1][j])]=find(num[i][j]);
					shang[i][j]=shang[i-1][j]+1;
				}
			}
		}
	}
	for(int i=n;i>=1;--i){
		for(int j=1;j<=m;++j){
			int u=find(num[i][j]);
			if(!b[u]&&shang[i][j]>=3){
				int l=i-shang[i][j]+1,r=i;
				ll df=sum[l][j];
				for(int k=l+2;k<=r;++k){
					ansc=(ansc+df*(ll)sum[k][j]%mod)%mod;
					df=(df+(ll)sum[k-1][j])%mod;
				}
				b[u]=1;
			}
		}
	}
	printf("%lld ",ansc*c%mod);
	for(int i=n;i>=1;--i){
		for(int j=1;j<=m;++j){
			int u=find(num[i][j]);
			if(!bb[u]&&shang[i][j]>=4){
				int l=i-shang[i][j]+1,r=i;
				ll df=sum[l][j];
				for(int k=l+2;k<=r;++k){
					ansf=(ansf+df*(ll)sum[k][j]%mod*(ll)(r-k)%mod)%mod;
					df=(df+(ll)sum[k-1][j])%mod;
				}
				bb[u]=1;
			}
		}
	}
	printf("%lld",ansf*f%mod);
}
int main(){
	freopen("plant.in","r",stdin);
	freopen("plant.out","w",stdout);
	
	dd(T),dd(id);
	while(T--){
		work();
		printf("\n");
	}
}
