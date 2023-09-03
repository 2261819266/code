#include<cstdio>
int lowbit(int a){
    return a&-a;
}
int main(){
    int a;
    scanf("%d",&a);
    printf("%d",lowbit(a));
}