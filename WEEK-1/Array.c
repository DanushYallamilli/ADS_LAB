#include <stdio.h>

int arr[100];
int count = 0;

void insert()
{
    if (count >= 100)
    {
        printf("Array is full. Cannot insert.\n");
        return;
    }

    int insertchoice;
    printf("\nInsert options:\n");
    printf("1. Insert at beginning\n");
    printf("2. Insert at end\n");
    printf("3. Insert at position\n");
    printf("Enter your choice: ");
    scanf("%d", &insertchoice);

    int value;
    int pos;
    switch (insertchoice)
    {
        case 1:
            printf("Enter element to insert at the beginning: ");
            scanf("%d", &value);
            for (int i = count; i > 0; i--)
            {
                arr[i] = arr[i - 1];
            }
            arr[0] = value;
            count++;
            printf("Inserted %d at the beginning.\n", value);
            break;

        case 2:
            printf("Enter element to insert at the end: ");
            scanf("%d", &value);
            arr[count] = value;
            count++;
            printf("Inserted %d at the end.\n", value);
            break;

        case 3:
            printf("Enter position to insert at (1 to %d): ", count + 1);
            scanf("%d", &pos);
            if (pos < 1 || pos > count + 1)
            {
                printf("Invalid position.\n");
                break;
            }
            printf("Enter element to insert: ");
            scanf("%d", &value);
            for (int i = count; i >= pos; i--)
            {
                arr[i] = arr[i - 1];
            }
            arr[pos - 1] = value;
            count++;
            printf("Inserted %d at position %d.\n", value, pos);
            break;

        default:
            printf("Invalid insert option.\n");
            break;
    }
}

void delete()
{
    if (count == 0)
    {
        printf("Array is empty. Cannot delete.\n");
        return;
    }

    int deletechoice;
    printf("\nDelete options:\n");
    printf("1. Delete from beginning\n");
    printf("2. Delete from end\n");
    printf("3. Delete from position\n");
    printf("Enter your choice: ");
    scanf("%d", &deletechoice);

    int removedValue;
    int pos;
    switch (deletechoice)
    {
        case 1:
            removedValue = arr[0];
            for (int i = 1; i < count; i++)
            {
                arr[i - 1] = arr[i];
            }
            count--;
            printf("Deleted %d from the beginning.\n", removedValue);
            break;

        case 2:
            removedValue = arr[count - 1];
            count--;
            printf("Deleted %d from the end.\n", removedValue);
            break;

        case 3:
            printf("Enter position to delete from (1 to %d): ", count);
            scanf("%d", &pos);
            if (pos < 1 || pos > count)
            {
                printf("Invalid position.\n");
                break;
            }
            removedValue = arr[pos - 1];
            for (int i = pos; i < count; i++)
            {
                arr[i - 1] = arr[i];
            }
            count--;
            printf("Deleted %d from position %d.\n", removedValue, pos);
            break;

        default:
            printf("Invalid delete option.\n");
            break;
    }
}

void display()
{
    if (count == 0)
    {
        printf("Array is empty.\n");
        return;
    }

    printf("Array elements: ");
    for (int i = 0; i < count; i++)
    {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

int main()
{
    int choice;

    printf("Enter the initial number of elements (0 to %d):\n", 100);
    scanf("%d", &count);
    if (count < 0 || count > 100)
    {
        printf("Invalid\n");
        return 1;
    }

    if (count > 0)
    {
        printf("Enter %d element(s):\n", count);
        for (int i = 0; i < count; i++)
        {
            scanf("%d", &arr[i]);
        }
    }

    do
    {
        printf("\nMenu:\n");
        printf("1. Insert into array\n");
        printf("2. Delete from array\n");
        printf("3. Display array\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice)
        {
            case 1:
                insert();
                break;

            case 2:
                delete();
                break;

            case 3:
                display();
                break;

            case 4:
                printf("Exiting.\n");
                break;

            default:
                printf("Invalid choice. Please try again.\n");
                break;
        }
    } while (choice != 4);

    return 0;
}
