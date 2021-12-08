#include <iostream>
#include <queue>

int main()
{
     int freq[27]{0};
     std::queue<char> alpha;
     char ch;
     std::cin >> ch;
     while (ch != '.')
     {
          alpha.push(ch);
          freq[ch - 'a']++;
          while (!alpha.empty())
          {
               int i = alpha.front() - 'a';
               if (freq[i] > 1)
                    alpha.pop();
               else
               {
                    std::cout << alpha.front() << std::endl;
                    break;
               }
               if (alpha.empty())
                    std::cout << "-1 \n";
          }
          std::cin >> ch;
     }
}