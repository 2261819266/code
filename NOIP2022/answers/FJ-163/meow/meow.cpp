#include<bits/stdc++.h>
using namespace std;
const int MAXS=2*1e6+5;
const int MAXN=305;
int T,n,m,k;
int a[MAXS],pos=1;
int op,ans[2*MAXS+1][3];
int at[MAXN*2+1];
int st[MAXN][3];
priority_queue<int,vector<int>,greater<int>>q1,q2;
void work(){
	while(pos<=m){
		if(at[a[pos]]){
			if(st[at[a[pos]]][0]==a[pos]){
				++op;
				ans[op][0]=1;
				ans[op][1]=n;
				ans[op][2]=0;
				++op;
				ans[op][0]=2;
				ans[op][1]=at[a[pos]];
				ans[op][2]=n;
				st[at[a[pos]]][0]=st[at[a[pos]]][1];
				st[at[a[pos]]][1]=0;
				if(st[at[a[pos]]][0])
					q2.push(at[a[pos]]);
				else
					q1.push(at[a[pos]]);
				at[a[pos]]=0;
			}else{
				++op;
				ans[op][0]=1;
				ans[op][1]=at[a[pos]];
				ans[op][2]=0;
				st[at[a[pos]]][1]=0;
				q2.push(at[a[pos]]);
				at[a[pos]]=0;
			}
		}else{
			if(!q1.empty()){
				int nxt=q1.top();q1.pop();
				st[nxt][0]=a[pos];
				at[a[pos]]=nxt;
				++op;
				ans[op][0]=1;
				ans[op][1]=nxt;
				ans[op][2]=0;
			}else if(!q2.empty()){
				int nxt=q2.top();q2.pop();
				st[nxt][1]=a[pos];
				at[a[pos]]=nxt;
				++op;
				ans[op][0]=1;
				ans[op][1]=nxt;
				ans[op][2]=0;
			}else{//we have all 2n-1 colors here
				if(a[pos]==a[pos+1]){
					++op;
					ans[op][0]=1;
					ans[op][1]=n;
					ans[op][2]=0;
					++op;
					ans[op][0]=1;
					ans[op][1]=n;
					ans[op][2]=0;
					pos+=2;
				}else{
					int i(1);
					for(;a[pos+i]!=a[pos]&&
						st[at[a[pos+i]]][0]!=a[pos+i];++i);
					if(a[pos]==a[pos+i]){
						++op;
						ans[op][0]=1;
						ans[op][1]=n;
						ans[op][2]=0;
						for(int j(1);j<i;++j){
							++op;
							ans[op][0]=1;
							ans[op][1]=at[a[pos+j]];
							ans[op][2]=0;
							q2.push(at[a[pos+j]]);
							st[at[a[pos+j]]][1]=0;
							at[a[pos+j]]=0;
						}
						++op;
						ans[op][0]=1;
						ans[op][1]=n;
						ans[op][2]=0;
					}else{
						++op;
						ans[op][0]=1;
						ans[op][1]=at[a[pos+i]];
						ans[op][2]=0;
						for(int j(1);j<i;++j){
							++op;
							ans[op][0]=1;
							ans[op][1]=at[a[pos+j]];
							ans[op][2]=0;
							q2.push(at[a[pos+j]]);
							st[at[a[pos+j]]][1]=0;
							at[a[pos+j]]=0;
						}
						++op;
						ans[op][0]=1;
						ans[op][1]=n;
						ans[op][2]=0;
						++op;
						ans[op][0]=2;
						ans[op][1]=at[a[pos+i]];
						ans[op][2]=n;
						st[at[a[pos+i]]][0]=st[at[a[pos+i]]][1];
						st[at[a[pos+i]]][1]=a[pos];
						at[a[pos]]=at[a[pos+i]];
						at[a[pos+1]]=0;
						pos+=i;
					}
				}
			}
		}
		++pos;
	}
}
void prt(){
	printf("%d\n",op);
	for(int i(1);i<=op;++i){
		printf("%d ",ans[i][0]);
		if(ans[i][0]==1){
			printf("%d\n",ans[i][1]);
		}else{
			printf("%d %d\n",ans[i][1],ans[i][2]);
		}
	}
}
int main(){
	freopen("meow.in","r",stdin);
	freopen("meow.out","w",stdout);
	scanf("%d",&T);
	while(T--){
		scanf("%d%d%d",&n,&m,&k);
		for(int i(1);i<=m;++i){
			scanf("%d",&a[i]);
		}
		op=0;
		while(!q1.empty()) q1.pop();
		while(!q2.empty()) q2.pop();
		for(int i(1);i<=n-1;++i){
			q1.push(i);q2.push(i);
		}
		work();
		prt();
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}

