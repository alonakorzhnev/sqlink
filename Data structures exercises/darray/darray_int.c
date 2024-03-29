#include "darray_int.h"
#include <stdlib.h>
#include <stdio.h>

static void swap(int* x, int* y)
{
	int temp;
	temp = *x;
	*x = *y;
	*y = temp;
}

struct darray
{
    int* arr;
    size_t index;
    size_t capacity;
    size_t initial_capacity;
};

AdtStatus darrayCreate(darray **dArr, size_t initial_capacity)
{
    *dArr = (darray*)malloc(sizeof(darray));

    if(*dArr == NULL)
    {
        return AllocationError;
    }

    (*dArr)->arr = (int*)malloc(initial_capacity*sizeof(int));

    if((*dArr)->arr == NULL)
    {
        free(*dArr);
        return AllocationError;
    }

    (*dArr)->index = 0;
    (*dArr)->capacity = initial_capacity;
    (*dArr)->initial_capacity = initial_capacity;

    return OK;
}

AdtStatus darrayDestroy(darray *dArr)
{
    if(dArr == NULL)
    {
        return AllocationError;
    }

    free(dArr->arr);
    free(dArr);

    return OK;
}

AdtStatus   darrayAdd(darray *dArr,  int  _item)
{
    int *temp;

    if(dArr == NULL)
    {
        return AllocationError;
    }

    if(dArr->index == dArr->capacity)
    {
        temp = dArr->arr;
        dArr->arr = (int*)realloc(dArr->arr, (dArr->capacity*2)*sizeof(int));

        if(dArr->arr == NULL)
        {
            dArr->arr = temp;
            return AllocationError;
        }

        (dArr->capacity) *= 2;
    }

    dArr->arr[dArr->index] = _item;
    (dArr->index)++;

    return OK;
}

AdtStatus   darrayDelete(darray *dArr,  int *_item)
{
    int *temp;

    if(dArr == NULL)
    {
        return AllocationError;
    }

    if((dArr->index == dArr->capacity*3/8) && (dArr->capacity != dArr->initial_capacity))
    {
        temp = dArr->arr;
        dArr->arr = (int*)realloc(dArr->arr, (dArr->capacity/2)*sizeof(int));

        if(dArr->arr == NULL)
        {
            dArr->arr = temp;
            return AllocationError;
        }

        (dArr->capacity) /= 2;
    }

    (dArr->index)--;
    *_item = dArr->arr[dArr->index];    

    return OK;
}

AdtStatus   darrayGet(darray *dArr, size_t _index, int *_item)
{
    if(dArr == NULL)
    {
        return AllocationError;
    }

    *_item = dArr->arr[_index];
    
    return OK;
}

AdtStatus   darraySet(darray *dArr, size_t _index, int  _item)
{
    if(dArr == NULL)
    {
        return AllocationError;
    }

    dArr->arr[_index] = _item;
    
    return OK;
}

AdtStatus   darrayItemsNum(darray *dArr, int*  _numOfItems)
{
    if(dArr == NULL)
    {
        return AllocationError;
    }

    *_numOfItems = dArr->index;
    
    return OK;
}

AdtStatus darraySort(darray *dArr)
{
    int i, j;	
    size_t size = dArr->index;

    if(dArr == NULL)
    {
        return AllocationError;
    }
	
	for(i = 0; i < size - 1; ++i)
	{
		for(j = 0; j < size - 1 - i; ++j)
		{
			if(dArr->arr[j] > dArr->arr[j + 1])
			{
				swap(&dArr->arr[j], &dArr->arr[j + 1]);
			}
		}		
	}

    return OK;
}

