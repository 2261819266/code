#include<bits/stdc++.h>
using namespace std;
typedef long long LL;
const int N=1e4+10;
int T;
long long to[N],n,m,k,cd[N],q1[N],q2[N],h1=1,h2=1,t1=0,t2=0;
void tepan(){
	int zs=0;
	int i=1;
	while(1){
		zs++;
		if(cd[i]==q1[t1]){
			i++;
			t1--;
		}else
		if(cd[i]==q1[h1]){
			h1++;
			i++;
			zs++;
		} 
		else{
			q1[++t1]=cd[i];
			i++;
			//zs++;
		}
		if(i>m&&h1>h2)break;
	}
	//cout<<"u";
	printf("%d\n",zs);
	i=1;memset(q1,0,sizeof(q1));
	h1=1;t1=0;
	while(1){
		zs++;
		if(cd[i]==q1[t1]){
			printf("1 1\n");
			i++;
			t1--;
		}else
		if(cd[i]==q1[h1]){
			printf("1 2\n");
			printf("2 1 2\n");
			h1++;
			i++;
			zs++;
		} 
		else{
			printf("1 1\n");
			q1[++t1]=cd[i];
			i++;
			
		}
		if(i>m&&h1>h2)break;
	}
}
int main(){
	
	freopen("meow.in","r",stdin);
	freopen("meow.out","w",stdout);
	
	scanf("%d",&T);
	while(T--){
		scanf("%d%d%d",&n,&m,&k);//n∏ˆ’ª m’≈≈∆ k¿‡ 
		for(int i=1;i<=m;i++){
			scanf("%d",&cd[i]);
			to[cd[i]]++;
		}
		if(n==2||n==3){
			tepan();
			continue;
		} 
	
	} 
	
	return 0;
}
