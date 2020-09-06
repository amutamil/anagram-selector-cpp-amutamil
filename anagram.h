#include <string>
#include <vector>
using namespace std;
namespace Anagram
{
    bool WordPairIsAnagram(const string& word1, const string& word2);

    vector<string> SelectAnagrams(
        const string& word,
        const vector<string>& candidates);
} // namespace Anagram
