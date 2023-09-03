#include<bits/stdc++.h>
using namespace std;
int t,n,m,k,a[2000010],cnt,r,o;
map<int,int> x[305],ans[5];
int main(){
	freopen("meow.in","r",stdin);
	freopen("meow.out","w",stdout);
	scanf("%d",&t);
	for(int v=1;v<=t;v++){
		scanf("%d%d%d",&n,&m,&k);cnt=0;
		for(int i=1;i<=300;i++)x[i][1]=0,x[i][2]=0;
		for(int i=1;i<=m;i++)scanf("%d",&a[i]);
		if(t%10==1){
			for(int i=1;i<=m;i++){
				r=(a[i]+1)>>1;
				if(!x[r][1]){
					ans[1][++cnt]=1;ans[2][cnt]=r;
					x[r][1]=a[i];
				}
				else if(!x[r][2]){
					ans[1][++cnt]=1;ans[2][cnt]=r;
					if(x[r][1]!=a[i])x[r][2]=a[i];
					else x[r][1]=0;
				}
				else if(a[i]==x[r][2]){
					ans[1][++cnt]=1;ans[2][cnt]=r;
					x[r][2]=0;
				}
				else{
					ans[1][++cnt]=1;ans[2][cnt]=n;
					ans[1][++cnt]=2;ans[2][cnt]=r;ans[3][cnt]=n;
					x[r][1]=x[r][2];x[r][2]=0;
				}
			}
			printf("%d\n",cnt);
			for(int i=1;i<=cnt;i++){
				if(ans[1][i]==1)printf("%d %d\n",ans[1][i],ans[2][i]);
				else printf("%d %d %d\n",ans[1][i],ans[2][i],ans[3][i]);
			}
		}
		if(t%10==2){
			o=1;
			for(int i=1;i<=m;i++){
				if(!x[o][1]){
					ans[1][++cnt]=1;ans[2][cnt]=o;
					x[o][1]=a[i];
				}
				else if(!x[o][2]&&!x[3-o][1]){
					ans[1][++cnt]=1;ans[2][cnt]=o;
					x[o][2]=a[i];
				}
				else if(!x[3-o][1]){
					if(a[i]==x[o][2]){
						ans[1][++cnt]=1;ans[2][cnt]=o;
						x[o][2]=0;
					}
					else if(a[i]==x[o][1]){
						ans[1][++cnt]=1;ans[2][cnt]=3-o;
						ans[1][++cnt]=2;ans[2][cnt]=1;ans[3][cnt]=2;
						x[o][1]=x[o][2];x[o][2]=0;
					}
					else{
						if(a[i+1]==x[o][1]){
							ans[1][++cnt]=1;ans[2][cnt]=o;
							ans[1][++cnt]=1;ans[2][cnt]=3-o;
							ans[1][++cnt]=2;ans[2][cnt]=1;ans[3][cnt]=2;
							x[o][1]=x[o][2];x[o][2]=a[i];i++;
						}
						else if(a[i+1]==x[o][2]){
							ans[1][++cnt]=1;ans[2][cnt]=3-o;
							ans[1][++cnt]=1;ans[2][cnt]=o;
							x[o][2]=0;x[3-o][1]=a[i];i++;
						}
					}
				}
				else if(!x[o][2]){
					if(a[i]==x[3-o][1]){
						ans[1][++cnt]=1;ans[2][cnt]=3-o;
						x[3-o][1]=0;
					}
					else if(a[i]==x[o][2]){
						ans[1][++cnt]=1;ans[2][cnt]=o;
						x[o][1]=0;o=3-o;
					}
					else ans[1][++cnt]=1;ans[2][cnt]=o;
				}
				else{
					if(a[i]==x[o][2]){
						ans[1][++cnt]=1;ans[2][cnt]=o;
						x[o][2]=0;
					}
					else{
						ans[1][++cnt]=1;ans[2][cnt]=3-o;
						x[3-o][1]=0;
					}
				}
			}
			printf("%d\n",cnt);
			for(int i=1;i<=cnt;i++){
				if(ans[1][i]==1)printf("%d %d\n",ans[1][i],ans[2][i]);
				else printf("%d %d %d\n",ans[1][i],ans[2][i],ans[3][i]);
			}
		}
	}
	return 0;
}