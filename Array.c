#include<stdio.h>
int main(){
    int newOddSize = 0;
    int newEvenSize = 0;
    int finalElement;
    int size;
    printf("Enter the size of array :");
    scanf("%d",&size);
    int userArray[size];
    for(int i=0;i<size;i++){
        int tempElement;
        printf("Enter the element at position %d :\n",i);
        scanf("%d",&tempElement);
        userArray[i] = tempElement;
        printf("im inside input");
    }
    printf("outside");
    while(newEvenSize != 1){
        printf("I am in while loop");
        //for odd array
            newOddSize = size;
            if(size % 2 == 0){
                newOddSize = (size/2) + 1;
            }
            else{
                newOddSize = size/2;
             }
            int newOddArray[newOddSize];
            int j=0;
            for(int i=0;i<newOddSize;i+2){
                newOddArray[j]=userArray[i];
                j++;
            }
         //for even array
            int newEvenSize = size/2;
            int newEvenArray[newEvenSize];
            int k=0;
            for(int i=0;i<newOddSize;i+2){
                newEvenArray[k] = newOddArray[i];
                k++;
            }
            finalElement = newEvenArray[0];
        }
    for(int i=0;i<size;i++){
        if(userArray[i] == finalElement){
            printf("Element %d is at index %d",finalElement,i);
        }
    }
    return 0;
}

