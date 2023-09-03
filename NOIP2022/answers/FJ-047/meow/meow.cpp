#include <deque>
#include <cstdio>
#include <cstring>
#include <iostream>
#define M 2000006
//#define int long long
int T,n,m,k;
int a[M];
int in[350];
int read(){
	int x=0,f=1;char ch=getchar();
	for(;!isdigit(ch);ch=getchar()) if(ch=='-') f=-1;
	for(;isdigit(ch);ch=getchar()) x=(x<<3)+(x<<1)+(ch xor 48);
	return x*f;
}
void solve(){
	n=read(),m=read(),k=read();
	std::deque<int> q[n+1];
	for(int i=1;i<=m;++i) a[i]=read();
	for(int i=1;i<=m;++i){
		for(int t1=1;t1<=n;++t1){
			for(int t2=1;t2<=n;++t2){
				if(t1==t2 or !q[t1].size() or !q[t2].size()) continue;
				if(q[t1].front()==q[t2].front()){
					printf("2 %d %d\n",t1,t2);
					q[t1].pop_front();q[t2].pop_front();
				}
			}
		}
		if(in[a[i]]){
			if(q[in[a[i]]].back()==a[i] and in[a[i]]!=n){
				printf("1 %d\n",n);
				printf("2 %d %d\n",in[a[i]],n);
				q[in[a[i]]].pop_back(),in[a[i]]=0;
				continue;
			}
			bool flag=true;
			for(int t=1;t<=n;++t){
				if(!q[t].size()){
					q[t].push_back(a[i]);
					printf("1 %d\n",t);
					in[a[i]]=t,flag=false;
					break;
				}
			}
			if(flag){
				for(int t=1;t<=n;++t){
					if(t!=in[a[i]]){
						q[t].push_back(a[i]);
						printf("1 %d\n",t);
						break;
					}
				}
			}
		}
		else{
			for(int t=1;t<=n;++t){
				if(!q[t].size()){
					printf("1 %d\n",t);
					q[t].push_back(a[i]);
					in[a[i]]=t;
					break;
				}
			}
			if(!in[a[i]]){
				q[1].push_back(a[i]);
				in[a[i]]=1;
				printf("1 1\n");
			}
		}
		for(int t1=1;t1<=n;++t1){
			for(int t2=1;t2<=n;++t2){
				if(t1==t2 or !q[t1].size() or !q[t2].size()) continue;
				if(q[t1].front()==q[t2].front()){
					printf("2 %d %d\n",t1,t2);
					q[t1].pop_front();q[t2].pop_front();
				}
			}
		}
		for(int t1=1;t1<=n;++t1){
			for(int t2=1;t2<=n;++t2){
				if(t1==t2 or !q[t1].size() or !q[t2].size()) continue;
				if(q[t1].front()==q[t2].front()){
					printf("2 %d %d\n",t1,t2);
					q[t1].pop_front();q[t2].pop_front();
				}
			}
		}
		for(int t1=1;t1<=n;++t1){
			for(int t2=1;t2<=n;++t2){
				if(t1==t2 or !q[t1].size() or !q[t2].size()) continue;
				if(q[t1].front()==q[t2].front()){
					printf("2 %d %d\n",t1,t2);
					q[t1].pop_front();q[t2].pop_front();
				}
			}
		}
	}
}
signed main(){
	freopen("meow.in","r",stdin);
	freopen("meow.out","w",stdout);
	T=read();
	while(T--) solve();
	return 0;
}

