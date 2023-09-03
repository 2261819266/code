#include<bits/stdc++.h>
#define N 2000050
using namespace std;
int T,n,m,k,a[N];
int v[605][4],st[305][4];
int cot,ans[N][3],et;
int main(){
	freopen("meow.in","r",stdin);
	freopen("meow.out","w",stdout);
	scanf("%d",&T);
	int flag=1;
	for(int kk=1;kk<=T;kk++){
		memset(a,0,sizeof(a));
		memset(v,0,sizeof(v));
		memset(st,0,sizeof(st));
		scanf("%d%d%d",&n,&m,&k);
		for(int i=1;i<=m;i++){
			scanf("%d",&a[i]);
		}
		int cnt=0;cot=0;et=0;
		st[0][2]=1;
		if(flag==1)
		{
			
		for(int i=1;i<=m;i++){
			if(!v[a[i]][1]&&!v[a[i]][2]){
				if(st[cnt][2]){
					cnt++;
					st[cnt][1]=a[i];
					v[a[i]][1]=cnt;
					ans[++cot][0]=1;ans[cot][1]=cnt;
				}
				else{
					st[cnt][2]=a[i];
					v[a[i]][2]=cnt;
					ans[++cot][0]=1;ans[cot][1]=cnt;
				}
			}
			else{
				if(v[a[i]][2]){
					ans[++cot][0]=1;ans[cot][1]=v[a[i]][2];
					v[a[i]][2]=0;
				}
				else{
					int u=cnt+1;
					ans[++cot][0]=1;ans[cot][1]=u;
					ans[++cot][0]=2;ans[cot][1]=v[a[i]][1];ans[cot][2]=u;
					v[a[i]][1]=0;
				}
			}	
		}
		
    	}
    	else{
    		queue <int> ept;
		   for(int i=1;i<=m;i++){
		   	if(v[a[i]][1]){
		   		int r=v[a[i]][1];v[a[i]][1]=0;
		   		ans[++cot][0]=1;ans[cot][1]=n;
		   		ans[++cot][0]=2;ans[cot][1]=n;ans[cot][2]=r;
		   		st[r][1]=st[r][2];
				   v[st[r][2]][2]=0;
		   		if(!v[st[r][2]][1]){
		   			v[st[r][2]][1]=r;
		   			st[r][2]=st[r][3];
		   		    v[st[r][3]][2]=r;
		   	    	v[st[r][3]][3]=0;
		   		    st[r][0]--;
				   } 
		   		else{
		   			ans[++cot][0]=2;ans[cot][1]=r;ans[cot][2]=v[st[r][2]][1];
		   			v[st[r][2]][1]=0;
		   			st[r][1]=st[r][3];
		   			if(!v[st[r][3]][1]){
		   				v[st[r][3]][1]=r;
		   				st[r][0]=1;st[r][1]=st[r][3];
		   				v[st[r][3]][3]=0;
		   				st[r][0]=1;
					   } 
		   			else{
		   				ans[++cot][0]=2;ans[cot][1]=r;ans[cot][2]=v[st[r][3]][1];
		   				v[st[r][3]][1]=0;
		   				st[r][0]=0;
					   }
				   }
		   		if(ept.empty()&&st[r][0]<2) et=r;
		   		else if(st[r][0]<2) ept.push(r);
			   }
		   else{
		   	if(v[a[i]][2]){
		   		int rl=v[a[i]][2];
		   		if(st[rl][0]==2){
		   			v[a[i]][2]=0;
		   			ans[++cot][0]=1;ans[cot][1]=rl;
		   			st[rl][0]=1;
		   			ept.push(rl);
				   }
				else{
					v[a[i]][st[et][0]+1]=et;
					ans[++cot][0]=1;ans[cot][1]=et;
					st[et][0]++;
					if(st[et][0]==2){
						if(ept.empty()) et=0;
						else{
							et=ept.front();ept.pop();
						}
					}
				}
			   }
			 else{
			 	if(v[a[i]][3]){
			 		ans[++cot][0]=1;ans[cot][1]=v[a[i]][3];
			 		st[v[a[i]][3]][0]=2;v[a[i]][3]=0;
			 		st[v[a[i]][3]][3]=0;
				 }
				 else{
				 	if(cnt<n-1){
				 		if(st[cnt][0]==1){
				 			st[cnt][0]++;
				 			st[cnt][2]=a[i];
				 			v[a[i]][2]=cnt;
				 			ans[++cot][0]=1;ans[cot][1]=cnt;
						 }
						 else{
						 	cnt++;
						 	st[cnt][0]++;
				 			st[cnt][1]=a[i];
				 			v[a[i]][1]=cnt;
				 			ans[++cot][0]=1;ans[cot][1]=cnt;
						 }
					 }
					else{
						if(et){
							st[et][0]++;
							st[et][st[et][0]]=a[i];
							v[a[i]][st[et][0]]=et;
							ans[++cot][0]=1;ans[cot][1]=et;
							if(	st[et][0]==2){
								if(ept.empty()) et=0;
								else{
									et=ept.front();
									ept.pop();
								}
							}
						}
						else{
							for(int z=1;z<=n;z++){
								if(st[z][1]!=a[i+1]&&st[z][2]!=a[i+1]){
									ans[++cot][0]=1;ans[cot][1]=z;
									v[a[i]][3]=z;
									st[z][0]++;
									st[z][3]=a[i];
									break;
								}
							}
						}
					}
				 }
			 }
		   }
     	} 
     	    
 		}
		printf("%d\n",cot);
		for(int i=1;i<=cot;i++){
			if(ans[i][0]==1) printf("%d %d",1,ans[i][1]);
			else printf("%d %d %d",2,ans[i][1],ans[i][2]);
			printf("\n");
		}
	}
	return 0;
}
