#include<bits/stdc++.h>
using namespace std;
int t,a[2000005],x[305],y[305],z[305],nm[305];
int q[305][200005];
int main(){
	freopen("meow.in","r",stdin);
	freopen("meow.out","w",stdout);
	scanf("%d",&t);
	while(t--){
		int n,m,k,num=0,c=1;
		scanf("%d%d%d",&n,&m,&k);
		for(int i=1;i<=m;++i)scanf("%d",&a[i]);
	    q[1][1]=a[1];
	    nm[1]++;
	    x[1]=1;y[1]=1;z[1]=0;
	    c++;
	    num++;
	    for(int i=2;i<=m;++i){
	    	int p=1;
	    	for(int j=1;j<=n;++j){
	    		if(a[i]==q[j][nm[j]]){
	    			num++;
					q[j][nm[j]]=0;
	    			nm[j]--;
	    			p=0;
	    			x[c]=1,y[c]=j;
	    			break;
				}
			}
			if(p!=0)
			for(int j=1;i<=n;++j){
				if(a[i]==q[j][1])
					for(int l=1;l<=n;++l)
					    if(q[l][1]==0){
					    	num+=2;
						    for(int kl=1;kl<nm[j];kl++)q[j][kl]=q[j][kl+1];
						    q[j][nm[j]]=0;nm[j]--;
					    	p=0;
					    	x[c]=2,y[c]=j,z[c]=l;
					    	p=0;
					    }
				if(p==0)break;
			}
			if(p!=0){
				int minn=2000005,kl;
				for(int l=1;l<=n;++l)if(minn>nm[l]){minn=nm[l];kl=l;}
				nm[kl]++;
				q[kl][nm[kl]]=a[i];
				num++;
				x[c]=1,y[c]=kl;
			}
		}
		cout<<num<<endl;
		for(int i=1;i<c;++i){
			cout<<x[i]<<" "<<y[i];
			if(x[i]==1)cout<<z[i];
			cout<<endl;
		}
	}
	return 0;
}
//=0
