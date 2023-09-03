#include <bits/stdc++.h>
using namespace std;
const int N=305,M=2e6+5;
int T,n,m,k,a[M];
inline int read(){
	int x=0; char ch;
	bool bz=0;
	while(((ch=getchar())<'0'||ch>'9')&&ch!='-') ;
	if(ch=='-') bz=1;
	else x=(x<<1)+(x<<3)+(ch^48);
	while((ch=getchar())>='0'&&ch<='9') x=(x<<1)+(x<<3)+(ch^48);
	return bz?-x:x;
}
set<int> h,y;
deque<int> q[N];
struct ans{
	int bz,d1,d2;
}Ans[2*M];
int main(){
	freopen("meow.in","r",stdin);
	freopen("meow.out","w",stdout);
	T=read();
	while(T--){
		int bs=0;
		n=read(),m=read(),k=read();
		while(h.size()) h.erase(*h.begin());
		while(y.size()) y.erase(*y.begin());
		for(int i=1;i<=n;i++){
			h.insert(i);
			while(q[i].size()) q[i].pop_back();
		}
		int g=0;
		for(int i=1;i<=m;i++){
			a[i]=read();
			int b=0;
			for(set<int>::iterator it=y.begin();it!=y.end();it++){
				if(q[*it].back()==a[i]){Ans[++bs]={1,*it,0}; q[*it].pop_back(),b=1; if(!q[*it].size()) h.insert(*it),y.erase(*it); break;}
			}
			if(!b){
				if(h.size()){
					Ans[++bs]={1,*h.begin(),0}; 
					q[*h.begin()].push_back(a[i]),y.insert(*h.begin()),h.erase(*h.begin());
					for(int j=1;j<=n;j++){
						for(int jj=j+1;jj<=n;jj++){
							if(q[j].size()&&q[jj].size()){
								while(q[j].size()&&q[jj].size()&&q[j].front()==q[jj].front()){
									Ans[++bs]={2,j,jj}; 
									q[j].pop_front();
									q[jj].pop_front();
								}
								if(!q[j].size()) h.insert(j),y.erase(j);
								if(!q[jj].size()) h.insert(jj),y.erase(jj);
							}
						}
					}
				}
				else{
					if(h.size()){
						Ans[++bs]={1,*h.begin(),0}; 
						q[*h.begin()].push_back(a[i]),y.insert(*h.begin()),h.erase(*h.begin());
						for(int j=1;j<=n;j++){
							for(int jj=j+1;jj<=n;jj++){
								if(q[j].size()&&q[jj].size()){
									while(q[j].size()&&q[jj].size()&&q[j].front()==q[jj].front()){
										Ans[++bs]={2,j,jj}; 
										q[j].pop_front();
										q[jj].pop_front();
									}
									if(!q[j].size()) h.insert(j),y.erase(j);
									if(!q[jj].size()) h.insert(jj),y.erase(jj);
								}
							}
						}
					}
					else{
						int wz=rand()%n+1;
						Ans[++bs]={1,wz,0}; 
						q[wz].push_back(a[i]);
						for(int j=1;j<=n;j++){
							for(int jj=j+1;jj<=n;jj++){
								if(q[j].size()&&q[jj].size()){
									while(q[j].size()&&q[jj].size()&&q[j].front()==q[jj].front()){
										Ans[++bs]={2,j,jj}; 
										q[j].pop_front();
										q[jj].pop_front();
									}
									if(!q[j].size()) h.insert(j),y.erase(j);
									if(!q[jj].size()) h.insert(jj),y.erase(jj);
								}
							}
						}
					}
				}
			}
		}
		printf("%d\n",bs);
		for(int i=1;i<=bs;i++){
			cout<<Ans[i].bz<<" ";
			if(Ans[i].bz==1) cout<<Ans[i].d1<<"\n";
			else cout<<Ans[i].d1<<" "<<Ans[i].d2<<"\n";
		}
	}
	return 0;
}
