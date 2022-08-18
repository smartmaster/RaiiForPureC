#include <csetjmp>
#include <cstdio>

void testsjlj()
{
	int ii = 0;

	jmp_buf jbfinal;
	jmp_buf jb0;
	if (setjmp(jb0))
	{
		--ii;
		printf("backtrace %d" "\r\n", ii);
		longjmp(jbfinal, 1);
	}
	++ii;
	printf("forward %d" "\r\n", ii);


	jmp_buf jb1;
	if (setjmp(jb1))
	{
		--ii;
		printf("backtrace %d" "\r\n", ii);
		longjmp(jb0, 1);
	}
	++ii;
	printf("forward %d" "\r\n", ii);


	jmp_buf jb2;
	if (setjmp(jb2))
	{
		--ii;
		printf("backtrace %d" "\r\n", ii);
		longjmp(jb1, 1);
	}
	++ii;
	printf("forward %d" "\r\n", ii);


	jmp_buf jb3;
	if (setjmp(jb3))
	{
		--ii;
		printf("backtrace %d" "\r\n", ii);
		longjmp(jb2, 1);
	}
	++ii;
	printf("forward %d" "\r\n", ii);

	jmp_buf jb4;
	if (setjmp(jb4))
	{
		--ii;
		printf("backtrace %d" "\r\n", ii);
		longjmp(jb3, 1);
	}
	++ii;
	printf("forward %d" "\r\n", ii);

	if (setjmp(jbfinal))
	{

	}
	else
	{
		longjmp(jb4,1);
	}

	printf("end %d" "\r\n", ii);
}