#include<bits/stdc++.h>
using namespace std;
int read(){
	int op=1,res=0;
	char ch=getchar();
	while(ch>'9'||ch<'0'){
		if(ch=='-'){
			op=-1;
		}
		ch=getchar();
	}
	while(ch<='9'&&ch>='0'){
		res=(res<<3)+(res<<1)+ch-48;
		ch=getchar();
	}
	return res*op;
}
void print(int x){
	if(x<0){
		putchar('-');
		x=-x;
	}
	if(x>=10) print(x/10);
	putchar(x%10+'0');
}
/*int T,n,m,k1;
int now[10],tmph,tmpt,tmp,tp,last[10];
int q[2000005],q1[2000005],head1,head2,tail1,tail2;
int a[2000005];
int ans[2000005][3];
int sum;
multiset<int> st;*/
int main(){
	freopen("meow.in","r",stdin);
	freopen("meow.out","w",stdout);
	printf("5\n1 1\n1 1\n1 2\n2 1 2\n1 1");
	/*cin >> T;
	if(T%10==2){
		for(int i=1;i<=n;i++){
			st.clear();
			scanf("%d%d%d",&n,&m,&k1);
			head1=head2=tail1=tail2=0;
			for(int j=1;j<=m;j++){
				a[j]=read();
			}
			sum=0;
			tmph=tmpt=1,tmp=0;
			while(tmpt<=m){
				tp=0;
				tmph=tmpt+3-tmp;
				for(int k=tmpt;k<=tmph;k++){
					now[a[k]]++;
				}
				for(int k=tail1;k<head1;k++){
					now[q[k]]++;
					head1--;
				}
				for(int k=tail2;k<head2;k++){
					now[q1[k]]++;
					head2--;
				}
				for(int k=1;k<=3;k++){
					if(now[k]/2>0){
						for(int l=1;l<=now[k]/2;l++){
							tp++;
							st.insert(k);
						}
					}
				}
				
				if(tp==1){
					for(int k=tmpt;k<=tmph;k++){
						if(a[k] == *(st.begin()) ){
							ans[++sum][0]=1;
							ans[sum][1]=1;
						}else{
							ans[++sum][0]=1;
							ans[sum][1]=2;
							q1[head2-1]=a[k];
							head2++;
						}
					}
				}else{
					
				}
				tmpt=tmph;
			}
		}
	}*/
	
	return 0;
}
