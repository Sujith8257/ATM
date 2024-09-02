#include <stdio.h>
#include <stdlib.h>

void deposit(int amt);
void withdraw(int amt);
void denomination(int amt);
int showbal();

int balance;

int main() {
    int choice, amt, i, j, n, count;
    balance = 10000; // INITIAL BALANCE IS TEN THOUSAND

    // Pin Setup
    printf("Set your pin:\n");
    scanf("%d", &i);

    count = 0;
    while (count < 3) {
        printf("Re-enter the pin:\n");
        scanf("%d", &j);

        if (i == j) {
            printf("\n\n************");
            printf("\n\tWELCOME TO SBI ATM");
            printf("\n************");
            break; // Exit the loop if pin is correct
        } else {
            printf("Wrong pin\n");
            count++;
        }
    }

    if (count == 3) {
        printf("Too many incorrect attempts. Exiting...\n");
        exit(0);
    }

    // Main loop
    do {
        printf("\n\n\xB2\xB2\xB2 1. DEPOSIT \n\n \xB2\xB2\xB2 2. WITHDRAW \n\n \xB2\xB2\xB2 3. SHOW BALANCE \n\n \xB2\xB2\xB2 4. EXIT");
        printf("\n\nENTER YOUR CHOICE: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("\xB2\xB2 ENTER AMOUNT TO DEPOSIT: ");
                scanf("%d", &amt);
                deposit(amt);
                break;

            case 2:
                printf("\xB2\xB2 ENTER AMOUNT TO WITHDRAW: ");
                scanf("%d", &amt);
                if (amt > balance) {
                    printf("\n\xB2\xB2 INSUFFICIENT BALANCE\n");
                } else {
                    withdraw(amt);
                    denomination(amt);
                }
                break;

            case 3:
                amt = showbal();
                printf("\xB2\xB2 THE BALANCE IS %d\n", amt);
                break;

            case 4:
                exit(0);

            default:
                printf("INVALID CHOICE\n");
        }
    } while (choice != 4);

    return 0;
}

void deposit(int amt) {
    balance += amt;
    printf("\xB2\xB2 Amount added successfully\n");
    printf("\t\tTHANK YOU\n");
}

void withdraw(int amt) {
    balance -= amt;
    printf("\xB2\xB2 Balance is %d\n", balance);
    printf("\t\tTHANK YOU\n");
}

void denomination(int amt) {
    int amt1, amt2, a, b, c, d;
    amt1 = amt;
    printf("The amount for the denomination is %d\n", amt);

    printf("Enter number of 100 notes: ");
    scanf("%d", &a);
    amt -= 100 * a;

    printf("Enter number of 200 notes: ");
    scanf("%d", &b);
    amt -= 200 * b;

    printf("Enter number of 500 notes: ");
    scanf("%d", &c);
    amt -= 500 * c;

    printf("Enter number of 2000 notes: ");
    scanf("%d", &d);
    amt -= 2000 * d;

    if (amt < 0) {
        printf("Invalid input due to insufficient balance\n");
    } else if (amt != 0) {
        printf("\nRemaining amount denomination is being randomised.\n");
    }
    printf("\t\tTHANK YOU\n");
}

int showbal() {
    return balance;
}
