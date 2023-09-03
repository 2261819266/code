#include<bits/stdc++.h>
using namespace std;
const int maxn=300+5;
int n,m,K;
inline int rd(){
	int x=0,ng=1;char c;
	while((c=getchar())&&(!isdigit(c)&&(c!='-')));
	c=='-'?ng=1:x=c&15;
	while((c=getchar())&&(isdigit(c)))x=(x<<3)+(x<<1)+(c&15);
	return x*ng;
}
inline void wr(int x,char end='\n'){
	if(x==0)return putchar('0'),putchar(end),void();
	static char c[32];int t=0;
	if(x<0)putchar('-'),x=-x;
	while(x)c[++t]=x%10,x/=10;
	while(t)putchar(c[t--]^'0');
	putchar(end);
}
struct step{
	int t,x,y;
	step(){}
	step(int _t,int _x,int _y){
		t=_t,x=_x,y=_y;
	}
	step(int _t,int _x){
		t=_t,x=_t;
	}
};
vector<step> st;
list<int>stk[maxn];
list<int>pai;
void sol15(){
	int j=0; 
	//stack #n is reserved
	for(int i=1;i<=m;i++){
		int x=pai.front();pai.pop_front();
		int done=0;
		for(int j=1;j<=n-1;j++){
			if(stk[j].size()&&stk[j].back()==x){
				st.push_back(step(1,j));
				stk[j].pop_back();
				done=1;
				break;
			}
		}
		if(done)continue;
		for(int j=1;j<=n-1;j++){
			if(stk[j].size()&&stk[j].front()==x){
				st.push_back(step(1,n));
				st.push_back(step(2,n,j));
				stk[j].pop_front();
				done=1;
				break;
			}
		}
		if(done)continue;
		st.push_back(step(1,j+1));
		stk[1+j].push_back(x);
		j++,j%=(n-1);
	}
}
void sol15_2(){
	for(int i=1;i<=m;i++){
		int x=pai.front();pai.pop_front();
		if(stk[1].size()&&stk[1].back()==x){
			st.push_back(step(1,1));
			stk[1].pop_back();
			continue;
		}
		if(stk[1].size()&&stk[1].front()==x){
			st.push_back(step(1,2));
			st.push_back(step(2,1,2));
			stk[1].pop_front();
			continue;
		} 
		stk[1].push_back(x);
		st.push_back(step(1,1));
	}
}
void sol(){
	n=rd(),m=rd(),K=rd();
	for(int i=1;i<=m;i++){
		pai.push_back(rd());
	}
	for(int i=1;i<=n;i++)stk[i].clear();
	st.clear();
	if(n==2){
		sol15_2();
	}
	else sol15();
	printf("%d\n",(int)st.size());
	for(auto a:st)a.t==1?printf("%d %d\n",a.t,a.x):printf("%d %d %d\n",a.t,a.x,a.y);
}
int main(){
	freopen("meow.in","r",stdin);
	freopen("meow.out","w",stdout);
	int t;t=rd();while(t--)sol();
}
