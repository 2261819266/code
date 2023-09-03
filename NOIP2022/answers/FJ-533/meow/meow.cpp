#include<bits/stdc++.h>
using namespace std;
const int N=601,M=2e6+1;
struct node{int t,x,y;}ans[M*2];
int st[N][N],top[N],low[N];
int T,n,m,k,a[M],opt;
inline int read(){
	int x=0,f=1;char c=getchar();
	while(c<'0'||c>'9'){if(c=='-')f=-f;c=getchar();}
	while(c>='0'&&c<='9'){x=x*10+c-'0';c=getchar();}
	return x*f;
}
int main(){
	freopen("meow.in","r",stdin);
	freopen("meow.out","w",stdout);
	T=read();
	while(T--){
		n=read(),m=read(),k=read();
		for(int i=1;i<=m;i++)a[i]=read();
		
		
		int now=1;
		while(now<=m){
			bool flag=0;
			for(int i=1;i<=n;i++){
				while(st[i][top[i]]==a[now]||top[i]==low[i]){
					ans[++opt].t=1;ans[opt].x=i;
					st[i][top[i]+1]=a[now];
					if(top[i]!=low[i])top[i]--;
					else top[i]++;
					now++;
					flag=1;
				}
			}
			for(int i=1;i<n;i++)
				for(int j=i+1;j<=n;j++)
					if(st[i][low[i]+1]==st[j][low[j]+1]&&top[i]!=low[i]&&top[j]!=low[j]){
						ans[++opt].t=2;
						ans[opt].x=i,ans[opt].y=j;
						low[i]++,low[j]++;
						flag=1;
					}
		}
		
		
		cout<<opt<<endl;
		for(int i=1;i<=opt;i++){
			cout<<ans[i].t<<' '<<ans[i].x;
			if(ans[i].t==1)cout<<endl;
			else cout<<' '<<ans[i].y<<endl;
		}
	}
	return 0;
}
/*
#include<bits/stdc++.h>
using namespace std;
const int N=4e6+1,M=301;
struct node{int opt,x,y;}ans[N];
int T,n,m,k,a[N];
int sta[N],stb[N],ha,hb,ta,tb;
queue<int>qwq[M];
inline int read(){
	int x=0,f=1;char c=getchar();
	while(c<'0'||c>'9'){if(c=='-')f=-f;c=getchar();}
	while(c>='0'&&c<='9'){x=x*10+c-'0';c=getchar();}
	return x*f;
}
void dfs(int now,int turn){
	if(turn>2*m)return ;
	if(now>m&&tb==hb&&ta==ha){
		cout<<turn<<endl;
		for(int i=1;i<=turn;i++)
			if(ans[i].opt==1)printf("1 %d\n",ans[i].x);
			else printf("2 1 2\n");
		exit(0);
	}
	turn++;
	if(sta[ta]==stb[tb]&&ta!=ha&&tb!=hb){
		ans[turn].opt=2;
		ta++,tb++;
		dfs(now,turn);
	}
	else if(a[now]==sta[ha]){
		ans[turn].opt=1,ans[turn].x=1;
		ha--;dfs(now+1,turn);
	}
	else if(a[now]==stb[hb]){
		ans[turn].opt=1,ans[turn].x=2;
		hb--;dfs(now+1,turn);
	}
	else{
		if(a[now]==a[now+1]){
			sta[++ha]=a[now];
			ans[turn].opt=1,ans[turn].x=1;
			dfs(now+1,turn);
		}
		else{
			if(a[now+1]==stb[hb]){
				sta[++ha]=a[now];
				ans[turn].opt=1,ans[turn].x=1;
				dfs(now+1,turn);
			}
			else{
				stb[++hb]=a[now];
				ans[turn].opt=1,ans[turn].x=2;
				dfs(now+1,turn);
			}
		}
	}
}
void workof2(){
	while(T--){
		n=read(),m=read(),k=read();
		for(int i=1;i<=m;i++)a[i]=read();
		sta[0]=0;stb[0]=0;
		ha=0,hb=0,ta=0,tb=0;
		dfs(1,0);
	}
}
void dfss(int now,int turn){
	
}
void haveatry(){
	while(T--){
		n=read(),m=read(),k=read();
		for(int i=1;i<=m;i++)a[i]=read();
		dfss(1,0);
	}
}
int main(){
//	freopen("meow.in","r",stdin);
//	freopen("meow.out","w",stdout);
	T=read();int opt=T%10;
	if(opt==2){workof2();return 0;}
	if(opt==3){haveatry();return 0;}
	while(T--){
		n=read(),m=read(),k=read();
		for(int i=1;i<=m;i++)a[i]=read();
		
	}
	return 0;
}
#include<bits/stdc++.h>
using namespace std;
const int N=2e6+1,M=601;
struct node{int t,x,y;}ans[N];
int a[N],opt,n,m,k,T;
int st[M][M],vis[M],use,tot[M],low[M];
inline int read(){
	int x=0,f=1;char c=getchar();
	while(c<'0'||c>'9'){if(c=='-')f=-f;c=getchar();}
	while(c>='0'&&c<='9'){x=x*10+c-'0';c=getchar();}
	return x*f;
}
int main(){
	freopen("meow.in","r",stdin);
	freopen("meow.out","w",stdout);
	T=read();
	while(T--){
		n=read(),m=read(),k=read();
		for(int i=1;i<=m;i++)a[i]=read();a[m+1]=0;
		memset(vis,0,sizeof(vis));
		memset(st,0,sizeof(st));
		
		for(int i=1;i<=m;i++){
			if(vis[a[i]]){
				ans[++opt]=(node){1,vis[a[i]]};
			}
			else{
				int tag=a[i]%(n-1)+1;
				ans[++opt]=(node){1,tag};
				st[tag][++]
			}
		}
		
		cout<<opt<<endl;
		for(int i=1;i<=opt;i++){
			cout<<ans[i].t<<' '<<ans[i].x;
			if(ans[i].t==1)cout<<endl;
			else cout<<' '<<ans[i].y<<endl;
		}
	}
	return 0;
}
*/
