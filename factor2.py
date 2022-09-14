#!/usr/bin/python3

import sys

args = sys.argv[1:]

if len(args) == 0:
    exit()

with open(args[0]) as fd:
    lines = fd.readlines()
    lines = (int(i) for i in lines)

for number in lines:
    i = 2
    j = int(number / 2)

    while (i < number / 2 and j > 2):

        if (number % i == 0):
            print("{:d}={:d}*{:d}".format(number, int(number/i), i))
            break

        if (number % j == 0):
            print("{:d}={:d}*{:d}".format(number, j, int(number/j)))
            break
        i += 1
        j -= 1
