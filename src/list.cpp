#include "list.hpp"
#include <stdlib.h>

size_t at(list **data_list, size_t index, size_t _default)
{
    if (! *data_list) return _default;

    for(size_t i = 0; i < index; i++ ) {

        if((*data_list)->next == nullptr) return _default;

        (*data_list) = (*data_list)->next;
    }

    return (*data_list)->data;
}

void push(list **_data_list, size_t data)
{
    if (! *_data_list) (*_data_list) = (struct list* ) malloc(sizeof(struct list));

    list* data_list = *_data_list;

    while (data_list->next) data_list = data_list->next;

    data_list->next = (struct list*) malloc(sizeof(list));
    
    data_list->next->previous = data_list;
    data_list->next->data     = data;
}

size_t pop(list *data_list, size_t _default)
{

    if(! data_list) return _default;


    while (data_list->next) data_list = data_list->next;

    size_t ret_value = data_list->data;
    data_list = data_list->previous;

    free(data_list->next);

    data_list->next = nullptr;

    return ret_value;    
}

void push_front(list **_data_list, size_t data)
{

    if (! *_data_list) {
        (*_data_list) = (struct list *) malloc(sizeof(struct list));
    } else {
        (*_data_list)->previous = (struct list*) malloc(sizeof(struct list));
        (*_data_list)->previous->next = (*_data_list);
        (*_data_list) = (*_data_list)->previous;
    }

    (*_data_list)->data = data;

}

size_t pop_front(list **data_list, size_t _default)
{
    if (! *data_list) return _default;

    size_t return_value = (*data_list)->data;
    
    if (!(*data_list)->next) {
        free((*data_list));
        (*data_list) = nullptr;  
    }else {
        (*data_list) = (*data_list)->next;
        free((*data_list)->previous);
        (*data_list)->previous = nullptr;
    }
    
    return return_value;
}

size_t size(list *data_list)
{
    size_t _size = 0;

    if (!data_list) return _size;

    while(data_list->next) {
        _size++;
        data_list = data_list->next;
    }

    return _size;
}

void foreach (list *data_list, void (*function)(size_t postion, size_t value))
{
    if (! data_list) return;

    size_t position = 0;
    
    function(position,data_list->data);

    while (data_list->next) {
        data_list = data_list->next;
        position ++;

        function(position,data_list->data);
    }
    
}
