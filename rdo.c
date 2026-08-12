#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

void print_usage(const char *prog_name) {
    printf("Usage: %s -fm <frequency>\n", prog_name);
    printf("Example: %s -fm 90.8\n", prog_name);
    printf("A simple radio tool for amateur radio enthusiasts.\n");
}

int main(int argc, char *argv[]) {
    double frequency = 0.0;
    int opt;

    while ((opt = getopt(argc, argv, "fm:")) != -1) {
        switch (opt) {
            case 'f':
            case 'm':
                if (optarg) {
                    frequency = atof(optarg);
                }
                break;
            default:
                print_usage(argv[0]);
                exit(EXIT_FAILURE);
        }
    }

    if (frequency > 0) {
        printf("[RDO] Tuning FM radio to %.2f MHz...\n", frequency);
        printf("[RDO] Antenna ready. Happy listening!\n");
    } else {
        print_usage(argv[0]);
        return 1;
    }

    return 0;
}

