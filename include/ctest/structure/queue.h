/**
 * File containing a generic queue.
 *
 * @author Matheus Nogueira
 * @version 1.0
 */
#ifndef STRUCTURE_QUEUE_H
#define STRUCTURE_QUEUE_H

#include <ctest/types.h>

// Foward declaration for the QueueNode, which is a private structure
struct CTest_QueueNode;

// Foward declaration for the queue of functions
struct CTest_FQueueNode;

/**
 * Structure used to store all the nodes of the queue.
 */
struct CTest_Queue {
    struct CTest_QueueNode* top; ///< Next element that will be removed from the queue.
};

/**
 * Struture used to store all the nodes of the queue (functions).
 */
struct CTest_FQueue {
    struct CTest_FQueueNode* top;
};

/**
 * Create a new queue.
 * @return reference to the new queue.
 */
struct CTest_Queue* CTest_Queue_New();

/**
 * Add an object to the queue.
 * @param queue queue that will store the object.
 * @param object reference to the object.
 */
void CTest_Queue_Add(struct CTest_Queue* queue, void* object);

/**
 * Get the next object from the queue.
 * @param queue reference to the queue that will be popped.
 * @return reference to the object.
 */
void* CTest_Queue_Pop(struct CTest_Queue* queue);

/**
 * Create a new queue.
 * @return reference to the new queue.
 */
struct CTest_FQueue* CTest_FQueue_New();

/**
 * Add an object to the queue.
 * @param queue queue that will store the object.
 * @param object reference to the object.
 */
void CTest_FQueue_Add(struct CTest_FQueue* queue, struct CTest_FunctionMap* object);

/**
 * Get the next object from the queue.
 * @param queue reference to the queue that will be popped.
 * @return reference to the object.
 */
struct CTest_FunctionMap* CTest_FQueue_Pop(struct CTest_FQueue* queue);

#endif
