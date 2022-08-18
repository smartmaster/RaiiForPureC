#include <stdio.h>
#include <assert.h>
#include <stdlib.h>
#include <string.h>

#include "xPureCRAII.h"


void testsjljMac1()
{
	

	SML_RAII_SCOPE_BEGIN(regctx, 10);

	 const char* volatile str0 = _strdup("0000");
	SML_RAII(regctx, {
	printf("free %s" "\r\n", str0);
	free(str0);
		});


	const char* volatile str1 = _strdup("1111");
	SML_RAII(regctx, {
	printf("free %s" "\r\n", str1);
	free(str1);
		});


	const char* volatile str2 = _strdup("2222");
	SML_RAII(regctx, {
	printf("free %s" "\r\n", str2);
	free(str2);
		});


	const char* volatile str3 = _strdup("33333");
	SML_RAII(regctx, {
	printf("free %s" "\r\n", str3);
	free(str3);
		});


	const char* volatile str4 = _strdup("4444");
	SML_RAII(regctx, {
	printf("free %s" "\r\n", str4);
	free(str4);
		});



	SML_RAII_SCOPE_END(regctx, 10);


	return;
}