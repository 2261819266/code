#include<bits/stdc++.h>
#define int long long
using namespace std;
const int mod=1e9+7;
int qpow(int a,int b){
  int r=1;
  while(b){
    if(b&1)r=r%mod*a%mod;
    a=a%mod*a%mod; b>>=1ll;
  }
  return r;
}
bool a[100][100];
signed main(){
  freopen("barrack.in","r",stdin);
  freopen("barrack.out","w",stdout);
  int n,m,s=0; cin>>n>>m;
  if(n==1){
    cout<<2<<endl;
    return 0;
  }
  for(int i=1;i<=m;i++){
    int u,v; cin>>u>>v;
    a[--u][--v]=a[v][u]=true;
  }
  for(int i=1;i<1<<n;i++){
    int c=0;
    for(int j=0;j<n-1;j++)
      for(int k=j+1;k<n;k++)
        if(a[j][k]&&((i>>j)&1)&&((i>>k)&1))c++;
    s=(s+qpow(2,m-c))%mod;
  }
  cout<<s<<endl;
  return 0;
}
