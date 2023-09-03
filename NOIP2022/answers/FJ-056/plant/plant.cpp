#include<bits/stdc++.h>
const int mod = 998244353;
int n,m,c,f;
int ansc,ansf;
char s[1010];
struct node{
	int num,len,dep,ansc,ansf;
}a[1010][1010];
using namespace std;
int main(){
	freopen("plant.in","r",stdin);
	freopen("plant.out","w",stdout);
	int T,id;
	cin>>T>>id;
	while(T--){
		ansc=0,ansf=0;
		memset(a,0,sizeof(a));
		scanf("%d%d%d%d",&n,&m,&c,&f);
		for(int i=1;i<=n;i++){
			scanf("%s",&s);
			for(int j=1;j<=m;j++){
				a[i][j].num=s[j-1]-'0';
			}
		}
		if(c==0){
			cout<<"0 0"<<endl;
			continue;
		}
		for(int i=1;i<=n;i++){
			for(int j=m;j>=1;j--){
				if(a[i][j].num==1)  a[i][j].len=0;
				else a[i][j].len=a[i][j+1].len+1;
			}
		}
		for(int j=1;j<=m;j++){
			for(int i=n;i>=1;i--){
				if(a[i][j].num==1)  a[i][j].dep=0;
				else a[i][j].dep=a[i+1][j].dep+1;
			}
		}
		for(int i=n;i>=1;i--){
			for(int j=1;j<=m;j++){
				int t=0;
				if(a[i][j].len>=2&&a[i][j].dep>=3){
					for(int p=i+2;p<=i+a[i][j].dep-1;p++){
						if(a[p][j].len>=2) {
							t=p;break;
						}
					}
				}
				if(t){
					if(t<i+a[i][j].dep-1&&a[t+1][j].len>=2){
						a[i][j].ansc=((a[i][j].len-1)*(a[t][j].len+a[t+1][j].len-2)+a[t][j].ansc*(a[i][j].len-1)/(a[t][j].len-1))%mod;
						a[i][j].ansf=((a[i][j].len-1)*(a[t][j].len-1)*(a[t][j].dep-1)+(a[i][j].len-1)*(a[t+1][j].len-1)*(a[t+1][j].dep-1)+a[t][j].ansf*(a[i][j].len-1)/(a[t][j].len-1))%mod;
					}
					else{
						a[i][j].ansc=((a[i][j].len-1)*(a[t][j].len-1)+a[t][j].ansc*(a[i][j].len-1)/(a[t][j].len-1))%mod;
						a[i][j].ansf=((a[i][j].len-1)*(a[t][j].len-1)*(a[t][j].dep-1)+a[t][j].ansf*(a[i][j].len-1)/(a[t][j].len-1))%mod;
					}	
				}
				ansc=(ansc+a[i][j].ansc)%mod;
				ansf=(ansf+a[i][j].ansf)%mod;
			}
		}
		cout<<ansc*c<<" "<<ansf*f<<endl;
	}
	return 0;
} 
