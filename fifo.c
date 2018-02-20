#include <stdio.h>
#include <stdlib.h>

struct Queue{
    int value;
    struct Queue *next;
};

struct Queue *newQueue(int firstElement){
    struct Queue *q = malloc(sizeof(struct Queue));
    q->next = NULL;
    q->value = firstElement;

    return q;
}

void addToQueue(int value, struct Queue *q){
    if(q == NULL){
        q = newQueue(value);
    }
    else{
        struct Queue *cur = q;

        while(cur->next != NULL){
            cur = cur->next;
        }

        cur->next = malloc(sizeof(struct Queue));
        cur->next->value = value;
        cur->next->next = NULL;
    }
}

int getFromQueue(struct Queue **q){

    if(*q == NULL){
        printf("Queue empty, printing 0...\n");
        return 0;
    }

    int result = (*q)->value;
    struct Queue *temp;
    temp = (*q)->next;

    free(*q);
    *q = temp;


    return result;
}

void deleteFromQueue(struct Queue **q){
    if(*q == NULL){
        return ;
    }
    
    struct Queue *temp;
    temp = (*q)->next;

    free(*q);
    *q = temp;
}

void printQueue(struct Queue *q){
    struct Queue *cur = q;

    printf("[ ");
    while(cur->next != NULL){
        printf("%d ,", cur->value);
        cur = cur->next;
    }

    printf("%d ", cur->value);
    printf("]\n");
}

int main(){
    struct Queue *fifo = newQueue(6);
    addToQueue(7, fifo);
    addToQueue(9, fifo);
    addToQueue(11, fifo);

    printQueue(fifo);

    printf("%d \n", getFromQueue(&fifo));
    printf("%d \n", getFromQueue(&fifo));
    printf("%d \n", getFromQueue(&fifo));
    printf("%d \n", getFromQueue(&fifo));
    printf("%d \n", getFromQueue(&fifo));
    printf("%d \n", getFromQueue(&fifo));

    return 0;
}