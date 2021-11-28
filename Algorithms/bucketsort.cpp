#include <iostream>
#include <vector>
#include <string>

class student
{
public:
    std::string name;
    int marks;
};

void bucket_sort(student sarr[],int n)
{
    std::vector<student> v[101];
    for (int i = 0; i != n; i++)
    {
        int m = sarr[i].marks;
        v[m].push_back(sarr[i]);
    }
    for (auto i = 100; i >= 0; i--)
    {
        for (auto j = v[i].begin(); j != v[i].end(); j++)
        {
            std::cout << (*j).marks << " " << (*j).name << std::endl;
        }
    }
}

int main()
{
    student sarr[1000];
    for (int i = 0; i != 10; i++){
        std::cin >> sarr[i].marks >> sarr[i].name;
    }
    bucket_sort(sarr,10);
}