#include<iostream>
#include<cstring>
using namespace std;
#define ll long long

int read(){
	int w=0;bool f=1;char c=getchar();
	while(!isdigit(c)){
		if(c=='-')f=0;c=getchar();
	}
	while(isdigit(c))w=(w<<3)+(w<<1)+(c^48);
	return f?w:-w;
}
void print(int x){
	if(x<0)x=-x,putchar('-');
	if(x>9)print(x/10);
	putchar(x%10+'0');
}
const int maxm=1e5;
const int mod=1e9+7;
struct nod{
	int n,v;
}e[maxm];
int cnt,h[maxm];
void add(int x,int y){e[++cnt]=nod{h[x],y};h[x]=cnt;}
ll ans;
ll qpow(int a,int w){
	ll res=1;
	while(w){
		if(w&1)res*=a,res%mod;
		a=a*a%mod;
		w>>=1;
	}
	return res%mod;
}
int n,m;
int f[1500][1500];

int main(){
	freopen("barrack.in","r",stdin);
	freopen("barrack.out","w",stdout);
	n=read();m=read();
	for(int i=1;i<=1500;++i)f[i][i]=1,f[i][0]=1,f[i][1]=i;
	for(int i=2;i<=1500;++i)
		for(int j=1;j<=i;++j)f[i][j]=f[i-1][j]+f[i-1][j-1];
	if(m=n-1){
		bool ff=1;int x,y;
		for(int i=1;i<=m;++i){
			x=read(),y=read();add(x,y);add(y,x);if(y!=x+1)ff=0;
		}
		if(f){
			ans=qpow(2,n);
			for(int i=n;i>=0;--i)ans+=f[n][i]*qpow(2,n-i)%mod;
		}
	}
	print(ans);
	return 0;
}
