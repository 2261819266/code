#include<iostream>
#include<cstdio>
using namespace std;

const int mod=998244353;
int T,id,n,m,cc,ff;
char a[1003][1003];
int f[1003][1003];
int C=0,F=0;

int main(){
	freopen("plant.in","r",stdin);
	freopen("plant.out","w",stdout);
	scanf("%d%d",&T,&id);
	for(int o=1;o<=T;o++){
		C=0,F=0;
		scanf("%d%d%d%d",&n,&m,&cc,&ff);
		
		if(cc==0&&ff==0){
			printf("0 0\n");
			continue;
		}
		
		for(int i=1;i<=n;i++){
			scanf("%s",a[i]+1);
		}
		for(int i=1;i<=n;i++){
			f[i][m+1]=0;
		}
		for(int i=1;i<=n;i++){
			for(int j=m;j>=1;j--){
				if(a[i][j]=='0'){
					f[i][j]=f[i][j+1]+1;
				}
				else{
					f[i][j]=0;
				}
			}
		}
		
		
		/*
		int flag1=1;
		
		for(int i=1;i<=n;i++){
			if(i%4==0){
				if(c[i]!=m){
					flag1=0;
					break;
				}
			}
			else{
				if(c[i]!=0){
					flag1=0;
					break;
				}
			}
		}
		
		
		if(flag1){
			int e1=(m-1)*(m-1)%mod;
			if(n%4==0||n%4==3){
				printf("%d 0\n",e1*((n+1)/4)%mod);
			}
			else{
				printf("%d 0\n",e1*(n/4)%mod);
			}
			continue;
		}
		*/
		/*
		if(ff==0){
			for(int j=1;j<=m;j++){
				int len=0,clast=0;
				for(int i=1;i<=n;i++){
					if(a[i][j]=='0'){
						len++;
						if(len==1){
							clast=f[i][j]-1;
						}
					}
					else{
						len=0;
						clast=0;
					}
					
					//printf("%d %d %d\n",i,j,len);
					
					if(len>=3){
						C+=(clast*(f[i][j]-1))%mod;
						//printf("%d %d %d C %d\n",i,j,k,(a1*(f[i][j]-1))%mod);
						C%=mod;
						clast+=(f[i][j]-1);
					}
				}
				
				
			}
		}
		else{*/
			for(int j=1;j<=m;j++){
				for(int k=1;k<=n;k++){
					if(a[k][j]=='0'){
						int len=0,a1=f[k][j]-1,ft=0,fx=0;
						for(int i=k;i<=n;i++){
							if(a[i][j]=='0'){
								len++;
							}
							else{
								break;
							}
							
							//printf("%d %d %d\n",i,j,len);
							
							if(len>=3){
								C+=(a1*(f[i][j]-1))%mod;
								//printf("%d %d %d C %d\n",i,j,k,(a1*(f[i][j]-1))%mod);
								C%=mod;
							}
							
							if(len>=4){
								int e=f[i-1][j]-1;
								//if(e<a1)ft=ft*2%mod+(a1*(a1-1)/2%mod+mod-(a1-e)*(a1-e-1)/2%mod)%mod;
								//else ft=ft*2%mod+(a1*(a1-1)%mod/2%mod)%mod;
								
								ft+=fx%mod+(a1*e)%mod;
								ft%=mod;
								
								fx+=(a1*e)%mod;
								fx%=mod; 
								
								
								//printf("%d %d %d F %d\n",i,j,k,ft);
							}
						}
						F+=ft;
						F%=mod;
					}
				}
			}
		//}
		
		
		printf("%d %d\n",cc*C%mod,ff*F%mod);
	}
	
	
	
	return 0;
} 
