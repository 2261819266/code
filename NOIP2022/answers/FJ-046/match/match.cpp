#include<bits/stdc++.h>
#define R register
using namespace std;
int a[250005],b[250005];
int f1[250005],f2[250005],f[250005];
int T,l,r,Q,n,ans,sun;
int main(){
	freopen("match.in","r",stdin);
	freopen("match.out","w",stdout);
	cin>>T>>n;
	for(R int i=1;i<=n;i++) cin>>a[i];
	for(R int i=1;i<=n;i++) cin>>b[i];
	cin>>Q;
	while(Q--){
		cin>>l>>r;
		ans=0;
		memset(f,0,sizeof(f));
		memset(f1,0,sizeof(f1));
		memset(f2,0,sizeof(f2));
		for(R int i=r;i>=l;i--){
		 for(R int p=r;p>=i;p--){
		  for(R int q=p;q<=r;q++){
		  	f2[q]=max(f2[q],a[p]*b[q]);
		  }
		  for(R int q=p;q<=r;q++){
		    f1[p]+=f2[q];
		    //cout<<f1[p]<<"\n";
	      }
		  //f1[p]=max(f1[p],sun);
		  //f1[i]+=f1[p];
		  //f1[i]=max(f1[i],f1[p]);
		  //cout<<f1[p]<<"\n";
		  //sun=0;
	     }
	     f[l]+=f1[i];
	    }
	    cout<<f[l]<<"\n";
	}
	return 0;
}
