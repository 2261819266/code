#include<bits/stdc++.h>
using namespace std;
const int M=1000010,N=1010;
int ans[2*M][2],tot,s[2*M];
int a[M],f[N],d[N][2],lst[N];
int t,n,k,m;
queue<int> emp,e;

void h1(){
	emp=e;
	tot=0;
	for(int i=1;i<=n-1;i++){
		emp.push(i);
		emp.push(i);
	}
	for(int i=1;i<=m;i++){
		if(f[a[i]]==0){
			int u=emp.front();
			emp.pop();
			if(d[u][0]==0) d[u][0]=i;
			else d[u][1]=i;
			f[i]=u;
			ans[++tot][0]=u;
			s[tot]=1;
		}
		else{
			if(d[f[a[i]]][0]==a[i]){
				ans[++tot][0]=n,s[tot]=1;
				ans[++tot][0]=f[a[i]],ans[tot][1]=n,s[tot]=2;
				
				if(d[f[a[i]]][1]!=0) d[f[a[i]]][0]=d[f[a[i]]][1],d[f[a[i]]][1]=0;
				emp.push(f[a[i]]);
				f[a[i]]=0;
			}
			else{
				ans[++tot][0]=f[a[i]],s[tot]=1;
				d[f[a[i]]][1]=0;
				emp.push(f[a[i]]);
				f[a[i]]=0;
			}
		}
	}
	return ;
}

void h2(){
	tot=0;
	for(int i=1;i<=m;i++){
		if(f[a[i]]==0){
			if(d[1][0]==0){
				ans[++tot][0]=1,s[tot]=1;
				d[1][0]=a[i];
				lst[a[i]]=tot;
				f[a[i]]=1;
			}
			else if(d[2][0]==0){
				ans[++tot][0]=2,s[tot]=1;
				d[2][0]=a[i];
				lst[a[i]]=tot;
				f[a[i]]=2;
			}
			else{
				ans[++tot][0]=1,s[tot]=1;
				d[1][1]=a[i];
				lst[a[i]]=tot;
				f[a[i]]=1;
			}
		}
		else{
//			cout<<lst[d[f[a[i]]][1]]<<" "<<lst[d[f[a[i]]%2+1][1]]<<" "<<d[f[a[i]]][1]<<" "<<d[f[a[i]]%2+1][0]<<" "<<a[i]<<endl<<endl;
			if(d[f[a[i]]][0]==a[i]){
				if(d[f[a[i]]][1]==0){
					ans[++tot][0]=f[a[i]],s[tot]=1;
					d[f[a[i]]][0]=0;
//					cout<<1<<endl;
				}
				else if(d[f[a[i]]%2+1][0]==0){
					ans[++tot][0]=f[a[i]]%2+1,s[tot]=1;
					ans[++tot][0]=f[a[i]]%2+1,ans[tot][1]=f[a[i]],s[tot]=2;
					d[f[a[i]]][0]=d[f[a[i]]][1];
					d[f[a[i]]][1]=0;
//					cout<<2<<endl;
				}
				else if(lst[d[f[a[i]]][1]]<lst[d[f[a[i]]%2+1][0]]){
					ans[lst[d[f[a[i]]%2+1][0]]][0]=f[a[i]];
					ans[++tot][0]=f[a[i]]%2+1,s[tot]=1;
					ans[++tot][0]=f[a[i]]%2+1,ans[tot][1]=f[a[i]],s[tot]=2;
					d[f[a[i]]][0]=d[f[a[i]]][1];
					d[f[a[i]]][1]=d[f[a[i]]%2+1][0];
//					cout<<3<<endl;
				}
				else{
					ans[lst[d[f[a[i]]][1]]][0]=f[a[i]]%2+1;
					ans[++tot][0]=f[a[i]],s[tot]=1;
					d[f[a[i]]][0]=0;
					d[f[a[i]]%2+1][1]=d[f[a[i]]][1];
					d[f[a[i]]][1]=0;
//					cout<<4<<endl;
				}
			}
			else{
				ans[++tot][0]=f[a[i]],s[tot]=1;
				d[f[a[i]]][1]=0;
			}
			f[a[i]]=0;
		}
		
//		for(int j=1;j<=2;j++){
//			for(int k=0;k<=1;k++){
//				cout<<d[j][k]<<" ";
//			}
//			cout<<endl;
//		}
//		cout<<i<<endl;			
	}
}		

int main(){
	freopen("meow.in","r",stdin);
	freopen("meow.out","w",stdout);
	scanf("%d",&t);
	int h=t;
	while(h--){
		scanf("%d%d%d",&n,&m,&k);
		for(int i=1;i<=m;i++){
			scanf("%d",&a[i]);
		}
		if(t%1000==2){
			h2();
		}
		else{
			h1();
		}
		printf("%d\n",tot);
		for(int i=1;i<=tot;i++){
			printf("%d ",s[i]);
			if(s[i]==1) printf("%d\n",ans[i][0]);
			else printf("%d %d\n",ans[i][0],ans[i][1]);
		}
	}
	return 0;
}
/*
2
2 6 3
1 2 3 1 2 3
*/
