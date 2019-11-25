/*
 * @author Uri Hanunov
 *
 */
#include <iostream>
#include "Document.h"

using namespace std;

#ifndef MATALA_1___EDITOR_LINUX_EDITOR_H
#define MATALA_1___EDITOR_LINUX_EDITOR_H

class Editor{
public:
    Editor();
    void loop(); //start the editor
    bool isNumber(const std::string& s); //check if string is a number
private:
    Document doc;
};


#endif //MATALA_1___EDITOR_LINUX_EDITOR_H
