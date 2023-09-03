#include<bits/stdc++.h>
using namespace std;
int t,n,m,k,c[2000002],ans;
int all=0;
struct numbe{
	int c,f,t;
}l[1000002];
int nx[2000020],la[2000020],z[602][2],kl[2000020];
bool ways[2000020];
int makeans[2000020],wayw[2000020];
void find(int sta,int b){
	int x[1000002],r=0;bool dow=0;
	while(sta!=all+1){
		while(r!=0&&l[x[r]].t<l[sta].f){
			r--;
			if(r==1||(r!=1&&l[x[r]].t>l[x[r-1]].t))dow=0;
		}
		if(r==0){
			dow=0;
			r++;
			x[1]=sta;kl[sta]=b;
			la[nx[sta]]=la[sta];
			nx[la[sta]]=nx[sta];
			ways[sta]=0;
			if(dow==0)ans++;
		}
		else{
			if(dow==0){
				r++;
			    x[r]=sta;kl[sta]=b;
			    la[nx[sta]]=la[sta];
			    nx[la[sta]]=nx[sta];
			    if(l[x[r]].t<l[x[r-1]].t){
				dow=1;
				}
				ways[sta]=dow;
				if(dow==0)ans++;
			}
			else{
				if(l[sta].t<l[x[r]].t){
					r++;
			        x[r]=sta;kl[sta]=b;
			        ways[sta]=dow;
			        la[nx[sta]]=la[sta];
			        nx[la[sta]]=nx[sta];
				}
			}
		}
		sta=nx[sta];
	}
	return;
}
int main(){
   freopen("meow.in","r",stdin);
   freopen("meow.out","w",stdout);
   cin>>t;
   while(t--){
   	scanf("%d%d%d",&n,&m,&k);ans=0;
   	for(int i=1;i<=m;i++)scanf("%d",&c[i]);
   		all=0;
		for(int i=1;i<=k;i++)z[i][0]=z[i][1]=0;
		for(int i=1;i<=m;i++){wayw[i]=makeans[i]=0;
			if(z[c[i]][0]==0){
				z[c[i]][0]=i;z[c[i]][1]=++all;
			}
			else{
				l[z[c[i]][1]].c=c[i];l[z[c[i]][1]].t=i;l[z[c[i]][1]].f=z[c[i]][0];
				kl[all]=0;
				z[c[i]][0]=z[i][1]=0;
			}
		}
		//sort(l+1,l+all+1,cmp);
		for(int i=1;i<=all;i++){
		ways[i]=0;kl[i]=0;
		nx[i]=i+1;
		la[i]=i-1;
		}
		nx[0]=1;
		for(int i=1;i<=n-1;i++){
		    int q=nx[0];
		    find(q,i);
		}
		cout<<ans+m<<endl; 
		for(int i=1;i<=all;i++){
			makeans[l[i].f]=makeans[l[i].t]=kl[i];
			wayw[l[i].t]=ways[i]^1;
		}
		for(int i=1;i<=m;i++){
			if(wayw[i]==1){
				printf("%d %d\n",1,n);
				printf("%d %d %d\n",2,makeans[i],n);
			}
			else{
				printf("%d %d\n",1,makeans[i]);
			}
		} 
   }
   return 0;
}
