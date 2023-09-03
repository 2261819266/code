#include <bits/stdc++.h>
typedef long long ll;
const int N=2e6+15;

inline ll rd(){
	ll w=1,r=0;char c=getchar();
	while(!isdigit(c)) ((c=='-')&&(w=-1)),c=getchar();
	while(isdigit(c)) r=r*10+c-'0',c=getchar();
	return w*r;
}

struct node{
	int op,a,b;
	node(int i=0,int j=0,int k=0){op=i,a=j,b=k;}
}ans[N];

int T,n,m,k,a[N],tt,help;
std::deque<int> q[315];


int main(){
	freopen("meow.in","r",stdin);freopen("meow.out","w",stdout);
	T=rd();
	while(T--){
		n=rd(),m=rd(),k=rd();
		for(int i=1;i<=m;++i) a[i]=rd();
		for(int i=1;i<=m;++i){
			bool fl=0;
			for(int j=1;j<n;++j){
				if(!q[j].empty() && q[j].back()==a[i]){
					//printf("i:%d\n%d %d\n",i,tt,n);
					ans[++tt]=node(1,n);
					ans[++tt]=node(2,n,j),q[j].pop_back();
					fl=true;
				}
			}if(fl) continue;
			
			for(int j=1;j<n;++j){
				if(!q[j].empty() && q[j].front()==a[i]){
					q[j].pop_front(),ans[++tt]=node(1,j);fl=true;
				}
			}if(fl) continue;
			
			for(int j=1;j<n;++j){
				if(q[j].empty()){
					ans[++tt]=node(1,j);
					q[j].push_front(a[i]);
					fl=true;
				}
			}if(fl) continue;
			 
			for(int j=1;j<n;++j){
				if(q[j].size()<2){
					ans[++tt]=node(1,j);
					q[j].push_front(a[i]);
					fl=true;
				}
			}if(fl) continue;
		}
		printf("%d\n",tt);
		for(int i=1;i<=tt;++i){
			if(ans[i].op==1) printf("1 %d\n",ans[i].a);
			else printf("2 %d %d\n",ans[i].a,ans[i].b);
		}
	}
	
	return 0;
}
