#include <stdlib.h>
#include "stack.h"


struct Node {
    struct Node* next;
    void* data;
};

struct StackImplementation {
    struct Node* head;
    int count;
};

Stack create_stack() {
    Stack stack = (Stack) smalloc(sizeof(StackImplementation));
    stack->head = 0;
    stack->count = 0;
    return stack;
}

void delete_stack(Stack stack) {
    struct Node* node = stack->head;
    while (node != 0) {
        Node *tmp = node;
        node = node->next;
        sfree(tmp);
    }
    sfree(stack);
}

void push_stack(Stack stack, void *data) {
    Node* new_node = (Node*) smalloc(sizeof(Node));
    new_node->data = data;
    new_node->next = stack->head;
    stack->head = new_node;
    stack->count++;
}

int get_count(Stack stack) {
    return stack->count;
}

void* pop_stack(Stack stack) {
    if (get_count(stack) == 0){
        return 0;
    }
    Node* top = stack->head;
    stack->head = top->next;
    stack->count--;
    void* data = top->data;
    sfree(top);
    return data;
}

void* peek_stack(Stack stack) {
    if (get_count(stack) == 0){
        return 0;
    }
    return stack->head->data;
}
