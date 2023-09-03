#include<bits/stdc++.h>
using namespace std;
inline int read()
{
	char ch=getchar();
	int f=1,x=0;
	while(!isdigit(ch)) {
		if(ch=='-') {
			f=0;
		}
		ch=getchar();
	}
	while(isdigit(ch)) {
		x=(x<<1)+(x<<3)+(ch^48);
		ch=getchar(); 
	}
	return f ? x : -x;
}
int t,n,m,k,a[305],nxt[305],fi[305],vis[305],fro[305];
deque<int> q[2];
inline void sol(int l,int r)
{
	for(int i=l;i<=r;++i) {
		
	}
}
int main()
{
	freopen("meow.in","r",stdin);
	freopen("meow.out","w",stdout);
	t=read();
	while(t--) {
		n=read();m=read();k=read();
		for(int i=1;i<=max((n<<1)-2,m);++i) {
			fi[i]=fro[i]=nxt[i]=vis[i]=0;
		}
		for(int i=1;i<=m;++i) {
			a[i]=read();
			if(!fi[a[i]]) {
				fi[a[i]]=i;
			} else {
				nxt[fi[a[i]]]=i;
				fro[i]=fi[a[i]];
				fi[a[i]]=i;
			}
		}
		for(int i=1;i<=m;++i) {
			if(q[0].size() && q[1].size() && q[0].back()==q[1].back()) {
				printf("2 1 2\n");
				q[0].pop_back();q[1].pop_back();
			}
			if((q[0].size() && q[0].front()==a[i])) {
				printf("1 1\n");
				q[0].pop_front();
				continue;
			}
			if((q[1].size() && q[1].front()==a[i])) {
				printf("1 2\n");
				q[1].pop_front();
				continue;
			}
			if(q[0].size()==0)  {
				int tmp=q[0].front();
    			q[0].push_front(a[i]);
    			if(tmp==a[i]) {
    				q[0].pop_front();
				}
    			printf("1 1\n");
    		} else if(q[1].size()==0){
    			int tmp=q[1].front();
    			q[1].push_front(a[i]);
    			if(tmp==a[i]) {
    				q[1].pop_front();
				}
    			printf("1 2\n");
    		} else {
    			if(nxt[q[0].front()]>nxt[i]) {
    				int tmp=q[0].front();
     				q[0].push_front(a[i]);
     				if(tmp==a[i]) {
    					q[0].pop_front();
					}
    				printf("1 1\n");
    			} else {
    				int tmp=q[1].front();
    				q[1].push_front(a[i]);
    				if(tmp==a[i]) {
    					q[1].pop_front();
					}
     				printf("1 2\n");
   		    	}
   		    }
		}
		for(int i=1;i<=q[0].size();++i) {
			q[0].pop_back();
		}
		for(int i=1;i<=q[1].size();++i) {
			q[1].pop_back();
		}
	}
	return 0;
}

