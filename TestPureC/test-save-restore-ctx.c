#include <stdio.h>
#include <assert.h>
#include <stdlib.h>

#include "tRegContext.h"

extern unsigned long long xSaveRegCtx(volatile void* bufferRcx, unsigned long long dummyRdx, unsigned long long dummyR8, unsigned long long dummyR9);
extern unsigned long long xRestoreRegCtx(volatile void* bufferRcx, unsigned long long dummyRdx, unsigned long long dummyR8, unsigned long long dummyR9);


void testsjlj()
{
	/*volatile*/ int ii = 0;

	volatile tRegContext jb[10];
	volatile int jb_index = -1;
	volatile int jb_final_index = -1;

	++jb_index;
	if (xSaveRegCtx(&jb[jb_index], 0xd, 8, 9))
	{
		--ii;
		printf("backtrace %d" "\r\n", ii);
		
		--jb_index;
		if (0 == jb_index)
		{
			jb_index = jb_final_index;
		}
		xRestoreRegCtx(&jb[jb_index], 0xd, 8, 9);
	}
	++ii;
	printf("forward %d" "\r\n", ii);


	++jb_index;
	if (xSaveRegCtx(&jb[jb_index], 0xd, 8, 9))
	{
		--ii;
		printf("backtrace %d" "\r\n", ii);

		--jb_index;
		if (0 == jb_index)
		{
			jb_index = jb_final_index;
		}
		xRestoreRegCtx(&jb[jb_index], 0xd, 8, 9);
	}
	++ii;
	printf("forward %d" "\r\n", ii);


	++jb_index;
	if (xSaveRegCtx(&jb[jb_index], 0xd, 8, 9))
	{
		--ii;
		printf("backtrace %d" "\r\n", ii);

		--jb_index;
		if (0 == jb_index)
		{
			jb_index = jb_final_index;
		}
		xRestoreRegCtx(&jb[jb_index], 0xd, 8, 9);
	}
	++ii;
	printf("forward %d" "\r\n", ii);


	++jb_index;
	if (xSaveRegCtx(&jb[jb_index], 0xd, 8, 9))
	{
		--ii;
		printf("backtrace %d" "\r\n", ii);

		--jb_index;
		if (0 == jb_index)
		{
			jb_index = jb_final_index;
		}
		xRestoreRegCtx(&jb[jb_index], 0xd, 8, 9);
	}
	++ii;
	printf("forward %d" "\r\n", ii);

	++jb_index;
	if (xSaveRegCtx(&jb[jb_index], 0xd, 8, 9))
	{
		--ii;
		printf("backtrace %d" "\r\n", ii);
		
		--jb_index;
		if (0 == jb_index)
		{
			jb_index = jb_final_index;
		}
		xRestoreRegCtx(&jb[jb_index], 0xd, 8, 9);
	}


	++jb_index;
	jb_final_index = jb_index;
	assert(_countof(jb) > jb_final_index);
	if (xSaveRegCtx(&jb[jb_index], 0xd, 8, 9))
	{
		assert(1);
	}
	else
	{
		
		--jb_index;
		if (0 == jb_index)
		{
			jb_index = jb_final_index;
		}
		xRestoreRegCtx(&jb[jb_index], 0xd, 8, 9);
	}

	printf("end %d" "\r\n", ii);
}