#include<bits/stdc++.h>
#include<deque>
using namespace std;

struct Op{
	long long num;
	long long s1;
	long long s2;
};
vector <Op> v;
long long t,n,m,k;
long long ceng;
stack <long long> s;
deque <long long> dq[1010];
long long dq_n;//用掉了多少个栈 
void dfs(long long now){//现要进行第几次操作
	if(now>ceng){
		for(long long i=1;i<=n;i++) if(!dq[i].empty()) return ;
		cout<<ceng<<endl;
		for(long long i=0;i<v.size();i++){
			if(v[i].num==1) cout<<1<<" "<<v[i].s1<<endl;
			else cout<<2<<" "<<v[i].s1<<" "<<v[i].s2<<endl;
		}
		exit(0);
	}
	//操作一
	for(long long i=1;i<=min(dq_n+1,n);i++){
		long long front=s.top();
		s.pop();
		if(dq[i].empty()&&dq_n<n){
			dq[i].push_back(front);
			v.push_back(Op{1,i,0});
			dq_n++;
			dfs(now+1);
			dq[i].pop_back();
			v.pop_back();
			dq_n--;
		}else{
			if(front==dq[i].back()){
				dq[i].pop_back();
				v.push_back(Op{1,i,0});
				dfs(now+1);
				dq[i].push_back(front);
				v.pop_back();
			}else{
				dq[i].push_back(front);
				v.push_back(Op{1,i,0});
				dfs(now+1);
				dq[i].pop_back();
				v.pop_back();
			}
		}
		s.push(front);
	}
	//操作二
	if(dq_n>=2)
		for(long long i=1;i<=min(dq_n,n);i++)
			for(long long j=i+1;j<=min(dq_n,n);j++)
				if(i!=j&&dq[i].front()==dq[j].front()){
					long long top=dq[i].front();
					dq[i].pop_front(),dq[j].pop_front();
					v.push_back(Op{2,i,j});
					dfs(now+1);
					dq[i].push_front(top),dq[j].push_front(top);
					v.pop_back();
				}
}
int main(){
	freopen("meow.in","r",stdin);
	freopen("meow.out","w",stdout);
	cin>>t;
	while(t--){
		cin>>n>>m>>k;
		dq_n=0;
		while(!s.empty()) s.pop();
		for(long long i=0;i<=n+1;i++) dq[i].clear();
		long long xulie[1010];
		for(long long i=1;i<=m;i++) cin>>xulie[i];
		for(long long i=m;i>=1;i--) s.push(xulie[i]);
		for(ceng=m;ceng<=2*m;ceng++)
			dfs(1);
	}
	return 0;
}
