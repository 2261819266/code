#include<bits/stdc++.h>
using namespace std;
int T,id;
int n,m,c,f;
char a[1005][1005];
int ansc,ansf;
int num[1005][1005];
void mod(){ansc%=998244353;ansf%=998244353;}
int main(){
	freopen("plant.in","r",stdin);
	freopen("plant.out","w",stdout);
	scanf("%d %d",&T,&id);
	while(T--){
		ansc=0;ansf=0;
		scanf("%d %d %d %d",&n,&m,&c,&f);
		for(int i=0;i<n;i++){
			scanf("%s",&a[i]);
		}
		if(c==0&&f==0){printf("0 0\n");continue;}
		for(int i=0;i<n;i++){
			a[i][m]=1;
			for(int j=m-1;j>=0;j--){
				a[i][j]-='0';
				if(!a[i][j+1]&&!a[i][j])num[i][j]=num[i][j+1]+1;
				else num[i][j]=0;
			}
		}/*
		for(int i=0;i<n;i++){
			for(int j=0;j<m;j++){
				cout<<num[i][j]<<" ";
			}cout<<endl;
		}*/
		int l,r;bool flag=0;
		for(int j=0;j<m-1;j++){
			flag=0;
			for(int i=0;i<n;i++){
				if(flag==0&&a[i][j]==0){l=i;flag=1;}
				if(flag==1&&a[i][j]==1||flag==1&&i==n-1){
					
					if(a[i][j]==1)r=i-1;
					else r=i;
					flag=0;
					if(r-l>=2){
					//cout<<j<<" "<<l<<"!!!"<<r<<endl;
							//	cout<<"@";
						for(int k=l;k<=r-2;k++){
							if(!num[k][j])continue;
							for(int k1=k+2;k1<=r;k1++){
								if(c){ansc+=num[k][j]*num[k1][j];/*cout<<num[k][j]<<"&"<<num[k1][j]<<endl;*/}
								if(f)ansf+=num[k][j]*num[k1][j]*(r-k1);
								mod();
							}
						}
					}
				}
			}
		}
		mod();
		printf("%d %d",ansc,ansf);
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
