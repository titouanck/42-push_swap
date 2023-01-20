#!/bin/bash
clear && make re && make bonus
for i in 1 2 3 4 5 6 7 8 9 10 11 19 20 42 50 99 100 101 250 500 1000
do
    bash ./push_swap_tester/tester.sh . $i 50
done