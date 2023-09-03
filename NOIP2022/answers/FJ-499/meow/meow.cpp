#include<bits/stdc++.h>
using namespace std;

int t,n,m,k;
struct card{
	int a,q=0,h=0,z;
	bool b=0;
}p[1000010];
struct zhan{
	int head=0,sum=0;
	int d[1010];
}zh[1010];

int main(){
	freopen("meow.in","r",stdin);
	freopen("meow.out","w",stdout);
	cin>>t;
	if(t%10==3){
		while(t--){
			cin>>n>>m>>k;
			int a[1010],op=0,cnt=0;//
			for(int i=1;i<=m;i++){
				cin>>p[i].a;
			}
			for(int i=1;i<=m;i++){
				p[i].q=0,p[i].h=0,p[i].z=0;
			}
			for(int i=1;i<=n;i++){
				zh[i].head=0,zh[i].sum=0;
			}
			for(int i=1;i<m;i++){
				for(int j=i+1;j<=m;j++){
					if(p[j].b==0&&p[j].a==p[i].a){
						p[i].h=j;
						p[j].q=i;
						p[j].b=1;
						break;
					}
				} 
			} 
			p[1].z=1;a[++cnt]=1;a[++cnt]=1;
			for(int i=2;i<=m;i++){
				if(p[i].q==0){
					for(int j=1;j<=n;j++){
						if(zh[j].sum==0){
							zh[j].head++;
							zh[j].d[zh[j].head]=p[i].a;
							zh[j].sum++;p[i].z=j;
							op++;
							a[++cnt]=1;a[++cnt]=j;
							break;
						}else{
							if(p[i].h<p[zh[j].d[zh[j].head]].h){
								zh[j].head++;
								zh[j].d[zh[j].head]=p[i].a;
								zh[j].sum++;p[i].z=j;
								op++;
								a[++cnt]=1;a[++cnt]=j;
								break;
							}
						}
					} 
				}else{
					int x=p[p[i].q].z;
					int y=zh[x].head;
					if(zh[x].d[y]==p[p[i].q].a){
						a[++cnt]=1;a[++cnt]=x;op++;
						zh[x].d[y]=0;
						zh[x].head--;zh[x].sum--;
						break;
					}else{
						for(int j=1;j<=n;j++){
							if(zh[j].sum==0){
								p[i].z=j;
								op++;
								a[++cnt]=1;a[++cnt]=j;
								a[++cnt]=2;a[++cnt]=p[p[i].q].z;a[++cnt]=p[i].z;
								for(int r=1;r<zh[p[p[i].q].z].sum;r++){
									zh[p[p[i].q].z].d[r]=zh[p[p[i].q].z].d[r+1];
								}
								int summ=zh[p[p[i].q].z].sum;
								zh[p[p[i].q].z].d[summ]=0;
								zh[p[p[i].q].z].head--;
								zh[p[p[i].q].z].sum--;
								break;
							}
						} 
					}
				}
			} 
			cout<<op<<endl;
			for(int i=1;i<=cnt;i++){
				if(a[i]==1){
					cout<<a[i]<<" "<<a[i+1]<<endl;
					i+=2;
				}else if(a[i]==2){
					cout<<a[i]<<" "<<a[i+1]<<" "<<a[i+2]<<endl;
					i+=3;
				}
			} 
		}
	}
	return 0;
} 
