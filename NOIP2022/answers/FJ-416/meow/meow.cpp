#include <bits/stdc++.h>
using namespace std;
int T,n,m,k,a[2000000],ans[2000000][3]={0},op=0;
int q[300][600]={0},l[300]={0},r[300]={0},L=0;
bool empty(){
	for(int i=0;i<n;i++){
		if(l[i]!=r[i])return false;
	}
	return true;
}
void f(){
	if(empty()&&op!=0&&L==n){
		return;
	}
	for(int i=0;i<n;i++){
		q[i][r[i]]=a[L];
		r[i]++;L++;
		if(r[i]>=2&&q[i][r[i]-2]==q[i][r[i-1]])r[i]-=2;
	    ans[op][0]=1;
	    ans[op][1]=i+1;
	    op++;
	    f();
	    op--;L--;r[i]--;
	}
	for(int i=0;i<n;i++){
		for(int j=0;j<n;j++){
			if(q[i][l[i]]==q[j][l[j]]&&i!=j){
				l[i]++;l[j]++;
				ans[op][0]=2;
				ans[op][1]=i+1;
				ans[op][2]=j+1;
				op++;
				f();
				l[i]--;l[j]--;op--;
			}
		}
	}
}
int main(){
	freopen("meow.in","r",stdin);
	freopen("meow.out","w",stdout);
	scanf("%d",&T);
	while(T--){
		memset(a,0,sizeof(a));
		memset(ans,0,sizeof(ans));
		memset(q,0,sizeof(q));
		memset(l,0,sizeof(l));
		memset(r,0,sizeof(r));
		op=0;L=0;
	    scanf("%d%d%d",&n,&m,&k);
	    for(int i=0;i<m;i++){
	    	scanf("%d",&a[i]);
		}
		f();
	}
	printf("%d\n",op);
	for(int i=op-1;i>=0;i--){
		if(ans[i][0]==1)printf("1 %d\n",ans[i][1]);
		if(ans[i][0]==2)printf("2 %d %d\n",ans[i][1],ans[i][2]);	
	}
	return 0;
}