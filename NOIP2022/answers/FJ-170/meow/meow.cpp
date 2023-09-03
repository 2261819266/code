#include<iostream>
#include<cstdio>
#include<cmath>
#include<algorithm>
#include<cstring>
#include<vector>
#include<queue>
using namespace std;
const int maxn=1e6+100,maxm=1e3+10,mod=998244353;

inline int read(int x=0){
	int c,f(1);
	for(c=getchar();!isdigit(c);c=getchar())if(c=='-')f=-f;
	for(;isdigit(c);c=getchar())x=(x<<3)+(x<<1)+c-0x30;
	return x*f;
}

int T,n,m,k,a[maxn]={0},b1[maxn]={0},b2[maxn]={0},b3[maxn]={0},end1=1,end2=1,end3=1,t1,t2,t3,op=0,ans1[maxn]={0},cnt1=0,cnt2=0;
int ans2[maxn][2]={0};

void dfs(int step){
	if(step>m)return;
	if(step==m){
		if(t1==end1+1&&t2==end2+1&&t3==end3+1){
			cout<<cnt1+cnt2<<endl;
		}
	}
	for(int i=1;i<=3;i++){
		if(i==1)b1[++t1]=a[step],ans1[++cnt1]=1;
		else if(i==2)b2[++t2]=a[step],ans1[++cnt1]=1;
		else if(i==3)b3[++t3]=a[step],ans1[++cnt1]=1;
		if(b1[t1]==b1[t1-1])t1=t1-2;
		if(b2[t2]==b2[t2-1])t2=t2-2;
		if(b3[t3]==b3[t3-1])t3=t3-2;
		if(b1[end1]==b2[end2])end1++,end2++,ans2[++cnt2][0]=1,ans2[cnt2][0]=2;
		if(b3[end3]==b2[end2])end3++,end2++,ans2[++cnt2][0]=2,ans2[cnt2][0]=3;
		if(b1[end1]==b3[end3])end1++,end3++,ans2[++cnt2][0]=1,ans2[cnt2][0]=3;
		dfs(step++);
	}
}

int main(){
	freopen("meow.in","r",stdin);
	freopen("meow.out","w",stdout);
	T=read(),n=read(),m=read(),k=read();
	for(int i=1;i<=m;i++)a[i]=read();
	if(T%10==3){
		dfs(1);
	}
	return 0;
}
