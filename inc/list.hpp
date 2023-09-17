#ifndef __LIST__
#define __LIST__

#include <cstddef>

struct list {
    list* previous;
    size_t  data;
    list* next;        
};
/**
 * @brief provides the value held in the list or returns the default.
 * 
 * @param data_list 
 * @param index 
 * @param default
 * @return size_t 
 */
size_t at         (list** data_list, size_t index, size_t _default = 0);

/**
 * @brief creates a new node in the list and pushes to the end of the list.
 * 
 * @param data_list 
 * @param data 
 */
void   push       (list** data_list, size_t data);

/**
 * @brief removes the last element in the list and returns its value.
 * 
 * @param data_list 
 * @return size_t 
 */
size_t pop        (list** data_list, size_t _default = 0);

/**
 * @brief creates a new node and addes to the start of the list 
 * 
 * @param data_list 
 * @param data 
 * @return size_t 
 */
void push_front (list** data_list, size_t data);

/**
 * @brief this removes the first value from the list and returns or returns the 
 *        if the list is empty
 * 
 * @param data_list 
 * @return size_t 
 */
size_t pop_front  (list** data_list, size_t _default = 0);

/**
 * @brief return the length of the given list 
 * 
 * @param data_list 
 * @return size_t 
 */
size_t size       (list* data_list);

/**
 * @brief runs the given function on every node in the list.
 * 
 * @param data_list 
 * @param function 
 */
void foreach      (list* data_list,
                   void (*function) (size_t postion,size_t value));

#endif