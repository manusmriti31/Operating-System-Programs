//  FIRST COME FIRST SERVE (FCFS)

/*
    1. Input number of processes
    2. Input the process burst time
    3. Find waiting time (wt) for all processes.
        - As first process that comes need not to wait so waiting time for process 1 will be 0 i.e wt[0] = 0
        - Find waiting time for all other processes i.e for process i -> wt[i] = b[i-1] + wt[i-1]
    4. Find turnaround time = waiting
*/