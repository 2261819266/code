#include<bits/stdc++.h>
using namespace std;
int t,n,m,e[1500][1500],id,ansc,ansf,c,f,mod=998244353;
char s[1500];
void find(int x,int y){
	int y1,x2,upcf=0,underc=0,underf=0;
	if(e[x+1][y]==1||e[x+2][y]==1||e[x][y+1]==1||e[x][y]==1)return;
	y1=y+1;
	while(e[x][y1]==2){++y1;++upcf;}
	x2=x+2;
	while(e[x2][y]==2){
		y1=y+1;
		while(e[x2][y1]==2){
		    ++y1;
			++underc;
			int xx=x2+1;
			while(e[xx][y]==2){++xx;++underf;}
		}
		++x2;
	}
	ansc=ansc+upcf*underc%mod;
	ansf=ansf+upcf*underf%mod;
	return;
}
int main(){
	freopen("plant.in","r",stdin);
	freopen("plant.out","w",stdout);
	scanf("%d%d",&t,&id);
	while(t--){
		scanf("%d%d%d%d",&n,&m,&c,&f);
		ansc=0;ansf=0;
		for(int i=1;i<=n;++i){
		    cin>>s;
		    for(int j=0;j<m;++j){
		    	if(s[j]=='0')e[i][j+1]=2;
		    	else e[i][j+1]=1;
			}
		}
		for(int i=1;i<=n;++i)
		    for(int j=1;j<=m;++j){
		    	find(i,j);
			}
		c=c*ansc%mod;
		f=f*ansf%mod;
		printf("%d %d\n",c,f);
		for(int i=1;i<=n;++i)
		    for(int j=1;j<=m;++j)
		        e[i][j]=0;
	}
	return 0;
}
//=60?100
