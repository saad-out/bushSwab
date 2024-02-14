# <p align="center">bushSwab-42</p>
![alt text](https://github.com/saad-out/bushSwab/blob/main/images/push_swap.png?raw=true)

# Description
The Push Swap 42 project is a sorting algorithm implementation challenge that aims to efficiently sort a stack of integers using a limited set of operations. Developed as part of the curriculum at coding bootcamp 42, this project tests students' algorithmic and problem-solving skills.

# Installation
Clone the repo:
```
git clone https://github.com/saad-out/bushSwab.git
```
Change directory into the cloned repo:
```
cd bushSwab
```
 Generate the `push_swap` executable by running:
 ```
make
```
 Generate the `checker` executable by running:
```
make bonus
```

# Usage
To sort a stack of integers, execute the push_swap executable followed by the integers as arguments. For example:
```
./push_swap 4 67 2 8
```
Additionally, you can use the checker executable to verify if the stack is sorted correctly. To do this, try:
```
ARG="4 67 2 8" ; ./push_swap $ARG | ./checker $ARG
```
This will output either "OK" or "KO" depending on whether the stack is sorted correctly after executing the provided instructions.
