#include<bits/stdc++.h>
using namespace std;
#define int long long 
inline int read(){
	int x=0,f=1;char c=getchar();
	while(c<'0'||c>'9')f=(c!='-'),c=getchar();
	while(c>='0'&&c<='9')x=10*x+c-'0',c=getchar();
	if(f)return x;return -x;
}
const int maxn=2e6+10;
int n,m,k,a[maxn],used[maxn],now;
deque<int> dq[400];
signed main(){
	freopen("meow.in","r",stdin);
	freopen("meow.out","w",stdout);
	int T=read();while(T--){
		n=read(),m=read(),k=read(),now=n;
		for(int i=1;i<=m;i++)a[i]=read();
		for(int i=1;i<=n;i++)dq[i].clear();
		for(int i=1;i<=m;i++){
			int t=(a[i]+1)/2;
			if(t==n){
				int tmp=0;
				for(int i=1;i<n;i++)while(dq[i].size()&&used[dq[i].front()])dq[i].pop_front();
				for(int i=1;i<n;i++)if(dq[i].front()>=n)tmp=i;
				if(!tmp){
					int tag=++now;
					for(int i=1;i<n;i++)dq[i].push_back(tag);
					continue;
				}
				printf("1 %lld\n",n);
				printf("2 %lld %lld\n",n,tmp);
				used[dq[tmp].front()]=1;
				continue;
			}
			while(dq[t].size()&&used[dq[t].front()])dq[t].pop_front();
			if(!dq[t].size()){dq[t].push_back(a[i]);}
			else if(a[i]==dq[t].front()){
				printf("1 %lld\n",n);
				printf("2 %lld %lld\n",t,n);
				dq[t].pop_front();
			}
			else if(a[i]==dq[t].back()){
				printf("1 %lld\n",t);
				dq[t].pop_back();
			}else{
				printf("1 %lld\n",t);
				dq[t].push_back(a[i]);
			}
		}for(int i=n;i<=now;i++)used[i]=0;
		/*for(int i=1;i<=n;i++){
			for(int v:dq[i])printf("%lld ",v);
			putchar('\n');
		}*/
	}return 0;
}
