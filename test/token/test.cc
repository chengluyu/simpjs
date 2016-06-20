#include "../../src/token.h"

#include <iostream>
#include <string>

#define NOT_NULL(x) ((x) ? (x) : "(nope)")

using simpjs::Token;
using simpjs::Tokens;

const char* KeywordTest(Token token) {
  if (Tokens::Literal(token)) {
    std::string lit(Tokens::Literal(token));
    Token lookuped = Tokens::LookupKeyword(lit);
    if (lookuped != Token::Identifier)
      return token == lookuped ? "passed" : "failed";
  }
  return "not a keyword";
}

int main() {
  std::cout << "Test on `tokens.h`" << std::endl;
  std::cout << "Test all token's proeprties." << std::endl;
  std::cout << "------------------------------------" << std::endl;
  for (int i = 0; i < Tokens::TOKEN_COUNT; i++) {
    Token tok = static_cast<Token>(i);
    std::cout << "Token ID: " << i << '\n'
              << "Token Name: " << NOT_NULL(Tokens::Name(tok))  << '\n'
              << "Token Literal: " << NOT_NULL(Tokens::Literal(tok))  << '\n'
              << "Token Precedence: " << Tokens::Precedence(tok) << '\n'
              << "Keyword Test: " << KeywordTest(tok) << '\n'
              << "------------------------------------"
              << std::endl;
  }
  return 0;
}