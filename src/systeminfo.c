#include "App.h"

#ifdef _WIN32
    #include <windows.h>
#else
    #include <unistd.h>
#endif

void print_os(void) {
#ifdef _WIN32
    OSVERSIONINFO osvi;
    ZeroMemory(&osvi, sizeof(OSVERSIONINFO));
    osvi.dwOSVersionInfoSize = sizeof(OSVERSIONINFO);
    if (GetVersionEx(&osvi)) {
        if (osvi.dwMajorVersion == 10) {
            printf("Operating System: Windows 10\n");
        } else if (osvi.dwMajorVersion == 6 && osvi.dwMinorVersion == 3) {
            printf("Operating System: Windows 8.1\n");
        } else if (osvi.dwMajorVersion == 6 && osvi.dwMinorVersion == 2) {
            printf("Operating System: Windows 8\n");
        } else if (osvi.dwMajorVersion == 6 && osvi.dwMinorVersion == 1) {
            printf("Operating System: Windows 7\n");
        } else {
            printf("Operating System: Windows (Version %d.%d)\n", osvi.dwMajorVersion, osvi.dwMinorVersion);
        }
    } else {
        printf("Operating System: Unknown\n");
    }
#else
    FILE *os_release = fopen("/etc/os-release", "r");
    if (os_release == NULL) {
        printf("Operating System: Unknown\n");
        return;
    }
    char line[256];
    while (fgets(line, sizeof(line), os_release)) {
        if (strstr(line, "PRETTY_NAME")) {
            char *start = strchr(line, '"');
            if (start) {
                char *end = strrchr(start + 1, '"');
                if (end) {
                    *end = '\0';
                    printf("Operating System: %s\n", start + 1);
                    fclose(os_release);
                    return;
                }
            }
        }
    }
    fclose(os_release);
    printf("Operating System: Unknown\n");
#endif
}

void getProcessorInfo(void)
{
#ifdef _WIN32
    char processorName[49]; 
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
    char processorName[1024];
    if (fgets(processorName, sizeof(processorName), fp)) {
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

