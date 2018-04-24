# DA_Lab_7
Laboratory work №7 on discrete analysis, 4 semester, Moscow Aviation Institute (MAI).
## Formulation of the problem
There is a natural number *n*. You can perform 3 kinds of operations with it:
1. subtract 1
2. divide by 2
3. divide by 3

*Transformation* - the sequence of the above-mentioned operations. The cost of each operation is current value of *n*. The cost of the transformation is summary cost of all operations in the transformation. The task is to find a transformation with the lowest cost, that will transform input number to *n*.
### Input data
2 ≤ n ≤ 10^7
### Output data
In the first string print the lowest cost. In the second one print the transformation itself. Possible operations are: /2, /3, -1. All of them must be divided by space character.
## Example
| Input data | Output data    |
| ---------- | -------------- |
| 82         | 202<br> -1 /3 /3 /3 /3 |
## Solution method
To solve this problem I used a *dynamical programming* method. The task can be easily divided into separated subtasks, and if we solve them and unite the solutions, we will get the solution of the main task. As a subtask we can take counting minimal cost of each number less than *n*. Using the solutions we can count minimal cost of *n* and this will be an answer.

We will need an array with 2 lines and *n* columns. In the first line we will keep the lowest price for the number, operations in the second one. The minimal cost search algorithm works like this:
1. The number we begin with is 2
2. The lowest cost of the current number *i* will be the lowest cost of numbers *i* - 1, *i* / 2, *i* / 3. We put the cost to the first line of the array where *i* is column index.
3. In the second line we put an operation that allowed us to get the lowest cost.
4. Go to the next number (increment *i*) and do step 2.

The process will repeat until the cost of *n* will be counted.

