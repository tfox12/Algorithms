#include <stdio.h>

void
selection_sort(int * list, int length)
{
    int *current_index, *moving_index, *swap_index, minimum;

    current_index = list;

    while(current_index < (list + length))
    {
        minimum = *current_index;
        swap_index = current_index;
        moving_index = current_index + 1;

        while(moving_index < (list + length))
        {
            if(*moving_index < minimum)
            {
                swap_index = moving_index;
                minimum = *moving_index;
            }
            ++moving_index;
        }

        *swap_index = *current_index;
        *current_index = minimum;
        ++current_index;
    }
}

int
main(void)
{
    int list[10] = {0,9,8,7,6,5,4,3,2,1};
    int i = 0;
    selection_sort(list,10);
    for(; i < 10; ++i)
    {
        printf("%i ",list[i]);
    }
    printf("\n");
}
