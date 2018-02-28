#include <stdio.h>
#include <stdlib.h>

struct Node{
    struct Node *prev;
    int value;
};

struct Queue{
    struct Node *tail;
    struct Node *head;
};

struct Queue *newQueue(){
    struct Queue *q = malloc(sizeof(struct Queue));
    q->tail = NULL;
    q->head = NULL;

    return q;
}

void addToQueue(int nValue, struct Queue *q){
    if(q->tail == NULL){

        struct Node *newValue = malloc(sizeof(struct Node));

        newValue->value = nValue;

        newValue->prev = NULL;

        q->tail = newValue;
        q->head = newValue;
    }
    else{
        struct Node *newValue = malloc(sizeof(struct Node));
        newValue->value = nValue;
        newValue->prev = NULL;
        q->tail->prev = newValue;
        q->tail = newValue;

    }
}

int getFromQueue(struct Queue *q){

    if(q->head == NULL){
        printf("Queue empty, printing 0...\n");
        return 0;
    }

    struct Node *temp = q->head;

    int result = temp->value;
    q->head = temp->prev;

    if(q->tail == temp){
        q->tail = NULL;
    }

    free(temp);


    return result;
}

int main(){
    struct Queue *fifo = newQueue();
    addToQueue(7, fifo);
    addToQueue(9, fifo);
    addToQueue(11, fifo);

    printf("%d \n", getFromQueue(fifo));
    printf("%d \n", getFromQueue(fifo));
    printf("%d \n", getFromQueue(fifo));
    printf("%d \n", getFromQueue(fifo));
    printf("%d \n", getFromQueue(fifo));
    addToQueue(7, fifo);
    addToQueue(9, fifo);
    addToQueue(11, fifo);
    printf("%d \n", getFromQueue(fifo));

    return 0;
}