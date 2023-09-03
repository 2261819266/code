#include<bits/stdc++.h>
#define int unsigned long long
using namespace std;
signed main(){
  freopen("match.in","r",stdin);
  freopen("match.out","w",stdout);
  ios::sync_with_stdio(false);
  cin.tie(0); cout.tie(0);
  int t,n; cin>>t>>n;
  if(n>4000)return 0;
  vector<int> a(n),b(n);
  vector<vector<int> > sa(n,vector<int>(n)),sb(n,vector<int>(n));
  for(auto &i:a)cin>>i;
  for(auto &i:b)cin>>i;
  for(int i=0;i<n;i++)
    for(int j=i;j<n;j++)
      sa[i][j]=(i==j?a[i]:max(a[j],sa[i][j-1])),\
      sb[i][j]=(i==j?b[i]:max(b[j],sb[i][j-1]));
  int q; cin>>q;
  while(q--){
    int l,r,c=0; cin>>l>>r;
    for(int i=l-1;i<r;i++)
      for(int j=i;j<r;j++)
        c+=sa[i][j]*sb[i][j];
    cout<<c<<endl;
  }
  return 0;
}
