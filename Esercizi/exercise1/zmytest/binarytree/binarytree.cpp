#include <iostream>

/* ************************************************************************** */

#include "../../zlasdtest/container/container.hpp"
#include "../../zlasdtest/container/linear.hpp"
#include "../../zlasdtest/container/dictionary.hpp"
#include "../../zlasdtest/container/traversable.hpp"
#include "../../zlasdtest/container/mappable.hpp"


#include "../../zlasdtest/binarytree/binarytree.hpp"

/* ************************************************************************** */

#include "../../vector/vector.hpp"

#include "../../iterator/iterator.hpp"
#include "../../binarytree/binarytree.hpp"
#include "../../binarytree/lnk/binarytreelnk.hpp"
#include "../../binarytree/vec/binarytreevec.hpp"

/* ************************************************************************** */

using namespace std;

/* ************************************************************************** */



template <typename BT>
void binarytreetestint(unsigned int &testnum, unsigned int &testerr) {
    unsigned int loctesterr{0};
    unsigned int loctestnum{0};


    try {

        lasd::Vector<int> vec{5};
        for(int i = 0; i < 5; i++)
            vec[i] = i;

        BT tree{vec};
        TraverseBreadth(loctestnum, loctesterr, tree, true, TraversePrint<int>);
        TraversePreOrder(loctestnum, loctesterr, tree, true, TraversePrint<int>);
        TraversePostOrder(loctestnum, loctesterr, tree, true, TraversePrint<int>);
        TraverseInOrder(loctestnum, loctesterr, tree, true, TraversePrint<int>);

        vec[0] = 1;
        vec[1] = 0;
        BT tree2{vec};

        NonEqualBT(loctestnum, loctesterr, tree, tree2);

        tree2.Root().Element() = 0;
        tree2.Root().LeftChild().Element() = 1;
        
        cout<<endl;
        EqualBT(loctestnum, loctesterr, tree, tree2);
        
        cout<<endl;
        tree2.Root().Element() = 500;
        NonEqualBT(loctestnum, loctesterr, tree, tree2);
        
        cout<<endl;
        tree = tree2;
        EqualBT(loctestnum, loctesterr, tree, tree2);
        
        cout<<"test move"<<endl;
        BT tree3{move(tree)};
        Empty(loctestnum, loctesterr, tree, true);
        EqualBT(loctestnum, loctesterr, tree3, tree2);
        
        Traverse(loctestnum, loctesterr, tree, true, TraversePrint<int>);
        Traverse(loctestnum, loctesterr, tree2, true, TraversePrint<int>);

        cout<<"test copy assignment"<<endl;
        tree2 = tree;
        EqualBT(loctestnum, loctesterr, tree2, tree);
        Empty(loctestnum, loctesterr, tree2, true);
        
        cout<<endl;
        TraverseBreadth(loctestnum, loctesterr, tree3, true, TraversePrint<int>);
        tree3 = move(tree);
        NonEqualBT(loctestnum, loctesterr, tree3, tree);
        EqualBT(loctestnum, loctesterr, tree3, tree2);
        Empty(loctestnum, loctesterr, tree3, true);

        Root(loctestnum, loctesterr, tree, true, 500);
        Root(loctestnum, loctesterr, tree, false, 3000);

        cout<<"test alberi vuoti"<<endl;
        tree.Clear();
        tree2.Clear();
        tree3.Clear();
        Empty(loctestnum, loctesterr, tree, true);
        EqualBT(loctestnum, loctesterr, tree, tree2);
        EqualBT(loctestnum, loctesterr, tree, tree3);

        tree = tree2;
        tree3 = move(tree2);
        EqualBT(loctestnum, loctesterr, tree, tree3);
        Root(loctestnum, loctesterr, tree, false, 0);

        BT tree4{vec};
        tree = tree4;
        tree2 = move(tree4);
        Empty(loctestnum, loctesterr, tree4, true);
        EqualBT(loctestnum, loctesterr, tree, tree2);

        TraverseBreadth(loctestnum, loctesterr, tree2, true, TraversePrint<int>);
        TraversePreOrder(loctestnum, loctesterr, tree2, true, TraversePrint<int>);
        TraversePostOrder(loctestnum, loctesterr, tree2, true, TraversePrint<int>);
        TraverseInOrder(loctestnum, loctesterr, tree2, true, TraversePrint<int>);

        tree3 = move(tree2);
        Empty(loctestnum, loctesterr, tree3, false);
        Empty(loctestnum, loctesterr, tree2, true);

        lasd::Vector<int> vec2(100);
        for(int i = 0; i < 100; ++i)
            vec2[i] = i+1;
        
        BT tree5{vec2};
        FoldBreadth(loctestnum, loctesterr, tree5, true, FoldAdd<int>, 0, 5050);
        FoldPreOrder(loctestnum, loctesterr, tree5, true, FoldAdd<int>, 0, 5050);
        FoldPostOrder(loctestnum, loctesterr, tree5, true, FoldAdd<int>, 0, 5050);
        FoldInOrder(loctestnum, loctesterr, tree5, true, FoldAdd<int>, 0, 5050);

        Map(loctestnum, loctesterr, tree5, true, MapDouble<int>);
        MapBreadth(loctestnum, loctesterr, tree5, true, MapDouble<int>);
        MapPreOrder(loctestnum, loctesterr, tree5, true, MapDouble<int>);
		MapPostOrder(loctestnum, loctesterr, tree5, true, MapDouble<int>);
        MapInOrder(loctestnum, loctesterr, tree5, true, MapDouble<int>);
        
        Traverse(loctestnum, loctesterr, tree5, true, TraversePrint<int>);

        vec2.Resize(5);

        BT tree6{vec2};
        int x {100000};
        FoldBreadth(loctestnum, loctesterr, tree6, true, [&x](const int& dat, const int& acc){
            x /= 10;
            return acc + x * dat;
        }, 0, 12345);
        x = 100000;
        FoldPreOrder(loctestnum, loctesterr, tree6, true, [&x](const int& dat, const int& acc){
            x /= 10;
            return acc + x * dat;
        }, 0, 12453);
        x = 100000;
        FoldPostOrder(loctestnum, loctesterr, tree6, true, [&x](const int& dat, const int& acc){
            x /= 10;
            return acc + x * dat;
        }, 0, 45231);
        x = 100000;
        FoldInOrder(loctestnum, loctesterr, tree6, true, [&x](const int& dat, const int& acc){
            x /= 10;
            return acc + x * dat;
        }, 0, 42513);

        vec2.Resize(2);
        BT tree7{move(vec2)};

        Size(loctestnum, loctesterr, tree7, true, 2);
        tree7 = move(tree6);
        Size(loctestnum, loctesterr, tree7, true, 5);
        Size(loctestnum, loctesterr, tree6, true, 2);

        vec2.Clear();
        BT tree8{vec2};
        Size(loctestnum, loctesterr, tree8, true, 0);

        BT tree9{move(vec2)};
        Size(loctestnum, loctesterr, tree9, true, 0);
        
    }
    catch (exception &exc) {
        loctestnum++;
        loctesterr++;
        cout << endl << "Unmanaged error! " << exc.what() << endl;
    }
    catch (...) {
        loctestnum++;
        loctesterr++;
        cout << endl << "Unmanaged error! " << endl;
    }
    
    cout << "End of My BinaryTree<int> Test! (Errors/Tests: " << loctesterr << "/" << loctestnum << ")" << endl;
    testnum += loctestnum;
    testerr += loctesterr;
}



