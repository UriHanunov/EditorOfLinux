/*
 * @author Uri Hanunov
 *
 */
#include <iostream>
#include "Editor.h"
#include "Document.h"

using namespace std;

int main()
{
    std::cout << "Editor document :" << std::endl;
    Editor edit;
    edit.loop();
}