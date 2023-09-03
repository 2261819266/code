#include<iostream>
#include<cstdio>
using namespace std;

int T,n,m,k,a[2000006],now[303][2],q,ans[4000006][2],tot=0;

int main(){
	freopen("meow.in","r",stdin);
	freopen("meow.out","w",stdout);
	scanf("%d",&T);
	for(int o=1;o<=T;o++){
		scanf("%d%d%d",&n,&m,&k);
		for(int i=1;i<=m;i++){
			scanf("%d",&a[i]);
		}
		q=0;tot=0;
		for(int i=1;i<=n;i++){
			now[i][0]=0;
			now[i][1]=0;
		}
		
		//if(k<=2*n-2){
			
			for(int i=1;i<=m;i++){
				int pos;
				if(a[i]<=n-1){
					pos=a[i];
				}
				else{
					pos=a[i]-n+1;
				}
				if(now[pos][0]!=a[i]&&now[pos][1]!=a[i]){
					ans[++tot][0]=pos;
					if(now[pos][0]>0)now[pos][1]=a[i];
					else now[pos][0]=a[i];
				}
				else{
					if(now[pos][0]==a[i]){
						ans[++tot][0]=n;
						ans[++tot][0]=pos;
						ans[tot][1]=n;
						now[pos][0]=now[pos][1];
						now[pos][1]=0;
					}
					else{
						ans[++tot][0]=pos;
						now[pos][1]=0;
					}
				}
				
			}
			printf("%d\n",tot);
			for(int i=1;i<=tot;i++){
				if(ans[i][1]>0){
					printf("2 %d %d\n",ans[i][0],ans[i][1]);
				}
				else{
					printf("1 %d\n",ans[i][0]);
				}
			}
		//}
	}
	
	return 0;
} 
