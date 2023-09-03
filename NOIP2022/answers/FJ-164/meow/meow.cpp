#include<cstdio>
#include<iostream>
const int maxn=1e3+10;
const int maxm=2e6+10;
int read(){
	int sum=0,sg=1; char ch=getchar();
	while(ch<'0'||ch>'9'){if(ch=='-')sg=-1; ch=getchar();}
	while(ch>='0'&&ch<='9')sum=(sum<<1)+(sum<<3)+ch-'0',ch=getchar();
	return sum*sg;
}
int T,n,m,k,cnt,a[maxm],num[maxn],up[maxn],down[maxn];
struct Operation{int ty,a,b;}o[maxm<<1];
void solve1(){
	for(int i=1;i<=n;++i)num[i]=0;
	for(int i=1;i<=k;++i)up[i]=down[i]=0;
	cnt=0;
	for(int i=1;i<=m;++i){
		if(up[a[i]]!=0){
//			printf("1 %d\n",up[a[i]]);
			o[++cnt]={1,up[a[i]],0};
			--num[up[a[i]]],up[a[i]]=0;
		}
		else if(down[a[i]]!=0){
//			printf("1 %d\n",n);
			o[++cnt]={1,n,0};
//			printf("2 %d %d\n",down[a[i]],n);
			o[++cnt]={2,down[a[i]],n};
			--num[down[a[i]]],down[a[i]]=0;
		}
		else if(!num[(a[i]+1)/2]){
//			printf("1 %d\n",(a[i]+1)/2);
			o[++cnt]={1,(a[i]+1)/2,0};
			++num[(a[i]+1)/2],down[a[i]]=(a[i]+1)/2;
		}
		else if(num[(a[i]+1)/2]==1){
//			printf("1 %d\n",(a[i]+1)/2);
			o[++cnt]={1,(a[i]+1)/2,0};
			++num[(a[i]+1)/2],up[a[i]]=(a[i]+1)/2;
		}
	}
	printf("%d\n",cnt);
	for(int i=1;i<=cnt;++i){
		if(o[i].ty==1)printf("1 %d\n",o[i].a);
		else printf("2 %d %d\n",o[i].a,o[i].b);
	}
}
void solve2(){
	for(int i=1;i<=n;++i)num[i]=0;
	for(int i=1;i<=k;++i)up[i]=down[i]=0;
	cnt=0;
	int c=0,e=n;
	for(int i=1;i<=m;++i){
		if(up[a[i]]!=0){
//			printf("1 %d\n",up[a[i]]);
			o[++cnt]={1,up[a[i]],0};
			--num[up[a[i]]],up[a[i]]=0;
		}
		else if(down[a[i]]!=0){
//			printf("1 %d\n",n);
			o[++cnt]={1,n,0};
//			printf("2 %d %d\n",down[a[i]],n);
			o[++cnt]={2,down[a[i]],n};
			--num[down[a[i]]],down[a[i]]=0;
		}
		else if(!num[(a[i]+1)/2]){
//			printf("1 %d\n",(a[i]+1)/2);
			o[++cnt]={1,(a[i]+1)/2,0};
			++num[(a[i]+1)/2],down[a[i]]=(a[i]+1)/2;
		}
		else if(num[(a[i]+1)/2]==1){
//			printf("1 %d\n",(a[i]+1)/2);
			o[++cnt]={1,(a[i]+1)/2,0};
			++num[(a[i]+1)/2],up[a[i]]=(a[i]+1)/2;
		}
	}
	printf("%d\n",cnt);
	for(int i=1;i<=cnt;++i){
		if(o[i].ty==1)printf("1 %d\n",o[i].a);
		else printf("2 %d %d\n",o[i].a,o[i].b);
	}
}
int main(){
	freopen("meow.in","r",stdin);
	freopen("meow.out","w",stdout);
	T=read();
	while(T--){
		n=read(),m=read(),k=read();
		for(int i=1;i<=m;++i)a[i]=read();
		if(k==2*n-2)solve1();
		if(n==2&&k==3)solve2();
	}
	return 0;
}
