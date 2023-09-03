#include<bits/stdc++.h>
using namespace std;
int t;
int main(){
	freopen("meow.in","r",stdin);
	freopen("meow.out","w",stdout);
	scanf("%d",&t);
	for(int i=1;i<=t;i++){
		int n,m,k,x,y,op=0,a[100010],ans[100010][3];
		stack<int>s1,s2;
		scanf("%d%d%d",&n,&m,&k);
		for(int j=1;j<=m;j++)
			cin>>a[i];
		y=a[1];
		s1.push(y);
		ans[++op][0]=1;
		ans[op][1]=1;
		for(int j=2;j<=m;j++){
			x=y,y=a[i];
			if(x==s1.top()){
				s1.pop();
				ans[++op][0]=1;
				ans[op][1]=1;
			}
			else
			if(x==s2.top()){
				s2.pop();
				ans[++op][0]=1;
				ans[op][1]=2;
			}
			else
			if(y==s1.top()){
				s2.push(x);
				ans[++op][0]=1;
				ans[op][1]=2;
			}
			else
			if(y==s2.top()){
				s1.push(x);
				ans[++op][0]=1;
				ans[op][1]=1;
			}
			else{
				s1.push(x);
				ans[++op][0]=1;
				ans[op][1]=1;
			}
		}
		printf("%d\n",op);
		for(int j=1;j<=op;j++)
			printf("%d %d\n",ans[i][0],ans[i][1]);
	}
}



