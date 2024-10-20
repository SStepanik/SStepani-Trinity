# Operating Systems Final Project
BY: Sean Stepanik

Inter-process communication simulation: Using the concepts of resource sharing in an ordered manner and using a mutex lock, I have managed the traffic of processes in a 4-way lane (4 threads). The 20 completable processes are accepted in a FIFO format, and each process takes a previously set random amount of time between 1 and 10 seconds. The outputs are color-coded, with 'WHITE' for adding a process to the queue, 'YELLOW' for starting a process, and 'GREEN' for completing a process.