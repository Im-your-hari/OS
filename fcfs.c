#include<stdio.h>

void wait(int bt[],int n,int wt[]){
    wt[0]=0;
    for(int i=1;i<n;i++)
        wt[i]=wt[i-1]+bt[i-1];
}

void turn(int bt[],int n,int wt[],int tat[]){
    for(int i=0;i<n;i++){
        tat[i]=bt[i]+wt[i];
    }
}

void findavgtime(int process[],int n,int bt[]){
    int wt[n],tat[n],tot_wt=0,tot_tat=0;
    wait(bt,n,wt);
    turn(bt,n,wt,tat);
    printf("Process\tBurst\tWait\tTurn\n");
    for(int i=0;i<n;i++){
        printf("P[%d]\t%d\t%d\t%d\t\n",i+1,bt[i],wt[i],tat[i]);
        tot_tat+=tat[i];
        tot_wt+=wt[i];
    }
    printf("Avg\n\tWT=%d\n\tTAT=%d",tot_wt/n,tot_tat/n);

}

int main(){
    int process[]={1,2,3};
    int n=3;
    int bt[]={10,5,8};
    findavgtime(process,n,bt);
}