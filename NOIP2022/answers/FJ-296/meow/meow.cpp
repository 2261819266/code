//Lin Shuyao AK chemistry exam FOREVER.
#include<cstdio>
#include<list>

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

namespace xm{
	std::list<int> stacks[301];
	int card[2000001];
	void _(){
		int n,m,K,i,j,x;

		scanf("%d%d%d",&n,&m,&K);
		if(K==n*2-2){
			while(m--){
				scanf("%d",&x);
				++x;
				if(stacks[x/2].size()==0){
					stacks[x/2].push_back(x);
					printf("1 %d\n",x/2);
				}else if(stacks[x/2].size()==1){
					if(stacks[x/2].back()==x){
						stacks[x/2].pop_back();
						printf("1 %d\n",x/2);
					}else{
						stacks[x/2].push_back(x);
						printf("1 %d\n",x/2);
					}
				}else{
					if(stacks[x/2].back()==x){
						stacks[x/2].pop_back();
						printf("1 %d\n",x/2);
					}else{
						stacks[x/2].pop_front();
						printf("1 %d\n2 %d %d\n",n,x/2,n);
					}
				}
			}
		}else if(n==2){
			for(i=1;i<=m;++i) scanf("%d",card+i);
			
		}
	}
}

int main(){
	int t;
	
	freopen("meow.in","r",stdin);
	freopen("meow.out","w",stdout);
	
// ¾­ µä ÓÀ Á÷ ´«  hack spj
//	puts("4");
//	puts("1 1");
//	puts("1 2");
//	puts("1 1");
//	puts("1 2");
//	fclose(stdin);
	//freopen("meow.in","w",stdout);
//	puts("1");
//	puts("2 4 2");
//	puts("1 2 1 2");
//	return 0;
	
	scanf("%d",&t);
	while(t--) xm::_();
	return 0;
}

