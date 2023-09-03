#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
int dis[2000001][4],n,m,k,t,f[301];
int main(){
	freopen("meow.in","r",stdin);
	freopen("meow.out","w",stdout);
	scanf("%d",&t);
	while(t--){
		memset(f,0,sizeof(f));
		memset(dis,0,sizeof(dis));
		int op=0;
		scanf("%d%d%d",&n,&m,&k);
		for(int i=1;i<=m;++i)
		    scanf("%d",&dis[i][0]);
		for(int i=1;i<=m;++i){
			if(dis[i][1]!=0) continue;
			for(int r=i+1;r<=m;++r)
			    if(dis[i][0]==dis[r][0]&&dis[r][1]==0){
			    	for(int x=1;x<=n;++x){
			    		if(f[x]<i){
			    	    	f[x]=i;
			    	    	dis[i][1]=x;
			    	    	op+=1;
			    	    	break;
						}
					}
					for(int x=1;x<=n;++x){
						if(f[x]<r&&x!=dis[i][1]){
			    	    	f[x]=r;
			    	    	op+=1;
			    	    	dis[r][1]=x;
			    	    	dis[r][2]=1;
			    	    	dis[r][3]=dis[i][1];
			    	    	op+=1;
			    	    	break;
						}
					}
				}
		}
		printf("%d\n",op);
		for(int i=1;i<=m;++i){
			printf("1 %d\n",dis[i][1]);
			if(dis[i][2]==1){
				printf("2 %d %d\n",dis[i][3],dis[i][1]);
			}
		}
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
