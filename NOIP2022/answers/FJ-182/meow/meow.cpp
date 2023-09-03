#include<bits/stdc++.h>
#define F(i,x,n) for(int i=x;i<=n;++i)
#define _F(i,x,n) for(int i=x;i>=n;--i)
#define ll long long
#define ull unsgined long long
#define lson x<<1
#define rson x<<1|1
#define lowbit(x) x&-x
using namespace std;

inline int read(){
	int s=0;char c=getchar();bool flag=0;
	while(!isdigit(c))flag|=(c=='-'),c=getchar();
	while(isdigit(c))s=(s<<3)+(s<<1)+(c^48),c=getchar();
	return flag?-s:s;
}

const int N=305;//数组不要开小，记得检查。
const int M=2e6+5; 
const int mod=998244353;

deque<int>q[N];

int a[M];
int T,n,m,k,cnt;

struct node{
	int op,l,r;
}ans[M<<1];

void solve1(){
	int x,now=m;
	F(i,1,m){
		if(a[i]>n-1)x=a[i]-n+1;
		else x=a[i];
		if(q[n].size()&&q[n].back()==a[i])q[n].pop_back(),ans[++cnt].op=1,ans[cnt].l=n,now-=2;
		else if(!q[x].size())q[x].push_back(a[i]),ans[++cnt].op=1,ans[cnt].l=x;
		else if(q[x].size()&&q[x].back()==a[i])q[x].pop_back(),ans[++cnt].op=1,ans[cnt].l=x,now-=2;
		else q[n].push_back(a[i]),ans[++cnt].op=1,ans[cnt].l=n;
	}
	while(now){
		int x=q[n].back();
		if(x>n-1)x=x-n+1;
		ans[++cnt].op=2,ans[cnt].l=n,ans[cnt].r=x,q[x].pop_front(),q[n].pop_back(),now-=2;
	}
	printf("%d\n",cnt);
	F(i,1,cnt){
		if(ans[i].op==1)printf("1 %d\n",ans[i].l);
		else printf("2 %d %d\n",ans[i].l,ans[i].r);
	}
}

void solve2(){
	int now=m,i=2;
	q[1].push_back(a[1]),ans[++cnt].op=1,ans[cnt].l=1;
	for(;i<=m;++i){
		if(q[1].size()&&a[i]==q[1].back())q[1].pop_back(),ans[++cnt].op=1,ans[cnt].l=1;
		if(q[1].size()&&a[i]==q[1].front())q[1].pop_front(),ans[++cnt].op=1,ans[cnt].l=2,ans[++cnt].op=2,ans[cnt].l=1,ans[cnt].r=2;
		if(q[2].size()&&a[i]==q[2].back())q[2].pop_back(),ans[++cnt].op=1,ans[cnt].l=2;
		if(q[2].size()&&a[i]==q[2].front())q[2].pop_front(),ans[++cnt].op=1,ans[cnt].l=1,ans[++cnt].op=2,ans[cnt].l=1,ans[cnt].r=2;
		if(!q[1].size()&&!q[2].size()){
			q[1].push_back(a[i]),ans[++cnt].op=1,ans[cnt].l=1;
			continue;
		}
		if(q[1].size()==1&&q[2].size()==1){
			if(q[1].back()==a[i])q[1].pop_back(),ans[++cnt].op=1,ans[cnt].l=1;
			else if(q[2].back()==a[i])q[2].pop_back(),ans[++cnt].op=1,ans[cnt].l=2;
			else{
				if(q[1].back()==a[i+1])q[2].push_back(a[i]),q[1].pop_back(),ans[++cnt].op=1,ans[cnt].l=2;
				else q[1].push_back(a[i]),q[2].pop_back(),ans[++cnt].op=1,ans[cnt].l=1; 
			}
			continue;
		}
		bool f1=0,f2=0;
		int id;
		if(q[1].size()==2||q[2].size()==2)f2=1;
		else if((q[1].size()==1&&q[2].size()==0)||(q[1].size()==0&&q[2].size()==1))f1=1;
		if(f1){
			if(q[1].size()==1)id=1;
			else id=2;
			if(q[id].back()==a[i])q[id].pop_back(),ans[++cnt].op=1,ans[cnt].l=id;
			else q[id].push_back(a[i]),ans[++cnt].op=1,ans[cnt].l=id;
		}
		else if(f2){
			if(q[1].size()==2)id=1;
			else id=2;
			if(a[i]==q[id].back())q[id].pop_back(),ans[++cnt].op=1,ans[cnt].l=id;
			if(q[(id==1?2:1)].size()&&q[(id==1?2:1)].back()==a[i])q[(id==1?2:1)].pop_back(),ans[++cnt].op=1,ans[cnt].l=(id==1?2:1);
			else if(a[i+1]==q[id].back())q[(id==1?2:1)].push_back(a[i]),ans[++cnt].op=1,ans[cnt].l=(id==1?2:1);			
		}
	}
	printf("%d\n",cnt);
	F(i,1,cnt){
		if(ans[i].op==1)printf("1 %d\n",ans[i].l);
		else printf("2 %d %d\n",ans[i].l,ans[i].r);
	}
}

void solve3(){
	int x,now=m;
	F(i,1,m){
		if(a[i]==2*n-1){
			if(!q[n].size())q[n].push_back(a[i]),ans[++cnt].op=1,ans[cnt].l=n;
			else if(q[n].size()&&q[n].back()==a[i])q[n].pop_back(),ans[++cnt].op=1,ans[cnt].l=n,now-=2;
			else q[n].push_back(a[i]),ans[++cnt].op=1,ans[cnt].l=n;
		}
		else{
			if(q[n].size()&&q[n].front()==a[i]){
				int id=-1;
				F(j,1,n)if(!q[j].size()){id=j;break;}
				if(id!=-1){
					ans[++cnt].op=1,ans[cnt].l=id,ans[++cnt].op=2,ans[cnt].l=id,ans[cnt].r=n,now-=2;
					continue;
				}
			}
			if(a[i]>n-1)x=a[i]-n+1;
			else x=a[i];
			if(q[n].size()&&q[n].back()==a[i])q[n].pop_back(),ans[++cnt].op=1,ans[cnt].l=n,now-=2;
			else if(!q[x].size())q[x].push_back(a[i]),ans[++cnt].op=1,ans[cnt].l=x;
			else if(q[x].size()&&q[x].back()==a[i])q[x].pop_back(),ans[++cnt].op=1,ans[cnt].l=x,now-=2;
			else{
				if(q[n].size()&&q[n].back()==2*n-1)q[x].push_back(a[i]),ans[++cnt].op=1,ans[cnt].l=x;
				else q[n].push_back(a[i]),ans[++cnt].op=1,ans[cnt].l=n;
			} 			
		}
	}
	while(now&&q[n].size()){
		int x=q[n].back();
		if(x>n-1)x=x-n+1;
		if(q[x].size())ans[++cnt].op=2,ans[cnt].l=n,ans[cnt].r=x,q[x].pop_front(),q[n].pop_back(),now-=2;
	}
	printf("%d\n",cnt);
	F(i,1,cnt){
		if(ans[i].op==1)printf("1 %d\n",ans[i].l);
		else printf("2 %d %d\n",ans[i].l,ans[i].r);
	}	
}

int main(){
	freopen("meow.in","r",stdin);
	freopen("meow.out","w",stdout);
	T=read();
	while(T--){
		n=read(),m=read(),k=read();cnt=0;
		F(i,1,m)a[i]=read();
		F(i,1,n)q[i].clear();
		if(k==n*2-2)solve1();
		else solve3();
	}
	return 0;
}
