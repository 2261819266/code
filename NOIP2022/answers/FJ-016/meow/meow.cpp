#include<bits/stdc++.h>
#define fir first
#define sec second
#define mp make_pair
#define pb push_back

using namespace std;
typedef pair<int,int> pii;
typedef long long ll;
typedef unsigned long long ull;

void read(int &x){
	static char c;
	static int f;
	f=1;
	while(!isdigit(c=getchar()))
		if(c=='-') f=-1;x=c^48;
	while(isdigit(c=getchar())) x=(x*10)+(c^48);
	x*=f;
}

void read(ll &x){
	static char c;
	static int f;
	f=1;
	while(!isdigit(c=getchar()))
		if(c=='-') f=-1;x=c^48;
	while(isdigit(c=getchar())) x=(x*10)+(c^48);
	x*=f;
}

void read(ull &x){
	static char c;
	while(!isdigit(c=getchar()));x=c^48;
	while(isdigit(c=getchar())) x=(x*10)+(c^48);
}

void chkmax(int &x,int y){if(y>x)x=y;}
void chkmin(int &x,int y){if(y<x)x=y;}
void chkmax(ll &x,ll y){if(y>x)x=y;}
void chkmin(ll &x,ll y){if(y<x)x=y;}
void chkmax(ull &x,ull y){if(y>x)x=y;}
void chkmin(ull &x,ull y){if(y<x)x=y;}

void Solve(){
	int n,m,k;read(n),read(m),read(k);
	vector<int> a(m);
	for(int i=0;i<m;++i) read(a[i]),++a[i];
	
	vector<pii> op;
	vector< deque<int> > st(n+1);
	
	auto op1=[&](int id1)->void{op.pb(mp(id1,0));};
	auto op2=[&](int id1,int id2)->void{op.pb(mp(id1,id2));};
	
	if(k==2*n-2)
		return [&]()->void{
			for(int v:a){
				int stk=v/2;
				if(st[stk].empty()) op1(stk),st[stk].push_back(v);
				else
					if(st[stk].back()==v)
						op1(stk),st[stk].pop_back();
					else
						if(st[stk].front()==v) op1(n),op2(stk,n),st[stk].pop_front();
						else op1(stk),st[stk].push_back(v);
			}
			printf("%d\n",op.size());
			for(auto o:op)
				if(o.sec) printf("2 %d %d\n",o.fir,o.sec);
				else printf("1 %d\n",o.fir);
		}(),void();
	if(n==2)
		return [&]()->void{
			auto tran=[&](int v)->int{return (v==1)?2:1;};
			int sts=-1,p1=0,p2=0;
			for(int i=0;i<m;i+=2){
				if(a[i]==a[i+1]){op1(1),op1(1);continue;}
				if(sts==-1){
					op1(1),op1(1);
					sts=1,p1=a[i],p2=a[i+1];
				}
				else if(sts){
					if(p1==a[i]){
						op1(tran(sts)),op2(1,2),op1(sts);
						p1=p2,p2=a[i+1];
						if(p1==p2) sts=-1,p1=p2=0;
					}
					else if(p2==a[i]){
						op1(sts),op1(sts);
						p2=a[i+1];
						if(p1==p2) sts=-1,p1=p2=0;
					}
					else{
						if(p1==a[i+1]){
							op1(sts),op1(tran(sts)),op2(1,2);
							p1=p2,p2=a[i];
						}
						else{
							op1(tran(sts)),op1(sts);
							p2=a[i];
							if(sts==2) swap(p1,p2);
							sts=0;
						}
					}
				}
				else{
					if(p1==a[i]){
						op1(1),op1(1),p1=a[i+1];
						if(p1==p2) op2(1,2),sts=-1,p1=p2=0;
					}
					else if(p2==a[i]){
						op1(2),op1(2),p2=a[i+1];
						if(p1==p2) op2(1,2),sts=-1,p1=p2=0;
					}
					else if(p1==a[i+1]){
						op1(2),op1(1),p1=p2,p2=a[i],sts=2;
					}
					else op1(1),op1(2),p2=a[i],sts=1;
				}
			}
			printf("%d\n",op.size());
			for(auto o:op)
				if(o.sec) printf("2 %d %d\n",o.fir,o.sec);
				else printf("1 %d\n",o.fir);
		}(),void();
	
	if(m<=20)
	[&]()->void{
		vector<int> id(k);
		for(int i=0;i<k;++i) id[i]=i+2;
		
		auto chk=[&]()->bool{
			op.clear();
			vector< deque<int> > st1(n+1);
			for(int o:a){
				int v=id[o-2];
				int stk=v/2;
				if(v==k+1){
					if(st1[n].empty()) op1(n),st1[n].push_back(v);
					else op1(n),st1[n].pop_back();
					continue;
				}
				if(st1[stk].empty()) op1(stk),st1[stk].push_back(v);
				else if(st1[stk].back()==v) op1(stk),st1[stk].pop_back();
				else if(st1[stk].front()==v){
					if(st1[n].empty()) st1[stk].pop_front(),op1(n),op2(stk,n);
					else return false;
				}
				else op1(stk),st1[stk].push_back(v);
			}
			return true;
		};
		
		do{
			if(chk()){
				printf("%d\n",op.size());
				for(auto o:op)
					if(o.sec) printf("2 %d %d\n",o.fir,o.sec);
					else printf("1 %d\n",o.fir);
				return;
			}
		}while(next_permutation(id.begin(),id.end()));
	}();
}

void Work(){
	freopen("meow.in","r",stdin);
	freopen("meow.out","w",stdout);
	int T;read(T);
	while(T--) Solve();
}

int main(){Work();}

