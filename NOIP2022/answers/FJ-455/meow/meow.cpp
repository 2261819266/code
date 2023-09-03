#include<bits/stdc++.h>
using namespace std;
const int N=305,M=2000005;
deque<int>q[N];
int T,n,m,k,a[M];
int op,ans[1000005][3];
inline int read(){
	int x=0;
	char c=getchar();
	for(;c<'0'||c>'9';c=getchar());
	for(;c>='0'&&c<='9';c=getchar())
		x=(x<<1)+(x<<3)+(c^48);
	return x;
}
int main(){
	freopen("meow.in","r",stdin);
	freopen("meow.out","w",stdout);
	register int i,j;
	for(T=read();T--;){
		for(i=1;i<=300;++i)q[i].clear();
		op=0;
		n=read();m=read();k=read();
		for(i=1;i<=m;++i){
			a[i]=read();
		}
		if(k==n*2-2){
			for(i=1;i<=m;++i){
				int st=(a[i]+1)/2;
				if(!q[st].empty()&&q[st].front()==a[i]){
					q[st].pop_front();
					++op;
					ans[op][0]=1;
					ans[op][1]=st;
				}
				else if(!q[st].empty()&&q[st].back()==a[i]){
					q[st].pop_back();
					++op;
					ans[op][0]=1;
					ans[op][1]=n;
					++op;
					ans[op][0]=2;
					ans[op][1]=st;
					ans[op][2]=n;
				}
				else{
					++op;
					ans[op][0]=1;
					ans[op][1]=st;
					q[st].push_front(a[i]);
				}
			}
		}
		else if(n==2&&k==3){
			for(i=1;i<=m;++i){
				if(!q[1].empty()&&q[1].front()==a[i]){
					q[1].pop_front();
					++op;
					ans[op][0]=1;
					ans[op][1]=1;
				}
				else if(!q[2].empty()&&q[2].front()==a[i]){
					q[2].pop_front();
					++op;
					ans[op][0]=1;
					ans[op][1]=2;
				}
				else if(!q[1].empty()&&q[2].empty()&&q[1].back()==a[i]){
					q[1].pop_back();
					++op;
					ans[op][0]=1;
					ans[op][1]=2;
					++op;
					ans[op][0]=2;
					ans[op][1]=1;
					ans[op][2]=2;
				}
				else if(!q[2].empty()&&q[1].empty()&&q[2].back()==a[i]){
					q[2].pop_back();
					++op;
					ans[op][0]=1;
					ans[op][1]=1;
					++op;
					ans[op][0]=2;
					ans[op][1]=2;
					ans[op][2]=1;
				}
				else if(!q[1].empty()&&!q[2].empty()&&q[1].front()!=a[i]&&q[2].front()!=a[i]){
					int next=a[i+1];
					if(next==q[1].front()){
						q[2].push_front(a[i]);
						++op;
						ans[op][0]=1;
						ans[op][1]=2;
					}
					else{
						q[1].push_front(a[i]);
						++op;
						ans[op][0]=1;
						ans[op][1]=1;
					}
				}
				else if(!q[1].empty()&&q[2].empty()){
					q[2].push_front(a[i]);
					++op;
					ans[op][0]=1;
					ans[op][1]=2;
				}
				else if(!q[2].empty()&&q[1].empty()){
					q[1].push_front(a[i]);
					++op;
					ans[op][0]=1;
					ans[op][1]=1;
				}
				else if(q[1].empty()&&q[2].empty()){
					q[1].push_front(a[i]);
					++op;
					ans[op][0]=1;
					ans[op][1]=1;
				}
			}
		}
		printf("%d\n",op);
		for(i=1;i<=op;++i){
			printf("%d %d",ans[i][0],ans[i][1]);
			if(ans[i][0]==2)printf(" %d",ans[i][2]);
			putchar(10);
		}
	}
	return 0;
}
