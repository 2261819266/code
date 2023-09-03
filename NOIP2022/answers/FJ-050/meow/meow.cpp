#include<bits/stdc++.h>
#define For(i,a,b) for(int i(a);i<=b;++i)
#define foR(i,a,b) for(int i(a);i>=b;--i)
#define int long long
using namespace std;
inline void read(int &x){
	x=0;bool w=0;char ch;ch=getchar();
	while(ch<'0'||ch>'9'){if(ch=='-')w=1; ch=getchar();}
	while(ch>='0'&&ch<='9'){x=x*10+ch-'0';ch=getchar();}
	if(w)x=-x;
}
inline void print(int x){
	if(x<0){putchar('-'); print(-x); return;}
	if(x>9){print(x/10);}putchar(x%10+'0');
}
const int N=1e6+78,Mod=1e9+7;
deque<int> s[606];
int op[N],s1[N],s2[N],n,m,k,a[N],T;
bool fl=0;
bool check(){
	For(i,1,n)if(!s[i].empty())return 0;
	return 1;
}
void init(){
	For(i,1,n)if(!s[i].empty())s[i].clear();
}
void dfs(int mi,int st){
	if(mi==m+1){
		if(check()){
			fl=1;
			For(i,1,st-1){
				print(op[i]);putchar(' ');print(s1[i]);
				if(op[i]==2){putchar(' ');print(s2[i]);}
				puts("");
			}
			return ;
		}
	}
	if(mi<=m){
		if(a[mi]==a[mi+1]){
			op[st]=1;s1[st]=1;
			op[st+1]=1;s1[st+1]=1;
			dfs(mi+2,st+2);
			return ;
		}
		For(i,1,n){
			if(!s[i].empty())
			if(s[i].front()==a[mi]&&(s[n].empty())){
				op[st]=1;s1[st]=n;
				op[st+1]=2;s1[st+1]=i;s2[st+1]=n;
				int qwq=s[i].front();
				s[i].pop_front();
				dfs(mi+1,st+2);
				s[i].push_front(qwq);
				if(fl)return ;
//				return ;
			}
		}
		For(i,1,n){
			if(s[i].empty()){
				s[i].push_back(a[mi]);
				op[st]=1;s1[st]=i;
				dfs(mi+1,st+1); 
				s[i].pop_back();
				if(fl)return ;
//				return ;
			}
		}
		For(i,1,n){
			if(!s[i].empty())
			if(s[i].back()==a[mi]){
				op[st]=1;s1[st]=i;
				int qwq=s[i].back();
				s[i].pop_back();
				dfs(mi+1,st+1);
				s[i].push_back(qwq);
				if(fl)return ;
//				return ;
			}
		}
		For(i,1,n){
			s[i].push_back(a[mi]);
			op[st]=1;s1[st]=i;
			dfs(mi+1,st+1); 
			s[i].pop_back();
				if(fl)return ;
//			return ;
		}
	}
}
signed main(){
	freopen("meow.in","r",stdin);
	freopen("meow.out","w",stdout);
	read(T);
	while(T--){
		fl=0;
		read(n);read(m);read(k);
		For(i,1,m){read(a[i]);}
		init();
		dfs(1,1);
	}
}
