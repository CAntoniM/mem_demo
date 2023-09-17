#include "vector.hpp"
#include "stdlib.h"

void dealloc(vector* vec, size_t size) {
}

size_t at(vector *data_vector, size_t index, size_t _default)
{
    if(index >= data_vector->length) return _default;

    return data_vector->data[index];
}

void push(vector *data_vector, size_t data)
{
     size_t* new_memory = (size_t*) malloc(sizeof(size_t)*( data_vector->length + 1));
    
    for (size_t index = 0; index < data_vector->length + 1 ; index++) {
        new_memory[index] = data_vector->data[index];
    }

    free(data_vector->data);

    data_vector->data = new_memory;
    data_vector->length++;
    data_vector->data[data_vector->length-1] = data;
}

size_t pop(vector *data_vector, size_t _default)
{
    size_t return_value = data_vector->data[data_vector->length - 1 ];
    
    if (data_vector->length - 1 < 0) return return_value;

    size_t* new_memory = (size_t*) malloc(sizeof(size_t) * (data_vector->length - 1));
    
    for (size_t index = 0; index < data_vector->length - 1; index ++ ) {
        new_memory[index] = data_vector->data[index];
    }

    free(data_vector->data);
    data_vector->data = new_memory;
    data_vector->length --;

    return return_value;
}

void push_front(vector *data_vector, size_t data)
{
    size_t* new_memory = (size_t*) malloc(sizeof(size_t) * (data_vector->length + 1 ));
    
    for (size_t index = 1; index < data_vector->length + 1; index ++ ) {
        new_memory[index] = data_vector->data[index];
    }

    free(data_vector->data);
    data_vector->data = new_memory;
    data_vector->length --;

    data_vector->data[0] = data;
}

size_t pop_front(vector *data_vector)
{
    size_t return_value = data_vector->data[0];
    
    if (data_vector->length - 1 < 0) return return_value;

    size_t* new_memory = (size_t*) malloc(sizeof(size_t) * (data_vector->length - 1));
    
    for (size_t index = 1; index < data_vector->length; index ++ ) {
        new_memory[index] = data_vector->data[index];
    }

    free(data_vector->data);
    data_vector->data = new_memory;
    data_vector->length --;

    return return_value;
}

size_t size(vector *data_vector)
{
    return data_vector->length;
}

void foreach (vector *data_vector, void (*function)(size_t postion, size_t value))
{
    for(size_t i = 0; i < data_vector->length; i++) {
        function(i,data_vector->data[i]);
    }
}
