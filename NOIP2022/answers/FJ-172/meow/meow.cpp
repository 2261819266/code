#include<iostream>
#include<cstdio>
#include<algorithm>
#define LL long long
using namespace std;
inline int read(){
	int s=0,t=1; char ch=getchar();
	while(ch<'0'||ch>'9'){
		if(ch=='-')t=-1;
		ch=getchar();
	}
	while(ch>='0'&&ch<='9'){
		s=(s*10)+ch-'0';
		ch=getchar();
	}
	return s*t;
}
const int maxn=2000010;
int T,n,m,k,pad[maxn];
int zpa[maxn],top=0,bot=0;
int op,ans[maxn<<1][4];
/*struct zhan{
	int pa[maxn>>2],top,bot;
}z[301];*/
int main(){
	freopen("meow.in","r",stdin);
	freopen("meow.out","w",stdout);
	T=read(); 
	while(T--){
		n=read(); m=read(); k=read();
	    for(int i=1;i<=m;i++) pad[i]=read();
	    op=0; top=0; bot=0;
	    //int ppz=1;
	    for(int p=1;p<=m;p++){
	    	if(top==bot){
	    		zpa[++top]=pad[p];
	    		ans[++op][0]=2;
	    		ans[op][1]=1;
	    		ans[op][2]=1;
	    		//printf("1 1\n");
			}
			else if(zpa[top]==pad[p]){
				top--;
				ans[++op][0]=2;
	    		ans[op][1]=1;
	    		ans[op][2]=1;
				//printf("1 1\n");
			}
			else if(zpa[bot+1]==pad[p]){
				bot++;
				ans[++op][0]=2;
	    		ans[op][1]=1;
	    		ans[op][2]=2;
	    		ans[++op][0]=3;
	    		ans[op][1]=2;
	    		ans[op][2]=1;
	    		ans[op][3]=2;
				//printf("1 2\n2 1 2\n");
			}
			else{
				zpa[++top]=pad[p];
				ans[++op][0]=2;
	    		ans[op][1]=1;
	    		ans[op][2]=1;
				//printf("1 1\n");
			}
		}
		printf("%d\n",op);
		for(int i=1;i<=op;i++){
			for(int j=1;j<=ans[i][0];j++){
				printf("%d ",ans[i][j]);
			}
			printf("\n");
		}
	    
	}
	return 0;
}
