#include <iostream>
#include "LexicalAnalyzer.h"
using namespace std;

int main() 
{
  LexicalAnalyzer la;
  // string exp = "a+b/(35^X-(y+3))-6";
  //string exp = "a+b/x-y+3-6";
  string exp = "(a+b/x)-y+sin(3-6)";
  list<string> tokens = la.getListofTokens(exp);
  cout << exp << endl;
  for(auto tok: tokens)
    cout << tok << endl;
}
