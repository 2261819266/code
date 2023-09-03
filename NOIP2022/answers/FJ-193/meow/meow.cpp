#include<bits/stdc++.h>
#define re register
#define il inline
#define For(i,a,b) for(re int i=a;i<=b;++i)
using namespace std;
const int N = 305,K = 1005;
struct node{
	int p,x,y;
};
int T,n,m,k,posup[K],posdown[K];
int num,up[N],down[N];
node ans[K];
priority_queue<int,vector<int>,greater<int> > qdown,qup;
il int read(){
	int x=0,f=1;
	char c=getchar();
	for(;!isdigit(c);c=getchar())
		if(c=='-') f=-1;
	for(;isdigit(c);c=getchar())
		x=(x<<1)+(x<<3)+c-48;
	return x*f;
}
signed main(){
	freopen("meow.in","r",stdin);
	freopen("meow.out","w",stdout);
	T=read();
	while(T--){
		n=read(),m=read(),k=read();
		num=0;
		while(!qdown.empty()) qdown.pop();
		For(i,1,n-1) qdown.push(i);
		while(!qup.empty()) qup.pop();
		For(i,1,n-1) qup.push(i);
		memset(posdown,0,sizeof(posdown));
		memset(posup,0,sizeof(posup));
		memset(up,0,sizeof(up));
		memset(down,0,sizeof(down));
 		For(i,1,m){
			int a=read();
			if(posup[a]){
				ans[++num]=(node){1,posup[a],0};
				qup.push(posup[a]);
				up[posup[a]]=0;
				posup[a]=0;
			}
			else if(posdown[a]){
				ans[++num]=(node){1,n,0};
				ans[++num]=(node){2,posdown[a],n};
				if(up[posdown[a]]){
					qup.push(up[posdown[a]]);
					down[posdown[a]]=up[posdown[a]];
					posup[up[posdown[a]]]=0;
					posdown[up[posdown[a]]]=posdown[a];
					up[posdown[a]]=0;
				}
				else{
					down[posdown[a]]=0;
					qdown.push(posdown[a]);
				}
				posdown[a]=0;
			}
			else if(!qdown.empty()){
				int t=qdown.top();qdown.pop();
				ans[++num]=(node){1,t,0};
				posdown[a]=t;
				down[t]=a;
			}
			else{
				int t=qup.top();qup.pop();
				posup[a]=t;
				up[t]=a;
				ans[++num]=(node){1,t,0};
			}
		}
		printf("%d\n",num);
		For(i,1,num){
			if(ans[i].p==2) printf("2 %d %d\n",ans[i].x,ans[i].y);
			else printf("1 %d\n",ans[i].x);
		}
	}
	return 0;
}
