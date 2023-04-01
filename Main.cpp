#include <iostream>
#include <fstream>
#include <set>
#include "Tree.hpp"

using namespace std;

int main()
{
    int m = 0;
    string text[9157];
    ifstream myFile;
    myFile.open("bee.txt");
    struct node *root = NULL;
    set<string> stringSet;

    while (!myFile.eof())
    {
        myFile >> text[m];
        stringSet.insert(text[m]);
        root = insert(root, text[m]);
        m++;
    }
    myFile.close();
    
    display(root);
    cout << endl;

    cout << stringSet.size() << endl;
    cout << search(root, "your") << endl;
    cout << getHeight(root) << endl;
}