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

int lg[250001];

namespace ST{
	int fa[250001][20],fb[250001][20];
	void init(int n,int*a,int*b){
		int i,j;
		for(i=1;i<=n;++i){
			fa[i][0]=a[i];
			fb[i][0]=b[i];
		}
		for(j=1;j<20;++j)
		for(i=1;i+(1<<j)-1<=n;++i){
			fa[i][j]=max(fa[i][j-1],fa[i+(1<<(j-1))][j-1]);
			fb[i][j]=max(fb[i][j-1],fb[i+(1<<(j-1))][j-1]);
		}
	}int qa(int l,int r){
		int lg=::lg[r-l+1];
		return max(fa[l][lg],fa[r-(1<<lg)+1][lg]);
	}int qb(int l,int r){
		int lg=::lg[r-l+1];
		return max(fb[l][lg],fb[r-(1<<lg)+1][lg]);
	}
}

namespace xm{
	int a[250001],b[250001];
	void _(){
		unsigned long long ans=0;
		int n,q,l,r,i,j,k,amx,bmx;
		
		scanf("%*d%d",&n);
		for(i=1;i<=n;++i) scanf("%d",a+i);
		for(j=1;j<=n;++j) scanf("%d",b+j);
		ST::init(n,a,b);
		scanf("%d",&q);
		while(q--){
			scanf("%d%d",&l,&r);
			ans=0;
			for(i=l;i<=r;++i)
			for(j=i;j<=r;++j){
				ans+=(ll)ST::qa(i,j)*ST::qb(i,j);
			}
			printf("%llu\n",ans);
		} 
	}
}

int main(){
	int i;
	
	for(i=2;i<250001;++i) lg[i]=lg[i/2]+1;
	
	freopen("match.in","r",stdin);
	freopen("match.out","w",stdout);
	xm::_();
	return 0;
}

