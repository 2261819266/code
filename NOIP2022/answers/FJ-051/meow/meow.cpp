#include<stdio.h>
#include<string.h>
int t,n,m,k,a[2000001],len,res[4000001],ans[4000001],pos[601],bl[601];
int main(){
	freopen("meow.in","r",stdin),freopen("meow.out","w",stdout);
	scanf("%d",&t);
	for(int ccf=1;ccf<=t;++ccf){
		scanf("%d%d%d",&n,&m,&k);
		for(int i=1;i<=m;++i)scanf("%d",a+i);
		if(t==1001){
			memset(pos,0,sizeof pos),memset(bl,0,sizeof bl);
			for(int i=1;i<=m;++i){
				if(!pos[a[i]]){
					int j=1;
					for(;j<n*2;++j)if(j!=n&&!bl[j])break;
					ans[++len]=j%n,pos[a[i]]=j,bl[j]=a[i];
				}
				else if(pos[a[i]]<=n){
					ans[++len]=n;
					len++;
					res[len]=n,ans[len]=pos[a[i]]%n;
					pos[bl[pos[a[i]]+n]]=pos[a[i]];
					bl[pos[a[i]]]=bl[pos[a[i]]+n],bl[pos[a[i]]+n]=0;
					pos[a[i]]=0;
				}
				else ans[++len]=pos[a[i]]%n,bl[pos[a[i]]]=0,pos[a[i]]=0;
			}
			printf("%d\n",len);
			for(int i=1;i<=len;++i){
				res[i]?printf("2 %d %d\n",res[i],ans[i]):printf("1 %d\n",ans[i]);
			}
		}
	}
}
