
extern void testsjljMac();
extern void testsjlj();
extern void testsjlj_malloc();

int main(int argc, char** argv)
{
	int testCase = 0;
	switch (testCase)
	{
	case 2:
	{

	}
	break;

	case 1:
	{

	}
	break;

	case 0:
	{
		testsjlj_malloc();
		testsjljMac1();
		testsjljMac();
		testsjlj();
	}
	break;

	default:
		break;
	}
	return 0;
}