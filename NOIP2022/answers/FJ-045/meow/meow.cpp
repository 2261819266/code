#include<bits/stdc++.h>
using namespace std;
const int N=2e6+1,M=1001;
int a[N],op[N],x[N],y[N];
int cu[N],ap[N],num[N];
int  type[N],top[N];
int cnt,tl;
inline int read(){
	int x=0,f=1;char c=getchar();
	while(c>'9'||c<'0') {if(c=='0') f=-1;c=getchar();}
	while(c>='0'&&c<='9'){x=(x<<3)+(x<<1)+c-'0';c=getchar();}
	return x*f;
}
void insert(int xx,int w){
	ap[xx]=w;
	if(num[w]==0) type[xx]=1;
	else type[xx]=2,type[top[w]]=1;
	num[w]++;top[w]=xx;
	op[++cnt]=1;x[cnt]=w;
	return;
}
void del1(int xx){
	op[++cnt]=1;x[cnt]=cu[1];
	op[++cnt]=2;x[cnt]=cu[1];y[cnt]=ap[xx];
	ap[xx]=0;
	num[ap[xx]]--;cu[++tl]=ap[xx];
	return;
}
void del2(int xx){
	op[++cnt]=1;x[cnt]=xx;
	num[ap[xx]]--;cu[++tl]=ap[xx];
	ap[xx]=0;
	return;
}
signed main(){
	freopen("meow.in","r",stdin);
	freopen("meow.out","w",stdout);
	int T=read();
	while(T--){
		int n=read(),m=read(),k=read();cnt=0;tl=n;
		for(int i=1;i<=n;i++) cu[i]=i,num[i]=0;
		for(int i=1;i<=m;i++)
		a[i]=read();
		if(k==2*n-2){
		for(int i=1;i<=m;i++){
		if(ap[a[i]]==0) insert(a[i],cu[tl]),tl-=(num[ap[a[i]]]==2);
		else{
			if(type[a[i]]==1) del1(a[i]);
			if(type[a[i]]==2) del2(a[i]);
		}
	    }
	    cout<<cnt<<'\n';
	    for(int i=1;i<=cnt;i++){
	    	cout<<op[i]<<' '<<x[i];
	    	if(op[i]==2) cout<<' '<<y[i];
	    	cout<<'\n';
		}
	    continue;
	    }
	    if(n==2){
	    	for(int i=1;i<=m;i++){
	    		if(ap[a[i]]==0){
	    			if(a[i+1]==a[i]||type[a[i+1]]==0) {insert(a[i],cu[tl]);}
	    			else{
	    				if(type[a[i+1]]==1) insert(a[i],ap[a[i+1]]);
	    				if(type[a[i+1]]==2){
	    					if(ap[a[i]+1]==1) insert(a[i],2);
	    					else insert(a[i],1);
						}
					}
				}
				else{
					if(type[a[i]]==1) del1(a[i]);
				    if(type[a[i]]==2) del2(a[i]);
				}
				for(int i=1;i<=3;i++)
				 if(num[i]==1)
				  type[top[i]]=2;
			}
			cout<<cnt<<'\n';
	    	for(int i=1;i<=cnt;i++){
	    		cout<<op[i]<<' '<<x[i];
	    		if(op[i]==2) cout<<' '<<y[i];
	   		 	cout<<'\n';
			}
			continue;
		}
	}
	return 0;
}
