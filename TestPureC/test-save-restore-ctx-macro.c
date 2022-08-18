#include <stdio.h>
#include <assert.h>
#include <stdlib.h>

#include "xPureCRAII.h"

void testsjljMac()
{
	volatile int ii = 0;

	SML_RAII_SCOPE_BEGIN(regctx, 10);

	SML_RAII_BEGIN(regctx);
	--ii;
	printf("backtrace %d" "\r\n", ii);
	SML_RAII_END(regctx);


	++ii;
	printf("forward %d" "\r\n", ii);


	SML_RAII_BEGIN(regctx);
	--ii;
	printf("backtrace %d" "\r\n", ii);
	SML_RAII_END(regctx);


	++ii;
	printf("forward %d" "\r\n", ii);


	SML_RAII_BEGIN(regctx);
	--ii;
	printf("backtrace %d" "\r\n", ii);
	SML_RAII_END(regctx);


	++ii;
	printf("forward %d" "\r\n", ii);


	SML_RAII_BEGIN(regctx);
	--ii;
	printf("backtrace %d" "\r\n", ii);
	SML_RAII_END(regctx);


	++ii;
	printf("forward %d" "\r\n", ii);


	SML_RAII_BEGIN(regctx);
	--ii;
	printf("backtrace %d" "\r\n", ii);
	SML_RAII_END(regctx);



	SML_RAII_SCOPE_END(regctx, 10);

	printf("end %d" "\r\n", ii);
}


