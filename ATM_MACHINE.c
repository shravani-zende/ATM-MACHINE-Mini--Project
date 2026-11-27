#include <stdio.h>

int main()
{
    int pin, correctPin = 1234;
    int choice;
    int attempts = 0;
    double balance = 5000.00;
    double amount;

    printf("================================\n");
    printf("       WELCOME TO ATM\n");
    printf("================================\n");

    /* PIN verification */
    while (attempts < 3)
    {
        printf("Enter your 4-digit PIN: ");

        scanf("%d", &pin);

        if (pin == correctPin)
        {
            printf("\nPIN verified successfully!\n");
            break;
        }
        else
        {
            attempts++;
            printf("Incorrect PIN!\n");
            printf("Attempts remaining: %d\n", 3 - attempts);
        }
    }

    if (attempts == 3)
    {
        printf("\nToo many incorrect attempts.\n");
        printf("Your session has ended.\n");
        return 0;
    }

    /* ATM menu */
    do
    {
        printf("\n========== ATM MENU ==========\n");
        printf("1. Check Balance\n");
        printf("2. Deposit Money\n");
        printf("3. Withdraw Money\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");

        scanf("%d", &choice); 
        

        switch (choice)
        {
            case 1:
                printf("\nCurrent Balance: Rs. %.2f\n",
                       balance);
                break;

            case 2:
                printf("\nEnter deposit amount: Rs. ");

                scanf("%lf", &amount);

                if (amount > 0)
                {
                    balance = balance + amount;
                    printf("Deposit successful!\n");
                    printf("Updated Balance: Rs. %.2f\n",
                           balance);
                }
                else
                {
                    printf("Amount must be greater than zero.\n");
                }
                break;

            case 3:
                printf("\nEnter withdrawal amount: Rs. ");

                scanf("%lf", &amount);

                if (amount <= 0)
                {
                    printf("Amount must be greater than zero.\n");
                }
                else if (amount > balance)
                {
                    printf("Insufficient balance!\n");
                }
                else
                {
                    balance = balance - amount;
                    printf("Please collect your cash.\n");
                    printf("Updated Balance: Rs. %.2f\n",
                           balance);
                }
                break;

            case 4:
                printf("\nThank you for using our ATM!\n");
                printf("Please visit again.\n");
                break;

            default:
                printf("\nInvalid choice! Select 1 to 4.\n");
        }

    } while (choice!=4);

    return 0;
}
