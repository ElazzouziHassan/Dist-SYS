/*
 * Please do not edit this file.
 * It was generated using rpcgen.
 */

#include "sqrt.h"

bool_t
xdr_number (XDR *xdrs, number *objp)
{
	register int32_t *buf;

	 if (!xdr_float (xdrs, &objp->x))
		 return FALSE;
	return TRUE;
}
