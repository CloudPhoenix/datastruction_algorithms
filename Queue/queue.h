#include <stdio.h>

typedef struct QNode{
  int data;
  struct QNode *next;
}QNode, *QueuePtr;

typedef struct {
  QueuePtr front;
  QueuePtr rear;
}LinkQueue;

