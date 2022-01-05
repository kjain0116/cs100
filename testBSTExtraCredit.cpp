
#include "BSTExtraCredit.hpp"

#include <iostream>
#include <algorithm>
#include <vector>
#include<fstream>
#include <string>
#include <set>

using namespace std;


 int main() {
   //Size of tree should be stored in local variable size.
   //Height of tree should be stored in local variable height.
   //Input name will be stored in a string name
//    unsigned int size = 0;
//    int height = 0;
//    std::string name = "";
//
//
//    //Open file
//    ifstream in;
//    in.open("actors_sorted.txt");
//
//    //Check if input file was actually opened
//    if(!in.is_open())
//    {
//        cout<< "Invalid input file. No file was opened. Please try again.\n";
//        return -1;
//    }
// else {
//
//        // Follow the comments below to add code:

       // TODO: Create a new BST here
       BSTExtraCredit<int> b;

       int i = 0;

       b.insert(1);
       b.insert(2);
       // b.insert(3);
       // b.insert(4);
       // b.insert(5);
       // b.insert(6);


       // for(i = 0; i < 10; i++) {
       //   b.insert(i);
       // }
       cout << "The height is: " << b.height() << endl;
       cout << "The size is: " << b.size() << endl;



   //     while (getline(in, name)) {
   //         // TODO: add the name string to the BST
   //         b.insert(name);
   //
   //
   //     }
   //
   //     // TODO: Get the height of the BST and store it in height
   //     height = b.height();
   //
   //     // TODO: Get the size of the BST and store it in size
   //     size = b.size();
   //
   //     // DO NOT CHANGE THE LINES BELOW
   //     cout << "Size of tree: " << size << endl;
   //     cout << "Height of tree: " << height << endl;
   //
   //
   //     in.close();
   //
   // }

     return 0;

 }
