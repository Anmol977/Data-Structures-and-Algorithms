#include <map>
#include <string>
#include <iostream>
#include <algorithm>
#include <unordered_set>

int lengthOfLongestSubstring(const std::string &str) //  O(n) time complexity
{
    int n = str.length();
    std::unordered_set<char> freq;
    int maxlen = 0, i = 0, j = 0;
    while (i < n && j < n)
    {
        if (freq.find(str[j]) == freq.end() || freq.empty())
        {
            freq.insert(str[j++]);
            maxlen = std::max(maxlen, j - i);
        }
        else
        {
            freq.erase(str[i++]);
        }
    }
    return maxlen;
}

int longestsubstring(const std::string &str) // O(n^2) time complexity
{
    std::map<char, int> freq;
    std::string substr, maxsubstr = "";
    int maxlen = 0;
    for (auto i = 0; i != str.length(); i++)
    {
        substr = "";
        freq.clear();
        for (auto j = i; j != str.length(); j++)
        {
            if (freq.empty())
            {
                substr.push_back(str[j]);
                freq.insert(std::make_pair(str[j], 1));
                if (substr.length() >= maxlen)
                {
                    maxsubstr = substr;
                    maxlen = maxsubstr.length();
                }
            }
            else
            {
                auto it = freq.find(str[j]);
                if (it == freq.end())
                {
                    substr.push_back(str[j]);
                    freq.insert(std::make_pair(str[j], 1));
                    if (substr.length() >= maxlen)
                    {
                        maxsubstr = substr;
                        maxlen = maxsubstr.length();
                    }
                }
                else
                {
                    substr = "";
                    continue;
                }
            }
        }
    }
    return maxsubstr.length();
}

int main()
{
    int maxsub = lengthOfLongestSubstring("pwwkew");
    std::cout << maxsub;
    return 0;
}