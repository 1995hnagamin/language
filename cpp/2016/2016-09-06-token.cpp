#include <string>
#include <vector>
#include <exception>
#include "lexer.hpp"

enum class TokenType {
  SmallName,
  CapitalName,
  SpecialName,
  Digit,
  Symbol,
  Eof
};

class BadGetterException : std::domain_error {
  public:
    BadGetterException(std::string const & cause);
};

class Token {
  public:
    Token(TokenType type, std::string const & literal);
    TokenType type() const;
    std::string representation() const;
    std::string get_as_name() const;
    int get_as_integer() const;
  private:
    TokenType token_type;
    std::string literal;
};

class TokenStream {
  public:
    TokenStream(std::vector<Token> const & tokens);
  private:
    std::vector<Token> stream;
};


BadGetterException::BadGetterException(std::string const & cause):
  std::domain_error(cause)
{}

Token::Token(TokenType type, std::string const & token_literal):
  token_type(type),
  literal(token_literal)
{}

TokenType Token::type() const {
  return token_type;
}

std::string Token::representation() const {
  return literal;
}

std::string Token::get_as_name() const {
  switch (token_type) {
    case TokenType::SmallName:
    case TokenType::CapitalName:
    case TokenType::SpecialName:
      return literal;
    default:
      throw BadGetterException("Not a name");
  }
}

int Token::get_as_integer() const {
  switch (token_type) {
    case TokenType::Digit:
      return std::stoi(literal);
    default:
      throw BadGetterException("Not an integer");
  }
}

TokenStream::TokenStream(const std::vector<Token>& tokens):
  stream(tokens)
{}
