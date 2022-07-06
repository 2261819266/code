#include<cstdio>
#define maxn 500005
int n=10,arr[maxn]={1,2,3,4,5,6,7,8,9,10};
int lowbit(int a){
    return a&-a;
}
int quety(int x){
    int res=0;
    for(;x;x-=lowbit(x))res+=arr[x];
    return res;
}
int k;
int main(){
    for(k=1;k<=10;k++)
    printf("%d ",quety(k));
}