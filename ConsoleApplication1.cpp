// ConsoleApplication1.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include <stdexcept>//for runtime_error
#include "head.h"

using namespace std;

void letterGrade(vector<int> intGrade);
bool isVowel(string::iterator it);
bool isSpace(string::iterator it);
bool isT(string::iterator it);
void symbolCnt();
void wordCnt();
void wordCnt2();
void errDeal();

int main()
{
#if 0
    vector<int> grade = { 50,60,70,80,90,62,73,85,100 };

    letterGrade(grade);
#endif
    //symbolCnt();
    //wordCnt();
    //wordCnt2();

    errDeal();

    return 0;
}

void letterGrade(vector<int> intGrade)
{
    vector<string> grade = { "E","D","C","B","A","A++" };//0 1 2 3 4 5
    vector<string> letGrade;

    for (auto i : intGrade)
    {
        if (i < 60)
        {
            letGrade.push_back(grade[0]);
        }

        if (i == 100)
        {
            letGrade.push_back(grade[5]);
        }
        else
        {
            letGrade.push_back(grade[(i - 50) / 10]);
        }
        
    }

    for (auto i : letGrade)
    {
        cout << i << " ";
    }

}

bool isVowel(string::iterator it)
{
    *it = tolower(*it);

    if (*it == 'a' || *it == 'e' || *it == 'i' || *it == 'o' || *it == 'u')
    {
        return true;
    }

    return false;
}

bool isSpace(string::iterator it)
{
    if (*it == ' ')
    {
        return true;
    }

    return 0;
}

bool isT(string::iterator it)
{
    if (*it == '\t')
    {
        return true;
    }

    return 0;
}

void symbolCnt()
{
    int vowelCnt = 0;
    int spaceCnt = 0, tCnt = 0, nCnt = 0;
    vector<string> cntString = { "ff","fl","fi" };
    int stringCnt = 0;

    string str;
    while (getline(cin, str))
    {
        for (auto it = str.begin(); it != str.end() - 1; ++it)
        {
            if (isVowel(it))
            {
                ++vowelCnt;
            }

            if (isSpace(it))
            {
                ++spaceCnt;
            }

            if (isT(it))
            {
                ++tCnt;
            }

            if (*it == 'f')
            {
                if (*(it + 1) == 'f' || *(it + 1) == 'l' || *(it + 1) == 'i')
                {
                    ++stringCnt;
                }
            }

        }
        ++nCnt;

        if (isVowel(str.end() - 1))
        {
            ++vowelCnt;
        }

        if (isSpace(str.end() - 1))
        {
            ++spaceCnt;
        }

        if (isT(str.end() - 1))
        {
            ++tCnt;
        }
    }

    cout << "vowelCnt: " << vowelCnt << endl;
    cout << "stringCnt: " << stringCnt << endl;
    cout << "spaceCnt: " << spaceCnt << endl;
    cout << "nCnt: " << nCnt << endl;
    cout << "tCnt: " << tCnt << endl;
}

void wordCnt()
{
    string word = "";
    
    int cnt = 1, cntTemp = 1;
    string strMax = word;
    string strTemp = word;
    while (cin >> word)
    {
        if (word == strTemp)
        {
            ++cntTemp;
        }
        else
        {
            if (cnt < cntTemp)
            {
                strMax = strTemp;
                cnt = cntTemp;
            }
            cntTemp = 1;
            strTemp = word;
        }
    }

    cout << "strMax: " << strMax << endl;
    cout << "cnt " << cnt << endl;
}

void wordCnt2()
{
    string lastWord = "";
    string word;
    while (cin >> word)
    {
        if (word == lastWord)
        {
            cout << "word: " << word << " show twice." << endl;
            break;
        }
        lastWord = word;
    }
}

void errDeal()
{
    double val1, val2;
    cout << "Enter two numbers: ";
    while (cin >> val1 >> val2)
    {
        double res;
        try {
            res = val1 / val2;
            if (val2 == 0)
            {
                throw runtime_error("val2 must not be 0\n");
            }
            cout << res << endl;
        }
        catch (runtime_error err) {
            cout << err.what()
                << "try again? enter y/n" << endl;

            char ch;
            cin >> ch;
            if (ch == 'n')
            {
                break;
            }
        }
    }
    
}



// 运行程序: Ctrl + F5 或调试 >“开始执行(不调试)”菜单
// 调试程序: F5 或调试 >“开始调试”菜单

// 入门使用技巧: 
//   1. 使用解决方案资源管理器窗口添加/管理文件
//   2. 使用团队资源管理器窗口连接到源代码管理
//   3. 使用输出窗口查看生成输出和其他消息
//   4. 使用错误列表窗口查看错误
//   5. 转到“项目”>“添加新项”以创建新的代码文件，或转到“项目”>“添加现有项”以将现有代码文件添加到项目
//   6. 将来，若要再次打开此项目，请转到“文件”>“打开”>“项目”并选择 .sln 文件
