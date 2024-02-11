#!/usr/bin/python3

import sys
import random

def generate_unique_random_numbers(N):
    # INT_MIN = -2147483648  # Minimum value of int in C
    # INT_MIN = -1000
    # INT_MAX = 1000
    INT_MIN = -1000
    INT_MAX = 1000

    if N > (INT_MAX - INT_MIN + 1):
        print("Error: Cannot generate unique random numbers more than the range of int.")
        return []

    # Generate a list of unique random numbers
    unique_numbers = set()
    while len(unique_numbers) < N:
        unique_numbers.add(random.randint(INT_MIN, INT_MAX))

    return list(unique_numbers)

if __name__ == "__main__":
    if len(sys.argv) != 2:
        print("Usage: python script.py N")
        sys.exit(1)

    try:
        N = int(sys.argv[1])
    except ValueError:
        print("Error: N must be an integer.")
        sys.exit(1)

    if N <= 0:
        print("Error: N must be a positive integer.")
        sys.exit(1)

    random_numbers = generate_unique_random_numbers(N)
    for num in random_numbers:
        print(num, end=" ")
    print()
