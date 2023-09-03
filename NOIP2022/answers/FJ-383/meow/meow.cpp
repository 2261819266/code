#include<bits/stdc++.h>
using namespace std;
deque<int> q[301];
int main(){
  freopen("meow.in","r",stdin);
  freopen("meow.out","w",stdout);
  ios::sync_with_stdio(false);
  int t; cin>>t;
  while(t--){
    int n,m,k; cin>>n>>m>>k;
    vector<int> a(m),r;
    for(auto &i:a)cin>>i;
    //if(k+2==(n<<1)){
      vector<tuple<int,int,int> > s;
      for(auto &i:a){
        int w=i+1>>1;
        if(q[w].empty()){
          s.emplace_back(1,w,0);
          q[w].emplace_front(i);
        }
        else if(q[w].front()==i){
          s.emplace_back(1,w,0);
          q[w].pop_front();
        }
        else{
          if(q[w].size()==1){
            s.emplace_back(1,w,0);
            q[w].emplace_front(i);
          }
          else{
            s.emplace_back(1,n,0);
            s.emplace_back(2,w,n);
            q[w].pop_back();
          }
        }
      }
      cout<<s.size()<<endl;
      for(auto i:s){
        if(get<0>(i)==1)cout<<"1 "<<get<1>(i);
        else cout<<"2 "<<get<1>(i)<<' '<<get<2>(i);
        cout<<endl;
      }
    //}
  }
  return 0;
}
