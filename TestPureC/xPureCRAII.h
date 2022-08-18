#pragma once

#include <assert.h>
#include "tRegContext.h"

extern unsigned long long xSaveRegCtx(volatile void* bufferRcx, unsigned long long dummyRdx, unsigned long long dummyR8, unsigned long long dummyR9);
extern unsigned long long xRestoreRegCtx(volatile void* bufferRcx, unsigned long long dummyRdx, unsigned long long dummyR8, unsigned long long dummyR9);


////////////////////////////////////////////////
#define SML_RAII_SCOPE_BEGIN(jb, N) \
volatile tRegContext jb[N]; \
volatile int jb ## _index = -1; \
volatile int jb ## _final_index = -1;

////////////////////////////////////////////////
#define SML_RAII_BEGIN(jb) \
++jb ## _index; \
if (xSaveRegCtx(&jb[jb ## _index], 0xd, 8, 9)) \
{


////////////////////////////////////////////////
#define SML_RAII_END(jb) \
	--jb ## _index;  \
	if (0 == jb ## _index) \
	{ \
		jb ## _index = jb ## _final_index; \
	} \
	xRestoreRegCtx(&jb[jb ## _index], 0xd, 8, 9); \
}

////////////////////////////////////////////////
#define SML_RAII(jb, stmt) \
SML_RAII_BEGIN(jb); \
stmt; \
SML_RAII_END(jb);

////////////////////////////////////////////////
#define SML_RAII_SCOPE_END(jb, N) \
++jb ## _index; \
jb ## _final_index = jb ## _index; \
assert(_countof(jb) > jb ## _final_index); \
if (xSaveRegCtx(&jb[jb ## _index], 0xd, 8, 9)) \
{ \
	assert(1); \
} \
else \
{ \
	--jb ## _index; \
	if (0 == jb ## _index) \
	{ \
		jb ## _index = jb ## _final_index; \
	} \
	xRestoreRegCtx(&jb[jb ## _index], 0xd, 8, 9); \
}