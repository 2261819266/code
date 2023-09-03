#include <bits/stdc++.h>
using namespace std;
int read(){
	int x=0,w=1;
	char ch=getchar();
	while(ch<'0'||ch>'9'){
		if(ch=='-')w=-1;
		ch=getchar();
	}
	while(ch>='0'&&ch<='9'){
		x=(x<<3)+(x<<1)+(ch^48);
		ch=getchar();
	}
	return x*w;
}
int t,n,q;
int a[3010],b[3010];
int f1[3010][20],f2[3010][20],lg2[3010];
int st1(int l,int r){
	int s=lg2[r-l+1];
	return max(f1[l][s],f1[r-(1<<s)+1][s]);
}
int st2(int l,int r){
	int s=lg2[r-l+1];
	return max(f2[l][s],f2[r-(1<<s)+1][s]);
}
long long ans;
int main(){
	freopen("match.in","r",stdin);
	freopen("match.out","w",stdout);
	for(int i=2;i<=3010;i++){
		lg2[i]=lg2[i/2]+1;
	}t=read(),n=read();
	for(int i=1;i<=n;i++){
		f1[i][0]=read();
		f2[i][0]=read();
	}
	for(int j=1;j<=lg2[n]+1;j++){
		for(int i=1;i+(1<<j)-1<=n;i++){
			f1[i][j]=max(f1[i][j-1],f1[i+(1<<(j-1))][j-1]);
			f2[i][j]=max(f2[i][j-1],f2[i+(1<<(j-1))][j-1]);
		}
	}
	q=read();
	for(int i=1;i<=q;i++){
		ans=0;
		int l=read(),r=read();
		for(int l1=l;l1<=r;l1++){
			for(int r1=l1;r1<=r;r1++){
				long long ans1=ans;
				ans+=st1(l1,r1)*st1(l1,r1);
				if(ans1>ans)ans++;
			}
		}
		cout<<ans<<endl;
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
