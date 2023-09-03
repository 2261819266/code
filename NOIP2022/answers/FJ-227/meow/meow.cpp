#include <bits/stdc++.h>
using namespace std;
int t;
int p=1,q=1,e=1,ans_num=1,tot=0;
struct an{
	int meant;
	int vis_num;
}ans[4000005];
long long a[2000005],s1[1000005],s2[1000005],s3[1000005];
int main(){
	freopen("meow.in","r",stdin);
	freopen("meow.out","w",stdout);
	scanf("%d",&t);
	while(t--){
	    long long n,m,k;
	    scanf("%lld%lld%lld",&n,&m,&k);
		for(int i=1;i<=m;i++){
			scanf("%lld",&a[i]);
		}
		if(n==2){
			queue<int> b;
			queue<int> c;
			b.push(a[1]);
			ans[1].meant=1;
			ans[1].vis_num=1;
			for(int i=2;i<=m;i++){
				if(b.back()=a[i-1]){
					b.push(a[i]);
					ans[i].meant=1;
					ans[i].vis_num=2;
					tot++;
				}else if(c.back()=a[i-1]){
					c.push(a[i]);
					ans[i].meant=1;
					ans[i].vis_num=2;
					tot++;
				}else{
					c.push(a[i]);
					ans[i].meant=1;
					ans[i].vis_num=2;
					tot++;
				}
				while(b.front()==c.front()){
					b.pop();
					c.pop();
					ans[i].meant=2;
					tot++;
				}
				printf("%lld",&tot);
				for(int i=1;i<=tot;i++){
					if(ans[i].meant==1){
						printf("1 %d\n",ans[i].vis_num);
					}else{
						printf("2 1 2\n");
					}
				}
			}
	    }
	    if(n==3){
	    	queue<int> b;
	    	queue<int> c;
	    	queue<int> d;
		}
	    memset(a,0,sizeof(a));
	}
	return 0;
}
