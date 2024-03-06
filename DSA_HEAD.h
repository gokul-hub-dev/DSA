#ifndef DSA_HEAD_H
#define DSA_HEAD_H
#include <stdio.h>
#include <conio.h>
#include <stdint.h>
#include <stdlib.h>
#define print 

// #define stack
// #define single_linked_list
// #define double_linked_list
// #define queue
// #define circular_queue
#define binary_search_tree
#define graph

#if defined stack
#define CAPACITY 10
extern int stack_array[CAPACITY];
extern int Top_Index,Index_Size;
extern uint8_t Push(int *);
extern uint8_t Pop(); 
extern void Show(); 
#endif

#if defined single_linked_list
extern uint8_t SLL_create(int );
extern void SLL_display();
extern uint8_t SLL_insert_begin(int );
extern uint8_t SLL_insert_end(int );
extern uint8_t SLL_delete_begin();
extern uint8_t SLL_delete_end();
extern uint8_t SLL_insert_pos(int ,int );
extern uint8_t SLL_delete_pos(int );
extern uint8_t SLL_search(int );
#endif

#if defined double_linked_list
extern uint8_t DLL_insert_begin(int );
extern uint8_t DLL_insert_end(int );
extern uint8_t DLL_delete_begin();
extern uint8_t DLL_delete_end();
extern uint8_t DLL_insert_pos(int ,int );
extern uint8_t DLL_delete_pos(int );
extern void DLL_RwDisplay();
extern void DLL_FwDisplay();
#endif

#if defined queue
extern uint8_t enqueue(int );
extern int dequeue();
extern uint8_t q_show();
#endif

#if defined circular_queue
extern uint8_t c_enqueue(int );
extern int c_dequeue();
#endif

#if defined binary_search_tree
extern uint8_t BST_creation(int );
extern uint8_t BST_insertion(int );
extern int BST_search(int );
extern uint8_t BST_deletion(int );
#endif

#endif