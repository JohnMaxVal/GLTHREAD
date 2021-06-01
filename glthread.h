#ifndef __GLUE_THREAD__
#define __GLUE_THREAD__

typedef unsigned int uint32;

#define offsetof(struct_name, field_name) \
  ((uint32)&((struct_name *)0)->field_name)

#define ITERATE_GLTHREAD_BEGIN(listptr, struct_type, node_ptr) \
  {\
    glthread_node* head = NULL, *next = NULL;\
    for(head = listptr->head; head != NULL; head = next) {\
      next = head->right;\
      node_ptr = (struct_type *)((char *)head - listptr->offset);

#define ITERATE_GLTHREAD_END }}

#define glthread_node_default_init(glnode)\
  glnode->left = NULL;\
  glnode->right = NULL;

typedef struct glthread_node_ {
  struct glthread_node_* left;
  struct glthread_node_* right;
} glthread_node;

typedef struct glthread_ {
  glthread_node* head;
  uint32 offset;
} glthread;

void
init_glthread(glthread* glthread, uint32 offset);

void
glthread_add(glthread* t, glthread_node* node);

void
glthread_remove(glthread* t, glthread_node* node); 

#endif
