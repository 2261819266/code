#include<cstdio>
#include<algorithm>
#include<cstring>
#include<queue>
const int H=100000010;
char G[H],*_=G;
int read(){
	int x=0;
	while(*_<'0'||'9'<*_)_++;
	while('0'<=*_&&*_<='9')x=x*10+(*_++&15);
	return x;
}
int t;
//if all a2 < a1 , we can push last one in stack last , other wise we can push the last one on the top of the a2 < a1 stack.
const int N=606,M=2000020;
int n,m,k,tot,a[M],p[M],vis[N],st[N][N],si[N],res[M];
struct point{
	int op,id;
	//op=0 under 
	//op=1 up
}b[N];
std::queue<int>Q1,Q2,Q3,Q4;
struct node{
	int op,x,y;
}c[M<<1]; 
void work(){
	n=read(),m=read(),k=read(),memset(vis,0,sizeof(int)*(k+1)),memset(si,0,sizeof(int)*(n+1)),tot=0;
	int hh=0,tt=0;
	for(int i=1;i<=m;i++){
		a[i]=read(),p[i]=0;
		if(vis[a[i]])p[vis[a[i]]]=i,vis[a[i]]=0;
		else vis[a[i]]=i;
	}
	if(k==2*n-2){
		for(int i=1;i<=n-1;i++)Q1.push(i);
		for(int i=1;i<=m;i++){
			if(!p[i]){
				if(b[a[i]].op==0)c[++tot]={1,n,0},c[++tot]={2,b[a[i]].id,n};
				else c[++tot]={2,b[a[i]].id,0};
				si[b[a[i]].id]--,Q1.push(i);
			}
			else {
				int u=Q1.front();Q1.pop();
				st[u][++si[u]]=i,c[++tot]={1,u,0};
				if(si[u]==1)b[a[i]]={0,u};
				else b[a[i]]={1,u};
				if(si[u]<=1)Q1.push(u);
			}	
		}
		goto Qzong;
	}
	while(Q1.size())Q1.pop();
	while(Q2.size())Q2.pop();
	for(int i=1;i<=n-1;i++)Q1.push(i);
	for(int i=1,now=1,lst=0;i<=m;i++){
		if(!p[i]){
			if(b[a[i]].op==0){
				c[++tot]={1,n,0},c[++tot]={2,b[a[i]].id,n};
				for(int i=2;i<=si[b[a[i]].id];i++)st[b[a[i]].id][i-1]=st[b[a[i]].id][i];
				si[b[a[i]].id]--;
				if(si[b[a[i]].id])b[a[st[b[a[i]].id][1]]].op=0;
				else Q1.push(b[a[i]].id);
				if(si[b[a[i]].id]==2&&st[b[a[i]].id][2]>st[b[a[i]].id][1]);
			}
			else {
				c[++tot]={1,b[a[i]].id,0},si[b[a[i]].id]--;
			}
		}
		else if(a[i]>st[now][si[now]]){
			if(si[now]<=1){
				st[now][++si[now]]=i,c[++tot]={1,now,0},lst=tot;
				if(si[now]==1)b[a[i]]={0,now};
				else b[a[i]]={1,now};
			}
			else {
				si[now]--;
				int u=Q1.front();Q1.pop();
				Q2.push(now),now=u;
				c[lst]={1,now,0},c[++tot]={1,now,0},lst=tot;
			}
		}
		else {
			st[now][++si[now]]=i,c[++tot]={1,now,0},lst=tot;
			if(si[now]>=3){
				now=Q2.front();Q2.pop(); 
			}
		}
	}
//	for(int i=1,lst;i<=m;i++){
//		if(!p[i]){
//			
//		}
//		else {
//			if(!si[1]||p[i]<p[st[1][si[1]]])st[1][++si[1]]=i,c[++tot]={1,1,0},lst=tot;
//			else {
//				
//			}
//		}
//	}
	Qzong:;
	printf("%d\n",tot);
	for(int i=1;i<=tot;i++){
		if(c[i].op==1)printf("%d %d\n",c[i].op,c[i].x);
		else printf("%d %d %d\n",c[i].op,c[i].x,c[i].y);
	}
}
int main(){
	freopen("meow.in","r",stdin),freopen("meow.out","w",stdout);
	fread(G,1,H,stdin),t=read();
	while(t--)work();
	return 0;
}
