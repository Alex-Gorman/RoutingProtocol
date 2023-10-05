#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char local_router_name = 0;
char *local_router_port = 0;

/*
    This function checks the user input. 

*/
void check_user_input_validity(int argc, char *argv[]) {
    
    if (argc <= 2) {
        printf("Usage: %s RouterNameLetter PortNumber [SendPort1] [SendPort2] ... \n", argv[0]);
        exit(1);
    }

    local_router_port = argv[2];

    if (atoi(local_router_port) < 30000 || atoi(local_router_port) > 40000) {
        printf("Port Number to receive on muse be between 30000 and 40000\n");
        exit(1);
    }

    if (strlen(argv[1]) > 1) {
        printf("The name should only be one letter\n");
        exit(1);
    }

    local_router_name = argv[2][0];
}

int main(int argc, char *argv[]) {

    check_user_input_validity(argc, argv);

    
    return 0;
}