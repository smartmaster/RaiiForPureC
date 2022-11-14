
#include <cassert>
#include <memory>
#include <vector>
#include <stack>
#include <string>
#include <set>
#include <iostream>
#include <fstream>
#include <random>

namespace SmartLib
{

	template<typename T>
	class Expression
	{
	public:
		virtual ~Expression() {};
		virtual T Evaluate() const = 0;
		virtual void Print(int spaceCount, std::ostream& out) const = 0;
	};

	template<typename T>
	using upExpr = std::unique_ptr<Expression<T>>;

	template<typename T>
	class ExpressionNumber : public Expression<T>
	{
	private:
		T _number;
	public:
		ExpressionNumber(T number) :
			_number{ number }
		{
		}

		virtual ~ExpressionNumber() override
		{

		}
		virtual T Evaluate() const override
		{
			return _number;
		}

		virtual void Print(int spaceCount, std::ostream& out) const override
		{
			for (int ii = 0; ii < spaceCount; ++ii)
			{
				out << '\t';
			}
			out << _number << std::endl;
		}
	};

	enum class OPERATOR : char
	{
		ADD = '+',
		SUB = '-',

		MUL = '*',
		DIV = '/',
		MOD = '%',

		LEFT_BRACKET = '(',
		RIGHT_BRACKET = ')',


		INVALID = '\0',
	};


	template<typename T>
	class ExpressionBinary : public Expression<T>
	{
	private:
		OPERATOR _op;
		upExpr<T> _left;
		upExpr<T> _right;
	public:
		ExpressionBinary(OPERATOR op, upExpr<T> left, upExpr<T> right) :
			_op{ op },
			_left{ move(left) },
			_right{ move(right) }
		{
		}


		virtual ~ExpressionBinary() override
		{

		}

		virtual T Evaluate() const override
		{
			T leftVal = _left->Evaluate();
			T rightVal = _right->Evaluate();

			T result{};
			switch (_op)
			{
			case OPERATOR::ADD:
				result = leftVal + rightVal;
				break;
			case OPERATOR::SUB:
				result = leftVal - rightVal;
				break;
			case OPERATOR::MUL:
				result = leftVal * rightVal;
				break;
			case OPERATOR::DIV:
				result = leftVal / rightVal;
				break;
			case OPERATOR::MOD:
				if constexpr (std::is_integral_v<T>)
				{
					result = leftVal % rightVal;
				}
				else if constexpr (std::is_floating_point_v<T>)
				{
					long long times = (long long)(leftVal / rightVal);
					result = leftVal - times * rightVal;
				}
				break;
			default:
				assert(false);
				break;
			}

			return result;
		}

		virtual void Print(int spaceCount, std::ostream& out) const override
		{
			for (int ii = 0; ii < spaceCount; ++ii)
			{
				out << '\t';
			}
			out << (char)(_op) << std::endl;

			_left->Print(spaceCount + 1, out);
			_right->Print(spaceCount + 1, out);
		}
	};

	enum class TokenType
	{
		TT_OP,
		TT_NUM,
	};

	template<typename T>
	struct Token
	{
		TokenType _type;
		OPERATOR _op{ OPERATOR::INVALID };
		T _number{};

		Token(OPERATOR op) :
			_type{ TokenType::TT_OP },
			_op{ op }
		{
		}

		Token(T num) :
			_type{ TokenType::TT_NUM },
			_number{ num }
		{
		}
	};

	template<typename T>
	class ExpressionBuilder
	{
		std::stack<upExpr<T>> _exprStack;
		std::stack<OPERATOR> _opStack;

	private:
		void MakeExpressionBinary()
		{
			//expr1 op expr2 --> exprNew
			OPERATOR topOp = _opStack.top();
			_opStack.pop();

			upExpr<T> expr2 = std::move(_exprStack.top());
			_exprStack.pop();

			upExpr<T> expr1 = std::move(_exprStack.top());
			_exprStack.pop();

			auto exprNew = std::make_unique<ExpressionBinary<T>>(topOp, std::move(expr1), std::move(expr2));

			_exprStack.push(std::move(exprNew));

		}

	private:

		static std::vector<Token<T>> StringToTokens(const char* begin, const char* end)
		{
			std::vector<Token<T>> result;
			result.push_back(Token<T>((OPERATOR)('('))); //add guarded token (
			while (begin != end && *begin)
			{
				const char ch = *begin;
				if (std::isdigit(ch) || ('.' == ch))
				{
					char* endstr = nullptr;
					T data{};
					if constexpr (std::is_floating_point_v<T>)
					{
						data = strtod(begin, &endstr);
					}
					else
					{
						data = strtoll(begin, &endstr, 10);
					}
					begin = endstr;
					result.push_back(Token<T>((T)(data)));

				}
				else if (!std::isspace(ch))
				{
					result.push_back(Token<T>((OPERATOR)(ch)));
					++begin;
				}
				else
				{
					++begin;
				}

			}

			result.push_back(Token<T>((OPERATOR)(')'))); //add guarded token )
			return result;
		}

