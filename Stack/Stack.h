/*
 * @Author: AGOGIN 
 * @Date: 2019-07-28 16:08:28 
 * @Last Modified by:   AGOGIN 
 * @Last Modified time: 2019-07-28 16:08:28 
 */
#ifndef _STACK_H
#define _STACK_H

typedef int ElementType;
struct Node;
typedef struct Node *PtrToNode;
typedef PtrToNode Stack;

int IsEmpty(Stack S);
Stack CreateStack(void);
void DisposeStack(Stack S);
void MakeEmpty(Stack S);
void push(ElementType X, Stack S);
ElementType Top(Stack S);
void pop(Stack S);

#endif

struct Node {
          ElementType ELement;
          PtrToNode Next;
};