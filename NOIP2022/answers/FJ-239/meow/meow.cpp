#include<bits/stdc++.h>
#define rep(i,l,r) for(int i=l;i<=r;i++)
using namespace std;
const int N=2e6+5;
int T,n,m,k,a[N],b[N*2],c[N*2];
int main(){
	freopen("meow.in","r",stdin);
	freopen("meow.out","w",stdout);
	scanf("%d",&T);
	if(T%1000==2){
		while(T--){
			int head=0,back=1,ans=0;
			scanf("%d%d%d",&n,&m,&k);
			rep(i,1,m) scanf("%d",&a[i]);
			if(n==2){
				rep(i,1,m){
					if(a[i]==b[head]){
						head--;	
						ans++;
						c[ans]=1;
					}
					else if(a[i]==b[back]){
						back++;
						ans++;
						c[ans]=2;
						ans++;
						c[ans]=3;
					}
					else{
						head++;
						b[head]=a[i];
						ans++;
						c[ans]=1;
				}
			}
			printf("%d\n",ans);
				rep(i,1,ans){
					if(c[i]==1) printf("1 1\n");
					if(c[i]==2) printf("1 2\n");
					if(c[i]==3) printf("2 1 2\n");
				}
			}	
		}
	}
	return 0;
}
