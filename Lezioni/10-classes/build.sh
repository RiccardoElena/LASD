#! /bin/bash

read -p "Which example do you want to compile? (Enter a number from 1 to 8): " example

while [[ ! $example =~ ^[1-8]$ ]]; do
  read -p "Invalid input. Please enter a number from 1 to 8: " example
done

g++ -std=c++20 -Wall -Wextra -Wpedantic -Werror -o "example$example.out" main.cpp "example$example.cpp"

./"example$example.out"