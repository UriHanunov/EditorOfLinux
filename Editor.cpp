/*
 * @author Uri Hanunov
 *
 */
#include <iostream>
#include <vector>
#include "Editor.h"

using namespace std;

Editor::Editor() //constructor
{
    Document doc;
}

void Editor::loop() //start the editor
{
    string temp;
    cin >> temp;
    string searchText;
    int index = 0;
    while(temp != "Q") //if 'Q' - so finish the loop
    {
        bool isDigit = isNumber(temp); //check if the string is a number
        if(temp == "p") //prints the current line (ed maintains a current line)
        {
            cout << "p" << endl;
            doc.currentLine();
        }
        else if(temp == "n") //prints line number of current line followed by TAB followed by current line
        {
            cout << "n" << endl;
            doc.numberAndCurrentLine();
        }
        else if(temp == "%p") //prints all lines
        {
            cout << "%p" << endl;
            doc.printAll();
        }
        else if(isDigit) //makes line #n the current line
        {
            int numberLine = stoi(temp);
            cout << numberLine << endl;
            doc.updateLine(numberLine);
        }
        else if(temp == "a") //appends new text after the current line
        {
            cout << "a" << endl;
            doc.insertToVector();
        }
        else if(temp == "i") //inserts new text before the current line
        {
            cout << "i" << endl;
            doc.insertBefore();
        }
        else if(temp == "c") //changes the current line for text that follows
        {
            cout << "c" << endl;
            doc.changeLine();
        }
        else if(temp == "d") //deletes the current line
        {
            cout << "d" << endl;
            doc.deleteLine();
        }
        else if(temp[0] == '/') //searches forward after current line for the specified text or Repeat search
        {
            cout << temp << endl;
            if(temp.size() == 1 && !(searchText.empty()))
            {
                doc.searchText(searchText); //send the repeat text
            }
            else
            {
                string str = temp.substr (1);     // get from 1 to the end
                searchText = str ;
                doc.searchText(searchText); //send the new one
            }
        }
        else if(temp[0] == '?') //searches backward
        {
            cout << temp << endl;
            string str = temp.substr (1);     // get from 1 to the end
            doc.searchTextBefore(str);
        }
        else if(temp[0] == 's' && temp[1] == '/' && temp[temp.size()-1] == '/') //replaces old string with new in current line (google: C++ split or token)
        {
            cout << temp << endl;
            string str = temp.substr (2);
            doc.changeString(str);
        }
        cin >> temp;
    }
    cout << "Q" << endl;

}

bool Editor::isNumber(const std::string& s)
{
    std::string::const_iterator it = s.begin();
    while (it != s.end() && std::isdigit(*it)) ++it;
    return !s.empty() && it == s.end();
}
