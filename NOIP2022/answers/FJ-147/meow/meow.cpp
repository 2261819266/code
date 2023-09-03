#include<stdio.h>
#include<deque>
#include<queue> 
using namespace std;
const int N=305,M=2e6+5; 
template<class R>
void read(R &x){
	char c=getchar();
	for(;c<48||c>57;c=getchar());
	for(x=0;c>47&&c<58;c=getchar())x=(x<<1)+(x<<3)+(c^48);
}
int T,n,m,k,a[M],cnt,is[N*2];
bool us,fg;
struct opt{
	int x,y;
}ans[2*M];
deque<int>s[N];
queue<int>em,pp[N*2];
void add1(int p){
	++cnt;
	ans[cnt].x=p,ans[cnt].y=0;
}
void add2(int x,int y){
	++cnt;
	ans[cnt].x=x,ans[cnt].y=y;
}
void solve1(){
	for(int i=1,p;i<=m;++i){
		p=(a[i]-1)/2+1;
		if(s[p].empty()){
			s[p].push_back(a[i]);
			add1(p);
		}else{
			if(a[i]==s[p].back()){
				add1(p);
				s[p].pop_back();
			}else if(a[i]!=s[p].front()){
				add1(p);
				s[p].push_back(a[i]);
			}else{
				add1(n);
				add2(p,n);
				s[p].pop_front();
			}
		}
	}
	//for(int i=1;i<=n;++i)if(s[i].size()>0)puts("Wrong");
}
void solve2(){
	for(int i=1;i<=k;++i)is[i]=0;
	for(int i=1;i<=n;++i)em.push(i);
	for(int i=1;i<=m;++i)pp[a[i]].push(i);
	for(int i=1,p,nx=0;i<=m;++i){
		p=is[a[i]];
		pp[a[i]].pop();
		if(i==nx)nx=0;
		if(p){
			if(s[p].back()==a[i]){
				add1(p);
				s[p].pop_back();
			}else {
				//if(s[p].front()!=a[i])puts("Wrong");
				add1(em.front());
				add2(p,em.front());
				s[p].pop_front();
			}
			if(s[p].empty())em.push(p);
			is[a[i]]=0;
		}else{
			if(em.size()>1){
				is[a[i]]=p=em.front();
				em.pop();
				add1(p);
				s[p].push_back(a[i]);
				continue;
			}
			if(em.size()==1){
				fg=false;
				for(int j=1;j<=n;++j)if(s[j].size()==1){
					is[a[i]]=p=j;
					add1(p);
					s[p].push_back(a[i]);
					fg=true;
					break;
				}
				if(!fg){
					nx=pp[a[i]].front();
					for(int j=1;j<=n;++j)if(!s[j].empty()){
						int p1=s[j].front(),p2=s[j].back();
						if(pp[p1].front()<pp[p2].front()){
							fg=true;
							is[a[i]]=p=j;
							add1(p);
							s[p].push_back(a[i]);
							break;
						}
						if(pp[p1].front()<nx)nx=pp[p1].front();
					}
					if(!fg){
						is[a[i]]=p=em.front();
						em.pop();
						add1(p);
						s[p].push_back(a[i]);
					}else nx=0;
				}
				continue;
			}
			for(int j=1;j<=n;++j)if(s[j].size()<2&&s[j].front()!=a[nx]){
				is[a[i]]=p=j;
				add1(p);
				s[p].push_back(a[i]);
				break;
			}
		}
	}
	//for(int i=1;i<=n;++i)if(s[i].size()>0)puts("Wrong");
}
void solve(){
	read(n),read(m),read(k);
	cnt=0;
	for(int i=1;i<=m;++i)read(a[i]);
	if(k==2*n-2)solve1();
	else solve2();
	printf("%d\n",cnt);
	for(int i=1;i<=cnt;++i){
		if(ans[i].y)printf("2 %d %d\n",ans[i].x,ans[i].y);
		else printf("1 %d\n",ans[i].x);
	}
}
int main(){
	freopen("meow.in","r",stdin);
	freopen("meow.out","w",stdout);
	scanf("%d",&T);
	while(T--)solve();
	return 0;
}
