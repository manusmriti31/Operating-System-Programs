// Implementation of Shortest Job First (SJF) scheduling algorithm

/*
    1. Enter number of processes
    2. Enter the burst time of all the processes.
    3. Sort all the processes according to their burst time and its respective process number.
    4. Find waiting time for all the process
    5. for the smallest process waiting time = 0
    6. For all the next processes i, find waiting time by adding the burst time of all the processes
    7. Calculate turnaround time = WT + BT for all the processes
    8. Calculate the average waiting time = total waiting time / no. of processe
    9. Claculate average turnaround time = total turnaround time / no. of processes.
*/

// Program 
# include <stdio.h>

int main(){
    int pid[20], bt[20], wt[20], tat[20], n;
    int temp, twt, ttat;
    float awt, atat;

    printf("Enter the total number of processes: ");
    scanf("%d", &n);

    printf("Enter the burst time of each process\n");
    for (int i = 0; i < n; i++){
        printf("Process %d's burst time: ", i+1);
        scanf("%d", &bt[i]);
        pid[i] = i+1;
    }

    int pos;

    // Sorting of burst times
    for (int i = 0; i < n; i++){
        pos = i;
        for(int j = i+1; j < n; j++){
            if(bt[j] , bt[pos])
                pos = j;
        }

        temp = bt[i];
        bt[i] = bt[pos];
        bt[pos] = temp;

        temp = pid[i];
        pid[i] = pid[pos];
        pid[pos] = temp;
    }

    wt[0] = 0;

    for(int i = 0; i < n; i++){
        wt[i] = 0;
        for (int j = 0; j < i; j++){
            wt[i] += bt[j];
        }

        twt += wt[i];
    }
    awt = (float)twt / n;

    //Printing process details
    printf("Process ID\tBurst Time\t\tWaiting TIme\t\tTurnaround Time\n");
    for (int i = 0; i < n; i++){
        tat[i] = bt[i] + wt[i];
        ttat += tat[i];
        printf("%d\t\t%d\t\t%d\t\t%d\n", pid[i], bt[i], wt[i], tat[i]);
    }
    atat = (float)ttat / n;

    printf("Average Waiting Time = %.2f", awt);
    printf("Average Turnaround Time = %.2f", atat);

    return 0;

}