#include<bits/stdc++.h>
using namespace std;
int n,m,k,the_test,a;
struct fafa{
	int sta[20020],t,u,len;
	fafa(){len=0;}
}s[320];
int main(){
	freopen("meow.in","r",stdin);
	freopen("meow.out","w",stdout);
	scanf("%d",&the_test);
	while(the_test--){
		scanf("%d%d%d",&n,&m,&k);
		for(int i=1;i<=m;i++){
			scanf("%d",&a);
			int po=a>=n?a-n+1:a;
		//	cout<<a<<"@@@@@@@@@"<<po<<endl;
			if(s[po].len==0){
				s[po].len++;
				s[po].t=s[po].u=a;
			}else{
//				cout<<s[po].t<<"&&";
				if(s[po].t==a){
					printf("1 %d\n",po);
					s[po].len--;
					s[po].t=s[po].u;
				}else if(s[po].len==1){
					s[po].len++;
					s[po].t=a;
				}else{
					printf("1 %d\n2 %d %d\n",n,po,n);
					s[po].len--;
					s[po].u=s[po].t;
				}
			}
		}
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
