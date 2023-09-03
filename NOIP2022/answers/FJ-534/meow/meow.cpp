#include<bits/stdc++.h>
using namespace std;
/*
1
2 4 2
1 2 1 2

*/
int main(){
	freopen("meow.in","r",stdin);
	freopen("meow.out","w",stdout);
	int T;
	cin>>T;
	for(int ii=1;ii<=T;ii++){
		int n,m,k;
		cin>>n>>m>>k;
		int z[n+10][21000];
		int zz[21000];
		int bookz[n+1]={m};
		for(int j=1;j<=m;j++){
			scanf("%d",&z[0][m-j+1]);
			zz[m-j+1]=z[0][m-j+1];
		}
		int ans=0;
		while((bookz[0])>0){//先求操作次数 
			bool shuchu=0;
			for(int i=1;i<=n;i++){
				if(z[0][bookz[0]]==z[i][bookz[i]]){
					ans++;
					z[0][bookz[0]]=0;
					z[i][bookz[i]]=0;
					bookz[i]--;
					bookz[0]--;
				}
			}
			if(bookz[0]<=0)break;
			int kongzhan=0;
			for(int i=1;i<=n;i++){
				if(bookz[i]==0){
					kongzhan=i;
					break;
				}
			}
			if(bookz[0]<=0)break;
			for(int i=1;i<=n;i++){
				if(z[0][bookz[0]]==z[i][0]){
					ans+=2;
					shuchu=1;
					for(int j=1;j<bookz[i];j++){
						z[i][j]=z[i][j+1];
					}
					bookz[i]--;
					bookz[0]--;
					break;
				}
			}
			if(bookz[0]<=0)break;
			if(kongzhan){
			ans++;
			z[kongzhan][++bookz[kongzhan]]=z[0][bookz[0]];
			bookz[0]--;
			}
		}
		cout<<ans<<endl;
		bookz[0]=m;//恢复原栈 
		for(int j=1;j<=m;j++){//恢复原栈 
			z[0][j]=zz[j];
		}
		while((bookz[0])>0){//求操作顺序 
			bool shuchu=0;
			for(int i=1;i<=n;i++){
				if(z[0][bookz[0]]==z[i][bookz[i]]){
			printf("1 %d\n",i);
					z[0][bookz[0]]=0;
					z[i][bookz[i]]=0;
					bookz[i]--;
					bookz[0]--;
				}
			}
			if(bookz[0]<=0)break;
			int kongzhan=0;
			for(int i=1;i<=n;i++){
				if(bookz[i]==0){
					kongzhan=i;
					break;
				}
			}
			if(bookz[0]<=0)break;
			for(int i=1;i<=n;i++){
				if(z[0][bookz[0]]==z[i][0]){
					printf("1 %d\n",kongzhan);
					printf("2 %d %d\n",kongzhan,i);
					shuchu=1;
					for(int j=1;j<bookz[i];j++){
						z[i][j]=z[i][j+1];
					}
					bookz[i]--;
					bookz[0]--;
					break;
				}
			}
			if(bookz[0]<=0)break;
			if(kongzhan){
			printf("1 %d\n",kongzhan);
			z[kongzhan][++bookz[kongzhan]]=z[0][bookz[0]];
			bookz[0]--;
			}
		}
	}
	return 0;
}
