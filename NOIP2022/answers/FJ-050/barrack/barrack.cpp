#include<bits/stdc++.h>
#define For(i,a,b) for(int i(a);i<=b;++i)
#define foR(i,a,b) for(int i(a);i>=b;--i)
#define int long long
using namespace std;
inline void read(int &x){
	x=0;bool w=0;char ch;ch=getchar();
	while(ch<'0'||ch>'9'){if(ch=='-')w=1; ch=getchar();}
	while(ch>='0'&&ch<='9'){x=x*10+ch-'0';ch=getchar();}
	if(w)x=-x;
}
inline void print(int x){
	if(x<0){putchar('-'); print(-x); return;}
	if(x>9){print(x/10);}putchar(x%10+'0');
}
const int N=1e6+78,Mod=1e9+7;
int n,m,Head[N],Next[N<<1],To[N<<1],cnt=1;
int num,dfn[N],stk[N],low[N],tp,tot,c[N];
bool ins[N],edg[N],v[N];int ecc[N],nm[N];
void add(int x,int y){
	Next[++cnt]=Head[x];Head[x]=cnt;To[cnt]=y;
}
void tarjan(int x,int e){
	dfn[x]=low[x]=++num;stk[++tp]=x;ins[x]=1;
	for(int i=Head[x];i;i=Next[i]){
		int y=To[i];
		if(!dfn[y]){
			tarjan(y,i);
			low[x]=min(low[x],low[y]);
		}
		else if(i!=(e^1)&&ins[y]){
			low[x]=min(low[x],dfn[y]);
		}
	}
	if(dfn[x]<=low[x]){
//		cout<<"ASSSS"<<e<<endl;
//		if(x==1)return ;
		edg[e]=edg[e^1]=1;
		ecc[e]=ecc[e^1]=++tot;
//		cout<<"!!"<<x<<endl;
		int y;
		do{
			y=stk[tp--];ins[y]=0;
			c[tot]++;nm[y]=tot;
		}while(y!=x);
	}
}
int ksm(int a,int b){
	int ans=1;
	while(b){
		if(b&1)ans=(ans*a)%Mod;
		a=(a*a)%Mod;b>>=1;
	}
	return ans%Mod;
}
int ans;
void ckck(int qwq){
	if(qwq==0)return ;
//	cout<<qwq<<endl;
	ans=(ans+ksm(2,m-qwq+1))%Mod;
}
void dfs(int x,int qwq){
	if(x==n+1){
		ckck(qwq);return ;
	}
	if(!v[nm[x]]){
		v[nm[x]]=1;
		dfs(x+1,qwq+1);
		v[nm[x]]=0;
	}
	else{
		dfs(x+1,qwq);
	}
	dfs(x+1,qwq);
}
int jc[N],inv[N];
int C(int n,int m){
	return jc[n]*inv[m]%Mod*inv[n-m]%Mod;
}
signed main(){
	freopen("barrack.in","r",stdin);
	freopen("barrack.out","w",stdout);
	read(n);read(m);
	int x,y;
	For(i,1,m){
		read(x);read(y);
		add(x,y);add(y,x);
	}
	if(m==n-1){
		jc[0]=1;
		For(i,1,n)jc[i]=(jc[i-1]*i)%Mod;
		inv[n]=ksm(jc[n],Mod-2);
		foR(i,n-1,0)inv[i]=(inv[i+1]*(i+1))%Mod;
		For(i,1,n){
			ans=(ans+C(n,i)*ksm(2,m-i+1)%Mod)%Mod;
		}
		print(ans);
		return 0;
	}
//	if(n==m){
//		
//		For(i,1,n)if(!dfn[i])tarjan(i,0);
//		For(i,1,tot)mx=max(mx,c[tot]);
//		print(ans);
//	}
	For(i,1,n)if(!dfn[i])tarjan(i,0);
//	For(i,1,n)cout<<i<<" "<<nm[i]<<endl;
	dfs(1,0);
	print(ans);
}
