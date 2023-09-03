#include<iostream>
#include<cstring>
#include<cstdio>
#include<algorithm>
#include<queue>
#define SIZE 2000005
using namespace std;
int T,n,m,k,cho[SIZE];
int a[SIZE],op[2*SIZE],x[SIZE],y[SIZE],z[SIZE],tx,ty,tz;
bool fl;
void dfs(int num) {
	if(num>=m) {
		int totx=tx,toty=ty,totz=tz;
		while(x[totx] || y[toty] || z[totz]) {
			bool t=0;
			if(x[totx]==y[toty]) totx++,toty++,t=1;
			if(x[totx]==z[totz]) totx++,totz++,t=1;
			if(y[toty]==z[totz]) toty++,totz++,t=1;
			if(!t) return ;
		}
		fl=1;
		for(int i=1;i<=m;i++) {
			cout<<"1 "<<cho[i]<<endl;
		}
		while(x[tx] || y[ty] || z[tz]) {
			if(x[tx]==y[ty]) tx++,ty++,cout<<"2 1 2"<<endl;
			if(x[tx]==z[tz]) tx++,tz++,cout<<"2 1 3"<<endl;
			if(y[ty]==z[tz]) ty++,tz++,cout<<"2 2 3"<<endl;
		}
		return ;
	}
	if(fl) return;
	cho[num+1]=1,x[++tx]=a[num+1];
	if(x[tx-1]==x[tx]) tx-=2;
	dfs(num+1);
	if(fl) return;
	cho[num+1]=2,y[++ty]=a[num+1];
	if(y[ty-1]==y[ty]) ty-=2;
	dfs(num+1);
	if(fl) return;
	cho[num+1]=3,z[++tz]=a[num+1];
	if(z[tz-1]==z[tz]) tz-=2;
	dfs(num+1);
}
int main() {
	freopen("meow.in","r",stdin);
	freopen("meow.out","w",stdout);
	cin>>T;
	while(T--) {
		cin>>n>>m>>k;
		for(int i=1;i<=m;i++) scanf("%d",&a[i]);
		if(k==n) {
			for(int i=1;i<=m;i++)
				printf("1 %d\n",a[i]);
			continue;
		}
		if(m<=14) {
			dfs(0);
		}
	}
	return 0;
}
