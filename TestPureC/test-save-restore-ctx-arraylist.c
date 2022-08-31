
#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>
#include <assert.h>

#include "tRegContext.h"
#include "ArrayList_tRegContext.h"

extern unsigned long long xSaveRegCtx(volatile void* bufferRcx, unsigned long long dummyRdx, unsigned long long dummyR8, unsigned long long dummyR9);
extern unsigned long long xRestoreRegCtx(volatile void* bufferRcx, unsigned long long dummyRdx, unsigned long long dummyR8, unsigned long long dummyR9);

void testsjlj_arraylist()
{
	/*volatile*/ int ii = 0;

	
	ArrayList_tRegContext* volatile jmpAL = New_ArrayList_tRegContext();
	tRegContext* jmpFinal = ArrayList_tRegContext_Append(jmpAL);

	/////////////1
	if (xSaveRegCtx(ArrayList_tRegContext_Append(jmpAL), 0xd, 8, 9))
	{
		--ii;
		printf("backtrace %d" "\r\n", ii);

		xRestoreRegCtx(ArrayList_tRegContext_Prev(jmpAL), 0xd, 8, 9);
	}
	++ii;
	printf("forward %d" "\r\n", ii);


	/////////////2
	if (xSaveRegCtx(ArrayList_tRegContext_Append(jmpAL), 0xd, 8, 9))
	{
		--ii;
		printf("backtrace %d" "\r\n", ii);


		xRestoreRegCtx(ArrayList_tRegContext_Prev(jmpAL), 0xd, 8, 9);
	}
	++ii;
	printf("forward %d" "\r\n", ii);


	/////////////3
	if (xSaveRegCtx(ArrayList_tRegContext_Append(jmpAL), 0xd, 8, 9))
	{
		--ii;
		printf("backtrace %d" "\r\n", ii);

		xRestoreRegCtx(ArrayList_tRegContext_Prev(jmpAL), 0xd, 8, 9);
	}
	++ii;
	printf("forward %d" "\r\n", ii);

	/////////////4
	if (xSaveRegCtx(ArrayList_tRegContext_Append(jmpAL), 0xd, 8, 9))
	{
		--ii;
		printf("backtrace %d" "\r\n", ii);

		xRestoreRegCtx(ArrayList_tRegContext_Prev(jmpAL), 0xd, 8, 9);
	}
	++ii;
	printf("forward %d" "\r\n", ii);

	/////////////5
	if (xSaveRegCtx(ArrayList_tRegContext_Append(jmpAL), 0xd, 8, 9))
	{
		--ii;
		printf("backtrace %d" "\r\n", ii);

		xRestoreRegCtx(ArrayList_tRegContext_Prev(jmpAL), 0xd, 8, 9);
	}



	if (xSaveRegCtx(jmpFinal, 0xd, 8, 9))
	{
		Delete_ArrayList_tRegContext(jmpAL);
		jmpAL = NULL;
		assert(1);
	}
	else
	{
		xRestoreRegCtx(ArrayList_tRegContext_Prev(jmpAL), 0xd, 8, 9);
	}

	printf("end %d" "\r\n", ii);
}