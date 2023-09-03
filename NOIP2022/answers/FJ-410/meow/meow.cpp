#include<bits/stdc++.h>
using namespace std;
const int N=305,M=2e6+5;
int n,m,zhan[N][5005],a[M],op[M],ansx[M],ansy[M],top[N],d[N],t,k;
inline void dd(int &ss){
	ss=0;int ff=1;
	char ch=getchar();
	while(ch<'0'||ch>'9'){
		if(ch=='-') ff=-1;
		ch=getchar();
	}
	while(ch>='0'&&ch<='9'){
		ss=ss*10+ch-'0',ch=getchar();
	}
	ss*=ff;
}
void dfs(int x,int s,int g){
	if(x==m+1&&g==0){
		printf("%d\n",s);
		for(int i=1;i<=s;++i){
			printf("%d ",op[i]);
			if(op[i]==1){
				printf("%d\n",ansx[i]);
			}else{
				printf("%d %d\n",ansx[i],ansy[i]);
			}
		}
		exit(0);
	}
//	cout<<x<<endl;
	if(x<=m){
		for(int i=1;i<=n;++i){
			int p=0;
			++g;
			zhan[i][++top[i]]=a[x];
			if(a[x]==zhan[i][top[i]-1]){
				top[i]-=2;
				g-=2;
				p=1;
			}
			op[s+1]=1,ansx[s+1]=i;
			dfs(x+1,s+1,g);
			--top[i];
			--g;
			if(p){
				top[i]+=2;
				g+=2;
				zhan[i][top[i]-1]=a[x];
			}
		}
	}
	
	for(int i=1;i<=n;++i){
		for(int j=i+1;j<=n;++j){
			if(zhan[i][d[i]]==zhan[j][d[i]]&&top[i]>=d[i]&&top[j]>=d[j]&&zhan[i][d[i]]){
				++d[i],++d[j];
				g-=2;
				op[s+1]=2,ansx[s+1]=i,ansy[s+1]=j;
				dfs(x,s+1,g);
				g+=2;
				--d[i],--d[j];
			}
		}
	}
}
int main(){
	freopen("meow.in","r",stdin);
	freopen("meow.out","w",stdout);
	dd(t);
	while(t--){
		dd(n),dd(m),dd(k);
		for(int i=1;i<=m;++i){
			dd(a[i]);
		}
		for(int i=1;i<=n;++i){
			d[i]=1;
		}
		dfs(1,0,0);
	}
}
//不可以，总司令 
