#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
const int inf=998244353;
int n,m,t,mf,mc,id,c,f;
int nxt1[1001][1001],nxt2[1001][1001];
char cc[1002][1002];
int main(){
	freopen("plant.in","r",stdin);
	freopen("plant.out","w",stdout);
	scanf("%d%d",&t,&id);
	while(t--){
		int x,y,xx,yy,yyy;
		mc=mf=0;
		scanf("%d%d%d%d",&n,&m,&c,&f);
		for(int i=1;i<=n;++i)
		    scanf("%s",cc[i]+1);
		if(c==0&&f==0){
			printf("%d %d\n",mc,mf);
			continue;
		}
		for(int i=1;i<=n;++i)
		    cc[i][m+1]='1';
		for(int j=1;j<=m;++j)
		    cc[n+1][j]='1';
		memset(nxt1,0,sizeof(nxt1));
		memset(nxt2,0,sizeof(nxt2));
		for(int i=1;i<=n;++i)
			for(int j=1,w=1;j<=m+1;++j){
		        if(cc[i][j]=='1'){
		        	for(int k=w;k<j;++k)
		        	    nxt1[i][k]=j-1;
		        	w=j+1;
				}	
			}
		for(int i=1;i<=m;++i)
			for(int j=1,w=1;j<=n+1;++j){
		        if(cc[j][i]=='1'){
		        	for(int k=w;k<j;++k)
		        	    nxt2[k][i]=j-1;
		        	w=j+1;
				}
			}
		for(int i=1;i<=n;++i)
			for(int j=1;j<=m;j++)
			    if(nxt1[i][j]-j>0){
			    	y=j,yy=nxt1[i][j],x=i,xx=nxt2[i][j];
			    	if(xx-x+1==3){
			    		yyy=nxt1[xx][y];
			    		if(yyy-y>0)
			    			mc=((mc+(yyy-y)*(yy-y))*c)%inf;
					}
					else if(xx-x+1>3){
						for(int k=x+2;k<=xx;++k){
							yyy=nxt1[k][y];
			    		    if(yyy-y>0)
			    		        if(k!=xx){
			    		        	mc=((mc+(yyy-y)*(yy-y))*c)%inf;
			    		        	mf=((mf+(yyy-y)*(yy-y)*(xx-k))*f)%inf;
								}
			    			    else
								    mc=((mc+(yyy-y)*(yy-y))*c)%inf;  
						}
					}
				}
		printf("%d %d\n",mc,mf);
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
