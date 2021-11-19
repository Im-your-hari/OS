#include<stdio.h>

int main(){
    int p[10],wt[10],bt[10],tat[10],n,i,j,temp,avgwt=0,avgtat=0;
    printf("Enter no.of process...");
    scanf("%d",&n);
    for(i=0;i<n;i++){
        printf("Bt of P[%d]",i+1);
        scanf("%d",&bt[i]);
        p[i]=i;
    }
    for(i=0;i<n;i++){
        for(j=i+1;j<n;j++){
            if(bt[i]>bt[j]){
                temp=bt[i];
                bt[i]=bt[j];
                bt[j]=temp;

                temp=p[i];
                p[i]=p[j];
                p[j]=temp;
            }
        }
    }
    wt[0]=0;
    for(i=0;i<n;i++){
        wt[i+1]=bt[i]+wt[i];
        tat[i]=bt[i]+wt[i];
    }

    printf("Process\tBurst\tWait\tTurn\n");
    for(i=0;i<n;i++){
        printf("p[%d]\t%d\t%d\t%d\n",i+1,bt[i],wt[i],tat[i]);
        avgtat+=tat[i];
        avgwt+=wt[i];
    }
    printf("Avg wt=%d\tAvg tat=%d",avgwt/n,avgtat/n);
}