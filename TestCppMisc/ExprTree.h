
#include <cassert>
#include <iostream>
#include <fstream>
#include <sstream>
#include <memory>
#include <vector>
#include <stack>
#include <string>
#include <unordered_set>
#include <set>
#include <random>

namespace SmartLib
{

	enum class ExprType
	{
		ET_NUMBER,
		ET_ID,
		ET_BIN,
		ET_FUNC,
	};

	template<typename T>
	class Expression
	{
	public:
		virtual ~Expression() {};
		virtual T Evaluate() const = 0;
		virtual void Print(int spaceCount, std::ostream& out) const = 0;
		virtual ExprType GetExprType() const = 0;
		virtual void SetExprType(ExprType et)
		{
			assert(false);
		}

		virtual void AddArg(std::unique_ptr<Expression<T>> arg)
		{
			assert(false);
		}
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

		virtual ExprType GetExprType() const override
		{
			return ExprType::ET_NUMBER;
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
				if constexpr (std::is_floating_point_v<T>)
				{
					long long times = (long long)(leftVal / rightVal);
					result = leftVal - times * rightVal;
				}
				else
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

		virtual ExprType GetExprType() const override
		{
			return ExprType::ET_BIN;
		}
	};


	template<typename T>
	class ExpressionFuncOrId : public Expression<T>
	{
	private:
		std::string _idName;
		std::vector<upExpr<T>> _args;
		ExprType _et{ ExprType::ET_ID };

	public:
		ExpressionFuncOrId(std::string idName) :
			_idName{ std::move(idName) }
		{
		}

		ExpressionFuncOrId(std::string idName, std::vector<upExpr<T>> args) :
			_idName{ std::move(idName) },
			_args{ std::move(args) }
		{
		}

		virtual ~ExpressionFuncOrId() override
		{
		}

		virtual void SetExprType(ExprType et) override
		{
			_et = et;
		}

		virtual void AddArg(upExpr<T> arg) override
		{
			_args.push_back(std::move(arg));
		}

		virtual T Evaluate() const override
		{
			if constexpr (false)
			{
				assert(false);
				//compile the function for production
				return T{};
			}
			else
			{
				T rv{};
				for (const auto& expr : _args) //arg0 + arg1 + arg2 + ... for test purpose
				{
					rv += expr->Evaluate();
				}
				return rv;
			}
		}

		virtual void Print(int spaceCount, std::ostream& out) const override
		{
			if (ExprType::ET_ID == _et)
			{
				for (int ii = 0; ii < spaceCount; ++ii)
				{
					out << '\t';
				}
				out << _idName << std::endl;
			}
			else
			{

				for (int ii = 0; ii < spaceCount; ++ii)
				{
					out << '\t';
				}
				out << _idName << std::endl;

				for (int ii = 0; ii < spaceCount; ++ii)
				{
					out << '\t';
				}
				out << "(" << std::endl;


				for (const auto& arg : _args)
				{
					arg->Print(spaceCount + 1, out);

					for (int ii = 0; ii < spaceCount + 1; ++ii)
					{
						out << '\t';
					}
					out << ',' << std::endl;;
				}


				for (int ii = 0; ii < spaceCount; ++ii)
				{
					out << '\t';
				}
				out << ")" << std::endl;
			}
		}

		virtual ExprType GetExprType() const override
		{
			return _et;
		}
	};

	enum class TokenType
	{
		TT_OP,
		TT_NUM,
		TT_ID,
		TT_COMMA,
	};

	template<typename T>
	struct Token
	{
		TokenType _type;
		OPERATOR _op{ OPERATOR::INVALID };
		T _number{};
		std::string _id;

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


		Token(std::string id) :
			_type{ TokenType::TT_ID },
			_id{ std::move(id) }
		{
		}

		Token(TokenType tt) :
			_type{ tt }
		{
		}
	};

	template<typename T>
	class ExpressionBuilder
	{
		std::stack<upExpr<T>> _exprStack;
		std::stack<OPERATOR> _opStack;
		//std::stack<std::vector<upExpr<T>>> _argsStack;

