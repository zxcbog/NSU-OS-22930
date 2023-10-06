#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

main(int argc, char *argv[]) {
    char options[] = "ispuU:cC:dvV:h";  // valid options
    int c = 0;
    //printf("argc equals %d\n", argc);

    while ((c = getopt(argc, argv, options)) != EOF) {
        switch (c) {
        case 'i':
            printf("Real user id: %d\n", getuid());
            printf("Effective user id: %d\n", geteuid());
            printf("Real group id: %d\n", getgid());
            printf("Effective group id: %d\n", getegid());
        case 's':
            setpgid(0, 0);
            break;
        case 'p':
            //system("ps a");
            printf("Process id: %d\n", getpid());
            printf("Parent id: %d\n", getppid());
            printf("Group id: %d\n", getpgrp());
            break;
        case 'u':
        case 'U':
        case 'c':
        case 'C':
        case 'd':
        case 'v':
        case 'V':
            printf("Work in progress!\n");
            break;

        case 'h':
            printf("-i :: Prints real and effective user and group IDs.\n");
            printf("-s :: Process becomes the group leader.\n");
            printf("-p :: Prints the process, parent process, and process group identifiers.\n");
            printf("-u :: Prints the value of ulimit.\n");
            printf("-Unew_ulimit :: Changes the value of ulimit.\n");
            printf("-c :: Prints the size in bytes of the core file that can be created.\n");
            printf("-Csize :: Changes the size of the core file.\n");
            printf("-d :: Prints the current working directory.\n");
            printf("-v :: Prints environment variables and their values.\n");
            printf("-Vname=value :: Introduces a new variable into the environment or changes the value of an existing variable.\n");
            printf("-h :: Prints this help message.\n");
            break;
        case ':':
            printf("Option '%c' requires an argument.\n", optopt);
        default:
            printf("Option '%c' is invalid; use 'h' for help.\n", optopt);
        }
    }
}