		//please add guarded '(' and ')' first
		template<typename TOKEN_ITER>
		upExpr<T> Build(TOKEN_ITER begin, TOKEN_ITER end)
		{
			while (begin != end)
			{
				const Token<T>& tok = *begin;
				switch (tok._type)
				{
				case TokenType::TT_NUM:
				{
					_exprStack.push(std::make_unique<ExpressionNumber<T>>(tok._number));
				}
				break;

				case TokenType::TT_OP:
				{
					switch (tok._op)
					{
					case OPERATOR::LEFT_BRACKET:
					{
						_opStack.push(OPERATOR::LEFT_BRACKET);
					}
					break;

					case OPERATOR::RIGHT_BRACKET:
					{
						//(expr1   )
						//(expr1 - expr2   )
						//(expr1 - expr2 / expr3  )
						int loopCount = 0;
						while (OPERATOR::LEFT_BRACKET != _opStack.top())
						{
							MakeExpressionBinary();
							++loopCount;
						}
						assert(loopCount <= 2);
						assert(OPERATOR::LEFT_BRACKET == _opStack.top());
						_opStack.pop(); //pop (
					}
					break;

					case OPERATOR::MUL:
					case OPERATOR::DIV:
					case OPERATOR::MOD:
					{
						OPERATOR lastOp = _opStack.top();
						switch (lastOp)
						{
						case OPERATOR::MUL:
						case OPERATOR::DIV:
						case OPERATOR::MOD:
						{
							//- expr1 / expr2		/  OK
							//(expr1 / expr2		/  OK
							MakeExpressionBinary();
							{
								OPERATOR tmpTop = _opStack.top();
								assert(OPERATOR::LEFT_BRACKET == tmpTop ||
									OPERATOR::ADD == tmpTop ||
									OPERATOR::SUB == tmpTop);
							}
							
						}
						break;
						}
						_opStack.push(tok._op);
					}
					break;

					case OPERATOR::ADD:
					case OPERATOR::SUB:
					{
						OPERATOR lastOp = _opStack.top();
						switch (lastOp)
						{
						case OPERATOR::ADD:
						case OPERATOR::SUB:
						case OPERATOR::MUL:
						case OPERATOR::DIV:
						case OPERATOR::MOD:
						{
							//(expr1 - expr2    -
							//(expr1 / expr2    - 
							//(expr1 - expr2 / expr3    - 
							int loopCount = 0;
							while (OPERATOR::LEFT_BRACKET != _opStack.top())
							{
								MakeExpressionBinary();
								++loopCount;
							}
							assert(loopCount >= 1 && loopCount <= 2);
							assert(OPERATOR::LEFT_BRACKET == _opStack.top());
						}
						break;
						}
						_opStack.push(tok._op);
					}
					break;

					default:
						assert(false);
						break;
					}
				}
				break;
				}

				++begin;
			}


			assert(1 == _exprStack.size() && 0 == _opStack.size());
			return std::move(_exprStack.top());
		}

	public:
		static std::string GenerateRandomExprString(
			int numCount,
			int minNum, //should be > 0
			int maxNum,
			int bracketCount,
			bool asDouble
		)
		{
			std::random_device rd;  //Will be used to obtain a seed for the random number engine
			std::mt19937 gen(rd()); //Standard mersenne_twister_engine seeded with rd()
			std::uniform_int_distribution<int> distrib(minNum, maxNum);

			std::vector<int> vecNums(numCount);
			for (int ii = 0; ii < numCount; ++ii)
			{
				int rndVal = distrib(gen);
				if (rndVal)
				{
					vecNums[ii] = rndVal;
				}
				else
				{
					--ii;
				}
			}

			static const char ops[] = "+-*/%";
			std::vector<char> vecOps(numCount);
			std::uniform_int_distribution<int> distribOps(0, asDouble ? _countof(ops) - 3 : _countof(ops) - 2);
			for (int ii = 0; ii < numCount; ++ii)
			{
				int rndVal = distribOps(gen);
				vecOps[ii] = ops[rndVal];
			}
			vecOps.back() = '\0';


			std::set<int> bracketPos;
			std::uniform_int_distribution<int> distribBracketPos(0, numCount - 1);
			while (bracketPos.size() < 2 * bracketCount)
			{
				int rndVal = distribBracketPos(gen);
				bracketPos.insert(rndVal);
			}

			std::vector<bool> veclb(numCount);
			std::vector<bool> vecrb(numCount);
			bool flaglb = true;

			for (int bpos : bracketPos)
			{
				if (flaglb)
				{
					veclb[bpos] = true;
				}
				else
				{
					vecrb[bpos] = true;
				}
				flaglb = !flaglb;
			}

			std::string exprStr;
			for (int ii = 0; ii < numCount; ++ii)
			{
				if (veclb[ii])
				{
					exprStr += "(";
				}

				exprStr += std::to_string(vecNums[ii]);

				if (asDouble)
				{
					exprStr += ".0";
				}

				if (vecrb[ii])
				{
					exprStr += ")";
				}

				if (vecOps[ii])
				{
					exprStr += vecOps[ii];
				}
			}


			return exprStr;
		}


		static upExpr<T> Parse(const char* begin, const char* end)
		{
			ExpressionBuilder<T> eb;
			std::vector<Token<T>> tokes = ExpressionBuilder<T>::StringToTokens(begin, end);
			upExpr<T> expr = eb.Build(tokes.begin(), tokes.end());
			return expr;
		}
	};
}

//#define SML_STRING(x) #x

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
		std::string exprStr = ExpressionBuilder<T>::GenerateRandomExprString(
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