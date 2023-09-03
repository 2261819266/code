#include <bits/stdc++.h>
using namespace std;
string s[35];
int n,m,k,a[305][305],b[305],alen[305];
bool dfs(int,int);
bool f1(int p,int x,int sl){
	a[p][++alen[p]]=b[x];
	s[sl+1]={'1',' ',char(p+'0'),'\0'};
	if(alen[p]>=2 && a[p][alen[p]]==a[p][alen[p]-1]){
		alen[p]-=2;
		if(dfs(x+1,sl+1)) return 1;
		alen[p]+=2;
	}
	else if(dfs(x+1,sl+1)) return 1;
	--alen[p];
	return 0;
}
bool f2(int p1,int p2,int x,int sl){
	if(alen[p1]>=1 && alen[p2]>=1 && a[p1][1]==a[p2][1]){
		int t1=a[p1][1],t2=a[p2][1];
		s[sl+1]={'2',' ',char(p1+'0'),' ',char(p2+'0'),'\0'};
		for(int i=1;i<=alen[p1]-1;i++){
			a[p1][i]=a[p1][i+1];
		}
		for(int i=1;i<=alen[p2]-1;i++){
			a[p2][i]=a[p2][i+1];
		}
		alen[p1]--;
		alen[p2]--;
		if(dfs(x,sl+1)) return 1;
		for(int i=1;i<=alen[p1]-1;i++){
			a[p1][i+1]=a[p1][i];
		}
		a[p1][1]=t1;
		for(int i=1;i<=alen[p2]-1;i++){
			a[p2][i+1]=a[p2][i];
		}
		a[p1][2]=t2;
		alen[p1]++;
		alen[p2]++;
	}
	return 0;
}
bool dfs(int x,int sl){
	if(x==m+1){
//		cout << m << " " << x << " " << sl << endl;
//		for(int i=1;i<=sl;i++) cout << s[i] << endl;
//		cout << endl;
//		cout << 114514 << endl;
		if(alen[1]==0 && alen[2]==0 && alen[3]==0){
//			cout << 114514 << endl;
//			cout << sl << endl;
			for(int i=1;i<=sl;i++) cout << s[i] << endl;
			return 1;
		}
		else return 0;
	}
	//1 1
	if(f1(1,x,sl)) return 1;
	//1 2
	if(f1(2,x,sl)) return 1;
	//1 3
	if(f1(3,x,sl)) return 1;
	//2 1 2
	if(f2(1,2,x,sl)) return 1;
	//2 1 3
	if(f2(1,3,x,sl)) return 1;
	//2 2 3
	if(f2(2,3,x,sl)) return 1;
	return 0;
}
int main(){
	freopen("meow.in","r",stdin);
	freopen("meow.out","w",stdout);
	int t;
	scanf("%d",&t);
//	cout << pow(3.0,14.0)*14 << endl;
	if(t==1001){
		memset(a,0,sizeof(a));
		memset(alen,0,sizeof(alen));
		scanf("%d%d%d",&n,&m,&k);
		for(int i=1;i<=m;i++){
			int aaa;
			scanf("%d",&aaa);
//			cout << alen[aaa/2] << "---";
			if(alen[(aaa+1)/2]==0){
				a[(aaa+1)/2][0]=aaa;
				alen[(aaa+1)/2]++;
				cout << "1 " << (aaa+1)/2 << endl;
//				cout << "111" << endl;
			}
			else if(alen[(aaa+1)/2]==1){
				if(a[(aaa+1)/2][0]==aaa){
					alen[(aaa+1)/2]--;
					cout << "1 " << (aaa+1)/2 << endl;
//					cout << "222" << endl;
				}
				else{
					a[(aaa+1)/2][1]=aaa;
					alen[(aaa+1)/2]++;
					cout << "1 " << (aaa+1)/2 << endl;
//					cout << "333" << endl;
				}
			}
			else{
				if(a[aaa/2][1]==aaa){
					alen[(aaa+1)/2]--;
					cout << "1 " << (aaa+1)/2 << endl;
//					cout << "444" << endl;
				}
				else{
					a[(aaa+1)/2][0]=a[(aaa+1)/2][1];
					alen[(aaa+1)/2]--;
					cout << "1 " << n << endl << "2 " << (aaa+1)/2 << " " << n << endl;
//					cout << "555" << endl;
				}
			}
//			cout << "---" << alen[aaa/2] << endl;
		}
	}
	else if(t==3){
		memset(a,0,sizeof(a));
		memset(alen,0,sizeof(alen));
		scanf("%d%d%d",&n,&m,&k);
//		cout << n << m << k << endl;
		for(int i=1;i<=m;i++) scanf("%d",&b[i]);
		dfs(1,0);
//		cout << dfs(1,0) << endl;
	}
	return 0;
}
