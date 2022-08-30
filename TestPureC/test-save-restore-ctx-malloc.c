
#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>
#include <assert.h>

#include "tRegContext.h"

extern unsigned long long xSaveRegCtx(volatile void* bufferRcx, unsigned long long dummyRdx, unsigned long long dummyR8, unsigned long long dummyR9);
extern unsigned long long xRestoreRegCtx(volatile void* bufferRcx, unsigned long long dummyRdx, unsigned long long dummyR8, unsigned long long dummyR9);

void testsjlj_malloc()
{
	/*volatile*/ int ii = 0;

	tRegContext* jmpFinal = (tRegContext*)malloc(sizeof(tRegContext));
	jmpFinal->prev = NULL;

	tRegContext* jmpCurrent = NULL;
	tRegContext* volatile jmpPrev = jmpFinal;

	tRegContext** volatile jmpStack = NULL;
	volatile int jmpCount = 1; //jmpFinal occupies 1 slot


	/////////////1
	++jmpCount;
	jmpCurrent = (tRegContext*)malloc(sizeof(tRegContext));
	jmpCurrent->prev = jmpPrev;
	jmpPrev = jmpCurrent;
	if (xSaveRegCtx(jmpCurrent, 0xd, 8, 9))
	{
		--ii;
		printf("backtrace %d" "\r\n", ii);

		--jmpCount;
		xRestoreRegCtx(jmpStack[jmpCount], 0xd, 8, 9);
	}
	++ii;
	printf("forward %d" "\r\n", ii);


	/////////////2
	++jmpCount;
	jmpCurrent = (tRegContext*)malloc(sizeof(tRegContext));
	jmpCurrent->prev = jmpPrev;
	jmpPrev = jmpCurrent;
	if (xSaveRegCtx(jmpCurrent, 0xd, 8, 9))
	{
		--ii;
		printf("backtrace %d" "\r\n", ii);

		
		--jmpCount;
		xRestoreRegCtx(jmpStack[jmpCount], 0xd, 8, 9);
	}
	++ii;
	printf("forward %d" "\r\n", ii);


	/////////////3
	++jmpCount;
	jmpCurrent = (tRegContext*)malloc(sizeof(tRegContext));
	jmpCurrent->prev = jmpPrev;
	jmpPrev = jmpCurrent;
	if (xSaveRegCtx(jmpCurrent, 0xd, 8, 9))
	{
		--ii;
		printf("backtrace %d" "\r\n", ii);

		--jmpCount;
		xRestoreRegCtx(jmpStack[jmpCount], 0xd, 8, 9);
	}
	++ii;
	printf("forward %d" "\r\n", ii);

	/////////////4
	++jmpCount;
	jmpCurrent = (tRegContext*)malloc(sizeof(tRegContext));
	jmpCurrent->prev = jmpPrev;
	jmpPrev = jmpCurrent;
	if (xSaveRegCtx(jmpCurrent, 0xd, 8, 9))
	{
		--ii;
		printf("backtrace %d" "\r\n", ii);

		--jmpCount;
		xRestoreRegCtx(jmpStack[jmpCount], 0xd, 8, 9);
	}
	++ii;
	printf("forward %d" "\r\n", ii);

	/////////////5
	++jmpCount;
	jmpCurrent = (tRegContext*)malloc(sizeof(tRegContext));
	jmpCurrent->prev = jmpPrev;
	jmpPrev = jmpCurrent;
	if (xSaveRegCtx(jmpCurrent, 0xd, 8, 9))
	{
		--ii;
		printf("backtrace %d" "\r\n", ii);

		--jmpCount;
		xRestoreRegCtx(jmpStack[jmpCount], 0xd, 8, 9);
	}



	if (xSaveRegCtx(jmpFinal, 0xd, 8, 9))
	{
		while (jmpPrev)
		{
			tRegContext* prev = jmpPrev->prev;
			free(jmpPrev);
			jmpPrev = prev;
		}
		free(jmpStack);

		assert(1);
	}
	else
	{
		jmpStack = (tRegContext**)malloc(sizeof(tRegContext*) * jmpCount);
		int jmpTmpIndex = jmpCount;
		while (jmpCurrent)
		{
			jmpStack[--jmpTmpIndex] = jmpCurrent;
			jmpCurrent = jmpCurrent->prev;
		}

		--jmpCount;
		xRestoreRegCtx(jmpStack[jmpCount], 0xd, 8, 9);
	}

	printf("end %d" "\r\n", ii);
}