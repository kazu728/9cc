#include <ctype.h>
#include <stdarg.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void error(char *loc, char *fmt, ...);
extern char *user_input;

typedef enum {
  ND_ADD,
  ND_SUB,
  ND_MUL,
  ND_DIV,
  ND_EQ,
  ND_NE,
  ND_LT,
  ND_LE,
  ND_NUM
} NodeKind;

typedef struct Node Node;

struct Node {
  NodeKind kind;
  Node *lhs;
  Node *rhs;
  int val;
  };

  // Token
  typedef enum {
    TK_RESERVED,
    TK_NUM,
    TK_EOF,
  } TokenKind;

  typedef struct Token Token;

  struct Token {
    TokenKind kind;
    Token *next;
    int val;
    char *str;
    int len;
  };

  extern Token *token;

  // Codegen
  void gen(Node * node);

  // Tokenizer
  Token *tokenize(char *p);

  // Parser
  bool consume(char *op);
  void expect(char *op);
  int expect_number();
  bool at_eof();
  bool startswith(char *p, char *q);

  //
  Node *expr();
  Node *equality();
  Node *relational();
  Node *add();
  Node *mul();
  Node *unary();
  Node *primary();

  // New token, node
  Token *new_token(TokenKind kind, Token * cur, char *str, int len);
  Node *new_node(NodeKind kind);
  Node *new_node_num(int val);
  Node *new_binary(NodeKind kind, Node * lhs, Node * rhs);