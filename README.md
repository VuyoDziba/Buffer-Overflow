# Buffer Overflow Demonstration

Student: Vuyo Dziba  
Course: Ethical Hacking 361  

## Project Overview
This project demonstrates a classic stack-based buffer overflow vulnerability using a vulnerable C program.

## Files
- overflow_demo.c – vulnerable program
- run.sh – exploit script
- report.pdf – full project report

## Compilation

gcc -g -o overflow_demo overflow_demo.c -fno-stack-protector -z execstack -no-pie -O0

## Running the Exploit

./run.sh

## Screenshots

### Code
![Code Screenshot](screenshots/code.png)

### Program Execution
![Execution](screenshots/terminal_run.png)

### Overflow Success
![Overflow](screenshots/overflow_result.png)# Buffer-Overflow