	public:
		template<typename U>
		U PopTop(std::stack<U>& s)
		{
			U cur = std::move(s.top());
			s.pop();
			return cur;
		}

	private:
		void MakeExpressionBinary()
		{
			//expr1 op expr2 --> exprNew
			OPERATOR topOp = PopTop(_opStack);

			upExpr<T> expr2 = PopTop(_exprStack);

			upExpr<T> expr1 = PopTop(_exprStack);

			auto exprNew = std::make_unique<ExpressionBinary<T>>(topOp, std::move(expr1), std::move(expr2));

			_exprStack.push(std::move(exprNew));

		}

		void AddToArgs()
		{
			//move from expression stack to argsStack top
			upExpr<T> arg = PopTop(_exprStack);
			auto& funcExpr = _exprStack.top();
			assert(ExprType::ET_FUNC == funcExpr->GetExprType());
			funcExpr->AddArg(std::move(arg));
			//_argsStack.top().push_back(std::move(arg));
		}

	private:

		static bool IsIdStartChar(char ch)
		{
			return ch == '_' ||
				(ch >= 'A' && ch <= 'Z') ||
				(ch >= 'a' && ch <= 'z');
		}

		static bool IsIdChar(char ch)
		{
			return ch == '_' ||
				(ch >= 'A' && ch <= 'Z') ||
				(ch >= 'a' && ch <= 'z') ||
				(ch >= '0' && ch <= '9');
		}


		static bool IsNumStartChar(char ch)
		{
			if constexpr (std::is_floating_point_v<T>)
			{
				return std::isdigit(ch) || ('.' == ch);
			}
			else
			{
				return std::isdigit(ch);
			}
		}

		static bool IsOpChar(char ch)
		{
			static std::unordered_set<char> op_char = { '+', '-', '*', '/', '%', '(', ')' };
			return op_char.end() != op_char.find(ch);
		}

		static bool IsCommaChar(char ch)
		{
			return ',' == ch;
		}

		static std::vector<Token<T>> StringToTokens(const char* begin, const char* end)
		{
			std::vector<Token<T>> result;
			result.push_back(Token<T>((OPERATOR)('('))); //add guarded token (
			while (begin != end && *begin)
			{
				const char ch = *begin;
				if (IsIdStartChar(ch))
				{
					std::string strid;
					strid += ch;
					++begin;

					char chTmp = 0;
					while (IsIdChar(chTmp = *begin))
					{
						strid += chTmp;
						++begin;
					}
					result.push_back(Token<T>(strid));
				}
				else if (IsNumStartChar(ch))
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
				else if (IsCommaChar(ch))
				{
					result.push_back(Token<T>(TokenType::TT_COMMA));
					++begin;
				}
				else if (IsOpChar(ch))
				{
					result.push_back(Token<T>((OPERATOR)(ch)));
					++begin;
				}
				else //if (std::isspace(ch))
				{
					assert(std::isspace(ch));
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

				case TokenType::TT_ID:
				{
					_exprStack.push(std::make_unique<ExpressionFuncOrId<T>>(tok._id));
				}
				break;

				case TokenType::TT_COMMA:
				{
					AddToArgs();
				}
				break;

				case TokenType::TT_OP:
				{
					switch (tok._op)
					{
					case OPERATOR::LEFT_BRACKET:
					{
						if (_exprStack.size() && ExprType::ET_ID == _exprStack.top()->GetExprType())
						{
							_exprStack.top()->SetExprType(ExprType::ET_FUNC);
						}
						_opStack.push(OPERATOR::LEFT_BRACKET);
					}
					break;

					case OPERATOR::RIGHT_BRACKET:
					{
						//(
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

						//funcName
						//funcName lastArg
						//ProcessPossilbleLastArg();
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
		static bool IsCloseFloat(T val1, T val2, T relTol, T absTol)
		{
			//
			T relTolVal = relTol * std::max(std::abs(val1), std::abs(val2));
			return std::abs(val1 - val2) <= std::max(relTolVal, absTol);
		}

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
