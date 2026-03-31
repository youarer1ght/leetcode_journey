#include <stdio.h>
int main(){
    int a[10],height,i,j=0;
    for(i=0;i<10;i++){
        scanf("%d",a+i);
    }
    scanf("%d",&height);
    height+=30;
    for(i=0;i<10;i++){
        if(a[i]<=height)
        j++;
    }
    return j;
}