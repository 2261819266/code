#include<bits/stdc++.h>
using namespace std;
int T,n,m,k;//n个栈，m张牌，k种图案 
int main(){
	freopen("meow.in","r",stdin);
	freopen("meow.out","w",stdout);
	scanf("%d",&T);
	while(T--){
		int u,mm;
		scanf("%d%d%d",&n,&m,&k);
		int a[m+1],o=0,an[2*n][4],s=0;
		mm=m;
		while(mm--){
			scanf("%d",&u);
			a[++o]=u;
		}
		int v[n+1][n];
		u=1;
		int f[n+1]; 
		for(int i=1;i<=n;i++){
			v[i][0]=0;f[i]=1;
		}
		while(m>0){
			int x=0,y=1000000;
			bool l=0;
			for(int i=1;i<=n;i++){
				if(v[i][0]-f[i]+1>0){
					int r=v[i][v[i][0]];
					if(a[u]==r){
						u++;
						m-=2;
						v[i][v[i][0]]=0;
						v[i][0]--;l=1;
						an[++s][1]=1;
						an[s][2]=i;//cout<<"I:"<<i<<" s:"<<s<<" ";
						break;
					}
				}
				if(v[i][0]-f[i]+1<=y){
					y=v[i][0]-f[i]+1;
					x=i;
				}
			}
			if(l)continue;
			for(int i=1;i<n;i++){
				for(int j=i+1;j<=n;j++){
					if(v[i][0]>=f[i]&&v[j][0]>=f[j]&&v[i][f[i]]==v[j][f[j]]){
					 	f[i]++,f[j]++;//cout<<"IJ"<<i<<j<<" "<<" s:"<<s<<" ";
					 	m-=2;
					 	an[++s][1]=2;
					 	an[s][2]=i;
					 	an[s][3]=j;l=1;
					}
				}
			}
			if(v[x][0]<f[x])
			for(int i=1;i<=n;i++){
				if(v[i][0]-f[i]>=0&&v[i][f[i]]==a[u]){
					u++;
					m-=2;l=1;
					an[++s][1]=1;
					an[s][2]=x;//cout<<"x:"<<x<<"i"<<i<<" "<<" s:"<<s<<" ";
					an[++s][1]=2;
					an[s][2]=min(x,i);
					an[s][3]=max(x,i);l=1;
				}
			}
			if(l)continue;//cout<<"M:"<<m<<"  U:"<<a[u]<<" "<<"C:"<<c<<" "<<"X:"<<x<<" ";
			v[x][++v[x][0]]=a[u];
			u++,
			an[++s][1]=1;
			an[s][2]=x;//cout<<"x"<<x<<" "<<" s:"<<s<<" ";
		}
		printf("%d\n",s);
		for(int i=1;i<=s;i++){
			printf("%d %d",an[i][1],an[i][2]);
			if(an[i][1]==2){
				printf(" %d",an[i][3]);
			}
			printf("\n");
		}
	}
	return 0;
}
