#include <stdio.h>

void
insertion_sort_place_element(int * list, int *index)
{
    int tmp;
    while(index > list && *index < *(index - 1))
    {
        tmp = *index;
        *index = *(index-1);
        *(index-1) = tmp;
        --index;
    }
}

void
insertion_sort(int * list, int length)
{
    int *current_index = list + 1;
    while(current_index < list + length)
    {
        insertion_sort_place_element(list,current_index);
        ++current_index;
    }
}

int
main(void)
{
    int list[10] = {0,9,8,7,6,5,4,3,2,1};
    int i = 0;
    insertion_sort(list,10);
    for(; i < 10; ++i)
        printf("%i ",list[i]);
    printf("\n");
}
