#include<bits/stdc++.h>
#define rep(i,l,r) for(int i=(l);i<(r);i++)
#define per(i,l,r) for(int i=(r)-1;i>=(l);i--)
using i64=long long;
template<class T>void chkMin(T &x,const T &y) {if(y<x)x=y;}
template<class T>void chkMax(T &x,const T &y) {if(y>x)x=y;}
std::ifstream fin("meow.in");std::ofstream fout("meow.out");
const int N=305,S=2e6+5,K=605;
std::deque<int> a[N];
int col[S];
void push(int id,int y) {if(!a[id].empty()&&a[id].back()==y) {a[id].pop_back();} else a[id].push_back(y);}
struct modify {
	int x,y,z;
};
std::vector<modify> ans;
std::stack<int> emp,sz1;
int pos[K];
int tests;
void solve() {
	int n,m,k;fin>>n>>m>>k;
	rep(i,1,m+1) fin>>col[i];
	std::stack<int> st;
	ans.clear();
	if(tests%10==1) {
		per(i,1,m+1) st.push(col[i]);
		while(!st.empty()) {
			int x=st.top();st.pop();
//			std::cerr<<x<<"\n";
			if(a[(x+1)/2].size()<=1||(!a[(x+1)/2].empty()&&a[(x+1)/2].back()==x)) {push((x+1)/2,x);ans.push_back({1,(x+1)/2,0});}
			else {
				ans.push_back({1,n,0});
				a[(x+1)/2].pop_front();
				ans.push_back({2,(x+1)/2,n});
			}
		}
	} else {
		rep(i,1,n) emp.push(i);
		per(i,1,m+1) st.push(col[i]);
		while(!st.empty()) {
			int x=st.top();st.pop();
			while(!sz1.empty()&&a[sz1.top()].size()!=1) sz1.pop();
			if(pos[x]==0) {
				int t=0;
				if(sz1.empty()) {t=emp.top();emp.pop();}
				else {sz1.top();sz1.pop();}
				push(t,x);
				pos[x]=t;
				if(a[t].size()==1) sz1.push(t);
				ans.push_back({1,t,0});
			} else {
//				std::cerr<<pos[x]<<' '<<a[pos[x]].size()<<std::endl;
//				assert(a[pos[x]].size()>=1);
				if(a[pos[x]].back()==x) {
					push(pos[x],x);
					ans.push_back({1,pos[x],0});
				} else {
					ans.push_back({1,n,0});
					ans.push_back({2,pos[x],n});
					a[pos[x]].pop_front();
				}
				if(a[pos[x]].empty()) emp.push(pos[x]);
				else if(a[pos[x]].size()==1) sz1.push(pos[x]);
				pos[x]=0;
			}
		}
	}
	fout<<ans.size()<<"\n";
	for(auto i:ans) if(i.x==1) fout<<i.x<<' '<<i.y<<"\n"; else fout<<i.x<<' '<<i.y<<' '<<i.z<<"\n";
//	std::cerr<<"i\n";
}
int main() {
	fin>>tests;
	while(tests--) solve();
	return 0;
}
