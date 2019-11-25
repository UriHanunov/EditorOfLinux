/*
 * @author Uri Hanunov
 *
 */
#include <iostream>
#include <vector>

using namespace std;

#ifndef MATALA_1___EDITOR_LINUX_DOCUMENT_H
#define MATALA_1___EDITOR_LINUX_DOCUMENT_H

class Document
{
public:
    Document();
    void currentLine(); //prints the current line (ed maintains a current line)
    void numberAndCurrentLine(); //prints line number of current line followed by TAB followed by current line
    void printAll(); //prints all lines
    void updateLine(int x); //makes line #n the current line
    void insertToVector(); //appends new text after the current line
    void insertBefore(); //inserts new text before the current line
    void changeLine(); //changes the current line for text that follows
    void deleteLine(); //prints the current line (ed maintains a current line)
    void searchText(string temp); //searches forward after current line for the specified text - also check a repeat text
    void searchTextBefore(string temp); //searches backward
    void changeString(string temp); //replaces old string with new in current line

private:
    vector <string> vec;
    int line; // to save the current line
};

#endif //MATALA_1___EDITOR_LINUX_DOCUMENT_H