void binarytrecrosstestint(unsigned int &testnum, unsigned int &testerr) {
    unsigned int loctesterr{0};
    unsigned int loctestnum{0};


    try {

        lasd::Vector<int> vec{5};
        for(int i = 0; i < 5; i++)
            vec[i] = i;
        
        lasd::BinaryTreeLnk<int> treelnk{vec};
        lasd::BinaryTreeVec<int> treevec{vec};

        EqualBT(loctestnum, loctesterr, treelnk, treevec);

        treelnk.Root().LeftChild().RightChild().Element() = 10000;
        NonEqualBT(loctestnum, loctesterr, treelnk, treevec);

        treelnk.Root().LeftChild().RightChild().Element() = 3;
        treelnk.Root().LeftChild().LeftChild().Element() = 4;
        
        Traverse(loctestnum, loctesterr, treelnk, true, TraversePrint<int>);
        Traverse(loctestnum, loctesterr, treevec, true, TraversePrint<int>);

        NonEqualBT(loctestnum, loctesterr, treelnk, treevec);
//?: Inizio cose strane
        treevec = treelnk;
        treelnk = treevec; 

        Traverse(loctestnum, loctesterr, treelnk, true, TraversePrint<int>);
        Traverse(loctestnum, loctesterr, treevec, true, TraversePrint<int>);

        lasd::BinaryTreeLnk<int> treelnk2{treevec};
        lasd::BinaryTreeVec<int> treevec2{treelnk};

        EqualBT(loctestnum, loctesterr, treelnk2, treevec2);

        treevec.Clear();
        Empty(loctestnum, loctesterr, treevec, true);
        
        Traverse(loctestnum, loctesterr, treelnk2, true, TraversePrint<int>);
        Traverse(loctestnum, loctesterr, treevec, true, TraversePrint<int>);

        treevec = move(treelnk2);

        treelnk2 = move(treevec);

        Traverse(loctestnum, loctesterr, treelnk2, true, TraversePrint<int>);
        Traverse(loctestnum, loctesterr, treevec, true, TraversePrint<int>);

        EqualBT(loctestnum, loctesterr, treelnk, treevec);

        Empty(loctestnum, loctesterr, treelnk2, true);
        EqualBT(loctestnum, loctesterr, treelnk2, treevec2);

        lasd::BinaryTreeVec<int> treevec3{move(treelnk)};
        Empty(loctestnum, loctesterr, treelnk, false);

    }
    catch (exception &exc) {
        loctestnum++;
        loctesterr++;
        cout << endl << "Unmanaged error! " << exc.what() << endl;
    }
    catch (...) {
        loctestnum++;
        loctesterr++;
        cout << endl << "Unmanaged error! " << endl;
    }
    
    cout << "End of My BinaryTree<int> Test! (Errors/Tests: " << loctesterr << "/" << loctestnum << ")" << endl;
    testnum += loctestnum;
    testerr += loctesterr;
}


/* ************************************************************************** */

void my_binarytree_int(unsigned int &testnum, unsigned int &testerr) {

    cout << endl << "Begin of My BinaryTreeLst<int> Test:" << endl;
    binarytreetestint<lasd::BinaryTreeLnk<int>>(testnum, testerr);

    cout << endl << "Begin of My BinaryTreeVec<int> Test:" << endl;
    binarytreetestint<lasd::BinaryTreeVec<int>>(testnum, testerr);

    cout << endl << "Begin of My BinaryTree<int> Test:" << endl;
    binarytrecrosstestint(testnum, testerr);


    cout << endl << "End of All My BinaryTree<int> Tests! (Errors/Tests: " << testerr << "/" << testnum << ")" << endl;
}

/* ************************************************************************** */

void my_binarytree_test(unsigned int &testnum, unsigned int &testerr) {

    my_binarytree_int(testnum, testerr);

}
