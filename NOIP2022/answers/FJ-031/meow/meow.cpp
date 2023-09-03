#include<bits/stdc++.h>
#define N 2000010
using namespace std;

int read() {
	int x=0,f=1;char ch=getchar();
	while(!isdigit(ch)) f=ch=='-'?-1:1,ch=getchar();
	while(isdigit(ch)) x=x*10+ch-'0',ch=getchar();
	return x*f;
}
int T,n,m,k,a[N],p[610],ot[N],xx[N],yy[N],on;
void add(int opt,int x,int y) {
	ot[++on]=opt,xx[on]=x,yy[on]=y;
}
int main() {
	freopen("meow.in","r",stdin);
	freopen("meow.out","w",stdout);
	T=read();
	while(T--) {
		n=read(),m=read(),k=read(),on=0;
		for(int i=1; i<=m; i++) a[i]=read();
		if(k==2*n-2) {
			for(int i=1; i<=m; i++) {
				int flag=0;
				for(int j=1; j<n; j++) if(p[j]==a[i]) add(1,n,0),add(2,j,n),p[j]=p[j+n],p[j+n]=0,flag=1;
				if(flag) continue;
				for(int j=n+1; j<2*n; j++) if(p[j]==a[i]) add(1,j-n,0),p[j]=0,flag=1;
				if(flag) continue;
				for(int j=1; j<n; j++) if(!p[j]) add(1,j,0),p[j]=a[i],flag=1;
				if(flag) continue;
				for(int j=n+1; j<2*n; j++) if(!p[j]) add(1,j-n,0),p[j]=a[i];
			}
			printf("%d\n",on);
			for(int i=1; i<=on; i++) {
				printf("%d ",ot[i]);
				if(ot[i]==1) printf("%d\n",xx[i]);
				else printf("%d %d\n",xx[i],yy[i]);
			}
			continue;
		}
	}
}
