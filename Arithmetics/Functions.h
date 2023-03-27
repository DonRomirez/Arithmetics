#pragma once
#include <iostream>
#include "Stack.h"
#include "Table.h"
#include <string>
#include<queue>

class Functions
{
	Table t;
public:
	Functions() {}
	bool CheckBracket(std::string S) {
		int size = S.size();
		int check = 1;
		StackC<int> ST(size);
		for (int i = 0; i < size; i++) {
			if (S[i] == '(') {
				ST.push(i);
			}
			if (S[i] == ')') {
				if (ST.IsEmpty()) {
					//cout << ") in" << i + 1 << " symbol isn't paired (" << endl;
					check = 0;
				}
				else ST.pop();
			}

		}

		while (!ST.IsEmpty()) {
			//cout << "( in " << ST.pop() + 1 << "symbol isn't paired" << endl;
			check = 0;
		}
		if ((ST.IsEmpty()) && (check == 1)) {
			//cout << "No errors" << endl;
			return true;
		}
		else { return false; }
	}
	std::queue<std::pair<std::string, int>> Lexical_view(std::string S) {
		std::queue<std::pair<std::string, int>> q;
		std::string str = S;
		str += " ";
		std::string t;
		std::string op = "()+-*/";
		int state = 0;
		int size = str.size();
		for (int i = 0; i < size; i++) {
			int IsOp = op.find(str[i]);
			if (state == 0)
			{
				if (IsOp >= 0)
				{
					if (IsOp == 1)
						q.push({ std::string(1, str[i]), 4 });
					if (IsOp == 0)
						q.push({ std::string(1, str[i]), 1 });
					if ((IsOp == 2) || (IsOp == 3))
						q.push({ std::string(1, str[i]), 2 });
					if ((IsOp == 4) || (IsOp == 5))
						q.push({ std::string(1, str[i]), 3 });
				}
				else {
					if (((str[i] >= '0') && (str[i] <= '9')) || (str[i] == '.') || ((str[i] >= 'a') && (str[i] <= 'z'))) {
						t = str[i];
						state = 1;
					}
				}
			}


			else {
				if (state == 1) {
					if (((str[i] >= '0') && (str[i] <= '9')) || (str[i] == '.') || ((str[i] >= 'a') && (str[i] <= 'z'))) {
						t += str[i];
					}
					else
						if (IsOp >= 0)
						{
							q.push({ t,0 });
							if (IsOp == 1)
								q.push({ std::string(1, str[i]), 4 });
							if (IsOp == 0)
								q.push({ std::string(1, str[i]), 1 });
							if ((IsOp == 2) || (IsOp == 3))
								q.push({ std::string(1, str[i]), 2 });
							if ((IsOp == 4) || (IsOp == 5))
								q.push({ std::string(1, str[i]), 3 });
							state = 0;
						}
						else {
							q.push({ t,0 });
							state = 0;
						}


				}
			}
		}
		return q;
	}
	void print_Lex_view(std::queue<std::pair<std::string, int>> q) {
		while (!q.empty()) {
			std::pair<std::string, int> val = q.front();
			q.pop();
			std::cout << val.first << "[" << val.second << "]" << " ";
		}
		std::cout << std::endl;
	}
	void addParameter(std::string p, std::string val) {
		t.Set(p, val);
	}
	void Match_table(std::queue<std::pair<std::string, int>> q) {
		while (!q.empty()) {
			std::pair<std::string, int> val = q.front();
			q.pop();
			if ((val.first[0] >= 'a') && (val.first[0] <= 'z')) {
				std::string c = val.first;
				t.Set(c, "0");
			}
			std::cout << std::endl;
		}
	}
	std::string Reverse_Polish_notation(std::queue<std::pair<std::string, int>> q) {
		std::string res;
		StackC < std::pair < std:: string, int >> ST(100);
		std::pair<std::string, int> op, val;
		while (!q.empty()) {
			val = q.front();
			q.pop();
			if (val.second == 0) {
				res += val.first;
				res += " ";
			}
			else {
				if (val.first == "(") {
					ST.push(val);
				}
				if (val.first == ")") {
					while (true) {
						op = ST.pop();
						if (op.first == "(") break;
						res += op.first;
						res += " ";

					}
				}
				if ((val.first == "*") || (val.first == "/") || (val.first == "+") || (val.first == "-")) {
					while (!ST.IsEmpty()) {
						op = ST.pop();
						if (val.second <= op.second) {
							res += op.first;
							res += " ";
						}
						else {
							ST.push(op);
							break;
						}
					}
					ST.push(val);
				}

			}

		}
		while (!ST.IsEmpty()) {
			std::pair<std::string, int> val3 = ST.pop();
			res += val3.first;
			res += " ";
		}
		return res;
	}
	std::string RPN_translate(std::string rpn) {
		std::string res;
		for (int i = 0; i < rpn.size(); i++) {
			if ((rpn[i] >= 'a') && (rpn[i] <= 'z')) {
				res += t.GetVal(std::to_string(rpn[i]));
				continue;
			}
			res += rpn[i];

		}
	}
	double Result(std::queue<std::pair<std::string, int>> qp) {
		double res = 0.0, operand1 = 0.0, operand2 = 0.0;
		StackC<double> ST;
		std::pair<std::string, int> val;
		while (!qp.empty()) {
			val = qp.front();
			qp.pop();
			if (val.second == 0) {
				double value = stod(val.first);
				ST.push(value);
			}
			else {
				if (val.first == "*") {
					operand1 = ST.pop();
					operand2 = ST.pop();
					res = operand1 * operand2;
					ST.push(res);
				}
				if (val.first == "/") {
					operand1 = ST.pop();
					operand2 = ST.pop();
					res = operand2 / operand1;
					ST.push(res);
				}
				if (val.first == "+") {
					operand1 = ST.pop();
					operand2 = ST.pop();
					res = operand1 + operand2;
					ST.push(res);
				}
				if (val.first == "-") {
					operand1 = ST.pop();
					operand2 = ST.pop();
					res = operand2 - operand1;
					ST.push(res);
				}
			}


		}
		res = ST.pop();
		return res;
	}
	std::string Double_To_String(double d) {
		std::string s = std::to_string(d);
		return s;
	}
	std::string Char_To_String(char c) {
		std::string s = std::to_string(c);
		return s;
	}
	void SetVal(std::string key, std::string val) {
		t.Set(key, val);
	}
};

