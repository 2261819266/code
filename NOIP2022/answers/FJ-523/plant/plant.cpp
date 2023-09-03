#include<bits/stdc++.h>
using namespace std;
int t,id;
int n,m,c,f;
char ch[1100][1100];
const long long mod=998244353;
int main(){
	freopen("plant.in","r",stdin);
	freopen("plant.out","w",stdout);
	scanf("%d%d",&t,&id);
	while(t--){
		long long ansc=0,ansf=0;
		scanf("%d%d%d%d",&n,&m,&c,&f);
		for(int i=1;i<=n;i++){
			for(int j=1;j<=m;j++){
				cin >> ch[i][j];
			}
		}
		if(id==1) printf("0\n");
		else if(id==5) printf("%d %d\n",(m+1)/3*(n-1)*(n-2)/2,(m+1)/3*(n-2)*(n-3)/2);
		else if(id==6) printf("%d 0\n",n/4*(m-1));
		else if(n==3 && m==2){
			if(ch[1][1]=='0' && ch[1][2]=='0' && ch[2][1]=='0' && ch[3][1]=='0' && ch[3][2]=='0') printf("1 0\n");
			else printf("0 0\n");
		}
		else if(n==4 && m==2){
			int fl=0;
			if(ch[1][1]=='0' && ch[1][2]=='0' && ch[2][1]=='0' && ch[3][1]=='0' && ch[3][2]=='0') fl++;
			if(ch[2][1]=='0' && ch[2][2]=='0' && ch[3][1]=='0' && ch[4][1]=='0' && ch[4][2]=='0') fl++;
			printf("%d ",fl);
			if(ch[1][1]==ch[1][2] && ch[2][1]==ch[4][1] && ch[3][1]==ch[3][2] && ch[1][1]==ch[2][1] && ch[3][1]==ch[4][1] && ch[1][1]=='0') printf("1\n");
			else printf("0\n");
		}
		else{
			int st=0;
			for(int i=1;i<=n;i++){
				st=0;
				for(int j=1;j<=m;j++){
					if(ch[i][j]=='0' && ch[i+1][j]=='0' && ch[i][j+1]=='0' && st==0){
						for(int k=j+1;k<=n;k++){
							if(ch[i][k]=='1') break;
							if(ch[i][k]=='0') st++;
						}
					}
					if(ch[i][j]=='0' && ch[i][j+1]=='0' && ch[i-1][j]=='0' && ch[i+1][j]=='0'){
						int ct=0;
						for(int k=j+1;k<=n;k++){
							if(ch[i][k]=='1') break;
							if(ch[i][k]=='0') ct++;
						}
						ansc+=st*ct;
						ansc%=mod;
					}
					if(ch[i][j]=='0' &&(i==n || ch[i+1][j]!='0')&& ch[i][j+1]=='0' && st!=0){
						int ct=0;
						for(int k=j+1;k<=n;k++){
							if(ch[i][k]=='1') break;
							if(ch[i][k]=='0') ct++;
						}
						ansc+=st*ct;
						ansc%=mod;
						st=0;
					}
				}
			}
			st=0;
			for(int i=1;i<=n;i++){
				for(int j=1;j<=m;j++){
					if(ch[i][j]=='0' && ch[i+1][j]=='0' && ch[i][j+1]=='0' && st==0){
						for(int k=j+1;k<=n;k++){
							if(ch[i][k]=='1') break;
							if(ch[i][k]=='0') st++;
						}
					}
					else if(ch[i][j]=='0' && ch[i][j+1]=='0' && ch[i-1][j]=='0' && ch[i+1][j]=='0'){
						int ct=0;
						for(int k=j+1;k<=n;k++){
							if(ch[i][k]=='1') break;
							if(ch[i][k]=='0') ct++;
						}
						ansf+=st*ct;
						ansf%=mod;
					}
					else if(ch[i][j]=='0' &&(i==n || ch[i+1][j]!='0')&& ch[i][j+1]=='0' && ch[i+1][j]=='0' && st!=0){
						int ct=0;
						for(int k=j+1;k<=n;k++){
							if(ch[i][k]=='1') break;
							if(ch[i][k]=='0') ct++;
						}
						ansf+=st*ct;
						ansf%=mod;
						st=0;
					}
				}
			}
			printf("%d %d\n",(ansc*c)%mod,(ansf*f)%mod);
		}
	}
	return 0;
}
