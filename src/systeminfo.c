#include "App.h"

#ifdef _WIN32
    #include <windows.h>
#else
    #include <unistd.h>
#endif

void getProcessorInfo(void)
{
#ifdef _WIN32
    // Windows-specific code to get the processor name here
    char processorName[49]; // Adjust the buffer size as needed
    if (GetEnvironmentVariable("PROCESSOR_IDENTIFIER", processorName, 49)) {
        printf("Processor Name: %s\n", processorName);
    } else {
        printf("Failed to retrieve processor name\n");
    }
#else
    FILE* fp = popen("grep 'model name' /proc/cpuinfo | uniq | cut -d ':' -f 2", "r");
    if (fp == NULL) {
        perror("Error executing command");
        return;
    }

    char processorName[1024]; // Adjust the buffer size as needed
    if (fgets(processorName, sizeof(processorName), fp)) {
        // Remove the trailing newline character
        processorName[strcspn(processorName, "\n")] = '\0';
        printf("Processor Name: %s\n", processorName);
    } else {
        printf("Failed to retrieve processor name\n");
    }

    pclose(fp);
#endif
}

void getProcessorCores(void)
{
#ifdef _WIN32
    SYSTEM_INFO sysInfo;
    GetSystemInfo(&sysInfo);
    printf("Number of Cores: %u\n", sysInfo.dwNumberOfProcessors);
#else
    FILE* fp = popen("nproc", "r");
    if (fp == NULL)
    {
        perror("Error executing command");
        return;
    }

    char cores[256];
    if (fgets(cores, sizeof(cores), fp))
    {
        printf("Number of Cores: %s", cores);
    }

    pclose(fp);
#endif
}

void print_processor_arch(void) {
    #if defined(__x86_64__)
        printf("Processor Architecture: x86-64\n");
    #elif defined(__i386__)
        printf("Processor Architecture: x86 (32-bit)\n");
    #elif defined(__aarch64__)
        printf("Processor Architecture: ARM64\n");
    #elif defined(__arm__)
        printf("Processor Architecture: ARM\n");
    #elif defined(__ppc64__)
        printf("Processor Architecture: PowerPC64\n");
    #elif defined(__ppc__)
        printf("Processor Architecture: PowerPC\n");
    #else
        printf("Processor Architecture: Unknown\n");
    #endif
}

void print_memory_usage(void) {
    struct rusage usage;
    if (getrusage(RUSAGE_SELF, &usage) == 0) {
        long ram_usage = usage.ru_maxrss;
        printf("Memory usage: %ld KB\n", ram_usage);
    } else {
        puts("Failed to retrieve memory usage");
    }
}

char* get_user(void) {
    return getenv("USER");
}

