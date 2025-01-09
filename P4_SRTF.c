// Program for the implementation of Shortest Remaining Time First (SRTF) scheduling algorithm

/*
    1. Enter number of processes
    2. Enter the burst time and arrival time of all the processes
    3. Sort all the processe according to their arrival time and it's respective process burst time
    4. Transeverse until all process gets completely executed
        - Find process with the minimum remaining time at every single time lap.
        - Reduce its time by 1
        - Check if remaining time becomes 0
        - Increment the counter of process completion
        - Completion time of current process = current_time + 1
        - Calculate waiting time for each completed process
            - wt[i] = Completion time - arrival_time - burst_time
        - Increment tiem lap by one.
    5. Calculate Turnaround time = WT + BT for all processes
    6. Calculate average waiting time = total waiting time / no. of processes
    7. Calculate average turnaround time = total turnaround time / no. of processes
*/

// Program 
#include <stdio.h>
#include <stdbool.h>

#define MAX_PROCESS 100

struct process{
    int pid;
    int arrival_time;
    int burst_time;
    int remaining_time;

};

int main(){
    int n;
    struct process processes[MAX_PROCESS];
    bool completed[MAX_PROCESS] = {false};
    int current_time = 0;

    printf("Enter the number of processes: ");
    scanf("%d", &n);

    for(int i = 0; i < n; i++){
        printf("Enter arrival time and burst time for process %d: ", i+1);
        scanf("%d%d", &processes[i].arrival_time, &processes[i].burst_time);
        processes[i].pid = i + 1;
        processes[i].remaining_time = processes[i].burst_time;
    }

    printf("\n");

    while(true){
        int shortest_time = __INT_MAX__;
        int shortest_index = -1;

        for(int i = 0; i < n; i++){
            if(!completed[i] && processes[i].arrival_time <= current_time && processes[i].remaining_time < shortest_time){
                shortest_time = processes[i].remaining_time;
                shortest_index = i;
            }
        }

        if (shortest_index == -1){
            break;
        }

        processes[shortest_index].remaining_time--;
        if (processes[shortest_index].remaining_time == 0){
            completed[shortest_index] == true;
        }

        current_time++;
    }

    // Printing the output
    printf("\nProcess ID\t\tArrival Time\t\tBurst Time\t\tWaiting Time\t\tTurnaround Time\n");
    int total_waiting_time = 0, total_turnaround_time = 0;
    
    for (int i = 0; i < n; i++){
        int waiting_time = current_time - processes[i].burst_time - processes[i].arrival_time;
        int turnaround_time = current_time - processes[i].arrival_time;
        total_waiting_time += waiting_time;
        total_turnaround_time+= turnaround_time;

        printf("%d\t\t%d\t\t%d\t\t%d\t\t%d\n", processes[i].pid, processes[i].arrival_time, processes[i].burst_time, waiting_time, turnaround_time);

    }

    float avg_waiting_time = (float)total_waiting_time / n;
    float avg_turnaround_time = (float)total_turnaround_time / n;

    printf("\nAverage Waiting time: %.2f\n", avg_waiting_time);
    printf("\nAverage turnaround time: %.2f\n", avg_turnaround_time);

    return 0;

}