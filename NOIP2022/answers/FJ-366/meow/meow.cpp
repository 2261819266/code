#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int N=2e6+10;
int n,m,k,cl,sv;
int a[N],p[N],fp[N];
bool vis[N];
int cnt;
struct pl{
	int op,s_1,s_2;
}ans[N];
//n n+1 ~ 2*n-2 
//1 2 3 ~ n-1  
void swpos(int x,int y){
//	printf("swpos  %d %d\n",x,y);
	swap(p[x],p[y]);
	swap(fp[p[x]],fp[p[y]]);
}
int main(){
	freopen("meow.in","r",stdin);
	freopen("meow.out","w",stdout);
	int T;scanf("%d",&T);
	while(T--){
		scanf("%d%d%d",&n,&m,&k);
		for(int i=1;i<=m;++i) scanf("%d",a+i);
		for(int i=1;i<=2*n;++i) p[i]=fp[i]=i;
		cl=n;sv=0;
		for(int i=1;i<=k;++i) vis[i]=0;
		cnt=0;
		for(int i=1;i<=m;++i){
//			printf("i    =     %d\n",i);
			if(p[a[i]]==cl){
				if(sv>=2*n-2) 
				{
					int ni=i;
//					printf("ni=%d\n",ni);
					i++;
					for(;i<=m;++i){
//						printf("p[a[i=%d]]=%d\n",i,p[a[i]]);
						if(p[a[i]]>=n) 
						{
							ans[i]=(pl){1,p[a[i]]-n,0};
							sv-=vis[a[i]];
							vis[a[i]]^=1;
							sv+=vis[a[i]];
						}
						else if(p[a[i]]==cl){
							ans[ni]=(pl){1,cl,0};
							ans[i]=(pl){1,cl,0};
							break;
						}
						else{
//							printf("a[%d]=%d\n",i,a[i]);
							if(vis[fp[p[a[i]]+n-1]]) 
							{
								ans[ni]=(pl){1,p[a[i]],0};
								ans[i]=(pl){2,cl,p[a[i]]};
								swpos(a[ni],a[i]);
								swpos(a[ni],fp[p[a[ni]]+n]);
							}
							else{
//								printf("%d %d %d\n",cl,p[a[ni]],p[a[i]]);
								ans[ni]=(pl){1,cl,0};
								ans[i]=(pl){1,p[a[i]],0};
								swap(cl,p[a[i]]);swap(p[a[i]],p[a[ni]]);
//								printf("%d %d %d\n",cl,p[a[ni]],p[a[i]]);
//								printf("%d\n",p[5]);
								fp[p[a[ni]]]=a[ni];
								fp[cl]=0;
							}
							break;
						}
					}
					continue;
				}
				else 
				{
					for(int j=1;j<=2*n;++j)
						if(fp[j]!=a[i]&&!vis[fp[j]]) {swpos(a[i],fp[j]);break;}
				}
			}
			if(p[a[i]]>n&&!vis[fp[p[a[i]]-n]])
				swpos(a[i],fp[p[a[i]]-n]);
			if(p[a[i]]>n) 
			{
//				printf("p[a[i]]=%d\n",p[a[i]]);
				ans[i]=(pl){1,p[a[i]]-n,0};
				sv-=vis[a[i]];
				vis[a[i]]^=1;
				sv+=vis[a[i]];
			}
			else 
			{
				if(vis[a[i]]){
					ans[i]=(pl){2,cl,p[a[i]]};
					swpos(a[i],fp[p[a[i]]+n]);
				}
				else{
					ans[i]=(pl){1,p[a[i]],0};
				}
				sv-=vis[a[i]];
				vis[a[i]]^=1;
				sv+=vis[a[i]];
			}
//			printf("p:  ");for(int j=1;j<=2*n;++j) printf("%d ",p[j]);puts("");
//			printf("fp: ");for(int j=1;j<=2*n;++j) printf("%d ",fp[j]);puts("");
		}
		int res=0;
		for(int i=1;i<=m;++i) res+=ans[i].op;
		printf("%d\n",res);
		for(int i=1;i<=m;++i)
		{
			printf("1 %d\n",ans[i].s_1);
			if(ans[i].op==2) printf("2 %d %d\n",ans[i].s_1,ans[i].s_2);
		}
	}
	return 0;
}
/*
1
3 10 5
1 2 3 4 5 3 4 1 5 2

*/
