// File: overflow_demo.c
// Description: A simple program demonstrating a stack-based buffer overflow vulnerability.
// Usage: Compile with gcc-g-o overflow_demo overflow_demo.c-fno-stack-protector-z execstack-no-pie-O0
// Run: ./overflow_demo
// Note: Ensure ASLR is disabled: echo 0 | sudo tee /proc/sys/kernel/randomize_va_space
#define _GNU_SOURCE
#include <stdio.h>
#include <string.h>
void vulnerable_function() {
int secret = 0x1337; // The target variable we want to overwrite
char buffer[64]; // A small, fixed-size buffer
// Print addresses and initial secret value for analysis
printf("\n[+] Buffer address: %p\n", (void*)buffer);
printf("[+] Secret variable address: %p\n", (void*)&secret);
printf("[+] Secret value (before): 0x%x\n", secret);
printf("\n[!] WARNING: Using unsafe input can be dangerous!\n");
printf("[>] Enter your input: ");
// MANUALUNSAFEINPUT-This is the vulnerability.
// It reads input character by character without checking the buffer's size.
int i = 0;
char c;
while ((c = getchar()) != '\n' && c != EOF) {
if (i < 256) { // Arbitrary large limit, allowing overflow of the 64-byte 'buffer'
buffer[i++] = c;
}
}
buffer[i] = '\0';
// Check if the secret variable was modified
printf("[+] Secret value (after): 0x%x\n", secret);
if (secret == 0x5555) {
printf(" BINGO! Buffer overflow successful!\n");
printf(" You've altered program behavior!\n");
} else {
printf(" Overflow failed. Try again.\n");
}
}
int main() {
printf("=== Buffer Overflow Demo ===\n");
printf("This program shows how writing past a buffer boundary can overwrite adjacent stack
variables.\n\n");
vulnerable_function();
return 0;
}
