// Source : https://leetcode.com/problems/substring-with-concatenation-of-all-words/description/
// Author : Shiv S. Kushwaha
// Date   : 2014-08-24

/*
You are given a string, s, and a list of words, words, that are all of the same length. Find all starting indices of substring(s) in s that is a concatenation of each word in words exactly once and without any intervening characters.
For example, given:
s: "barfoothefoobarman"
words: ["foo", "bar"]

You should return the indices: [0,9].
(order does not matter).
*/

#include <iostream>
#include <vector>
#include <string>
#include <map>
using namespace std;

/*
travel all the words combinations to maintain a window
there are wl(word len) times travel
each time, n/wl words, mostly 2 times travel for each word
one left side of the window, the other right side of the window
so, time complexity O(wl * 2 * N/wl) = O(2N)
*/

vector<int> findSubstring(string S, vector<string> &L) {
  vector<int> ans;
  int n = S.size(), cnt = L.size();
  if (n <= 0 || cnt <= 0) return ans;

  // init word occurence
  unordered_map<string, int> dict;
  for (int i = 0; i < cnt; ++i) dict[L[i]]++;

  // travel all sub string combinations
  int wl = L[0].size();
  for (int i = 0; i < wl; ++i) {
    int left = i, count = 0;
    unordered_map<string, int> tdict;
    for (int j = i; j <= n - wl; j += wl) {
      string str = S.substr(j, wl);
      // a valid word, accumulate results
      if (dict.count(str)) {
        tdict[str]++;
        if (tdict[str] <= dict[str])
          count++;
        else {
          // a more word, advance the window left side possiablly
          while (tdict[str] > dict[str]) {
            string str1 = S.substr(left, wl);
            tdict[str1]--;
            if (tdict[str1] < dict[str1]) count--;
            left += wl;
          }
        }
        // come to a result
        if (count == cnt) {
          ans.push_back(left);
          // advance one word
          tdict[S.substr(left, wl)]--;
          count--;
          left += wl;
        }
      }
      // not a valid word, reset all vars
      else {
        tdict.clear();
        count = 0;
        left = j + wl;
      }
    }
  }

  return ans;
}


int main(int argc, char**argv)
{
  string s = "barfoobarfoothefoobarman";
  vector<string> l;
  l.push_back("foo");
  l.push_back("bar");
  l.push_back("foo");

  vector<int> indics = findSubstring(s, l);

  for (int i = 0; i < indics.size(); i++) {
    cout << indics[i] << " ";
  }
  cout << endl;

  return 0;
}
