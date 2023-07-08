#include "App.h"

void executeSystemCommand(const char* command) {
    const char* systemCommand = command + 1;
    int result = system(systemCommand);

    if (result == -1) {
        printf("Error: %s\n", command);
    }
}
