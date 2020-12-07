//
// Unit test. Do not alter.
//

#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "doctest.h"

#include "bstree.hpp"

#include <iostream>
#include <sstream>
#include <string>
using std::cout;
using std::ostringstream;
using std::streambuf;
using std::string;

TEST_CASE("Binary Search Tree (int)") {

  streambuf *oldCout = cout.rdbuf();
  ostringstream captureCout;

  SUBCASE("BSTree<int> -- EMPTY") {
    BSTree<int> tree;

    CHECK_EQ(tree.getSize(), 0);

    captureCout.str("");
    cout.rdbuf(captureCout.rdbuf());
    tree.printInOrder();
    cout.rdbuf(oldCout);
    CHECK_EQ(captureCout.str(), string(""));
  }

  SUBCASE("BSTree<int> -- ONE ITEM") {
    BSTree<int> tree;

    CHECK_EQ(tree.insert(100), true);

    CHECK_EQ(tree.getSize(), 1);

    captureCout.str("");
    cout.rdbuf(captureCout.rdbuf());
    tree.printInOrder();
    cout.rdbuf(oldCout);
    CHECK_EQ(captureCout.str(), string("100\n"));

    CHECK_EQ(tree.insert(100), false);

    captureCout.str("");
    cout.rdbuf(captureCout.rdbuf());
    tree.printInOrder();
    cout.rdbuf(oldCout);
    CHECK_EQ(captureCout.str(), string("100\n"));
  }

  SUBCASE("BSTree<int> -- MULTIPLE ITEMS") {
    BSTree<int> tree;

    tree.insert(100);
    tree.insert(50);
    tree.insert(150);
    tree.insert(25);
    tree.insert(75);
    tree.insert(125);
    tree.insert(175);

    CHECK_EQ(tree.getSize(), 7);

    captureCout.str("");
    cout.rdbuf(captureCout.rdbuf());
    tree.printInOrder();
    cout.rdbuf(oldCout);
    CHECK_EQ(captureCout.str(), string("25\n50\n75\n100\n125\n150\n175\n"));

    CHECK_EQ(tree.insert(25), false);
    CHECK_EQ(tree.insert(50), false);
    CHECK_EQ(tree.insert(75), false);
    CHECK_EQ(tree.insert(100), false);
    CHECK_EQ(tree.insert(125), false);
    CHECK_EQ(tree.insert(150), false);
    CHECK_EQ(tree.insert(175), false);
    CHECK_EQ(tree.getSize(), 7);

    tree.clear();
    CHECK_EQ(tree.getSize(), 0);

    captureCout.str("");
    cout.rdbuf(captureCout.rdbuf());
    tree.printInOrder();
    cout.rdbuf(oldCout);
    CHECK_EQ(captureCout.str(), string(""));
  }
}