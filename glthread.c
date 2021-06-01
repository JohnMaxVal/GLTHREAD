#include "glthread.h"
#include <stdlib.h>

void
init_glthread(glthread* glthread, uint32 offset) {
  glthread->head = NULL;
  glthread->offset = offset;
}

void
glthread_add(glthread* glthread, glthread_node* node) {
  if(glthread == NULL || node == NULL)
    return;
  
  glthread_node** head = &glthread->head;
  
  if(*head == NULL) {
    *head = node;
    return;
  }

  if((*head)->right == NULL) { // the second node
    (*head)->right = node;
    node->left = *head;
    return;
  }

  glthread_node* tmp = (*head)->right;
  (*head)->right = node;
  node->left = *head;
  node->right = tmp;
  tmp->left = node;
}

void
glthread_remove(glthread* thread, glthread_node* node) {
  if(thread == NULL || node == NULL)
    return;

  glthread_node** head = &thread->head;

  if(*head == node) {
    *head = (*head)->right;
    return;
  }

  if(node->right == NULL) {
    node->left->right = NULL;
    node->left = NULL;
    free(node);
    return;
  }

  node->left->right = node->right;
  node->right->left = node->left;
  node->right = NULL;
  node->left = NULL;
  free(node);
}
