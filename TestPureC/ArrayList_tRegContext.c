#include "tRegContext.h"
#include <stdlib.h>
#include <malloc.h>
#include <assert.h>

#define INITIAL_COUNT 2


typedef struct ArrayList_tRegContext
{
	tRegContext _preallocated[INITIAL_COUNT];
	tRegContext* _last;
	tRegContext* _prev;
	int _count;
	int _dummy;
}ArrayList_tRegContext;


void ArrayList_tRegContext_ctor(ArrayList_tRegContext* self)
{
	self->_last = NULL;
	self->_prev = NULL;
	self->_count = 0;
	self->_dummy = 'FACE';
}


void ArrayList_tRegContext_dtor(ArrayList_tRegContext* self)
{
	if (self->_count > INITIAL_COUNT)
	{
		tRegContext* curr = self->_preallocated[INITIAL_COUNT - 1].next;
		while (curr)
		{
			tRegContext* next = curr->next;
			free(curr);
			curr = next;
		}
	}

	ArrayList_tRegContext_ctor(self); //init members
}


tRegContext* ArrayList_tRegContext_Append(ArrayList_tRegContext* self)
{
	tRegContext* node = NULL;
	if (self->_count < INITIAL_COUNT)
	{
		node = &self->_preallocated[self->_count];
	}
	else
	{
		node = (tRegContext*)malloc(sizeof(tRegContext));
	}

	node->next = NULL;
	node->prev = self->_last;

	if (self->_last == NULL)
	{
		self->_last = node;
	}
	else
	{
		self->_last->next = node;
		self->_last = node;
	}

	++ self->_count;
	return node;
}


tRegContext* ArrayList_tRegContext_Prev(ArrayList_tRegContext* self)
{

	if (self->_prev == NULL)
	{
		self->_prev = self->_last;
	}

	tRegContext* node = self->_prev;
	self->_prev = self->_prev->prev;
	return node;
}

ArrayList_tRegContext* New_ArrayList_tRegContext()
{
	ArrayList_tRegContext* al = (ArrayList_tRegContext*)malloc(sizeof(ArrayList_tRegContext));
	ArrayList_tRegContext_ctor(al);
	return al;
}

void Delete_ArrayList_tRegContext(ArrayList_tRegContext* al)
{
	ArrayList_tRegContext_dtor(al);
	free(al);
}
