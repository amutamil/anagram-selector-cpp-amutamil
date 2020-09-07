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

bool Anagram::WordPairIsAnagram(const string& word1, const string& word2) {
    string word1copy = word1, word2copy = word2;
    string word1_arranged = arrange(word1copy);
    string word2_arranged = arrange(word2copy);
    if (word1_arranged.length() != word2_arranged.length())
        return false;
    for (unsigned int i = 0;i < word1_arranged.length();i++)
    {
        if (word1_arranged[i] != word2_arranged[i])
        {
            return  false;
        }
    }
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
