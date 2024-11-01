#include <iostream>
#include <string>
using namespace std;

string ProcessBrackets(string s)    
{
    size_t start = 0,   
        finish;       

    
    while ((start = s.find('(', start)) != -1)
    {
        
        finish = s.find(')', start + 1);
        if (finish == -1)
        {
            start++;    
            continue;
        }

        // перевіряємо наявність вкладених дужок
        size_t nested_start = s.find('(', start + 1);
        if (nested_start != -1 && nested_start < finish)
        {
            // шукаємо останню закриваючу дужку 
            size_t outer_finish = finish;
            while (true)
            {
                size_t next_finish = s.find(')', outer_finish + 1);
                if (next_finish == -1) break;
                outer_finish = next_finish;
            }

            // видаляємо все між зовнішніми дужками включно з дужками
            s.erase(start, outer_finish - start + 1);
        }
        else
        {
            // видаляємо вміст між дужками разом з дужками
            s.erase(start, finish - start + 1);
        }
    }

    return s;
}

int main()
{
    string str;
    cout << "Enter string:" << endl;
    getline(cin, str);

    cout << "Result: " << ProcessBrackets(str) << endl;

    return 0;
}