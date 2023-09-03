#include<bits/stdc++.h>
using namespace std;
streambuf* inbuf;
int qr(){
	char ch=inbuf->sbumpc();
	int abs=0,sgn=1;
	while(ch>'9'||ch<'0'){
		if(ch=='-'){
			sgn=-sgn;
		}
		ch=inbuf->sbumpc();
	}
	while(ch<='9'&&ch>='0'){
		abs*=10;
		abs+=ch^48;
		ch=inbuf->sbumpc(); 
	}
	return sgn*abs; 
}
int main(){
	freopen("meow.in","r",stdin);
	freopen("meow.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	inbuf=cin.rdbuf();
	int T=qr();
	stack<int>s1;
	stack<int>s2;
	int input; 
	for(int i=0;i<T;i++){
		int n{qr()},m{qr()},k{qr()};
		if(n==2){
			cout<<m;
			for(int i=0;i<m;i++){
				input=qr();
				if(s1.size()==0){
					if(s2.size()==0){
						cout<<"1 1\n"; 
						s1.push(input);
					}else{
						if(s2.top()==input){
							s2.pop();
							cout<<"1 2\n";
						}else{
							s1.push(input);
							cout<<"1 1\n";
						}
					}
				}else{
					if(s2.size()==0){
						if(s1.top()==input){
							s1.pop();
							cout<<"1 1\n";
						}else{
							s2.push(input);
							cout<<"1 2\n";
						}
					}else{
						if(input==s2.top()){
							s2.pop();
							cout<<"1 2\n";
						}else if(input==s1.top()){
							s1.pop();
							cout<<"1 1\n"; 
						}else{
							int input1{qr()};
							i++;
							if(input1==input){
								cout<<"1 1\n1 1\n"; 
							}else if(input1==s1.top()){
								s2.push(input);
								s1.pop();
								cout<<"1 2\n1 1\n"; 
							}else{
								s1.push(input);
								s2.pop();
								cout<<"1 1\n1 2\n";
							}
						}
					}
				}
			}
		}
	}
	return 0;
}
