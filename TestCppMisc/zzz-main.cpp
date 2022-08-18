#include <string>
#include <iostream>

extern void CaseTestAlloc();
extern void TestSort();
extern void printCounter();
extern void testsjlj();

int main(int argc, char** argv)
{
	using namespace ::std;

	int testCase = -1;
	if (argc > 1)
	{
		testCase = std::stol(argv[1]);
	}

	switch (testCase)
	{
	case 3:
	{
		testsjlj();
	}
	break;

	case 2:
	{
		printCounter();
	}
	break;

	case 1:
	{
		TestSort();
	}
	break;

	case 0:
	{
		CaseTestAlloc();
	}
	break;

	default:
	{
		cout << "Please input a valid case number!" << endl;
	}
	break;
	}

	
	return 0;
}