#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include "timer.h" 
#include "binarySearchTree.h"
#include "binaryNode.h"
#include "misspelledV.h"

using namespace std;

//declaring functions and data structures
string cleanWord(string wordD);
binarySearchTree<string> dictionaryTree;


int main()
{

    Timer tim;
    
    //reading the dictionary
    int dictionarySize = 0;
    string tmp;

    ifstream dictFile;
    dictFile.open("dict.txt");
    
    while(dictFile >> tmp)
    {
        tmp = cleanWord(tmp);
        dictionaryTree.insert(tmp);
        dictionarySize++;
    }
    
    //starting the time
    tim.Start();

    //reading the book file and comparing to the dictionary
    string btmp;
    ifstream bookFile;
    vector<misspelledV*> bookV;

    bookFile.open("book.txt");

    //the number of skipped, misspelled, and matched words
    int skipped = 0; 
    int misspelled = 0;
    int matchNum = 0; 

    //keeping track of the number of compares
    long long int matchComp = 0;
    long long int missComp = 0; 
    long long int tempComp = 0;
    
    while(bookFile >> btmp)
    {
        btmp = cleanWord(btmp);
        if(btmp == "")
        {
        }
        else if(!isalpha(btmp[0]) || btmp[0] == '\"')
        {
            skipped++;
        }
        else
        {
            if(dictionaryTree.find(btmp, tempComp))
            {
                matchNum++;
                matchComp += tempComp;
                tempComp = 0;
            }
            else
            {
                bookV.push_back(new misspelledV);
                bookV.at(misspelled) -> setWord(btmp);
                misspelled++;
                missComp += tempComp;
                tempComp = 0;
            }
        }
    }

    tim.Stop();

    cout << "dictionary Size: " << dictionarySize << "\n";
    cout << "Done checking and these are the results \n";
    cout << " Finished in time: " << tim.Time() << "\n";//setprecision(2) << tim.Time() << "\n";
    cout << " There are: " << matchNum << " words found in the dictionary\n";
    cout << matchComp  << " compares. Average : " << matchComp/matchNum << "\n";
    cout << "There are " << misspelled << " words NOT found in the dictionary\n"; 
    cout << missComp  << " compares. Average: " << missComp/misspelled << "\n";
    cout << "There are " << skipped << " words not checked.";
    
    //writing to the misspelled file
    ofstream missFile;
    string tempString;
    missFile.open("misspelled.txt");

    for(int i =0; i<bookV.size(); i++)
    {
        tempString = bookV.at(i)->getWord();
        missFile<< tempString << endl;
    }

    missFile.close();
}

string cleanWord(string word)
{
    string cleanW = "";
    for(int i =0; i< word.size(); i++)
    {
        if(isupper(word[i]))
        {
            word[i] = tolower(word[i]);
        }
        if(isalnum(word[i]))
        {
            cleanW = cleanW + word[i];
        }
        else if(word[i] == '\'')
        {
            cleanW = cleanW + word[i];
        }
    }
    
    //return word;
    return cleanW;
};