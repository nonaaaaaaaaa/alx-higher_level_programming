#include <stdio.h>
#include <stdlib.h>

/* Structure for a singly linked list node */
typedef struct listint {
    int data;
    struct listint* next;
} listint_t;

/* Function to reverse a linked list */
listint_t* reverseList(listint_t* head) {
    listint_t *prev = NULL, *current = head, *next = NULL;
    while (current != NULL) {
        next = current->next;
        current->next = prev;
        prev = current;
        current = next;
    }
    return prev;
}

/* Function to check if a linked list is a palindrome */
int is_palindrome(listint_t **head) {
    listint_t *slow = *head, *fast = *head, *prev_slow = *head;
    listint_t *second_half, *mid_node = NULL;
    int is_palindrome = 1; // Initially assume it's a palindrome

    if (*head != NULL && (*head)->next != NULL) {
        while (fast != NULL && fast->next != NULL) {
            fast = fast->next->next; // Move fast pointer by two steps
            prev_slow = slow;
            slow = slow->next; // Move slow pointer by one step
        }

        /* Handling odd number of elements in the list */
        if (fast != NULL) {
            mid_node = slow;
            slow = slow->next;
        }

        second_half = reverseList(slow);
        prev_slow->next = second_half;

        /* Compare the first half and reversed second half */
        listint_t *p1 = *head, *p2 = second_half;
        while (p2 != NULL) {
            if (p1->data != p2->data) {
                is_palindrome = 0;
                break;
            }
            p1 = p1->next;
            p2 = p2->next;
        }

        /* Revert the changes made to the list */
        second_half = reverseList(second_half);
        if (mid_node != NULL) {
            prev_slow->next = mid_node;
            mid_node->next = second_half;
        } else {
            prev_slow->next = second_half;
        }
    }
    return is_palindrome;
}

/* Utility function to create a new node */
listint_t* newNode(int data) {
    listint_t* new_node = (listint_t*)malloc(sizeof(listint_t));
    new_node->data = data;
    new_node->next = NULL;
    return new_node;
}

/* Function to print the linked list */
void printList(listint_t* node) {
    while (node != NULL) {
        printf("%d -> ", node->data);
        node = node->next;
    }
    printf("NULL\n");
}

/* Main function to test the palindrome function */
int main() {
    listint_t* head = newNode(1);
    head->next = newNode(2);
    head->next->next = newNode(3);
    head->next->next->next = newNode(2);
    head->next->next->next->next = newNode(1);

    printf("Original linked list: ");
    printList(head);

    if (is_palindrome(&head)) {
        printf("The linked list is a palindrome.\n");
    } else {
        printf("The linked list is not a palindrome.\n");
    }

    return 0;
}

