#include<bits/stdc++.h>
using namespace std;
#define fr(x) freopen(#x".in","r",stdin),freopen(#x".out","w",stdout)
using ll = long long;
constexpr int N=305;
int T,n,m,k,a[N];
deque<int>d[N]; 
vector<tuple<int,int,int>>ans;
signed main(){
	fr(meow);
	scanf("%d",&T);
	if(T%10==1){
		while(scanf("%d%d%d",&n,&m,&k),T--){
			ans.clear();
			for(int i=1;i<=m;i++)scanf("%d",a+i);
			for(int i=1;i<=m;i++){
				if(d[(a[i]-1>>1)+1].empty())d[(a[i]-1>>1)+1].push_back(a[i]),ans.push_back(make_tuple(1,(a[i]-1>>1)+1,0));
				else if(d[(a[i]-1>>1)+1].back()==a[i])d[(a[i]-1>>1)+1].pop_front(),ans.push_back(make_tuple(1,(a[i]-1>>1)+1,0));
				else if(d[(a[i]-1>>1)+1].front()==a[i])d[(a[i]-1>>1)+1].pop_back(),ans.push_back(make_tuple(1,n,0)),ans.push_back(make_tuple(2,(a[i]-1>>1)+1,n));
				else d[(a[i]-1>>1)+1].push_back(a[i]),ans.push_back(make_tuple(1,(a[i]-1>>1)+1,0));
			}
			printf("%d\n",(int)ans.size());
			for(auto i:ans)if(get<0>(i)==2)printf("2 %d %d\n",get<1>(i),get<2>(i));else printf("1 %d\n",get<1>(i));
		}
	}
	
	return 0;
}

