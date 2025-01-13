#include <bits/stdc++.h>
#include <map>
using namespace std;
 
bool isCheckGroupWord(string word, map<char, int> saveWord)
{
    for(int i = 0; i < word.length(); ++i)
    {
        if(saveWord.find(word[i]) != saveWord.end()) {
            /* find OK
            if saveWord exist word, check location(current location - map value == 1)
            */
           int checkLocation = i - saveWord[word[i]];
           if(checkLocation == 1) {
                // pass -> update location
                saveWord[word[i]] = i;
           } else {
                return false;
           }
        } else {
            // find NG -> insert map
            saveWord[word[i]] = i;
        }
    }
    return true;
}
 
int main(void)
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    map<char, int> saveWord; // string, location
    int answer = 0;
    int N = 0;
    string word = "";
 
    cin >> N; // input
    for(int i = 0;  i < N; ++i) {
        cin >> word;
        if(isCheckGroupWord(word, saveWord)) {
            answer += 1;
        }
        saveWord.clear();
    }
    cout << answer;
}
