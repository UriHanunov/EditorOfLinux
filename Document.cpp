/*
 * @author Uri Hanunov
 *
 */
#include <iostream>
#include <vector>
#include "Document.h"

using namespace std;

Document::Document()
{
    vector<string> vec;
    line = 0;
}

void Document::currentLine()
{
    cout << vec[line-1] << endl;
}

void Document::numberAndCurrentLine()
{
    cout << line << "\t" << vec[line-1] << endl;
}

void Document::printAll()
{
    for (auto i = vec.begin(); i != vec.end(); i++)
    {
        cout << *i << endl;
    }
}

void Document::updateLine(int x)
{
    if(x<=vec.size())
    {
        line = x;
        cout << vec[line-1] << endl;
    }
    else
    {
        cout << "the number is bigger than the numbers of lines" << endl;
        cout << "please choose a smaller number" << endl;
    }
}

void Document::insertToVector()
{
    string text;
    getline (cin,text);
    while(text != ".")
    {
        getline (cin,text);
        if(text != ".")
        {
            vec.insert(vec.begin() + line, text);
            cout << text << endl;
            line++;
        }
    }
    cout << text << endl;
}

void Document::insertBefore()
{
    string text;
    getline (cin,text);
    while(text != ".")
    {
        getline (cin,text);
        if(text != ".")
        {
            vec.insert(vec.begin() + line-1, text);
            cout << text << endl;
            line++;
        }
    }
    cout << text << endl;
}

void Document::changeLine()
{
    deleteLine();
    insertToVector();
}

void Document::deleteLine()
{
    vec.erase(vec.begin() + line-1);
    line--;
}

void Document::searchText(string temp)
{
    int tempLine = line ;
    while(tempLine != line-1)
    {
        if(tempLine < vec.size())
            tempLine++;
        else
            tempLine = 1;
        size_t found = vec[tempLine-1].find(temp);
        if (found != string::npos)
        {
            cout << vec[tempLine-1] << endl;
            line = tempLine;
            break;
        }

    }
}

void Document::searchTextBefore(string temp)
{
    int tempLine = line -1;
    while(tempLine != line)
    {
        size_t found = vec[tempLine-1].find(temp);
        if (found != string::npos)
        {
            cout << vec[tempLine-1] << endl;
            line = tempLine;
            break;
        }
        if(tempLine != 0)
            tempLine--;
        else
            tempLine = vec.size();
    }
}

void Document::changeString(string temp)
{
    char delim = '/';
    std::size_t current, previous = 0;
    current = temp.find(delim);
    string oldOne;
    string newOne;
    bool first = true;
    while (current != std::string::npos)
    {
        if(first)
        {
            oldOne = (temp.substr(previous, current - previous));
            first = false;
        }
        else
        {
            newOne = (temp.substr(previous, current - previous));
        }
        previous = current + 1;
        current = temp.find(delim, previous);
    }
    vec[line-1].replace(vec[line-1].find(oldOne), oldOne.size() , newOne);
}