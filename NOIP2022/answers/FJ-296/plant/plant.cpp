//Lin Shuyao AK chemistry exam FOREVER.
#include<cstdio>

//#define dxx
#ifdef dxx
#define dbg(...) fprintf(stderr,__VA_ARGS__)
#define dex(a) dbg(#a"=%lld onL%d infun %s\n",a,__LINE__,__FUNCTION__)
#include<cstdlib>
#define pause sys##tem("pause")
#endif

using ll=long long;
template<class T> T max(T a,T b){return a>b?a:b;}
template<class T> T min(T a,T b){return a<b?a:b;}
template<class T> void cmax(T&a,T b){a=max(a,b);}
template<class T> void cmin(T&a,T b){a=min(a,b);}
template<class T> T sqr(T a){return a*a;}
template<class T> T abs(T a){return a<0?-a:a;}
template<class T> void swap(T&a,T&b){T t=a;a=b;b=t;}

// F-word the weak sample!
// Sample3:114514 ≥ÙÀ¿¡¶£®±Ø£© 

namespace xm{
	const ll mod=998244353;
	ll dspansumforc[1005][1005],dspansumforf[1005][1005];
	int n,m,c,f,rspan[1005][1005],dspan[1005][1005];
	char sz[1005][1005];
	ll calcC(){
		ll ans=0;
		int x1,y0;
		
		if(c==0) return 0;
		for(x1=1;x1<=n;++x1)
		for(y0=1;y0<=m;++y0)
			if(dspan[x1][y0]>x1+1&&rspan[x1][y0]!=y0)
				ans=(ans+(ll)(rspan[x1][y0]-y0)*dspansumforc[x1+2][y0]%mod)%mod;
				
		return ans;
	}ll calcF(){
		ll ans=0;
		int x1,y0;
		
		if(f==0) return 0;
		for(x1=1;x1<=n;++x1)
		for(y0=1;y0<=m;++y0)
			if(dspan[x1][y0]>x1+2&&rspan[x1][y0]!=y0)
				ans=(ans+(ll)(rspan[x1][y0]-y0)*dspansumforf[x1+2][y0]%mod)%mod;
				
		return ans;
	}
	void _(){
		int i,j;
		
		scanf("%d%d%d%d",&n,&m,&c,&f);
		if(c==0&&f==0) puts("0 0");
		else{
			for(i=1;i<=n;++i){
				scanf("%s",sz[i]+1);
				for(j=m;j;--j){
					if(sz[i][j]=='1') rspan[i][j]=0;
					else if(j==m) rspan[i][j]=m;
					else if(sz[i][j+1]=='1') rspan[i][j]=j;
					else rspan[i][j]=rspan[i][j+1];
				}
			}
			
			for(j=1;j<=m;++j){
				for(i=n;i;--i){
					if(sz[i][j]=='1'){
						dspan[i][j]=0;
						dspansumforc[i][j]=0;
						dspansumforf[i][j]=0;
					}else if(i==n){
						dspansumforc[i][j]=rspan[i][j]-j;
						dspansumforf[i][j]=0;
						dspan[i][j]=n;
					}else if(sz[i+1][j]=='1'){
						dspansumforc[i][j]=rspan[i][j]-j;
						dspansumforf[i][j]=0;
						dspan[i][j]=i;
					}else{
						dspan[i][j]=dspan[i+1][j];
						dspansumforc[i][j]=(dspansumforc[i+1][j]+rspan[i][j]-j)%mod;
						dspansumforf[i][j]=(dspansumforf[i+1][j]+(rspan[i][j]-j)*(dspan[i][j]-i)%mod)%mod;
					}
				}
			}
			
#ifdef dxx
			for(i=1;i<=n;++i,dbg("\n")) for(j=1;j<=m;++j) dbg("%d ",rspan[i][j]);
			dbg("\n");
			for(i=1;i<=n;++i,dbg("\n")) for(j=1;j<=m;++j) dbg("%d ",dspan[i][j]);
			dbg("\n");
			for(i=1;i<=n;++i,dbg("\n")) for(j=1;j<=m;++j) dbg("%lld ",dspansumforf[i][j]);
#endif

			printf("%lld %lld\n",calcC(),calcF());
		}
	}
}

int main(){
	int t;
	
	freopen("plant.in","r",stdin);
	freopen("plant.out","w",stdout);
	
	scanf("%d%*d",&t);
	while(t--) xm::_();
	return 0;
}
//rp++
