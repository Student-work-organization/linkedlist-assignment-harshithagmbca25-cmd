#include <stdio.h>
#include <stdlib.h>


struct node {
    int data;
    struct node *next;
};

struct node *head = NULL;


void insert_at_end(int data) {
    struct node *newnode, *temp;

    newnode = (struct node*)malloc(sizeof(struct node));
    newnode->data = data;

    if (head == NULL) {
        head = newnode;
        newnode->next = head;
        return;
    }

    temp = head;
    while (temp->next != head) {
        temp = temp->next;
    }

    temp->next = newnode;
    newnode->next = head;
}


void delete_node(int data) {
    struct node *temp = head, *prev;

    if (head == NULL) {
        printf("List empty\n");
        return;
    }

    
    if (head->data == data) {
        if (head->next == head) {
            free(head);
            head = NULL;
            return;
        }

        while (temp->next != head)
            temp = temp->next;

        struct node *del = head;
        head = head->next;
        temp->next = head;
        free(del);
        return;
    }

    prev = head;
    temp = head->next;

    while (temp != head) {
        if (temp->data == data) {
            prev->next = temp->next;
            free(temp);
            return;
        }
        prev = temp;
        temp = temp->next;
    }

    printf("Not found\n");
}

void display() {
    struct node *temp = head;

    if (head == NULL) {
        printf("List empty\n");
        return;
    }

    do {
        printf("%d -> ", temp->data);
        temp = temp->next;
    } while (temp != head);

    printf("HEAD\n");
}


int main() {
    insert_at_end(10);
    insert_at_end(20);
    insert_at_end(30);

    display();

    delete_node(20);
    display();

    return 0;
}
