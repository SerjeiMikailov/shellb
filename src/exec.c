#include "App.h"

void executeSystemCommand(const char* command) {
    const char* systemCommand = command + 1;
    int result = system(systemCommand);

    if (result == -1) {
        printf("Erro ao executar o comando: %s\n", command);
    }
}
