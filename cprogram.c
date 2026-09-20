#include <stdio.h>
#include <stdlib.h>

int initialized_global = 66;
const int read_only_global = 1010;
int uninitialized_global;

void foo(void)
{
    int local_value = 1;

    printf("Address of local_value: %p\n", (void *)&local_value);
}

int main(void)
{
    char stack_buffer[64];
    char *heap_buffer = malloc(sizeof stack_buffer);

    if (heap_buffer == NULL)
    {
        fprintf(stderr, "Unable to allocate heap buffer.\n");
        return EXIT_FAILURE;
    }

    printf("Enter text: ");
    if (fgets(stack_buffer, sizeof stack_buffer, stdin) == NULL)
    {
        free(heap_buffer);
        return EXIT_FAILURE;
    }

    snprintf(heap_buffer, sizeof stack_buffer, "%s", stack_buffer);

    printf("\nInput: %s", heap_buffer);
    printf("Address of read_only_global:  %p\n", (void *)&read_only_global);
    printf("Address of initialized_global: %p\n", (void *)&initialized_global);
    printf("Address of uninitialized_global: %p\n", (void *)&uninitialized_global);
    printf("Address of heap_buffer:       %p\n", (void *)heap_buffer);
    printf("Address of stack_buffer:      %p\n", (void *)stack_buffer);
    printf("Address of stack_buffer[0]:   %p\n", (void *)&stack_buffer[0]);
    printf("Address of stack_buffer[1]:   %p\n", (void *)&stack_buffer[1]);
    printf("Stack buffer offset [1]:      %td bytes\n",
           (char *)&stack_buffer[1] - (char *)&stack_buffer[0]);

    foo();
    free(heap_buffer);
    return EXIT_SUCCESS;
}