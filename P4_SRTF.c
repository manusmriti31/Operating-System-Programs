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
        - Calculate waiting time for each completed process.
*/