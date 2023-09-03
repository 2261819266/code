#include<bits/stdc++.h>
#define int long long
using namespace std;
typedef pair<int,int> pii;
const int mod=998244353;
string a[1001];
signed main(){
  freopen("plant.in","r",stdin);
  freopen("plant.out","w",stdout);
  ios::sync_with_stdio(false);
  int t,id; cin>>t>>id;
  while(t--){
    int n,m,c,f,sc=0,sf=0; cin>>n>>m>>c>>f;
    vector<vector<int>> hr(n);
    for(int i=0;i<n;i++)cin>>a[i];
    if(!c&&!f){cout<<0<<endl; continue;}
    for(int i=0;i<n;i++){
      for(int j=0;j<m;j++){
        if(a[i][j]==49){
          if(j&&a[i][j-1]==48)
            hr[i].emplace_back(j-1);
        }
        else if(j==m-1)
          hr[i].emplace_back(j);
      }
    }
    for(int i=0;i<m;i++){
      vector<int> r,v; int s0=0,s1=0;
      for(int j=0;j<=n;j++){
        if(j==n||a[j][i]==49){
          if(r.size()<3){
            r.clear(); continue;
          }
          if(!j||a[j-1][i]==49)continue;
          v.resize(r.size()); v[0]=r[0];
          for(int k=1;k<r.size();k++)v[k]=(v[k-1]+r[k])%mod;
          for(int k=0;k<r.size();k++){
            int p=(r[k]%mod*(k>1?v[k-2]:0)%mod)%mod;
            s0=(s0+p%mod)%mod; s1=(s1+p%mod*(r.size()-k-1)%mod)%mod;
          }
          r.clear(); v.clear(); continue;
        }
        r.emplace_back(*lower_bound(hr[j].begin(),hr[j].end(),i)-i);
      }
      sc=(sc+s0%mod)%mod;
      sf=(sf+s1%mod)%mod;
    }
    cout<<sc*c<<' '<<sf*f<<endl;
  }
  return 0;
}
