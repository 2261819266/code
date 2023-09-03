#include<iostream>
#include<cstring>
using namespace std;
int main(){
	freopen("meow.in","r",stdin);
	freopen("meow.out","w",stdout);
	int T;
	scanf("%d",&T);
	while(T--){
		int n,m,k,op=0,cnt=0,t,cnt2=1;
		scanf("%d%d%d",&n,&m,&k);
		int a[m+1];
		string ans[2*m+1];
		memset(a,0,sizeof a);
		for(int i=1;i<=m;i++) scanf("%d",&a[i]);
		t=-114514;
		for(int i=1;i<=m;i++){
			if(a[i]!=t){
				t=a[i];
				ans[++cnt]="1 ";
				ans[cnt]+=(cnt2+'0');
				cnt2++;
				if(cnt2>n) cnt2=1;
				op++;
			}
			else{
				ans[++cnt]="1 ";
				if(cnt2==1) ans[cnt]+=(n+'0');
				else ans[cnt]+=(cnt2-1+'0');
				op++;
			}
		}
		printf("%d\n",op);
		for(int i=1;i<=cnt;i++) cout<<ans[i]<<"\n";
	}
	return 0;
}

