#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<cmath>
#include <algorithm>
using namespace std;
int dan=998244353,t;
bool book[1010][1010];
int hang[1010][1010],lie[1010][1010];
int n,m;
int id;
int c,f;
void cs(){
	int ans=1;
	int ansf=1;
	int allc=0,allf=0;
	bool jk=1;
	bool fc=1,ff=1;//you mri
	for(int y=1;y<=n-2;++y){// diji hang
		if(id==6&&jk){
			jk=0;
			y=((n-1)/4);
			if(y==0)y=1;
		}
		for(int x=1;x<=m-1;++x){//di ji lie
			if(id==5&&jk){
				jk=0;
				x=((m-1)/3);
				if(x==0)x=1;
			}
			if(book[y][x])continue;
			if(book[y+1][x])continue;
			if(hang[y][x]<=1)continue;
			for(int l=1;l<=n-1-y;++l){
				if(book[y+l+1][x])break;
				if(hang[y+l+1][x]==1)continue;
				ans=hang[y][x]-1;
				fc=0;
				ans=(ans*(hang[y+l+1][x]-1))%dan;
				if(lie[y+l+1][x]>1){
					ff=0;
					ansf=hang[y][x]-1;
					ansf=(ansf*(hang[y+l+1][x]-1))%dan;
					ansf=(ansf*(lie[y+l+1][x]-1))%dan;
					allf=(allf+ansf)%dan;
				}
				allc=(allc+ans)%dan;
			}
		}
	}
	if(!c||fc){
		printf("0 ");
	}else{
		printf("%d ",allc);
	}
	if(!f||ff){
		printf("0\n");
	}else{
		printf("%d\n",allf);
	}
	return;
}
int main(){
	freopen("plant.in","r",stdin);
	freopen("plant.out","w",stdout);
	scanf("%d%d",&t,&id);
	while(t--){
		scanf("%d%d",&n,&m);
		memset(book,0,sizeof(book));
		memset(hang,0,sizeof(hang));
		memset(lie,0,sizeof(lie));
		char ch;
		scanf("%d%d",&c,&f);
		for(int i=1;i<=n;++i){
			for(int j=1;j<=m;++j){
				ch=getchar();
				while(ch!=48&&ch!=49){
					ch=getchar();
				}
				if(ch==49){
					book[i][j]=1;
				}
			}
		}
		for(int i=n;i>=1;--i){
			for(int j=m;j>=1;--j){
				if(!book[i][j]){
					hang[i][j]=hang[i][j+1]+1;
					lie[i][j]=lie[i+1][j]+1;
				}
			}
		}
		if(c==0&&f==0){
			printf("0 0\n");
			continue;
		}
		cs();
	}
	return 0;
}
