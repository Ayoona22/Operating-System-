#include<stdio.h>
typedef struct{
    int id,at,bt,tat,wt,ct,rt;
}process;

void main(){
    process p[100];
    int s,a[100],j;
    s=0,j=1;
    a[0]=0;
    printf("No. of processes : ");
    int n;
    scanf("%d",&n);
    for(int i=0;i<n;i++){
        p[i].id=i;
        printf("Enter the burst time of P%d : ",p[i].id);
        scanf("%d",&p[i].bt);
        p[i].at=0;
    }printf("GHANT CHART\n");
    for(int i=0;i<n;i++){
        printf("| P%d |",i);
        s+=p[i].bt;
        a[j]=s;
        p[i].ct=s;
        j++;
    }printf("\n");
    for(int i=0;i<j;i++){
        printf("%d    ",a[i]);
    }int avwt=0,avtat=0;
    for(int i=0;i<n;i++){
        p[i].tat=p[i].ct-p[i].at;
        avtat+=p[i].tat;
        p[i].wt=p[i].tat-p[i].bt;
        avwt+=p[i].wt;
        p[i].rt=a[i]-p[i].at;
    }printf("\nPROCESS\tARRIVAL\tBURST TURNAROUND WAITING COMPLETION RESPONCE\n");
    for(int i=0;i<n;i++){
        printf("P%d\t%d\t%d \t%d\t  %d \t  %d\t\t%d\n",p[i].id,p[i].at,p[i].bt,p[i].tat,p[i].wt,p[i].ct,p[i].rt);
    }printf("Average Waiting Time : %d\nAverage Turnaround Time : %d",avwt,avtat);
}

/*
            Output
            
    Enter the Number of Process : 3
    Enter Process 1 Burst Time :24
    Enter Process 2 Burst Time :3
    Enter Process 3 Burst Time :3

            Process           Burst      Completion      TurnAround         Waiting
    ------------------------------------------------------------------
    P1              24              24              24                0
    P2               3              27              27               24
    P3               3              30              30               27
    -----------------------------------------------------------------

    Gantt Chart
    ---------------------------
    | P1    | P2    | P3    |
    ---------------------------
    0       24      27      30

    Average Waiting Time : 17.00 ms
    Average TurnAround Time : 27.00 ms
 
 */
