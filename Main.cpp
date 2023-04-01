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

    while (!myFile.eof())
    {
        myFile >> text[m];
        root = insert(root, text[m]);
        m++;
    }
    myFile.close();
    display(root);
    cout << endl;
    cout << "height of tree: " << getHeight(root) << endl;
    cout << endl << endl << endl;

    string loop = "test";
    while (loop != "-1")
    {
        cout << "Enter a word you would like to look for. Enter -1 to quit: ";
        cin >> loop;
        cout << endl;

        if (search(root, loop) && loop != "-1")
        {
            cout << loop << " was found in the tree!" << endl;
        }
        else
        {
            cout << loop << " was not found in the tree :(" << endl;
        }
    }

}