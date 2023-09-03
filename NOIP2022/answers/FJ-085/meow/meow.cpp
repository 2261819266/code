#include<bits/stdc++.h>
#define ll long long
#define MAXN 2000005

using namespace std;
int T,n,m,k;
int a[MAXN];
map<ll,int> s;
map<ll,int> nextn;
int cnt;
int nxt[MAXN];
priority_queue< pair<int,int> > q;
int tmp[MAXN],num;
int pos[MAXN],pp;
map<ll,ll> up;
map<ll,ll> down;
inline int read(){
	int x=0,f=1;char ch=getchar();
	while(ch<'0'||'9'<ch){
		if(ch=='-') f=-1;
		ch=getchar();
	}
	while('0'<=ch&&ch<='9'){
		x=(x<<3)+(x<<1)+ch-'0';
		ch=getchar();
	}
	return x*f;
}
inline ll llread(){
	ll x=0,f=1;char ch=getchar();
	while(ch<'0'||'9'<ch){
		if(ch=='-') f=-1;
		ch=getchar();
	}
	while('0'<=ch&&ch<='9'){
		x=(x<<3)+(x<<1)+ch-'0';
		ch=getchar();
	}
	return x*f;
}

int main(){
	freopen("meow.in","r",stdin);
	freopen("meow.out","w",stdout);
	T=read();
	while(T--){
		n=read(),m=read(),k=read();cnt=0;
		while(!q.empty()) q.pop();
		for(int i=1;i<=num;i++) tmp[i]=0;
		num=0;
		for(int i=1;i<=m;i++) a[i]=read();
		for(int i=1;i<=m;i++){
			s[a[i]]=0;nextn[a[i]]=m+1;
		}
		for(int i=m;i>=1;i--){
			nxt[i]=nextn[a[i]];nextn[a[i]]=i;
		}
		for(int i=1;i<=m;i++){
			if(s[a[i]]){
				if(up[i]==0){
					printf("1 %d\n",s[a[i]]%n);
					up[down[i]]=0;
					if(down[i]) q.push(make_pair((-1)*nxt[down[i]],down[i]));
					else pos[++pp]=s[a[i]]%n;
				}
				else{
					printf("2 %d %d\n",s[a[i]]%n,n);
				}
				s[a[i]]=0;
			}
			else{
				while(((-1)*q.top().first<nxt[i]&&!q.empty())||up[q.top().second]!=0){
					if(up[q.top().second]==0) tmp[++num]=q.top().second;
					q.pop();
					if(q.empty()) break;
				}
				if(q.empty()){
					printf("1 %d\n",pos[pp]%n);
					s[a[i]]=pos[pp];
					pp++;
				}
				else{
					printf("1 %d\n",s[a[q.top().second]]%n);
					s[a[i]]=s[a[q.top().second]];
					up[q.top().second]=i;
					down[i]=q.top().second;
					q.pop();
				}
				while(num){
					q.push(make_pair((-1)*nxt[tmp[num]],tmp[num]));
					tmp[num]=0;num--;
				}
				q.push(make_pair((-1)*nxt[i],i));
			}
		}
	}
	return 0 ;
}
