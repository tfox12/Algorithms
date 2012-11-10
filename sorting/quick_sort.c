#include <stdlib.h>
#include <stdio.h>

typedef struct
{
    int * elements;
    int length;
} list;

int
quick_sort_compute_partition_size(list l, int * pivot, int (*comparator)(int,int))
{
    int *list_itor, partition_size = 0;

    for(list_itor = l.elements; 
        list_itor < l.elements + l.length; 
        ++list_itor)
    {
        if( list_itor != pivot && comparator(*list_itor,*pivot) )
        {
            ++partition_size;
        }
    }

    return partition_size;
}

void
quick_sort_fill_partition(list l, list list_partition, int * pivot, int (*comparator)(int,int))
{
    int *list_itor, *partition_itor;
    
    for(list_itor = l.elements, partition_itor = list_partition.elements; 
        list_itor < l.elements + l.length; 
        ++list_itor)
    {
        if( list_itor != pivot && comparator(*list_itor,*pivot) )
        {
            *(partition_itor++) = *list_itor;
        }
    }
}

list
quick_sort_partition_list(list l, int * pivot, int (*comparator)(int,int))
{
    int *list_itor, *partition_itor, partition_size;
    list list_partition;

    partition_size = quick_sort_compute_partition_size(l,pivot,comparator);

    list_partition.length = partition_size;
    list_partition.elements = (int *) calloc(partition_size, sizeof(int));
    
    quick_sort_fill_partition(l,list_partition,pivot,comparator);

    return list_partition;
}

int
quick_sort_left_comparator(int a, int b)
{
    return a <= b;
}

int
quick_sort_right_comparator(int a, int b)
{
    return a > b;
}

void
quick_sort(list l)
{
    list left, right;
    int *pivot, pivot_value, left_index, right_index, list_index;

    if(l.length <= 1) return;

    pivot = l.elements;
    left = quick_sort_partition_list(l, pivot, quick_sort_left_comparator);
    right = quick_sort_partition_list(l, pivot, quick_sort_right_comparator);

    quick_sort(left);
    quick_sort(right);

    for(list_index = 0, left_index = 0, pivot_value = *pivot;
        left_index < left.length;
        ++list_index, ++left_index)
    {
        l.elements[list_index] = left.elements[left_index];
    }

    l.elements[list_index++] = pivot_value;

    for(right_index = 0; right_index < right.length; ++list_index, ++right_index)
    {
        l.elements[list_index] = right.elements[right_index];
    }

    free(left.elements);
    free(right.elements);
}

int
main(void)
{
    int l[10] = {3,6,5,1,0,8,6,4,6,2}, i;
    list lst = {l,10};
    quick_sort(lst);
    for(i = 0 ; i < 10; ++i) printf("%i ", lst.elements[i]);
    printf("\n");
}
