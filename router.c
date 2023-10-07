#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdint.h>

typedef uint32_t route_cost_t;

char local_router_name = 0;
char *local_router_port_number = 0;

#define MAX_REMOTE_ROUTER_CONNECTIONS 26

char *remote_port[MAX_REMOTE_ROUTER_CONNECTIONS];

struct routing_table_entry {
    char remote_router_name;
    route_cost_t remote_router_cost;
    char remote_router_next_hop;
};

struct routing_table_entry routing_table[MAX_REMOTE_ROUTER_CONNECTIONS];

void initialize(void) {
    routing_table[0].remote_router_name = local_router_name;
    routing_table[0].remote_router_cost = 0;
    routing_table[0].remote_router_next_hop = 0;

    /* Go through the entire routing rable and initialize the values*/
}

/*
    This function prints the routing table with the info to stdout
*/
void print_routing_table(void) {
    printf("\n\n");
    printf("Routing table for Local Router %c, with Port Number %s.\n", local_router_name, local_router_port_number);
    printf("Destination Router\t Route Cost\t NextHop\n");




    printf("\n\n");
}

/*
    This function checks the user input. 

*/
void check_user_input_validity(int argc, char *argv[]) {
    
    /* Too few arguments */
    if (argc <= 2) {
        printf("Usage: %s RouterNameLetter PortNumber [SendPort1] [SendPort2] ... \n", argv[0]);
        exit(1);
    }

    /* Set the port number the local router will be listening on*/
    local_router_port_number = argv[2];

    /* Port number for local router to listen on should be between 30,000 and 40,000 */
    if (atoi(local_router_port_number) < 30000 || atoi(local_router_port_number) > 40000) {
        printf("Port Number to receive on muse be between 30000 and 40000\n");
        exit(1);
    }

    /* The local router name should only be one character */
    if (strlen(argv[1]) > 1) {
        printf("The name should only be one letter\n");
        exit(1);
    }

    /* Set the local router name */
    local_router_name = argv[1][0];
}

int main(int argc, char *argv[]) {

    /* Check the validity of the user input */
    check_user_input_validity(argc, argv);

    /* Initialize the router table */
    initialize();


    print_routing_table();

    
    return 0;
}