//  FIRST COME FIRST SERVE (FCFS)

/*
    1. Input number of processes
    2. Input the process burst time
    3. Find waiting time (wt) for all processes.
        - As first process that comes need not to wait so waiting time for process 1 will be 0 i.e wt[0] = 0
        - Find waiting time for all other processes i.e for process i -> wt[i] = b[i-1] + wt[i-1]
    4. Find turnaround time = waiting time + burst_time for all processes
    5. Find average waiting time = total_waiting_time / no_of_processes.
    6. average turnaround time = totatl_turn_around time / no of processes
*/

// Program
#include<stdio.h>

int main(){
    int pid[15];
    int bt[15];
    int n;

    printf("Enter the number of processes: ");
    scanf("%d", &n);

    // Get process ID and burst time 
    printf("Enter the process ID and Burst time of each process \n");
    for (int i = 0; i < n; i++){
        printf("Enter Process ID: ");
        scanf("%d", &pid[i]);
        printf("ENter the burst time: ");
        scanf("%d", &bt[i]);
        printf("\n");
    }

    int wt[n];
    wt[0] = 0;

    // Waiting time for all processes
    for (int i = 1; i < n; i++){
        wt[i] = bt[i-1] + wt[i-1];
    }

    // Print the process table
    printf("Process ID      Burst Time      Waiting Time        Turnaround Time");
    float twt = 0.0;
    float tat = 0.0;

    for (int i = 0; i < n; i++){
        printf("%d\t\t", pid[i]);
        printf("%d\t\t", bt[i]);
        printf("%d\t\t", wt[i]);
        printf("%d\t\t", bt[i] + wt[i]);
        printf("\n");

        twt += wt[i];
        tat += (wt[i] + bt[i]);
    }

    float awt = twt / n;
    float att = tat / n;

    printf("Avg waiting time  = %.2f\n", awt);
    printf("Avg turnaround time  = %.2f\n", att);
}
