#ifndef SIMPJS_TOKEN_H
#define SIMPJS_TOKEN_H

#include <string>
#include <unordered_map>

// #include "flora.h"
#include "checks.h"

namespace simpjs {

#define TOKEN_LIST(K, T)\
  T(EndOfSource, "(end of source)", 0)\
  /* Punctuation marks */\
  T(LeftParenthesis, "(", 0)\
  T(RightParenthesis, ")", 0)\
  T(LeftBracket, "[", 0)\
  T(RightBracket, "]", 0)\
  T(LeftBrace, "{", 0)\
  T(RightBrace, "}", 0)\
  T(Colon, ":", 0)\
  T(Semicolon, ";", 0)\
  T(Period, ".", 0)\
  T(Conditional, "?", 0)\
  T(Increment, "++", 0)\
  T(Decrement, "--", 0)\
  T(PostfixIncrement, "++", 0)\
  T(PostfixDecrement, "--", 0)\
  /* Assignment operators */\
  T(Assignment, "=", 2)\
  T(AssignmentBitwiseOr, "|=", 2)\
  T(AssignmentBitwiseXor, "^=", 2)\
  T(AssignmentBitwiseAnd, "&=", 2)\
  T(AssignmentShiftLeft, "<<=",2)\
  T(AssignmentShiftRight, ">>=",2)\
  T(AssignmentUnsignedShiftRight, ">>>=",2)\
  T(AssignmentAddition, "+=", 2)\
  T(AssignmentSubtraction, "-=", 2)\
  T(AssignmentMultiplication, "*=", 2)\
  T(AssignmentDivision, "/=", 2)\
  T(AssignmentModulus, "%=", 2)\
  /* Binary operators */\
  T(Comma, ",", 1)\
  T(LogicalOr, "||", 4)\
  T(LogicalAnd, "&&", 4)\
  T(BitwiseOr, "|", 6)\
  T(BitwiseXor, "^", 7)\
  T(BitwiseAnd, "&", 8)\
  T(ShiftLeft, "<<", 11)\
  T(ShiftRight, ">>", 11)\
  T(UnsignedShiftRight, ">>", 11)\
  T(Addition, "+", 12)\
  T(Subtraction, "-", 12)\
  T(Multiplication, "*", 12)\
  T(Division, "/", 13)\
  T(Modulus, "%", 13)\
  /* Compare operators */\
  T(Equal, "==", 9)\
  T(NotEqual, "!=", 9)\
  T(LessThan, "<", 10)\
  T(GreaterThan, ">", 10)\
  T(LessThanOrEqual, "<=", 10)\
  T(GreaterThanOrEqual, ">=", 10)\
  /* Unary operators */\
  T(LogicalNot, "!", 0)\
  T(BitwiseNot, "~", 0)\
  /* Keywords */\
  K(As, "as", 0)\
  K(Break, "break", 0)\
  K(Case, "case", 0)\
  K(Catch, "catch", 0)\
  K(Const, "const", 0)\
  K(Continue, "continue", 0)\
  K(Default, "default", 0)\
  K(Do, "do", 0)\
  K(Else, "else", 0)\
  K(Finally, "finally", 0)\
  K(For, "for", 0)\
  K(If, "if", 0)\
  K(New, "new", 0)\
  K(Return, "return", 0)\
  K(Switch, "switch", 0)\
  K(This, "this", 0)\
  K(Throw, "throw", 0)\
  K(Try, "try", 0)\
  K(While, "while", 0)\
  /* Literals */\
  K(Undefined, "undefined", 0)\
  K(Null, "null", 0)\
  K(True, "true", 0)\
  K(False, "false", 0)\
  T(Number, nullptr, 0)\
  T(String, nullptr, 0)\
  /* Identifier */\
  T(Identifier, nullptr, 0)\
  /* Illegal token */\
  T(Illegal, nullptr, 0)


enum class Token : int {
#define T(name, string, precedence) name,
  TOKEN_LIST(T, T)
  TOKEN_COUNT
#undef T
};

class Tokens {
public:

  static const char* Name(Token token) {
    return name_[static_cast<int>(token)];
  }

  static const char* Literal(Token token) {
    return literal_[static_cast<int>(token)];
  }

  static int Precedence(Token token) {
    return precedence_[static_cast<int>(token)];
  }

  static Token RemoveAssignment(Token token) {
    switch (token) {
      case Token::AssignmentBitwiseOr: return Token::BitwiseOr;
      case Token::AssignmentBitwiseXor: return Token::BitwiseXor;
      case Token::AssignmentBitwiseAnd: return Token::BitwiseAnd;
      case Token::AssignmentShiftLeft: return Token::ShiftLeft;
      case Token::AssignmentShiftRight: return Token::ShiftRight;
      case Token::AssignmentAddition: return Token::Addition;
      case Token::AssignmentSubtraction: return Token::Subtraction;
      case Token::AssignmentMultiplication: return Token::Multiplication;
      case Token::AssignmentDivision: return Token::Division;
      case Token::AssignmentModulus: return Token::Modulus;
      default: UNREACHABLE();
    }
  }

  static Token LookupKeyword(const std::string &identifier);

  // The number of tokens
  static const int TOKEN_COUNT = static_cast<int>(Token::TOKEN_COUNT);

private:
  // Token information
  static const char *name_[TOKEN_COUNT];
  static const char *literal_[TOKEN_COUNT];
  static const int precedence_[TOKEN_COUNT];
  // Hashtable used to lookup keywords
  static std::unordered_map<std::string, Token> lookup_table_;
  static void InitializeKeywordLookupTable();
  // Singleton object used to automatically initialize hashtable
  Tokens();
  static Tokens singleton;
};

}
#endif