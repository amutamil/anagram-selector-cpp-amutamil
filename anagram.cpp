#include "anagram.h"
#include<algorithm>
using namespace std;


string arrange(string& str)
{
    int count = 0;string str2;
    for (unsigned int i = 0;i < str.length();i++)
    {
        if (str[i] != ' ')
        {
            str[count] = str[i];
            count += 1;
        }
       str2 = str.substr(0, count);
    }transform(str2.begin(), str2.end(), str2.begin(), ::tolower);
    sort(str2.begin(), str2.end());
    return str2;
}

bool checklength( string word1,  string word2)
{
    if (word1.length() != word2.length())
    {   return false;    }     
    return true;
}
bool checkChar( string word1,  string word2)
{
    for (unsigned int i = 0;i < word1.length();i++)
    {
        if (word1[i] != word2[i])
        {
            return  false;
        }
    }
    return true;
}
bool WordPairIsAnagram(const string& word1, const string& word2) {
    string word1copy = word1;string word2copy = word2;
    string word1_arranged = arrange(word1copy);
    string word2_arranged = arrange(word2copy);
    bool result = false;
    if(checklength(word1_arranged, word2_arranged))
        result = checkChar(word1_arranged, word2_arranged);
    return true;
}

vector<string> Anagram::SelectAnagrams(
        const string& word,
        const vector<string>& candidates) {
    //Fill the correct implementation here
    vector<string> selection;
    for (unsigned int i = 0;i < candidates.size();i++)
    {
        if (WordPairIsAnagram(word, candidates[i]))
            selection.push_back(candidates[i]);
    }
    return selection;
    
}
