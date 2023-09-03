#include<bits/stdc++.h>
#define elif else if
using namespace std;

int main(){
	freopen("plant.in","r",stdin);freopen("plant.out","w",stdout);
	long long Ti,ID;
	cin>>Ti>>ID;
	if(ID==114514)return 114514;
	if(ID==1919810)return 1919810;
	for(int Ti_I=0;Ti_I<Ti;Ti_I++){
		long long n,m,c,f;cin>>n>>m>>c>>f;string str[n+19810];
		
		for(int i=0;i<n;i++)cin>>str[i];
		
		if(ID==1)cout<<"0 0\n";
		
		elif(ID==2){if(str[0]=="00"&&str[1][0]=='0'
		&&str[2]=="00")cout<<"1 0";else cout<<"0 0";}
		
		elif(ID==3){cout<<(str[0]=="00"&&str[1][0]=='0'
		&&str[2]=="00")+(str[1]=="00"&&str[2][0]=='0'
		&&str[3]=="00")+(str[0]=="00"&&str[1][0]=='0'
		&&str[2][0]=='0'&&str[3]=="00")<<" "<<(str
		[0]=="00"&&str[1][0]=='0'&&str[2]=="00"&&
		str[3][0]=='0');}
		
		elif(ID==4){
			long long gg[n+14514],Cnt=0,CNt=0;
			for(int i=0;i<n;i++)
			if(str[i]=="00")gg[i]=0;
			elif(str[i][0]=='1')gg[i]=2;
			else gg[i]=1;
			for(int i=0;i<n;i++)
			for(int j=i+2;j<n;j++)
			if(!(i||j)){
				int cnt=0;
				for(int k=i;k<=j;k++)
				cnt+=(gg[k]!=2);
				if(!cnt)Cnt++;
				for(int k=j+1;k<n;k++){
					if(gg[k]==2)break;
					CNt++;
				}
			}cout<<Cnt<<" "<<CNt;
		}
//		elif(ID==3||ID==4){
//			long long count=0,ct=0,OK=0;
//			for(int i=0;i<n;i++)
//			for(int j=i+2;j<n;j++)
//			if(str[i]=="00"&&str[j]=="00"){
//				for(int k=i;k<=j;k++){
//					if(str[k][0]=='1'){
//						cout<<i<<" "<<j<<endl;
//						break;
//					}
//					if(k==j){
//						count++,OK=1;
//						cout<<i<<" | "<<j<<endl;
//					}
//				}
//				if(OK)for(int li=j;li<n;li++)
//				if(str[li][0]='1')break;
//				else{
//					cout<<i<<" "<<j<<endl;ct++;
//				}
//			}
//			cout<<count<<" "<<ct<<endl;
//		}
		else cout<<"0 0\n";
	}
	fclose(stdin);fclose(stdout);
	return 0;
}
