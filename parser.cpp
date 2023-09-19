#include <iostream>
#include <map>
#include <memory>
#include <string>
#include <vector>

#include "AST.h"
#include "parser.h"

using namespace std;

void Parser::parse(
    vector<vector<string>> tokens, string pType) { // this->AST.push_back((shared_ptr<Node>)
                                     // make_shared<Literal>(move(CHILD_NODE)));
  // cout << tokens[tokens.size() - 1][0] << endl;

  for (int i = 0; i < tokens.size(); i++) {
    vector<string> token = tokens[i];
    if (token[0] == "STRING" || token[0] == "NUMBER") {
      Literal literal = Literal();
      literal.type = token[0];
      literal.value = token[1];

      this->AST.push_back(
          (shared_ptr<Node>)make_shared<Literal>(move(literal)));
    }else {
      cout << "error: unexpected token at" << i << endl;
    }
  }
  return;
}