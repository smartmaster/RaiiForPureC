#pragma once

#include <assert.h>
#include "tRegContext.h"
#include "ArrayList_tRegContext.h"

extern unsigned long long xSaveRegCtx(volatile void* bufferRcx, unsigned long long dummyRdx, unsigned long long dummyR8, unsigned long long dummyR9);
extern unsigned long long xRestoreRegCtx(volatile void* bufferRcx, unsigned long long dummyRdx, unsigned long long dummyR8, unsigned long long dummyR9);


////////////////////////////////////////////////
#define SML_RAII_SCOPE_BEGIN(jmp) \
ArrayList_tRegContext* volatile jmp ## AL = New_ArrayList_tRegContext(); \
tRegContext* jmp ## Final = ArrayList_tRegContext_Append(jmp ## AL);

////////////////////////////////////////////////
#define SML_RAII_BEGIN(jmp) \
if (xSaveRegCtx(ArrayList_tRegContext_Append(jmp ## AL), 0xd, 8, 9)) \
{


////////////////////////////////////////////////
#define SML_RAII_END(jmp) \
	xRestoreRegCtx(ArrayList_tRegContext_Prev(jmp ## AL), 0xd, 8, 9); \
}

////////////////////////////////////////////////
#define SML_RAII(jmp, stmt) \
SML_RAII_BEGIN(jmp); \
stmt; \
SML_RAII_END(jmp);

////////////////////////////////////////////////
#define SML_RAII_SCOPE_END(jmp) \
if (xSaveRegCtx(jmp ## Final, 0xd, 8, 9)) \
{ \
	Delete_ArrayList_tRegContext(jmp ## AL); \
	jmp ## AL = NULL; \
	assert(1); \
} \
else \
{ \
	xRestoreRegCtx(ArrayList_tRegContext_Prev(jmp ## AL), 0xd, 8, 9); \
}