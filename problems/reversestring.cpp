#include <iostream>
#include <string>
#include <cctype>
#include <algorithm>

const char* ws = " \t\n\r\f\v";

inline std::string& rtrim(std::string& s, const char* t = " \t\n\r\f\v")
{
    s.erase(s.find_last_not_of(t) + 1);
    return s;
}

inline std::string& ltrim(std::string& s, const char* t = " \t\n\r\f\v")
{
    s.erase(0, s.find_first_not_of(t));
    return s;
}

inline std::string& trim(std::string& s, const char* t = " \t\n\r\f\v")
{
    return ltrim(rtrim(s, t), t);
}

void remspace(std::string &s)
{
    trim(s);
    for (auto i = 0; i != s.size(); i++)
    {
        while (isspace(s[i]) && isspace(s[i + 1])){
            s.erase(i, 1);
        }
    }
}

std::string reverseWords(std::string s)
{
    remspace(s);
    int start = 0;
    reverse(s.begin(), s.end());
    for (int i = 0; i < s.size(); i++)
    {
        if (s[i] == ' ')
        {
            reverse(s.begin() + start, s.begin() + i);
            start = i + 1;
        }
    }
    reverse(s.begin() + start, s.end());
    return s;
}

int main()
{
    std::string s = "      this         is    a                  string !         ";
    std::string res = reverseWords(s);
    std::cout << res;
    return 0;
}