#include <iostream>
using namespace std;

struct node{
    int data;
    struct node *next;
    struct node *prev;
};

void printList(node *n){
    while (n != NULL)
    {
        cout << n->data << " ";
        n = n->next;
    }
    cout << endl;
}

void createList(node **head){
    node *first = new node();
    node *middle = new node();
    node *last = new node();

    first->data = 10;
    first->prev = NULL;
    first->next = middle;
    middle->data = 25;
    middle->next = last;
    middle->prev = first;
    last->data = 40;
    last->next = NULL;
    last->prev = middle;

    (*head) = first;
    printList(first);
}

void insertFirst(node **head, int temp){
    node *newNode = new node();
    newNode->data = temp;
    newNode->next = (*head);
    newNode->prev = NULL;
    (*head) = newNode;
}

void insertAfter(node **head, node *prevNode, int temp){
    node *first = *head;
    if (prevNode == NULL){
        insertFirst(&first, temp);
        return;
    }
    node *newNode = new node();
    newNode->data = temp;
    newNode->next = prevNode->next;
    prevNode->next = newNode;
    newNode->prev = prevNode;
}

void insertLast(node **head, int temp){
    node *newNode = new node();
    node *last = *head;
    newNode->data = temp;
    newNode->next = NULL;
    while (last->next != NULL)
        last = last->next;
    last->next = newNode;
    newNode->prev = last;
}

void deleteFirst(node **head){
    node *temp = *head;
    (*head) = temp->next;
    temp->next = NULL;
    (*head)->prev = NULL;
}

void deleteLast(node **head){
    node *temp = *head;
    while (temp->next != NULL)
        temp = temp->next;
    temp->prev->next = NULL;
    temp->prev = NULL;
}

void deleteAfter(node *prevNode){
    node *temp = prevNode->next;
    prevNode->next = prevNode->next->next;
    prevNode->next->prev = prevNode;
    temp->next = NULL;
    temp->prev = NULL;
}

void searchNode(node **head, int id){
    int currentID = 1;
    node *temp = *head;
    while (temp->next != 0 && currentID != id)
    {
        temp = temp->next;
        currentID++;
    }
    cout << temp->data << " ditemukan pada " << currentID;
}

int main(){
    node *head = NULL;
    createList(&head);
    cout << "Insertion : \n";
    insertFirst(&head, 5);
    insertAfter(&head, head->next->next, 35);
    insertLast(&head, 45);
    printList(head);
    cout << "Deletion  : \n";
    deleteFirst(&head);
    deleteLast(&head);
    deleteAfter(head->next);
    printList(head);
    searchNode(&head, 4);
}
