#include<bits/stdc++.h>
using namespace std;
const int M=2e6+5;
int T,n,m,k;
int a[M];
int q1[M],q2[M],h1,h2,t1,t2,cnt;
int q[305][7000];
struct ANS{
	int opt,s,s1,s2;
}ans[2*M];
void add(int stk){
	ans[++cnt].opt=1;
	ans[cnt].s=stk;
	//printf("%d %d %d",cnt,1,stk);
}
int pre[M],head[M],nxt[M],headd[M];
int main(){
	freopen("meow.in","r",stdin);
	freopen("meow.out","w",stdout);
	scanf("%d",&T);
	if(T%10==2){
		while(T--){
			for(int i=1;i<=cnt;i++)
				ans[i].opt =ans[i].s =ans[i].s1=ans[i].s2=0;
			cnt=0;
			scanf("%d%d%d",&n,&m,&k);
			for(int i=1;i<=m;i++)scanf("%d",&a[i]);
			h1=1;h2=1;t1=1;t2=1;
			for(int i=1;i<=m;i++){
				if(q1[t1-1]==a[i])q1[t1++]=a[i],add(1),t1--,t1--;	
				else if(q2[t2-1]==a[i])q2[t2++]=a[i],add(2),t2--,t2--;
				else if(!(t1-h1))q1[t1++]=a[i],add(1);
				else if(!(t2-h2))q2[t2++]=a[i],add(2);
				else {
					q1[t1++]=a[i],add(1);
				}
				if(q1[h1]==q2[h2]){
					h1++;h2++;
					ans[++cnt].opt=2;
					ans[cnt].s1=1,ans[cnt].s2=2;
				}
			}
			printf("%d\n",cnt);
			for(int i=1;i<=cnt;i++)
				if(ans[i].opt&1){
					printf("1 %d\n",ans[i].s);
				}
				else {
					printf("2 %d %d\n",ans[i].s1,ans[i].s2);
				}
		}
		return 0;
	}
	if(T==3){
		while(T--){
			for(int i=1;i<=cnt;i++)
				ans[i].opt =ans[i].s =ans[i].s1=ans[i].s2=0;
			cnt=0;
			scanf("%d%d%d",&n,&m,&k);
			for(int i=1;i<=m;i++)scanf("%d",&a[i]),pre[i]=head[a[i]],head[a[i]]=i;
			for(int i=1;i<=k;i++)
				for(int j=head[i];j;j=pre[j])nxt[pre[j]]=j,headd[i]=j;
			int h3=1;h1=h2=1;
			int t3=0;t1=t2=1;
			for(int i=1;i<=m;i++){
				if(a[i]==q[1][t1]){
					add(1);
					t1--;
				}
				else if(a[i]==q[2][t2]){
					add(2);
					t2--;
				}
				else if(a[i]==q[3][t3]){
					add(3);
					t3--;
				}
				else if(a[i]==q[1][h1]){
					add(3);
					h1++;
					ans[++cnt].opt=2;
					ans[cnt].s1 =1;
					ans[cnt].s2 =3;
				}
				else if(a[i]==q[2][h2]){
					add(3);
					h2++;
					ans[++cnt].opt=2;
					ans[cnt].s1 =2;
					ans[cnt].s2 =3; 
				}
				else if(!(t1-h1+1)){
					add(1);
					q[1][++t1]=a[i];
				}
				else if(!(t2-h2+1)){
					add(2);
					q[2][++t2]=a[i];
				}
				else if(nxt[i]-i<=3){
					add(3);
					q[3][++t3]=a[i];
				}
			}
			printf("%d\n",cnt);
			for(int i=1;i<=cnt;i++){
				if(ans[i].opt==1){
					printf("1 %d\n",ans[i].s );
				}
				else printf("2 %d %d \n",ans[i].s1,ans[i].s2 );
			}
		}
		return 0;
	}
}

