#include<bits/stdc++.h>
using namespace std;
long long int t,n,m,k,o=0,a,p,s[305],l[305],d,len=1;

struct no{
	int aa,ss;
}pp[100005];
long long read(){
	long long int p=0,fi=1;
	char d=getchar();
	while(d<'0'||d>'9'){
		if(d=='-') fi=-1;
		d=getchar();
	}
	while(d>='0'&&d<='9'){
		p+=p*10+d-'0';
		d=getchar();
	}
	return p*fi;
}

void find(){
	
	
}

int main(){
	freopen("meow.in","r",stdin);
	freopen("meow.out","w",stdout);
    t=read();
    if(t==1001) o=1;
    if(t==1002) o=2;
    while(t--){
    	p=0;
    	n=read();
	    m=read();
    	k=read();
    	if(o==1){
    		for(int i=1;i<=n;i++){
    			a=read();
    			d=(a+1)/2;
    				if(s[d]==a){
    					pp[p++]=(no){n,0};
    					pp[p++]=(no){d,n};
    					l[d]--;
					}
					else {
						pp[p++]=(no){d,0};
						if(l[d]==0) {
							s[d]=a;
							l[d]++;
						}
						else{
							if(a==2*d)s[d]=a-1;
							else s[d]=a+1;
							l[d]--;
						}
					}
				
					
			}
			cout<<p;
			for(int i=1;i<=p;i++){
				if(pp[i].ss==0)cout<<"1 "<<pp[i].aa;
				else cout<<"2 "<<pp[i].aa<<" "<<pp[i].ss;
			}
		}
	}
	
	
	return 0;
}
