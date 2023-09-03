#include<bits/stdc++.h>
using namespace std;
inline int rd(){
	int s=0,f=1; char c=getchar();
	while(c<'0'||c>'9'){if(c=='-')f=-1;c=getchar();}
	while(c<='9'&&c>='0'){s=(s*10)+(c^48);c=getchar();}
	return s*f;
}
const int N = 2e6+5;
deque<int>d[305];
int n,m,k,a[N],nxt[N],cnt,b[N],fla,sum,pos,mx;
int tot;
struct data{
	int op,x,y;
	data(int _o=0,int _x=0,int _y=0):
		op(_o),x(_x),y(_y){}
}ans[N*2];
int len=0;
void change(int x){
	ans[++len]=data(1,pos); 
	d[pos].push_front(x);
	pos=0;
}
void nd(int x){
	for(int i=1;i<=n;++i){
		if(d[i].empty()){
			pos=i;mx=max(mx,i);
			ans[++len]=data(1,i);
			d[i].push_front(x);
			return;
		}
	}
	return;
}
void ins(int x){
	int id=0;
	
	for(int i=1;i<=mx;++i){
		if(d[i].empty()){
			id=i;
			continue;	
		}
		if(a[d[i].front()]==a[x]){
			ans[++len]=data(1,i);
			d[i].pop_front();
			return;
		}
	}
	if(mx<n)id=mx+1;
	if(id)
	for(int i=1;i<=mx;++i){
		if(d[i].empty())continue;
		if(a[d[i].back()]==a[x]){
			ans[++len]=data(1,id);
			ans[++len]=data(2,i,id);
			d[i].pop_back();
			return;
		}
	}
	if(pos&&nxt[x]>nxt[d[pos].front()]){
		ans[++len]=data(1,pos);
		d[pos].push_front(x);
		return;
	}
	for(int i=1;i<=mx;++i){
		if(d[i].empty()||i==pos)continue;
		if(nxt[d[i].front()]>nxt[x]){
			ans[++len]=data(1,i);
			d[i].push_front(x);
			return;
		}
	}
	if(pos) change(x);
	else nd(x);
	return;
}
void solve(){
	tot=0; cnt=0; mx=0;
	n=rd(); m=rd(); k=rd(); pos=0; len=0;
	for(int i=1;i<=max(n,max(m,k));++i){
		nxt[i]=b[i]=0;
	}
	for(int i=1;i<=n;++i)d[i].clear();
	for(int i=1;i<=m;++i)a[i]=rd();
	for(int i=m;i>=1;--i){
		nxt[i]=b[a[i]];
		b[a[i]]=i;
	}
	for(int i=1;i<=m;++i){
		ins(i);
		if(d[pos].empty())pos=0;
	}
	printf("%d\n",len);
	for(int i=1;i<=len;++i)
		if(ans[i].op==1)printf("1 %d\n",ans[i].x);
		else printf("2 %d %d\n",ans[i].x,ans[i].y);
}
int main(){
	int T;
	freopen("meow.in","r",stdin);
	freopen("meow.out","w",stdout);
	T=rd();
	while(T--)solve();
	return 0;
}	
