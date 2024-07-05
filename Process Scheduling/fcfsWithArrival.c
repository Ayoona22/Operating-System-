#include<stdio.h>
typedef struct{
    int id,at,bt,tat,wt,ct,rt;
}process;
void sortat(process p[100],int n){
    for(int i=0;i<n;i++){
        if(p[i].at>p[i+1].at){
            process temp=p[i];
            p[i]=p[i+1];
            p[i+1]=temp;
        }
    }
}void sortid(process p[100],int n){
    for(int i=0;i<n;i++){
        if(p[i].id>p[i+1].id){
            process temp=p[i];
            p[i]=p[i+1];
            p[i+1]=temp;
        }
    }
}
void main(){
    process p[100];
    int s,a[100];
    int n,no=0;
    s=0,a[0]=0;
    int j=1;
    printf("Enter the number of processes: ");
    scanf("%d",&n);
    for(int i=0;i<n;i++){
        printf("Enter the arrival time and burst time of P%d : ",i+1);
        scanf("%d%d",&p[i].at,&p[i].bt);
        p[i].id=i+1;
    }
    sortat(p,n);
    while(no!=n){
        if(p[no].at<=s){
            printf("| P%d |",p[no].id);
            s+=p[no].bt;
            p[no].ct=s;
            a[j]=s;
            no++;
        }else{
            s+=1;
            printf("****");
            a[j]=s;
        }j++;
    }sortid(p,n);
    printf("\n");
    for(int i=0;i<j;i++){
        printf("%d   ",a[i]);
    }printf("\n");
    int avwt=0,avtat=0;
    for(int i=0;i<n;i++){
        p[i].tat=p[i].ct-p[i].at;
        avtat+=p[i].tat;
        p[i].wt=p[i].tat-p[i].bt;
        avwt+=p[i].wt;
    }
    printf("\nPROCESS\tARRIVAL\tBURST TURNAROUND WAITING COMPLETION\n");
    for(int i=0;i<n;i++){
        printf("P%d\t%d\t%d \t%d\t  %d \t  %d\n",p[i].id,p[i].at,p[i].bt,p[i].tat,p[i].wt,p[i].ct);
    }printf("Average Waiting Time : %d\nAverage Turnaround Time : %d",avwt/n,avtat/n);
}
/*
                               Output


    Enter the Number of Process : 5
    Enter Process 1 - Arrival Time & Burst Time : 2 2
    Enter Process 2 - Arrival Time & Burst Time : 0 1
    Enter Process 3 - Arrival Time & Burst Time : 2 3
    Enter Process 4 - Arrival Time & Burst Time : 3 5
    Enter Process 5 - Arrival Time & Burst Time : 4 4
    Gantt Chart:

    ----------------------------------------------------------
    |  P2  | Idle |  P1  |  P3  |  P4  |  P5  |
    ----------------------------------------------------------
    0      1      2      4      7     12     16
             Process         Arrival           Burst      Completion      TurnAround         Waiting
    --------------------------------------------------------------------------------------------
               P1             2               2               4               2               0
               P2             0               1               1               1               0
               P3             2               3               7               5               2
               P4             3               5              12               9               4
               P5             4               4              16              12               8

      Average Waiting Time       : 2.80 ms
      Average TurnAround Time    : 5.80 ms

  */