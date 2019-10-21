/*
Task table schema:
P.id A.T B.T C.T T.A.T W.T
*/
#include<stdio.h>
void swap(int *xp, int *yp) 
{ 
    int temp = *xp; 
    *xp = *yp; 
    *yp = temp; 
}
int main(){
    int task[5][6];
    int bt[5];
    for (int i=0;i<5;i++){
        printf("Enter the arrival time and burst time for process P%d :", i+1);
        task[i][0]=i+1;
        scanf("%d %d", &task[i][1], &task[i][2]);
        bt[i]=task[i][2];
    }
    printf("I.D.     A.T.    B.T.");
    for (int i=0;i<5;i++){
        printf("\n %d\t %d\t %d\n", task[i][0],task[i][1],task[i][2]);
    }
    //bubble short
   for (int i = 0; i < 5-1; i++){       
       // Last i elements are already in place    
       for (int j = 0; j < 5-i-1; j++){
           if (task[j][1] > task[j+1][1]){ 
              swap(&task[j][1], &task[j+1][1]);
              swap(&task[j][0], &task[j+1][0]);
              swap(&task[j][2], &task[j+1][2]);
              swap(&bt[j],&bt[j+1]);
           }
       } 
   }
   int total_bt = 1000;
   int ct=task[0][1];
   int queue[100];
   int queueIndex=0;
   int tq=2;
   while (total_bt!=0){
       total_bt = 0;
       for(int i=0;i<5;i++){
           if(bt[i]!=0 && ct>=task[i][1]){
               if(bt[i]>tq){
               queue[queueIndex]=task[i][0];
               queueIndex++;
               bt[i]-= tq;
        //finding C.T
               ct+=tq;
               task[i][3]=ct;
               }
               else{
               queue[queueIndex]=task[i][0];
               queueIndex++;
               bt[i] = 0;
        //finding C.T
               ct+=tq;
               task[i][3]=ct;
               }
           }
           total_bt+=bt[i];
       }
   }
   for(int index=0;index<5;index++){
        //finding T.A.T
        task[index][4]=task[index][3]-task[index][1];
        //finding W.T
        task[index][5]=task[index][4]-task[index][2];
   }

   for(int i=0;i<queueIndex;i++){
       printf(": P[%d] :",queue[i]);
   }
   printf("\n");

   //final output
   printf("I.D.     A.T.    B.T.    C.T.    T.A.T.  W.T.");
    for (int i=0;i<5;i++){
        printf("\n %d\t %d\t %d\t %d\t %d\t %d\n", task[i][0],task[i][1],task[i][2],task[i][3],task[i][4],task[i][5]);
    }
    //finding total W.T and T.A.T
    float totaltat=0;
    float totalwt=0;
    for(int i=0;i<5;i++){
        totaltat+=task[i][4];
        totalwt+=task[i][5];
    }
    printf("\n Average Turnaround time is : %f", totaltat/5);
    printf("\n Average waiting time is : %f\n", totalwt/5);
    return 0;
}
 
