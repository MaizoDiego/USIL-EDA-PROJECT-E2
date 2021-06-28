#ifndef __LEXICAL_ANALYZER_H__
#define __LEXICAL_ANALYZER_H__

#include <list>
#include <map>
#include <string>
using namespace std;

#include <ctype.h>
#include "NodeBase.h"

class LexicalAnalyzer
{
  map<string, int> operator_priority = {
        {"^",10},
        {"/",20},
        {"*",30},
        {"-",40},
        {"+",50},
};

  public:
    LexicalAnalyzer() {};
    NodeBase *MakeSyntacticExpressionTree(string str); 
  private:
    NodeBase *MakeSyntacticExpressionTree(list<string> &tokens);
  public:
    list<string> getListofTokens(string str);
};

/*
  Input: string i.e "X5^3/(YW-5)*2^X"
  Output: Expression tree
*/
NodeBase *LexicalAnalyzer::MakeSyntacticExpressionTree(string str)
{ 
  list<string> tokens = getListofTokens(str);
  return MakeSyntacticExpressionTree(tokens);
}

/*
  Input: List of tokens: "X","^","3","/","(","Y","-","5",
                         ")","*","2","^","X"
  Output: Expression tree
*/
NodeBase *LexicalAnalyzer::MakeSyntacticExpressionTree(list<string> &tokens)
{
  //()"^">"*">"/">"+">"-"
  //postorder
  return nullptr;
}

list<string> LexicalAnalyzer::getListofTokens(string str)
{
  list<string> output;
  auto pos = 0;
  string exp;
  auto size = str.size();
  for(auto i = 0; i<size;)
  {
      exp = "";
      if( str[i] == '(' )
      { i++;   // saltar el (
        auto cPar = 1; 
        while(cPar > 0)  // XW+15-(a+(b/c))+K.      => XW, +, 15,-,a+(b/c), +, K
        {   if(str[i] == '(') cPar++;
            if(str[i] == ')') cPar--;
            if( cPar > 0)
              exp += str[i];
            i++;
        }
      }
      else      // No es paréntesis
      {
        if( isalnum(str[i]) ) // letra o numero
        { while( isalnum(str[i]))
            exp += str[i++];
        }
        else    // Operaciones + - * / ^ -> != <>
        {
            while( !isalnum(str[i]))
                exp += str[i++];
        }
      }
      output.push_back(exp);
  }
  return output;
}

#endif
