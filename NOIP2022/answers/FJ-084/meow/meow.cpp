#include<bits/stdc++.h>
#define ll long long 
#define N 610
#define M 2000100 
#define GC getchar()
using namespace std;
ll re(){
	ll s=0,b=1; char c=GC;
	while(c>'9'||c<'0'){if(c=='-')b=-b; c=GC;}
	while(c<='9'&&c>='0'){s=(s<<1)+(s<<3)+(c^48); c=GC;}
	return s*b;
}
void ks(ll s){
	if(s<0){s=-s; putchar('-');} 
	if(s>=10)ks(s/10); 
	putchar((s%10)|48);
}
int T,n,m,k,a[M],kz[N],kzgs,kyd[N],kydgs,vi[N],zh[N][2],x,y,zbj[N],S1,S2;
int an[M<<1][4],ans;
void sc(int x,int y,int z){
	ans++; an[ans][0]=x,an[ans][1]=y; an[ans][2]=z;
} 
int main(){
	freopen("meow.in","r",stdin);
	freopen("meow.out","w",stdout);
	T=re();
	while(T--){
		n=re(),m=re(),k=re();
		for(int i=1; i<=m; i++)a[i]=re();
		for(int i=1; i<=n; i++)kz[i]=i;
		for(int i=1; i<=k; i++)vi[i]=0;
		kydgs=0; kzgs=n; S1=n; S2=0; ans=0;
		for(int i=1; i<=m; i++){
			x=a[i];
			if(vi[x]==0){
				while(zbj[kyd[kydgs]]!=1&&kydgs)kydgs--;
				if(S2){
					y=kyd[kydgs--]; sc(1,y,0);
					zh[y][1]=x; zbj[y]=2; S2--; vi[x]=-y; 
				} else{
					while(zbj[kz[kzgs]]!=0)kzgs--;
					if(S1>1){
						y=kz[kzgs--]; sc(1,y,0);
						zh[y][0]=x; zbj[y]=1; S1--; S2++;
						kyd[++kydgs]=y; vi[x]=y; 
					} else{
						for(int j=i+1; j<=m; j++){
							if(vi[a[j]]>=0){
								if(vi[a[j]]==0){
									sc(1,kz[1],0);
									for(i=i+1; i<j; i++){
										if(!vi[a[i]]){
											while(zbj[kyd[kydgs]]!=1)kydgs--;
											y=kyd[kydgs--]; sc(1,y,0);
											zh[y][1]=a[i]; zbj[y]=2; S2--; vi[a[i]]=-y; 
										} else{
											y=-vi[a[i]]; sc(1,y,0);
											zh[y][1]=0; zbj[y]=1; S2++; vi[a[i]]=0; 
										} 
									} sc(1,kz[1],0);
								} else{
									int mb=zh[vi[a[j]]][1],s=0;
									for(int k=i+1; k<j; k++) if(a[k]==mb)s^=1;
									if(s){
										sc(1,kz[1],0);
										for(i=i+1; i<j; i++){
											if(a[i]==mb){sc(1,-vi[a[i]],0); continue;}
											if(!vi[a[i]]){
												while(zbj[kyd[kydgs]]!=1)kydgs--;
												y=kyd[kydgs--]; sc(1,y,0);
												zh[y][1]=a[i]; zbj[y]=2; S2--; vi[a[i]]=-y; 
											} else{
												y=-vi[a[i]]; sc(1,y,0);
												zh[y][1]=0; zbj[y]=1; S2++; vi[a[i]]=0; 
											} 
										}
										zbj[vi[a[j]]]=1; S2++; zh[vi[a[j]]][1]=0;
										sc(1,vi[a[j]],0); zbj[kz[1]]=1; kyd[++kydgs]=kz[1];  
										zh[kz[1]][0]=a[i]; vi[x]=kz[1]; kz[1]=vi[a[j]];
										zh[vi[a[j]]][0]=0;
										zbj[vi[a[j]]]=0; vi[a[j]]=0;
									} else{
										sc(1,vi[a[j]],0);
										for(i=i+1; i<j; i++){
											if(a[i]==mb){sc(1,kz[1],0); continue;}
											if(!vi[a[i]]){
												while(zbj[kyd[kydgs]]!=1)kydgs--;
												y=kyd[kydgs--]; sc(1,y,0);
												zh[y][1]=a[i]; zbj[y]=2; S2--; vi[a[i]]=-y; 
											} else{
												y=-vi[a[i]]; sc(1,y,0);
												zh[y][1]=0; zbj[y]=1; S2++; vi[a[i]]=0; 
											} 
										}
										sc(1,kz[1],0);
										int s1=kz[1],s2=vi[a[j]]; if(s1>s2)swap(s1,s2);
										sc(2,s1,s2);
										s1=zh[vi[a[j]]][1],s2=x;
										zh[vi[a[j]]][0]=s1; zh[vi[a[j]]][1]=s2;
										vi[s1]=-vi[s1]; vi[s2]=-vi[s1]; vi[a[j]]=0;
									}
								}
								break;
							}
						}
					}
				}
			} else{
				if(vi[x]>0){
					while(zbj[kz[kzgs]]!=0)kzgs--; 
					sc(1,kz[kzgs],0);
					sc(2,min(vi[x],kz[kzgs]),max(vi[x],kz[kzgs]));
					if(!zh[vi[x]][1]){
						zh[vi[x]][0]=0;
						kz[++kzgs]=vi[x]; zbj[vi[x]]=0; S1++; S2--;
						vi[x]=0; 
					} else{
						zh[vi[x]][0]=zh[vi[x]][1]; zh[vi[x]][1]=0;
						kyd[++kydgs]=vi[x]; zbj[vi[x]]=1; S2++;
						vi[zh[vi[x]][0]]*=-1; vi[x]=0;
					}
				} else{
					sc(1,-vi[x],0); zh[-vi[x]][1]=0;
					kyd[++kydgs]=-vi[x]; zbj[-vi[x]]=1;  S2++;
					vi[x]=0;
				}
			}
		}
		ks(ans),putchar('\n');
		for(int i=1; i<=ans; i++){
			for(int j=0; j<=3; j++){
				if(an[i][j]==0){putchar('\n'); break;}
				if(j)putchar(' '); ks(an[i][j]); 
			} 
		}
	}
}
