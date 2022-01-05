#include "BSTInt.h"
#include "BST.hpp"
#include "BSTIterator.hpp"

#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <set>

using namespace std;

/**
 * A test driver for the BST int class and class template.
 * PA1 CSE 100 2016
 * Author: Christine Alvarado and YOU
 * TODO: Add more tests
 */
int main() {

 	// Empty Tree
 	BSTInt empty;

    /* Test height. */
    cout << "Empty height is: " << empty.height() << endl;
    if(empty.height() != -1) {
        cout << "... which is incorrect." << endl;
        return -1;
    }

    /* Test size. */
    cout << "Empty tree size is: " << empty.size() << endl;
    if(empty.size() != 0) {
        cout << "... which is incorrect." << endl;
        return -1;
    }

 	/* Test empty */
 	if(empty.empty() == false) {
     	cout << "Empty tree is not empty" << endl;
     	return -1;
    }


 	// Tree with 1 Node; 0 value
 	BSTInt oneNode;

 	/* Test insert */
 	bool insert1 = oneNode.insert(0);
 	bool insert2 = oneNode.insert(0);

 	if(insert1 == false) {
     	cout << "could not insert" << endl;
     	return -1;
    }

 	/* Test inserting a duplicate */
    if(insert2 == true) {
     	cout << "Error: inserted a duplicate" << endl;
     	return -1;
    }


    /* Test height. */
    cout << "One node tree height is: " << oneNode.height() << endl;
    if(oneNode.height() != 0) {
        cout << "... which is incorrect." << endl;
        return -1;
    }

    /* Test size. */
    cout << "One node tree size is: " << oneNode.size() << endl;
    if(oneNode.size() != 1) {
        cout << "... which is incorrect." << endl;
        return -1;
    }

 	/* Test empty */
 	if(oneNode.empty() == true) {
     	cout << "This tree shouldn't be empty" << endl;
     	return -1;
    }



  	// Tree with 1 Node, 5 value
 	BSTInt otherNode;

 	/* Test insert */
 	bool insert3 = otherNode.insert(5);
    bool insert4 = otherNode.insert(5);

 	if(insert3 == false) {
     	cout << "could not insert" << endl;
     	return -1;
    }
  	/* Test inserting a duplicate */
    if(insert4 == true) {
     	cout << "Error: inserted a duplicate" << endl;
     	return -1;
    }

    /* Test height. */
    cout << "Other node tree height is: " << otherNode.height() << endl;
    if(otherNode.height() != 0) {
        cout << "... which is incorrect." << endl;
        return -1;
    }

    /* Test size. */
    cout << "Other node tree size is: " << otherNode.size() << endl;
    if(otherNode.size() != 1) {
        cout << "... which is incorrect." << endl;
        return -1;
    }


    /* Create an STL vector of some ints */
    /*test*/

 	// tree 1
    vector<int> v;
    v.push_back(3);
    v.push_back(4);
    v.push_back(1);
    v.push_back(100);
    v.push_back(-33);

    /* Create an instance of BST holding int */
    BSTInt b;

    // Could use: for(auto item : v) { instead of the line below
    for(int item : v) {
        bool pr = b.insert(item);
        if(! pr ) {
            cout << "Incorrect bool return value when inserting " << item
                 << endl;
            return -1;
        }
    }

    /* Test height. */
    cout << "Tree 1 height is: " << b.height() << endl;
    if(b.height() != 2) {
        cout << "... which is incorrect." << endl;
        return -1;
    }


    /* Test size. */
    cout << "Size is: " << b.size() << endl;
    if(b.size() != v.size()) {
        cout << "... which is incorrect." << endl;
        return -1;
    }

    /* Test find return value. */
    // Test the items that are already in the tree
    for(int item : v) {
        if(!b.find(item)) {
            cout << "Incorrect return value when finding " << item << endl;
            return -1;
        }
    }

    /* Test find return value. */
    // Test the items not in the tree

    vector<int> v1;
    v1.push_back(5);
    v1.push_back(33);
    v1.push_back(-1);
    v1.push_back(50);
    v1.push_back(0);

    for(int item : v1) {
        if(b.find(item)) {
            cout << "Incorrect return value when finding-- found items not in tree" << item << endl;
            return -1;
        }
    }

    /* Test empty */
 	if(b.empty() == true) {
     	cout << "This tree shouldn't be empty" << endl;
     	return -1;
    }


 	// tree 2

    /* Create an STL vector of some other ints */
    /*test ascending only values */
    vector<int> va;
    va.push_back(-10);
    va.push_back(-5);
    va.push_back(0);
    va.push_back(6);
    va.push_back(10);

    /* Create an instance of BST holding int */
    BSTInt ba;

    // Could use: for(auto item : v) { instead of the line below
    for(int item : va) {
        bool pr = ba.insert(item);
        if(! pr ) {
            cout << "Incorrect bool return value when inserting " << item
                 << endl;
            return -1;
        }
    }

    /* Test height. */
    cout << "Tree 2 height is: " << ba.height() << endl;
    if(ba.height() != 4) {
        cout << "... which is incorrect." << endl;
        return -1;
    }

    /* Test find return value. */
    // Test the items that are already in the tree
    for(int item : va) {
        if(!ba.find(item)) {
            cout << "(Ascending) Incorrect return value when finding " << item << endl;
            return -1;
        }
    }


 	// Tree 3

    /* Create an STL vector of some other ints */
    /*test descending only values */
    vector<int> vd;
    vd.push_back(8);
    vd.push_back(4);
    vd.push_back(1);
    vd.push_back(-4);
    vd.push_back(-8);

    /* Create an instance of BST holding int */
    BSTInt bd;

    // Could use: for(auto item : v) { instead of the line below
    for(int item : vd) {
        bool pr = bd.insert(item);
        if(! pr ) {
            cout << "(Descending) Incorrect bool return value when inserting " << item
                 << endl;
            return -1;
        }
    }

    /* Test find return value. */
    // Test the items that are already in the tree
    for(int item : vd) {
        if(!bd.find(item)) {
            cout << "Incorrect return value when finding " << item << endl;
            return -1;
        }
    }

    /* Test height. */
    cout << "Tree 3 height is: " << bd.height() << endl;
    if(bd.height() != 4) {
        cout << "... which is incorrect." << endl;
        return -1;
    }


 	// Tree 4

     /* Create an STL vector of some ints */
    /*test*/
    vector<int> v3;
    v3.push_back(20);
    v3.push_back(12);
    v3.push_back(23);
    v3.push_back(18);
    v3.push_back(30);

    /* Create an instance of BST holding int */
    BSTInt b3;

    // Could use: for(auto item : v) { instead of the line below
    for(int item : v3) {
        bool pr = b3.insert(item);
        if(! pr ) {
            cout << "Incorrect bool return value when inserting " << item
                 << endl;
            return -1;
        }
    }


    /* Test size. */
    cout << "Size is: " << b3.size() << endl;
    if(b3.size() != v3.size()) {
        cout << "... which is incorrect." << endl;
        return -1;
    }

     /* Test height. */
    cout << "Tree 4 height is: " << b3.height() << endl;
    if(b3.height() != 2) {
        cout << "... which is incorrect." << endl;
        return -1;
    }






    /* UNCOMMENT THE LINES BELOW TO TEST THE TEMPLATE-BASED ITERATOR */

    /*
    // tree 1
      vector<int> v;
      v.push_back(3);
      v.push_back(4);
      v.push_back(1);
      v.push_back(100);
      v.push_back(-33);

      BSTInt b;

    */

    // Test the template version of the BST  with ints
    BST<int> btemp;

    for (int item : v) {
        // The auto type here is the pair of BSTIterator<int>, bool
        cout << "Inserting " << item << " into the int template-based BST...";
        auto p = btemp.insert(item);
        if (*(p.first) != item) {
            cout << "Wrong iterator returned.  "
                 << "Expected " << item << " but got " << *(p.first) << endl;
            return -1;
        }
        if (!p.second) {
            cout << "Wrong boolean returned.  Expected true but got "
                 << p.second << endl;
            return -1;
        }
        cout << "success!" << endl;

    }

    // Now test finding the elements we just put in
    for (int item: v) {
        cout << "Finding " << item << "...." << endl;
        BSTIterator<int> foundIt = btemp.find(item);
        if (*(foundIt) != item) {
            cout << "incorrect value returned.  Expected iterator pointing to "
                 << item << " but found iterator pointing to " << *(foundIt)
                 << endl;
            return -1;
        }
        cout << "success!" << endl;
    }


    // Test the iterator: The iterator should give an in-order traversal


    // Sort the vector, to compare with inorder iteration on the BST
    sort(v.begin(),v.end());

    cout << "traversal using iterator..." << endl;
    auto vit = v.begin();
    auto ven = v.end();

    // This is equivalent to BSTIterator<int> en = btemp.end();
    auto en = btemp.end();

    //This is equivalent to BST<int>::iterator it = btemp.begin();
    auto it = btemp.begin();
    for(; vit != ven; ++vit) {
        if(! (it != en) ) {
            cout << *it << "," << *vit
                 << ": Early termination of BST iteration." << endl;
            return -1;

        }
        cout << *it << endl;
        if(*it != *vit) {
            cout << *it << "," << *vit
                 << ": Incorrect inorder iteration of BST." << endl;
            return -1;
        }
        ++it;
    }

    cout << "success!" << endl;



    // ADD MORE TESTS HERE.  You might also want to change what is input
    // into the vector v.

    // more tests of given tree:
    /* Test height. */
    cout << "Tree 1 height is: " << btemp.height() << endl;
    if(btemp.height() != 2) {
        cout << "... which is incorrect." << endl;
        return -1;
    }


    /* Test size. */
    cout << "Size is: " << btemp.size() << endl;
    if(btemp.size() != v.size()) {
        cout << "... which is incorrect." << endl;
        return -1;
    }

    /* Test find return value. */
    // Test the items not in the tree

    // for (int stuff: v1) {
    //     cout << "Finding " << stuff << "...." << endl;
    //     BSTIterator<int> foundIt2 = btemp.find(stuff);
    //     if (*(foundIt2) == stuff) {
    //         cout << "found something not in tree"
    //              << endl;
    //         return -1;
    //     }
    //     cout << "success!" << endl;
    // }

    vector<int> nf;
    nf.push_back(300);
    nf.push_back(400);
    nf.push_back(600);
    nf.push_back(10000);
    nf.push_back(-3300);

     for (int item: nf) {
         cout << "Finding " << item << "...." << endl;
         BSTIterator<int> foundIt = btemp.find(item);
      	 if(foundIt == NULL){
          cout << "foundit is null" <<endl;
         }
         else if (*(foundIt) == item) {
             cout << "incorrect" << endl;
             return -1;
         }
         cout << "success!" << endl;
     }
    

    /* Test empty */
  if(btemp.empty() == true) {
      cout << "This tree shouldn't be empty" << endl;
      return -1;
    }


    // TEST1: Empty Tree
    BST<int> btempEmpty;

      /* Test height. */
      cout << "Empty height is: " << btempEmpty.height() << endl;
      if(btempEmpty.height() != -1) {
          cout << "... which is incorrect." << endl;
          return -1;
      }

      /* Test size. */
      cout << "Empty tree size is: " << btempEmpty.size() << endl;
      if(btempEmpty.size() != 0) {
          cout << "... which is incorrect." << endl;
          return -1;
      }

    /* Test empty */
    if(btempEmpty.empty() == false) {
        cout << "Empty tree is not empty" << endl;
        return -1;
      }

    // TEST 2: Tree with 1 Node; 0 value
     	BST<int> btempOneNode;

      // Test insert //
      auto p2 = btempOneNode.insert(0);
      if (*(p2.first) != 0) {
        cout << "Wrong iterator returned.  " << endl;
        return -1;
      }
      if (!p2.second) {
          cout << "Wrong boolean returned.  Expected true but got "
               << p2.second << endl;
          return -1;
      }

      // Test insert duplicate//
      auto p3 = btempOneNode.insert(0);
      if (*(p3.first) != 0) {
        cout << "Wrong iterator returned.  " << endl;
        return -1;
      }
      if (p3.second) {
          cout << "Wrong boolean returned.  Expected false but got "
               << p3.second << endl;
          return -1;
      }

      // test Find inserted item
      vector<int> v0;
      v0.push_back(0);

      for (int item: v0) {
          cout << "Finding " << item << "...." << endl;
          BSTIterator<int> foundIt = btempOneNode.find(item);
          if (*(foundIt) != item) {
              cout << "incorrect value returned.  Expected iterator pointing to "
                   << item << " but found iterator pointing to " << *(foundIt)
                   << endl;
              return -1;
          }
          cout << "success!" << endl;
      }

        /* Test height. */
        cout << "One node tree height is: " << btempOneNode.height() << endl;
        if(btempOneNode.height() != 0) {
            cout << "... which is incorrect." << endl;
            return -1;
        }

        /* Test size. */
        cout << "One node tree size is: " << btempOneNode.size() << endl;
        if(btempOneNode.size() != 1) {
            cout << "... which is incorrect." << endl;
            return -1;
        }

     	/* Test empty */
     	if(btempOneNode.empty() == true) {
         	cout << "This tree shouldn't be empty" << endl;
         	return -1;
        }

// TEST 3: Ascending Tree

// Test the template version of the BST  with ints
BST<int> btempA;

for (int item : va) {
    // The auto type here is the pair of BSTIterator<int>, bool
    cout << "Inserting " << item << " into the int template-based BST...";
    auto p = btempA.insert(item);
    if (*(p.first) != item) {
        cout << "Wrong iterator returned.  "
             << "Expected " << item << " but got " << *(p.first) << endl;
        return -1;
    }
    if (!p.second) {
        cout << "Wrong boolean returned.  Expected true but got "
             << p.second << endl;
        return -1;
    }
    cout << "success!" << endl;

}

// Now test finding the elements we just put in
for (int item: va) {
    cout << "Finding " << item << "...." << endl;
    BSTIterator<int> foundIt = btempA.find(item);
    if (*(foundIt) != item) {
        cout << "incorrect value returned.  Expected iterator pointing to "
             << item << " but found iterator pointing to " << *(foundIt)
             << endl;
        return -1;
    }
    cout << "success!" << endl;
}


// Sort the vector, to compare with inorder iteration on the BST
sort(va.begin(),va.end());

cout << "traversal using iterator..." << endl;
auto vitA = va.begin();
auto venA = va.end();

// This is equivalent to BSTIterator<int> en = btemp.end();
auto enA = btempA.end();

//This is equivalent to BST<int>::iterator it = btemp.begin();
auto itA = btempA.begin();
for(; vitA != venA; ++vitA) {
    if(! (itA != enA) ) {
        cout << *itA << "," << *vitA
             << ": Early termination of BST iteration." << endl;
        return -1;

    }
    cout << *itA << endl;
    if(*itA != *vitA) {
        cout << *itA << "," << *vitA
             << ": Incorrect inorder iteration of BST." << endl;
        return -1;
    }
    ++itA;
}

        /* Test height. */
        cout << "Tree 1 height is: " << btempA.height() << endl;
        if(btempA.height() != 4) {
            cout << "... which is incorrect." << endl;
            return -1;
        }


        /* Test size. */
        cout << "Size is: " << btempA.size() << endl;
        if(btempA.size() != va.size()) {
            cout << "... which is incorrect." << endl;
            return -1;
        }

// TEST 4: Descending Tree

// Test the template version of the BST  with ints
BST<int> btempD;

for (int item : vd) {
    // The auto type here is the pair of BSTIterator<int>, bool
    cout << "Inserting " << item << " into the int template-based BST...";
    auto p = btempD.insert(item);
    if (*(p.first) != item) {
        cout << "Wrong iterator returned.  "
             << "Expected " << item << " but got " << *(p.first) << endl;
        return -1;
    }
    if (!p.second) {
        cout << "Wrong boolean returned.  Expected true but got "
             << p.second << endl;
        return -1;
    }
    cout << "success!" << endl;

}

// Now test finding the elements we just put in
for (int item: vd) {
    cout << "Finding " << item << "...." << endl;
    BSTIterator<int> foundIt = btempD.find(item);
    if (*(foundIt) != item) {
        cout << "incorrect value returned.  Expected iterator pointing to "
             << item << " but found iterator pointing to " << *(foundIt)
             << endl;
        return -1;
    }
    cout << "success!" << endl;
}


// Sort the vector, to compare with inorder iteration on the BST
sort(vd.begin(),vd.end());

cout << "traversal using iterator..." << endl;
auto vitD = vd.begin();
auto venD = vd.end();

// This is equivalent to BSTIterator<int> en = btemp.end();
auto enD = btempD.end();

//This is equivalent to BST<int>::iterator it = btemp.begin();
auto itD = btempD.begin();
for(; vitD != venD; ++vitD) {
    if(! (itD != enD) ) {
        cout << *itD << "," << *vitD
             << ": Early termination of BST iteration." << endl;
        return -1;

    }
    cout << *itD << endl;
    if(*itD != *vitD) {
        cout << *itD << "," << *vitD
             << ": Incorrect inorder iteration of BST." << endl;
        return -1;
    }
    ++itD;
}

        /* Test height. */
        cout << "Tree 1 height is: " << btempD.height() << endl;
        if(btempD.height() != 4) {
            cout << "... which is incorrect." << endl;
            return -1;
        }


        /* Test size. */
        cout << "Size is: " << btempD.size() << endl;
        if(btempD.size() != vd.size()) {
            cout << "... which is incorrect." << endl;
            return -1;
        }


    cout << "All tests passed!" << endl;
    return 0;
}
