/*
 * This is sample code generated by rpcgen.
 * These are only templates and you can use them
 * as a guideline for developing your own functions.
 */

#include "add.h"


void
add_prog_1(char *host)
{
	CLIENT *clnt;
	int  *result_1;
	numbers  add_1_arg;

#ifndef	DEBUG
	clnt = clnt_create (host, ADD_PROG, ADD_VERS, "udp");
	if (clnt == NULL) {
		clnt_pcreateerror (host);
		exit (1);
	}
#endif	/* DEBUG */

	printf("Saisir un 1er entier: ");
	scanf("%d", &add_1_arg.a);
	printf("Saisir un 2eme entier: ");
	scanf("%d", &add_1_arg.b);

	result_1 = add_1(&add_1_arg, clnt);
	if (result_1 == (int *) NULL) {
		clnt_perror (clnt, "call failed");
	}else{
		printf("La somme de %d et %d est: %d", add_1_arg.nbr1,add_1_arg.nbr2,*result_1);
	}
#ifndef	DEBUG
	clnt_destroy (clnt);
#endif	 /* DEBUG */
}


int
main (int argc, char *argv[])
{
	char *host;

	if (argc < 2) {
		printf ("usage: %s server_host\n", argv[0]);
		exit (1);
	}
	host = argv[1];
	add_prog_1 (host);
exit (0);
}
