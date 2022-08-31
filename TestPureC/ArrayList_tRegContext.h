#pragma once

#include "tRegContext.h"

typedef struct ArrayList_tRegContext ArrayList_tRegContext;

extern ArrayList_tRegContext* New_ArrayList_tRegContext();
extern void Delete_ArrayList_tRegContext(ArrayList_tRegContext* al);

extern tRegContext* ArrayList_tRegContext_Append(ArrayList_tRegContext* self);
extern tRegContext* ArrayList_tRegContext_Prev(ArrayList_tRegContext* self);
