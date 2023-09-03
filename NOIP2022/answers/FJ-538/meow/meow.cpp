#include<bits/stdc++.h>
using namespace std;
const int N=2e6+5;
int T,n,m,k;
int a[N],s[N][2];
struct Node{
	int op,_1,_2;
	void print(){
		if(op==1)	printf("1 %d\n",_1);
		else	printf("2 %d %d\n",_1,_2);
	}
};
int anstot;
Node ans[N*2];
void One(){
	cin>>n>>m>>k;
	for(int i=1;i<=m;i++)	scanf("%d",&a[i]);
	memset(s,-1,sizeof s);
	anstot=0;
	for(int i=1;i<=m;i++){
		int c=a[i],t=(c<=n-1?c:c-(n-1));
		if(s[t][0]==-1){
			ans[++anstot]={1,t,0};
			s[t][0]=c;
		}
		else if(s[t][1]==-1){
			if(s[t][0]==c){
				ans[++anstot]={1,t,0};
				s[t][0]=-1;
			}
			else{
				ans[++anstot]={1,t,0};
				s[t][1]=c;
			}
		}
		else{
			if(s[t][1]==c){
				ans[++anstot]={1,t,0};
				s[t][1]=-1;
			}
			else{
				ans[++anstot]={1,n,0};
				ans[++anstot]={2,t,n};
				s[t][0]=s[t][1],s[t][1]=-1;
			}
		}
	}
	printf("%d\n",anstot);
	for(int i=1;i<=anstot;i++)	ans[i].print();
}
int main(){
	freopen("meow.in","r",stdin);
	freopen("meow.out","w",stdout);
	cin>>T;
	if(T%10==1)	while(T--)	One();
	return 0;
}
