#ifndef __vector__
#define __vector__

#include <cstddef>

struct vector {
    size_t*  data;
    size_t   length;
};
/**
 * @brief provides the value held in the vector or returns the default.
 * 
 * @param data_vector 
 * @param index 
 * @param default
 * @return size_t 
 */
size_t at         (vector* data_vector, size_t index, size_t _default = 0);

/**
 * @brief creates a new node in the vector and pushes to the end of the vector.
 * 
 * @param data_vector 
 * @param data 
 */
void   push       (vector* data_vector, size_t data);

/**
 * @brief removes the last element in the vector and returns its value.
 * 
 * @param data_vector 
 * @return size_t 
 */
size_t pop        (vector* data_vector, size_t _default = 0);

/**
 * @brief creates a new node and addes to the start of the vector 
 * 
 * @param data_vector 
 * @param data 
 */
void push_front (vector* data_vector, size_t data);

/**
 * @brief this removes the first value from the vector and returns or returns the 
 *        if the vector is empty
 * 
 * @param data_vector 
 * @return size_t 
 */
size_t pop_front  (vector* data_vector);

/**
 * @brief return the length of the given vector 
 * 
 * @param data_vector 
 * @return size_t 
 */
size_t size       (vector* data_vector);

/**
 * @brief runs the given function on every node in the vector.
 * 
 * @param data_vector 
 * @param function 
 */
void foreach      (vector* data_vector,
                   void (*function) (size_t postion,size_t value));

#endif