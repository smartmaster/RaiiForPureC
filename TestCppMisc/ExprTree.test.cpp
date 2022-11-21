#include "ExprTree.h"

//#define SML_STRING(x) #x

void TestExprFuncWithVar()
{
	using namespace SmartLib;
	using namespace ::std;
	using T = double;

#if 0
	const char* funcstr[] = {
		"2+fff()",
		"3+fff(aaa,)",
		"4+ggg(aaa, bbb, ccc,)",
		"5+hhh(h1(aaa, bbb,),h2(ccc,ddd,),h3(eee,fff,), h4(),)",
	};
#else
	const char* funcstr[] = {
		"2+fff()",
		"3+fff(aaa)",
		"4+ggg(aaa, bbb, ccc)",
		"5+hhh(h1(aaa, bbb),h2(ccc,ddd),h3(eee,fff), h4())",
	};
#endif
	

	int index = 0;
	for (const char* str : funcstr)
	{
		upExpr<T> expr = ExpressionBuilder<T>::Parse(str, nullptr);
		std::cout << str << std::endl;
		expr->Print(0, std::cout);
		std::cout << std::endl;
		//T eval = expr->Evaluate();
		//bool isClose = ExpressionBuilder<T>::IsCloseFloat(testVal[index], eval, 1e-9, 1e-6);
		//cout << str << "=" << eval << endl;
		//cout << "Is " << testVal[index] << " and " << eval << " close? " << isClose << endl;
		//assert(isClose);
		++index;
	}
}

void TestExprFunc()
{
	using namespace SmartLib;
	using namespace ::std;
	using T = double;

#if 1
	const char* funcstr[] = {
		"fff(0+0+0+5*1*1*1)",
		"ggg(0.5+0+0+0,1.0+0+0+0,1.5+0+0+0)",
		"hhh(h1(0.1+0+0+0,0.3+0+0+0),h2(0.2+0+0+0,0.5+0+0+0),h3(0.3+0+0+0,0.6+0+0+0))",

				"  fff(0+0+0+5*1*1*1)  -  ggg(0+0+0+0+0.5*1*1*1,0+0+0+0+1.0*1*1*1,0+0+0+0+1.5*1*1*1)  -  hhh(h1(0.1,0.3),h2(0.2,0.5),h3(0.3,0.6),h4())  ",
		"  fff(0+0+0+5*1*1*1)  /  ggg(0+0+0+0+0.5*1*1*1,0+0+0+0+1.0*1*1*1,0+0+0+0+1.5*1*1*1)  /   hhh(h1(0.1,0.3),h2(0.2,0.5),h3(0.3,0.6),h4())  ",
		"  fff(0+0+0+5*1*1*1)  -  ggg(0+0+0+0+0.5*1*1*1,0+0+0+0+1.0*1*1*1,0+0+0+0+1.5*1*1*1)  /   hhh(h1(0.1,0.3),h2(0.2,0.5),h3(0.3,0.6),h4())  " ,
		"   fff(0+0+0+5*1*1*1)  /   ggg(0+0+0+0+0.5*1*1*1,0+0+0+0+1.0*1*1*1,0+0+0+0+1.5*1*1*1)  -  hhh(h1(0.1,0.3),h2(0.2,0.5),h3(0.3,0.6),h4())  ",

		"  (fff(0+0+0+5*1*1*1)  -  ggg(0+0+0+0+0.5*1*1*1,0+0+0+0+1.0*1*1*1,0+0+0+0+1.5*1*1*1))  -  hhh(h1(0.1,0.3),h2(0.2,0.5),h3(0.3,0.6),h4())  ",
		"  (fff(0+0+0+5*1*1*1)  /  ggg(0+0+0+0+0.5*1*1*1,0+0+0+0+1.0*1*1*1,0+0+0+0+1.5*1*1*1))  /   hhh(h1(0.1,0.3),h2(0.2,0.5),h3(0.3,0.6),h4())  ",
		"  fff(0+0+0+5*1*1*1)  -  (ggg(0+0+0+0+0.5*1*1*1,0+0+0+0+1.0*1*1*1,0+0+0+0+1.5*1*1*1)  /   hhh(h1(0.1,0.3),h2(0.2,0.5),h3(0.3,0.6),h4()))  " ,
		"   (fff(0+0+0+5*1*1*1)  /   ggg(0+0+0+0+0.5*1*1*1,0+0+0+0+1.0*1*1*1,0+0+0+0+1.5*1*1*1))  -  hhh(h1(0.1,0.3),h2(0.2,0.5),h3(0.3,0.6),h4())  ",
	};
#else
	const char* funcstr[] = {
		"fff(5,)",
		"ggg(0.5,1.0,1.5,)",
		"hhh(h1(0.1,0.3,),h2(0.2,0.5,),h3(0.3,0.6,),)",

				"  fff(5,)  -  ggg(0.5,1.0,1.5,)  -  hhh(h1(0.1,0.3,),h2(0.2,0.5,),h3(0.3,0.6,),)  ",
		"  fff(5,)  /  ggg(0.5,1.0,1.5,)  /   hhh(h1(0.1,0.3,),h2(0.2,0.5,),h3(0.3,0.6,),)  ",
		"  fff(5,)  -  ggg(0.5,1.0,1.5,)  /   hhh(h1(0.1,0.3,),h2(0.2,0.5,),h3(0.3,0.6,),)  " ,
		"   fff(5,)  /   ggg(0.5,1.0,1.5,)  -  hhh(h1(0.1,0.3,),h2(0.2,0.5,),h3(0.3,0.6,),)  ",

		"  (fff(5,)  -  ggg(0.5,1.0,1.5,))  -  hhh(h1(0.1,0.3,),h2(0.2,0.5,),h3(0.3,0.6,),)  ",
		"  (fff(5,)  /  ggg(0.5,1.0,1.5,))  /   hhh(h1(0.1,0.3,),h2(0.2,0.5,),h3(0.3,0.6,),)  ",
		"  fff(5,)  -  (ggg(0.5,1.0,1.5,)  /   hhh(h1(0.1,0.3,),h2(0.2,0.5,),h3(0.3,0.6,),))  " ,
		"   (fff(5,)  /   ggg(0.5,1.0,1.5,))  -  hhh(h1(0.1,0.3,),h2(0.2,0.5,),h3(0.3,0.6,),)  ",
	};
#endif
	

	const T testVal[]
	{
		(T)5,
		(T)3,
		(T)2,
		(T)5 - (T)3 - (T)2,
		(T)5 / (T)3 / (T)2,
		(T)5 - (T)3 / (T)2,
		(T)5 / (T)3 - (T)2,

		(T)5 - (T)3 - (T)2,
		(T)5 / (T)3 / (T)2,
		(T)5 - (T)3 / (T)2,
		(T)5 / (T)3 - (T)2,
	};

	int index = 0;
	for (const char* str : funcstr)
	{
		upExpr<T> expr = ExpressionBuilder<T>::Parse(str, nullptr);
		expr->Print(0, std::cout);
		T eval = expr->Evaluate();
		bool isClose = ETBUtils::IsCloseFloat(testVal[index], eval, 1e-9, 1e-6);
		cout << str << "=" << eval << endl;
		cout << "Is " << testVal[index] << " and " << eval << " close? " << isClose << endl;
		assert(isClose);
		++index;
	}
}

