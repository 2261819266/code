#include<iostream>
#include<cstdio>
#include<cmath>
#include<cstring>
using namespace std;
struct Node{
	int oo;
	int s1,s2;
}step[4000001];
int T;
int n,m,k;
int c[2000001];
int nt[2000001],f[1001];
int sta[1001][4],top[1001];
int cnt,num;
void del(int x){
	for(int i=1;i<=top[x];i++) sta[x][i]=sta[x][i+1];
	--top[x];
	if(top[x]==1)cnt++;
	if(top[x]==0) num++;
}
int main(){
	freopen("meow.in","r",stdin);
	freopen("meow.out","w",stdout);
	cin>>T;
	while(T--){
		memset(step,0,sizeof(step));
		memset(c,0,sizeof(c));
		memset(nt,0,sizeof(nt));
		memset(f,0,sizeof(f));
		memset(sta,0,sizeof(sta));
		memset(top,0,sizeof(top));
		cin>>n>>m>>k;
		for(int i=1;i<=m;i++) scanf("%d",&c[i]);
		for(int i=m;i>=1;i--){
			if(!f[c[i]]) f[c[i]]=i;
			else {
			  nt[i]=f[c[i]];
			  f[c[i]]=0;
			}
		}
		cnt=n,num=n;
		int tot=0;
		for(int i=1;i<=m;i++){
		    if(nt[i]==0){
		    	int rec=0;
		    	for(int j=1;j<=n;j++) 
				if(top[j]==0) {
		    	    rec=j;
		    	    break;
				}
		    	for(int j=1;j<=n;j++){
		    		if(c[sta[j][top[j]]]==c[i]&&top[j]>0){
		    			top[j]--;
		    			step[++tot].oo=1;
		    			step[tot].s1=j;
		    			if(top[j]==1)cnt++;
						if(top[j]==0)num++; 
					}
					else if(c[sta[j][1]]==c[i]&&top[j]>1) {
						step[++tot].oo=1;
						step[tot].s1=rec;
						step[++tot].oo=2;
						step[tot].s1=rec;
						step[tot].s2=j;
						top[rec]++;
						del(j);
						del(rec);
					}
				}
				continue;
			}
			bool ww=false;
			if(num==0){
				int maxn=-0x7FFFFFFF,re=0;
				bool cc=true;
				for(int j=1;j<=n;j++){
					if(maxn<nt[j]&&top[j]==1) {
						maxn=nt[j],re=j;
					}
					if(top[j]==2){
						if(nt[sta[j][2]]>nt[i]){
							sta[j][++top[j]]=i;
							step[++tot].oo=1;
							step[tot].s1=j;
							cc=false;
							break;
						}
					}
				}
				if(cc){
					step[++tot].oo=1;
					step[tot].s1=re;
					sta[re][++top[re]]=i;	
				}
			}
			else if(cnt==1){
				int rec1=0;
				for(int j=1;j<=n;j++) if(top[j]==0) rec1=j;
				bool cc=false;
				for(int j=1;j<=n;j++){
					if(j==rec1) continue;
					if(top[j]==2){
						if(nt[sta[j][2]]>nt[i]){
							sta[j][++top[j]]=i;
							step[++tot].oo=1;
							step[tot].s1=j;
							cc=false;
							break;
						}
					}
					if(nt[sta[j][1]]<nt[sta[j][2]]){
						cc=true;
						step[++tot].oo=1;
						step[tot].s1=j;
						sta[j][++top[j]]=i;
						break;
					}
					
				}
				if(!cc){
					step[++tot].oo=1;
					step[tot].s1=rec1;
					sta[rec1][++top[rec1]]=i;
					num--;
				}
			}
			else {
				for(int j=1;j<=n;j++){
					if(top[j]==0&&num==1) continue;
					if(top[j]<2){
						sta[j][++top[j]]=i;
						step[++tot].oo=1;
						step[tot].s1=j;
						if(top[j]==2) cnt--;
						if(top[j]==1) num--;
						break;
					}
				}
			}
		}
		printf("%d\n",tot);
		for(int i=1;i<=tot;i++){
			printf("%d ",step[i].oo);
			if(step[i].oo==1) printf("%d",step[i].s1);
			else printf("%d %d",step[i].s1,step[i].s2);
			printf("\n");
		}
	}
	return 0;
}