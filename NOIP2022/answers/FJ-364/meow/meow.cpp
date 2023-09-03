#include <bits/stdc++.h>
using namespace std;
long long t,n,m,k,a[305],cnt,mp[305][100005],l[305],r[305];
string ans[100005];
inline long long read(){
	long long x=0,f=1;
	char c=getchar();
	while(c>'9'||c<'0'){
		if(c=='-') f=-1;
		c=getchar();
	}
	while(c>='0'&&c<='9'){
		x=x*10+c-48;
		c=getchar();
	}
	return x*f;
}
inline void dfs(int x,int y,int z,int op){
	if(op>2*m) return;
	if(x==m+1&&y==0&&z==0){
		cout<<op<<'\n';
		for(int i=1;i<=op;++i){
			cout<<ans[i]<<'\n';
		}
	}
	if(y&&z){
		if(mp[1][1]==mp[2][1]){
			l[1]++,l[2]++;
			ans[op+1]="2 1 2";
			dfs(x,y-1,z-1,op+1);
			l[1]--,l[2]--;
		}
	}
	if(a[x]==mp[1][r[1]]){
		ans[op+1]="1 1";
		r[1]--;
		dfs(x-1,y-1,z,op+1);
		r[1]++;
	}else{
		ans[op+1]="1 1";
		mp[1][++r[1]]=a[x];
		dfs(x-1,y+1,z,op+1);
		mp[1][--r[1]]=0;
	}
	if(a[x]==mp[2][r[2]]){
		ans[op+1]="1 2";
		r[2]--;
		dfs(x-1,y-1,z,op+1);
		r[2]++;
	}else{
		ans[op+1]="1 2";
		mp[2][++r[2]]=a[x];
		dfs(x-1,y+1,z,op+1);
		mp[2][--r[2]]=0;
	}
}
int main(){
	freopen("meow.in","r",stdin);
	freopen("meow.out","w",stdout);
	t=read();
	if(t==1002) {
		int id=2;
	}
	while(t--){
		n=read(),m=read(),k=read();
		for(int i=1;i<=n;++i){
			a[i]=read();
		}
		dfs(1,0,0,0);
	}
	return 0;
}