void TestExprRandom()
{
	using namespace SmartLib;
	using namespace ::std;
	using T = double;

	int bracketCounts[] = { 0, 7, 11, 17, 31, 79 };

	/*
	print('exprStr = ', 'exprStr')
	varpy = exprStr

	print('varpy = ', varpy)
	varcpp = result

	print('varcpp = ', varcpp)

	print('varpy == varcpp?', varpy == varcpp)

	*/

	std::ofstream fout("000-verify-result.py");
	fout.precision(15);

	fout << "import math" << endl;


	for (int bc : bracketCounts)
	{
		std::string exprStr = ETBUtils::GenerateRandomExprString(
			511,//int numCount,
			1,//int minNum, ,//should be > 0
			1000,//int maxNum,
			bc,//int bracketCount,
			true//,//int asDouble
		);

		fout << "#BBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBB" << endl;
		fout << "print('exprStr = ', '" << exprStr << "')" << endl;
		fout << endl;
		fout << "varpy = " << exprStr << endl;
		fout << "print('varpy  = ', varpy)" << endl;
		fout << endl;

		upExpr<T> expr = ExpressionBuilder<T>::Parse(exprStr.c_str(), exprStr.c_str() + exprStr.size());
		T result = expr->Evaluate();

		fout << "varcpp = " << result << endl;
		fout << "print('varcpp = ', varcpp)" << endl;
		fout << endl;
		fout << "print('varpy == varcpp?', varpy == varcpp)" << endl;
		fout << "print('math.isclose(varpy, varcpp, 1e-9, 1e-6)?', math.isclose(varpy, varcpp))" << endl;
		fout << "print()" << endl;
		fout << "#EEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEE" << endl;
		fout << endl;

		fout << "'''" << endl;
		//expr->Print(2, fout);
		fout << "'''" << endl;
	}


	std::ofstream foutcmd("000-verify-result.cmd");
	foutcmd << "python 000-verify-result.py" << endl;

}

void TestExpr()
{
	using namespace SmartLib;
	using T = double;

	const char* testData[]
	{
		"  5  -  3  -  2  ",
		"  5  /  3  /   2  ",
		"  5  -  3  /   2  " ,
		"   5  /   3  -  2  ",
		"  (5  -  3)  -  2  ",
		"  (5  /  3)  /   2  ",
		"  5  -  (3  /   2)  " ,
		"   (5  /   3)  -  2  ",
	};

	const T testVal[]
	{
		(T)5 - (T)3 - (T)2,
		(T)5 / (T)3 / (T)2,
		(T)5 - (T)3 / (T)2,
		(T)5 / (T)3 - (T)2,

		(T)5 - (T)3 - (T)2,
		(T)5 / (T)3 / (T)2,
		(T)5 - (T)3 / (T)2,
		(T)5 / (T)3 - (T)2,
	};

	int index = 0;
	for (const char* str : testData)
	{
		upExpr<T> expr = ExpressionBuilder<T>::Parse(str, nullptr);
		T result = expr->Evaluate();

		std::cout << str << "=" << result << ", realResult=" << testVal[index] << std::endl;
		assert(testVal[index] == result);

		expr->Print(2, std::cout);
		std::cout << std::endl;

		++index;
	}

}