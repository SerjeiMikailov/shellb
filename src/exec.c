#include "App.h"

/*
----------------------------------------
|                                      |
|            Deprecated file           |
|                                      |
|          Deprecated in V1.07         |
|                                      |
----------------------------------------
*/

/*
void executeSystemCommand(const char* command)
{
    const char* systemCommand = command + 1;

    FILE* pipe = popen(systemCommand, "r");
    if (!pipe)
    {
        printf("Failed to execute command: %s\n", systemCommand);
        return;
    }

    char buffer[128];
    while (fgets(buffer, sizeof(buffer), pipe) != NULL)
    {
        printf("%s", buffer);
    }

    pclose(pipe);
}
*/
