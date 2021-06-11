# Problem

Taylor series is a series that used to create an estimation of what a function look like. 1 Dimensional Taylor series is an expansion of a function about a point, and it is formulated as below:
![alt text](https://github.com/erkanfatma/PICalculationWithMultiThreads/blob/main/img/formula.png)

The study problem needs a multithreaded application code with C programming language that calculates the pi number with Taylor series with the equation below:

![alt text](https://github.com/erkanfatma/PICalculationWithMultiThreads/blob/main/img/formula2.png)

The first step is to ask the client that how many threads wanted to run the program.  And then the assignment needs to ask about total number of executions. Assignment requires a different number of threads that is in the range from 1 to 64. The application also needs to display approximation error and execution time of the computation. 

# Solution Strategy

To calculate pi number with Taylor series:
1.	Request a number which is n from the user that used for how many terms the code will sum in the approximation.
2.	Request a number from the client to define the number of threads. 
3.	A loop statement is used to iterate n times.
4.	For summation of Pi, there are some different variables can be used.
5.	Calculate the pi number.
6.	Print result pi number.
7.	Repeat these steps to approximate the e number.

![alt text](https://github.com/erkanfatma/PICalculationWithMultiThreads/blob/main/img/formula3.png)

# Execution 

```
 gcc picalculation.c -lm -o picalc -pthread
 
 ./picalc
```

# Results

In the result with 1 thread, when comparing operation size, the small number of the operation sizes i.e., 100 has too high approximation error value. On the other hand, when compare the computation time, small number of iterations has small execution time. In the thread 1, when we increase the number of iterations, the result gives better result for the calculated pi number, but the duration time is high at that time.

![alt text](https://github.com/erkanfatma/PICalculationWithMultiThreads/blob/main/img/figure1.png)

Above figure shows the output as a graph where thread number is equal to5. Herewith, it is clearly seen that if the number of iterations increased at the constant thread number, the approximation error is decreased. However, the execution time is increasing. If the iteration number is increased, then the correct calculation rate of the oi number is increasing. 

![alt text](https://github.com/erkanfatma/PICalculationWithMultiThreads/blob/main/img/figure2.png)

The figure above shows the computation time vs number of threads for 1.000.000 add/sub operations. As seen in the figure the computation time changes depend on thread sizes. In the 1.000.000 iteration, the approximation error is too small, and so close to the 0 value. Nearly, all the results very close to the other results. 
