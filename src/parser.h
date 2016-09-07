
class Parser {
public:
  Parser();
  void Initialize(Scanner *scanner);

  AstNode* ParseProgram();
private:
  Token peek;
  bool Match(Token expected);
  void Expect(Token )

  // Scope management
  Scope *current_scope_;

  Scope* NewScope();
  void LeaveScope();
  Symbol* NewSymbol();

  // Parsing routines 
  AstNode* ParseProgram();

  Expression* ParseNullDenotation();
  Expression* ParseLeftDenotation();

  Expression* ParseExpression(int rbp = 0);
  Statement* ParseStatement();
  Expression* ParseFunction();
  Statement* ParseBlock();
  Expression* ParseLocal();
  Statement* ParseIf();
  Statement* ParseReturn();
  Statement* ParseBreak();
  Statement* ParseWhile();
  Statement* ParseDoWhile();
};