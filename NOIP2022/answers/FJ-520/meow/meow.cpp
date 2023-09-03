#include<iostream>
#include<cstdio>
using namespace std;
int a[3000000];
int zhan[600][3];
int w[1000];
int que[100000];int n,m,k;int t;
int hh(){
	int u=0;
	int l=1,r=2*n-2;
		for(int i=l;i<=r;i++) que[i]=i;
		if(k==2*n-2||t==1001){
			for(int i=1;i<=m;i++){
				if(w[a[i]]!=0){
					if(w[a[i]]%2==0){
						u+=1;
						//printf("1 %d\n",((w[a[i]]+1)/2));
						que[++r]=w[a[i]];
						zhan[(que[r]+1)/2][que[r]%2]=0;
						w[a[i]]=0;
					}else{
						//printf("1 %d\n",n);
						//printf("2 %d %d\n",(w[a[i]]+1)/2,n);
						u+=2;
						w[a[i]]=0;
						que[++r]=w[a[i]]+1;
						w[zhan[(que[r]+1)/2][que[r]%2]]--;
						zhan[(que[r]+1)/2][que[r]%2]=0;
						
					}
			
				}else{
					u+=1;
					//printf("1 %d\n",(que[l]+1)/2);
					w[a[i]]=que[l];
					zhan[(que[l]+1)/2][que[l]%2];
					l++;
				}
			}
		}
	return u;
}
int main( ){
	freopen("meow.in","r",stdin);
	freopen("meow.out","w",stdout);
	
	cin>>t;
	for(int g=1;g<=t;g++){
		
		scanf("%d%d%d",&n,&m,&k);
		for(int i=1;i<=m;i++){
			scanf("%d",&a[i]);
		}
		printf("%d\n",hh());
		int l=1,r=2*n-2;
		for(int i=l;i<=r;i++) que[i]=i;
		if(k==2*n-2||t==1001){
			for(int i=1;i<=m;i++){
				if(w[a[i]]!=0){
					if(w[a[i]]%2==0){
						printf("1 %d\n",((w[a[i]]+1)/2));
						que[++r]=w[a[i]];
						zhan[(que[r]+1)/2][que[r]%2]=0;
						w[a[i]]=0;
					}else{
						printf("1 %d\n",n);
						printf("2 %d %d\n",(w[a[i]]+1)/2,n);
						w[a[i]]=0;
						que[++r]=w[a[i]]+1;
						w[zhan[(que[r]+1)/2][que[r]%2]]--;
						zhan[(que[r]+1)/2][que[r]%2]=0;
						
					}
			
				}else{
					printf("1 %d\n",(que[l]+1)/2);
					w[a[i]]=que[l];
					zhan[(que[l]+1)/2][que[l]%2];
					l++;
				}
			}
		}
	}
	return 0;
}
