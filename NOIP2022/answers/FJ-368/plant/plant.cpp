//NOIP2022 RP++!
//in:plant.in
//out:plant.out
//Let us go!
#include <iostream>
#include <cstring>
#include <cstdio>
#define MOD 998244353
using namespace std;
int read(){
	int x=0;
	char c=getchar();
	while(c<'0'||c>'9') c=getchar();
	while(c>='0'&&c<='9') x=x*10+(c-'0'),c=getchar();
	return x;
}
void print(int _114514){
	if(_114514<10){
		putchar(_114514+'0');
		return;
	}
	print(_114514/10);
	putchar(_114514%10+'0');
}
int t,id;
int n,m,c,f;
int a[1001][1001];
int d[1001][1001];
int p[1001][1001];
int main(){
	freopen("plant.in","r",stdin);
	freopen("plant.out","w",stdout);
	t=read(),id=read();
	if(id==1){
		for(int i=1;i<=t;i++){
			print(0);
			putchar(' ');
			print(0);
			putchar('\n');
		}
	}
	else if(id==2){
		while(t--){
			n=read(),m=read(),c=read(),f=read();
			for(int i=1;i<=n;i++){
				for(int j=1;j<=m;j++){
					char ccc;
					ccc=getchar();
					a[i][j]=ccc-'0';
				}
			}
			if(a[1][1]==0&&a[1][2]==0&&a[2][1]==0&&a[3][1]==0&&a[3][2]==0){
				print(1);
				putchar(' ');
				print(0);
				putchar('\n');
			}
			else{
				print(0);
				putchar(' ');
				print(0);
				putchar('\n');
			}
		}
	}
	else if(id==3){
		while(t--){
			n=read(),m=read(),c=read(),f=read();
			for(int i=1;i<=n;i++){
				for(int j=1;j<=m;j++){
					char ccc;
					ccc=getchar();
					a[i][j]=ccc-'0';
				}
			}
			int cc=0,ff=0;
			if(a[1][1]==0&&a[1][2]==0&&a[2][1]==0&&a[3][1]==0&&a[3][2]==0) cc++;
			if(cc==1&&a[4][1]==0) ff++;
			if(a[1][1]==0&&a[1][2]==0&&a[2][1]==0&&a[3][1]==0&&a[4][1]==0&&a[4][2]==0) cc++;
			if(a[4][1]==0&&a[2][2]==0&&a[2][1]==0&&a[3][1]==0&&a[4][2]==0) cc++;
			print(cc);
			putchar(' ');
			print(ff);
			putchar('\n');
		}
	}
	else{
		while(t--){
			n=read(),m=read(),c=read(),f=read();
			for(int i=1;i<=n;i++){
				for(int j=1;j<=m;j++){
					char ccc;
					cin>>ccc;
					a[i][j]=ccc-'0';
				}
			}
			for(int i=1;i<=n;i++){
				for(int j=m;j;j--){
					if(a[i][j]==1||j==m) continue;
					d[i][j]=(a[i][j+1]==1?0:d[i][j+1]+1);
				}
			}
			for(int j=1;j<=m;j++){
				for(int i=n;i;i--){
					if(a[i][j]==1||i==n) continue;
					p[i][j]=(a[i+1][j]==1?0:p[i+1][j]+1);
				}
			}
			int cc=0,ff=0;
			for(int i=1;i<=n;i++){
				for(int j=1;j<=m;j++){
					if(j==m||a[i][j]==1||a[i+1][j]==1||a[i][j+1]==1) continue;
					int aaa=d[i][j];
					for(int k=i+2;k<=i+p[i][j];k++){
						if(a[k][j]==1) break;
						if(a[k][j+1]==1) continue;
						int bbb=d[k][j];
						cc=(cc+aaa*bbb%MOD)%MOD;
						if(k==n||a[k+1][j]==1) break;
						int ccc=p[k][j];
						ff=(ff+aaa*bbb%MOD*ccc%MOD)%MOD;
					}
				}
			}
			print(cc*c);
			putchar(' ');
			print(ff*f);
			putchar('\n');
		}
	}
	return 0;
}
//70pts
