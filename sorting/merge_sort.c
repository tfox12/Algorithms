#include <stdlib.h>
#include <stdio.h>

int * 
merge_sort_make_left_list(int * list, int length)
{
    int * left_list, left_length, index;

    left_length = length / 2;
    left_list = (int *) calloc(left_length,sizeof(int));

    for(index = 0; index < left_length; ++index)
    {
        left_list[index] = list[index];
    }

    return left_list;
}

int *
merge_sort_make_right_list(int * list, int length)
{
    int * right_list, right_length, index;

    right_length = length - length / 2;
    right_list = (int *) calloc(right_length, sizeof(int));

    for(index = 0; index < right_length; ++index)
    {
        right_list[index] = list[length / 2 + index];
    }

    return right_list;
}

void
merge_sort_merge(int * list, int * left_list, int * right_list, int length)
{
    int list_index, left_index, right_index;

    list_index = length;
    left_index = length / 2;
    right_index = length - length / 2;

    while(list_index)
    {
        if(!left_index)
        {
            list[list_index - 1] = right_list[right_index-- - 1];
        }
        else if(!right_index)
        {
            list[list_index - 1] = left_list[left_index-- - 1];
        }
        else
        {
            list[list_index - 1] = (left_list[left_index - 1] > right_list[right_index - 1])
                             ? left_list[left_index-- - 1]
                             : right_list[right_index-- - 1];
        }

        --list_index;
    }
}

void
merge_sort(int * list, int length)
{
    int * left_list, *right_list, i;
    
    if(length <= 1) return;

    printf("sorting list: %i", list[0]);
    for(i = 1; i < length; ++i)
        printf(", %i", list[i]);
    printf("\n");

    left_list = merge_sort_make_left_list(list, length);
    right_list = merge_sort_make_right_list(list, length);
    
    merge_sort(left_list, length / 2);
    merge_sort(right_list, length - length / 2);
    merge_sort_merge(list,left_list,right_list,length);

    free(left_list);
    free(right_list);
}

int
main(void)
{
    int list[10] = {2,4,3,1,7,3,4,9,7,8};
    int i = 0;
    merge_sort(list,10);
    for(;i < 10; ++i) printf("%i ",list[i]);
    printf("\n");
}
