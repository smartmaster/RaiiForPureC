
#include <cassert>
#include <memory>
#include <vector>
#include <iostream>

namespace SmartLib
{

	template<typename T>
	class Expression
	{
	public:
		virtual ~Expression() {};
		virtual T Evaluate() const = 0;
		virtual void Print(int spaceCount) const = 0;
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

		virtual void Print(int spaceCount) const override
		{
			for (int ii = 0; ii < spaceCount; ++ ii)
			{
				std::cout << '\t';
			}
			std::cout << _number << std::endl;
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
				break;
			default:
				assert(false);
				break;
			}

			return result;
		}

		virtual void Print(int spaceCount) const override
		{
			for (int ii = 0; ii < spaceCount; ++ii)
			{
				std::cout << '\t';
			}
			std::cout << (char)(_op) << std::endl;

			_left->Print(spaceCount + 1);
			_right->Print(spaceCount + 1);
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
		std::vector<upExpr<T>> _exprStack;
		std::vector<OPERATOR> _opStack;

	private:
		void MakeExpressionBinary()
		{
			//expr1 op expr2 --> exprNew
			OPERATOR topOp = _opStack.back();
			_opStack.pop_back();

			upExpr<T> expr2 = std::move(_exprStack.back());
			_exprStack.pop_back();

			upExpr<T> expr1 = std::move(_exprStack.back());
			_exprStack.pop_back();

			auto exprNew = std::make_unique<ExpressionBinary<T>>(topOp, std::move(expr1), std::move(expr2));

			_exprStack.push_back(std::move(exprNew));

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
					_exprStack.push_back(std::make_unique<ExpressionNumber<T>>(tok._number));
				}
				break;

				case TokenType::TT_OP:
				{
					switch (tok._op)
					{
					case OPERATOR::LEFT_BRACKET:
					{
						_opStack.push_back(OPERATOR::LEFT_BRACKET);
					}
					break;

					case OPERATOR::RIGHT_BRACKET:
					{
						//(expr1   )
						//(expr1 - expr2   )
						//(expr1 - expr2 / expr3  )
						while (OPERATOR::LEFT_BRACKET != _opStack.back())
						{
							MakeExpressionBinary();
						}
						_opStack.pop_back();
					}
					break;

					case OPERATOR::MUL:
					case OPERATOR::DIV:
					case OPERATOR::MOD:
					{
						OPERATOR lastOp = _opStack.back();
						switch (lastOp)
						{
						case OPERATOR::MUL:
						case OPERATOR::DIV:
						case OPERATOR::MOD:
						{
							//expr1 / expr2    /  OK
							//expr1 - expr2    /  KO
							MakeExpressionBinary();
						}
						break;
						}
						_opStack.push_back(tok._op);
					}
					break;

					case OPERATOR::ADD:
					case OPERATOR::SUB:
					{
						OPERATOR lastOp = _opStack.back();
						switch (lastOp)
						{
						case OPERATOR::ADD:
						case OPERATOR::SUB:
						case OPERATOR::MUL:
						case OPERATOR::DIV:
						case OPERATOR::MOD:
						{
							//expr1 - expr2    -
							//expr1 / expr2    - 
							MakeExpressionBinary();
						}
						break;
						}
						_opStack.push_back(tok._op);
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
			return std::move(_exprStack[0]);
		}

	public:
		static upExpr<T> Parse(const char* begin, const char* end)
		{
			ExpressionBuilder<T> eb;
			std::vector<Token<T>> tokes = ExpressionBuilder<T>::StringToTokens(begin, end);
			upExpr<T> expr = eb.Build(tokes.begin(), tokes.end());
			return expr;
		}
	};
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

		expr->Print(2);
		std::cout << std::endl;

		++index;
	}

}