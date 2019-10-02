#include<stdio.h>
void main(){
    int size = 5;
    int userArray[5];
    for(int i=0;i<size;i++){
        int tempElement;
        printf("Enter the element at position %d :\n",i);
        scanf("%d",&tempElement);
        userArray[i] = tempElement;
        printf("im inside input");
    }
}