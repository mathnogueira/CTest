#include <ctest/structure/queue.h>
#include <ctest/types.h>
#include <stdlib.h>

/**
 * Structure used to store information about the nodes.
 */
struct CTest_QueueNode {
    void* content;
    struct CTest_QueueNode* next;
};

/**
 * Structure used to store a pointer to the actual information of the node
 * and to store the next node after this one.
 */
struct CTest_FQueueNode {
    struct CTest_FunctionMap* content;       // Content of the node
    struct CTest_FQueueNode* next;           // Next node
};

// Create a new queue.
struct CTest_Queue* CTest_Queue_New() {
    struct CTest_Queue* queue = (struct CTest_Queue*) malloc(sizeof(struct CTest_Queue));
    queue->top = NULL;
    return queue;
}

struct CTest_FQueue* CTest_FQueue_New() {
    struct CTest_FQueue* queue = (struct CTest_FQueue*) malloc(sizeof(struct CTest_FQueue));
    queue->top = NULL;
    return queue;
}

void CTest_Queue_Add(struct CTest_Queue* queue, void* object) {
    struct CTest_QueueNode* node = (struct CTest_QueueNode*) malloc(sizeof(struct CTest_QueueNode));
    node->content = object;
    node->next = NULL;
    if (queue->top == NULL)
        queue->top = node;
    else {
        struct CTest_QueueNode* last = queue->top;
        for (; last->next != NULL; last = last->next);
        last->next = node;
    }
}

// Add an object to the queue.
void CTest_FQueue_Add(struct CTest_FQueue* queue, struct CTest_FunctionMap* object) {
    struct CTest_FQueueNode* node = (struct CTest_FQueueNode*) malloc(sizeof(struct CTest_FQueueNode));
    node->content = object;
    node->next = NULL;
    if (queue->top == NULL)
        queue->top = node;
    else {
        struct CTest_FQueueNode* last = queue->top;
        for (; last->next != NULL; last = last->next);
        last->next = node;
    }
}

// Pop an object from the queue
struct CTest_FunctionMap* CTest_FQueue_Pop(struct CTest_FQueue* queue) {
    struct CTest_FQueueNode* top = queue->top;
    queue->top = top->next;
    return top->content;
}

void* CTest_Queue_Pop(struct CTest_Queue* queue) {
    struct CTest_QueueNode* top = queue->top;
    queue->top = top->next;
    return top->content;
}
