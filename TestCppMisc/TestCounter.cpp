#include <stdio.h>

#define SML_STRING_OF(x) # x
#define SML_EXPAND_MACRO(x) SML_STRING_OF(x)
#define SML_CAT(x, y) x ## y



#define LOCAL_COUNTER		(__COUNTER__ - __COUNTER__BASE__)

static void print1()
{
	
	constexpr int __COUNTER__BASE__	=	(__COUNTER__ + 1);

	printf("local counter %d" "\r\n", LOCAL_COUNTER);
	printf("local counter %d" "\r\n", LOCAL_COUNTER);
	printf("local counter %d" "\r\n", LOCAL_COUNTER);
	printf("local counter %d" "\r\n", LOCAL_COUNTER);

	printf("%s" "\r\n", SML_EXPAND_MACRO(hello) SML_EXPAND_MACRO(__COUNTER__));
	printf("%s" "\r\n", SML_EXPAND_MACRO(hello) SML_EXPAND_MACRO(__COUNTER__));
	printf("%s" "\r\n", SML_EXPAND_MACRO(hello) SML_EXPAND_MACRO(__COUNTER__));
	printf("%s" "\r\n", SML_EXPAND_MACRO(hello) SML_EXPAND_MACRO(__COUNTER__));
	printf("%s" "\r\n", SML_EXPAND_MACRO(hello) SML_EXPAND_MACRO(__COUNTER__));


	printf("%s" "\r\n", SML_EXPAND_MACRO(__COUNTER__));
	printf("%s" "\r\n", SML_EXPAND_MACRO(__COUNTER__));
	printf("%s" "\r\n", SML_EXPAND_MACRO(__COUNTER__));
	printf("%s" "\r\n", SML_EXPAND_MACRO(__COUNTER__));
	printf("%s" "\r\n", SML_EXPAND_MACRO(__COUNTER__));
}



static void print2()
{
	constexpr int __COUNTER__BASE__ = __COUNTER__ + 1;


	printf("local counter %d" "\r\n", LOCAL_COUNTER);
	printf("local counter %d" "\r\n", LOCAL_COUNTER);
	printf("local counter %d" "\r\n", LOCAL_COUNTER);
	printf("local counter %d" "\r\n", LOCAL_COUNTER);

	printf("%s" "\r\n", SML_EXPAND_MACRO(hello) SML_EXPAND_MACRO(__COUNTER__));
	printf("%s" "\r\n", SML_EXPAND_MACRO(hello) SML_EXPAND_MACRO(__COUNTER__));
	printf("%s" "\r\n", SML_EXPAND_MACRO(hello) SML_EXPAND_MACRO(__COUNTER__));
	printf("%s" "\r\n", SML_EXPAND_MACRO(hello) SML_EXPAND_MACRO(__COUNTER__));
	printf("%s" "\r\n", SML_EXPAND_MACRO(hello) SML_EXPAND_MACRO(__COUNTER__));


	printf("%s" "\r\n", SML_EXPAND_MACRO(__COUNTER__));
	printf("%s" "\r\n", SML_EXPAND_MACRO(__COUNTER__));
	printf("%s" "\r\n", SML_EXPAND_MACRO(__COUNTER__));
	printf("%s" "\r\n", SML_EXPAND_MACRO(__COUNTER__));
	printf("%s" "\r\n", SML_EXPAND_MACRO(__COUNTER__));
}



void printCounter()
{
	print1();
	print2();
}