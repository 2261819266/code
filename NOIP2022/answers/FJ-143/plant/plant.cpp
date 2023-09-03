#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
typedef long long ll;
const int p=998244353;
int T,n,m,C,F,a[1005],b[1005],now,ans1,ans2;
char s[1005][1005];
inline void inc(int &x,int y){(x+=y)>=p?x-=p:0;}
int main(){
	freopen("plant.in","r",stdin);
	freopen("plant.out","w",stdout);
	scanf("%d%*d",&T);
	while(T--){
		scanf("%d%d%d%d",&n,&m,&C,&F);
		for(int i=1;i<=n;++i)
			scanf("%s",s[i]+1),a[i]=0;
		ans1=ans2=0;
		for(int k=m;k>=1;--k){
			for(int i=1;i<=n;++i){
				if(s[i][k]=='0')++a[i];
				else a[i]=0;
			}
			now=b[n+1]=0;
			for(int i=n;i>=1;--i){
				if(!a[i])b[i]=0;
				else b[i]=b[i+1]+1;
			}
			for(int i=3;i<=n;++i){
				if(!a[i] || !a[i-1] || !a[i-2]){
					now=0;
					continue;
				}
				inc(now,a[i-2]-1);
				ans1=(ans1+(a[i]-1ll)*now)%p;
				ans2=(ans2+(a[i]-1ll)*now%p*(b[i]-1))%p;
			}
		}
		ans1=(ans1*C+p)%p;
		ans2=(ans2*F+p)%p;
		printf("%d %d\n",ans1,ans2);
	}
	return 0;
}
