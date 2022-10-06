#ifndef MISSPELLEDV_H
#define MISSPELLEDV_H
#include<string>

using namespace std;

struct misspelledV
{
private:
  string mWord;

public:
  void setWord(string word)
  {
    mWord = word;
  }
  string getWord()
  {
    return mWord;
  }
};
#endif