#include <stdio.h>
#include <stdlib.h> // Required for exit(0)

// Global variables
int mutex = 1, full = 0, empty = 3, x = 0;

// Function prototypes
void producer();
void consumer();
int wait(int s);
int signal(int s);

int main() {
    int n;
    printf("\n1.Producer\n2.Consumer\n3.Exit\n");
    while (1) {
        printf("\nEnter choice: ");
        scanf("%d", &n);
        
        switch (n) {
            case 1:
                if ((mutex == 1) && (empty != 0)) {
                    producer();
                } else {
                    printf("Buffer is full");
                }
                break;
                
            case 2:
                if ((mutex == 1) && (full != 0)) {
                    consumer();
                } else {
                    printf("Buffer is empty");
                }
                break;
                
            case 3:
                exit(0); // Exit the program
                break;
                
            default:
                printf("Invalid choice! Please enter 1, 2, or 3.");
        }
    }
    return 0;
}

int wait(int s) {
    return (--s);
}

int signal(int s) {
    return (++s);
}

void producer() {
    mutex = wait(mutex); // Acquire lock
    full = signal(full); // Increment full slots
    empty = wait(empty); // Decrement empty slots
    x++; // Produce an item
    printf("\nProducer produces the item %d", x);
    mutex = signal(mutex); // Release lock
}

void consumer() {
    mutex = wait(mutex); // Acquire lock
    full = wait(full); // Decrement full slots
    empty = signal(empty); // Increment empty slots
    printf("\nConsumer consumes the item %d", x);
    x--; // Consume an item
    mutex = signal(mutex); // Release lock
}