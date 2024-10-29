#include <stdio.h>
#include <stdlib.h>

void RunProcess(const char* command)
{
    int result = system(command);
    if (result != 0)
    {
        fprintf(stderr, "Error! Command failed with exit code %d: %s\n", result, command);
    }
}
