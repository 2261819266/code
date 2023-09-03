#include<iostream>
#include<cstring>
using namespace std;

int read(){
	int w=0;bool f=1;char c=getchar();
	while(!isdigit(c)){
		if(c=='-')f=0;c=getchar();
	}
	while(isdigit(c))w=(w<<3)+(w<<1)+(c^48),c=getchar();
	return f?w:-w;
}
void print(int x){
	if(x<0)x=-x,putchar('-');
	if(x>9)print(x/10);
	putchar(x%10+'0');
}
const int maxm=20000;
const int N=90000;
const int mod=1e9;

//vector<int > v[N];
int q[301][maxm];
int h[301],t[301];
int f[N][5];
int a[maxm];

int n,m,k,T;
void pp(int x,int y,int z){
	if(x==1)print(x),putchar(' '),print(y);
	if(x==2)print(x),putchar(' '),print(y),putchar(' '),print(z);
	puts("");
}


int main(){
	freopen("meow.in","r",stdin);
	freopen("meow.out","w",stdout);
	T=read();
	while(T--){
		n=read(),m=read(),k=read();
		memset(a,0,sizeof(a));
		memset(f,0,sizeof(f));
		for(int i=1;i<=m;++i)a[i]=read();
		if(n==1&&k==0)return 0;
		if (k==1)for(int i=1;i<=m;puts(""),++i)print(1),putchar(' '),print(1);
		if(k==2*n-2){
			for(int i=m;i>=1;--i){
				int x=a[i];
				x=x%n;if(a[i]>=n)x++;
				if(!f[x][1])f[x][1]=a[i],pp(1,x,0);
				else if(f[x][2]==a[i])f[x][2]=0,pp(1,x,0);
				else if(f[x][1]==a[i])f[x][1]=f[x][2],f[x][2]=0,pp(1,n,0),pp(2,x,n);
			}
		}
		else {
			for(int i=m;i>=1;--i){
				int x=a[i];
				x=x%n;if(a[i]>=n)x++;
				if(!f[x][1])f[x][1]=a[i],pp(1,x,0);
				else if(f[x][2]==a[i])f[x][2]=0,pp(1,x,0);
				else if(f[x][1]==a[i])f[x][1]=f[x][2],f[x][2]=0,pp(1,n,0),pp(2,x,n);
			}
		}
	}
	return 0;
}
