#include <stdio.h>
#include <stdlib.h>
#include "towers.h"

int main(int argc, char **argv)
{
    int n = 3;
    int from = 1;
    int dest = 2;

    if (argc >= 5){
	    fprintf(stderr, "N/A .\n");
	    exit(1);
    
    } else if (argc == 4) {
	    n = atoi(argv[1]);
	    from = atoi(argv[2]);
	    dest = atoi(argv[3]);

	    if (from < 1 || from > 3) {
		fprintf(stderr, "argc[2] !>= 3.\n");
		exit(1);
	    } else if (dest < 1 || dest > 3) {
		fprintf(stderr, "argc[3]!>=3.\n");
		exit(1);
	    } else if (from == dest){
	      fprintf(stderr,"argc[2] = argc[3]");
	    } else {
		towers(n, from, dest);
	    }
    } else if (argc == 3) {
	    fprintf(stderr, "WE DO NOT CARE\n");
	    exit(1);
    } else if (argc == 2) {
	    n = atoi(argv[1]);
		towers(n, from, dest);
    } else if(argc ==1) {
        towers(n, from, dest);
    }
    exit(0);
}

