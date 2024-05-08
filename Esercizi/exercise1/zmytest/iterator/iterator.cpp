#include <iostream>

/* ************************************************************************** */

#include "../../zlasdtest/container/container.hpp"
#include "../../zlasdtest/container/linear.hpp"
#include "../../zlasdtest/container/dictionary.hpp"
#include "../../zlasdtest/container/traversable.hpp"

#include "../../zlasdtest/iterator/iterator.hpp"
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

void my_iterator_int(unsigned int &testnum, unsigned int &testerr) {
	unsigned int loctesterr{0};
	unsigned int loctestnum{0};
	cout << endl << "Begin of My Iterator<int> Test:" << endl;
	try {
        {
            // test generale
            lasd::Vector<int> vec{5};
            for(int i = 0; i < 5; i++)
                vec[i] = i;

            lasd::BinaryTreeLnk<int> tree{vec};
            TraverseBreadth(loctestnum, loctesterr, tree, true, TraversePrint<int>);

            lasd::BTBreadthIterator<int> it{tree};

            for(int i = 0; !it.Terminated(); ++it, i++) {
                Terminated(loctestnum, loctesterr, it, false);
                GetItrValue(loctestnum, loctesterr, it, true, vec[i]);
            }
            Terminated(loctestnum, loctesterr, it, true);

            // test su albero vuoto
            tree.Clear();
            lasd::BTBreadthIterator<int> it2{tree};
            Terminated(loctestnum, loctesterr, it2, true);
            GetItrValue(loctestnum, loctesterr, it2, false, 0);

            // test reset
            lasd::BinaryTreeVec<int> tree2{vec};
            lasd::BTBreadthIterator<int> it3{tree2};
            GetItrValue(loctestnum, loctesterr, it3, true, vec[0]);
            ++it3;
            GetItrValue(loctestnum, loctesterr, it3, true, vec[1]);
            it3.Reset();

            Terminated(loctestnum, loctesterr, it3, false);
            GetItrValue(loctestnum, loctesterr, it3, true, vec[0]);


            // test settare valore
            lasd::BTBreadthMutableIterator<int> it4{tree2};
            for(int i = 0; !it4.Terminated(); ++it4, i++) {
                GetItrValue(loctestnum, loctesterr, it4, true, vec[i]);
                SetItrValue(loctestnum, loctesterr, it4, true, vec[i]+10);
                GetItrValue(loctestnum, loctesterr, it4, true, vec[i]+10);
            }
        }
        {
            // test generale
            lasd::Vector<int> vec{5};
            for(int i = 0; i < 5; i++)
                vec[i] = i;

            lasd::BinaryTreeLnk<int> tree{vec};

            lasd::BTPreOrderIterator<int> it{tree};
            TraversePreOrder(loctestnum, loctesterr, tree, true, TraversePrint<int>);


            Terminated(loctestnum, loctesterr, it, false);
            GetItrValue(loctestnum, loctesterr, it, true, 0);
            ++it;

            Terminated(loctestnum, loctesterr, it, false);
            GetItrValue(loctestnum, loctesterr, it, true, 1);
            ++it;

            Terminated(loctestnum, loctesterr, it, false);
            GetItrValue(loctestnum, loctesterr, it, true, 3);
            ++it;

            Terminated(loctestnum, loctesterr, it, false);
            GetItrValue(loctestnum, loctesterr, it, true, 4);
            ++it;

            Terminated(loctestnum, loctesterr, it, false);
            GetItrValue(loctestnum, loctesterr, it, true, 2);
            ++it;

            Terminated(loctestnum, loctesterr, it, true);

            // test su albero vuoto
            tree.Clear();
            lasd::BTPreOrderIterator<int> it2{tree};
            Terminated(loctestnum, loctesterr, it2, true);
            GetItrValue(loctestnum, loctesterr, it2, false, 0);

            // test reset
            lasd::BinaryTreeVec<int> tree2{vec};
            lasd::BTPreOrderIterator<int> it3{tree2};
            GetItrValue(loctestnum, loctesterr, it3, true, 0);
            ++it3;
            GetItrValue(loctestnum, loctesterr, it3, true, 1);
            it3.Reset();

            Terminated(loctestnum, loctesterr, it3, false);
            GetItrValue(loctestnum, loctesterr, it3, true, 0);


            // test settare valore
            lasd::BTPreOrderMutableIterator<int> it4{tree2};
            for(int i = 0; !it4.Terminated(); ++it4, i++) {
                SetItrValue(loctestnum, loctesterr, it4, true, vec[i]+10);
                GetItrValue(loctestnum, loctesterr, it4, true, vec[i]+10);
            }

        }
        {
            // test generale
            lasd::Vector<int> vec{5};
            for(int i = 0; i < 5; i++)
                vec[i] = i;

            lasd::BinaryTreeLnk<int> tree{vec};

            lasd::BTPostOrderIterator<int> it{tree};
            TraversePostOrder(loctestnum, loctesterr, tree, true, TraversePrint<int>);


            Terminated(loctestnum, loctesterr, it, false);
            GetItrValue(loctestnum, loctesterr, it, true, 3);
            ++it;

            Terminated(loctestnum, loctesterr, it, false);
            GetItrValue(loctestnum, loctesterr, it, true, 4);
            ++it;

            Terminated(loctestnum, loctesterr, it, false);
            GetItrValue(loctestnum, loctesterr, it, true, 1);
            ++it;

            Terminated(loctestnum, loctesterr, it, false);
            GetItrValue(loctestnum, loctesterr, it, true, 2);
            ++it;

            Terminated(loctestnum, loctesterr, it, false);
            GetItrValue(loctestnum, loctesterr, it, true, 0);
            ++it;

            Terminated(loctestnum, loctesterr, it, true);

            // test su albero vuoto
            tree.Clear();
            lasd::BTPostOrderIterator<int> it2{tree};
            Terminated(loctestnum, loctesterr, it2, true);
            GetItrValue(loctestnum, loctesterr, it2, false, 0);

            // test reset
            lasd::BinaryTreeVec<int> tree2{vec};
            lasd::BTPostOrderIterator<int> it3{tree2};
            GetItrValue(loctestnum, loctesterr, it3, true, 3);
            ++it3;
            GetItrValue(loctestnum, loctesterr, it3, true, 4);
            it3.Reset();

            Terminated(loctestnum, loctesterr, it3, false);
            GetItrValue(loctestnum, loctesterr, it3, true, 3);


            // test settare valore
            lasd::BTPostOrderMutableIterator<int> it4{tree2};
            for(int i = 0; !it4.Terminated(); ++it4, i++) {
                SetItrValue(loctestnum, loctesterr, it4, true, vec[i]+10);
                GetItrValue(loctestnum, loctesterr, it4, true, vec[i]+10);
            }
        }
        {
            // test generale
            lasd::Vector<int> vec{5};
            for(int i = 0; i < 5; i++)
                vec[i] = i;

            lasd::BinaryTreeLnk<int> tree{vec};

            lasd::BTInOrderIterator<int> it{tree};
            TraverseInOrder(loctestnum, loctesterr, tree, true, TraversePrint<int>);

            Terminated(loctestnum, loctesterr, it, false);
            GetItrValue(loctestnum, loctesterr, it, true, 3);
            ++it;

            Terminated(loctestnum, loctesterr, it, false);
            GetItrValue(loctestnum, loctesterr, it, true, 1);
            ++it;

            Terminated(loctestnum, loctesterr, it, false);
            GetItrValue(loctestnum, loctesterr, it, true, 4);
            ++it;

            Terminated(loctestnum, loctesterr, it, false);
            GetItrValue(loctestnum, loctesterr, it, true, 0);
            ++it;

            Terminated(loctestnum, loctesterr, it, false);
            GetItrValue(loctestnum, loctesterr, it, true, 2);

            // test su albero vuoto
            tree.Clear();
            lasd::BTInOrderIterator<int> it2{tree};
            Terminated(loctestnum, loctesterr, it2, true);
            GetItrValue(loctestnum, loctesterr, it2, false, 0);

            // test reset
            lasd::BinaryTreeVec<int> tree2{vec};
            lasd::BTInOrderIterator<int> it3{tree2};
            GetItrValue(loctestnum, loctesterr, it3, true, 3);
            ++it3;
            GetItrValue(loctestnum, loctesterr, it3, true, 1);
            it3.Reset();

            Terminated(loctestnum, loctesterr, it3, false);
            GetItrValue(loctestnum, loctesterr, it3, true, 3);


            // test settare valore
            lasd::BTInOrderMutableIterator<int> it4{tree2};
            for(int i = 0; !it4.Terminated(); ++it4, i++) {
                SetItrValue(loctestnum, loctesterr, it4, true, vec[i]+10);
                GetItrValue(loctestnum, loctesterr, it4, true, vec[i]+10);
            }
        }
        {
            cout << "Costruttori e assignment Breadth Iterator" << endl;

            lasd::Vector<int> vec{5};
            for(int i = 0; i < 5; i++)
                vec[i] = i;
            
            lasd::BinaryTreeVec<int> tree{vec};

            lasd::BTBreadthIterator<int> it{tree};
            lasd::BTBreadthIterator<int> it2{it};

            for(int i = 0; !it.Terminated(); ++i, ++it, ++it2) {
                GetItrValue(loctestnum, loctesterr, it, true, vec[i]);
                GetItrValue(loctestnum, loctesterr, it2, true, vec[i]);
            }
            Terminated(loctestnum, loctesterr, it, true);
            Terminated(loctestnum, loctesterr, it2, true);

            it.Reset();
            it2.Reset();

            Terminated(loctestnum, loctesterr, it, false);
            lasd::BTBreadthIterator<int> it3{move(it)};
            Terminated(loctestnum, loctesterr, it, true);

            for(int i = 0; !it2.Terminated(); ++i, ++it2, ++it3) {
                GetItrValue(loctestnum, loctesterr, it2, true, vec[i]);
                GetItrValue(loctestnum, loctesterr, it3, true, vec[i]);
            }
            Terminated(loctestnum, loctesterr, it2, true);
            Terminated(loctestnum, loctesterr, it3, true);

            it2.Reset();
            it = it2;
            for(int i = 0; !it2.Terminated(); ++i, ++it, ++it2) {
                GetItrValue(loctestnum, loctesterr, it, true, vec[i]);
                GetItrValue(loctestnum, loctesterr, it2, true, vec[i]);
            }
            Terminated(loctestnum, loctesterr, it, true);
            Terminated(loctestnum, loctesterr, it2, true);

            it2.Reset();
            it = move(it2);
            it2.Reset();

            for(int i = 0; !it2.Terminated(); ++i, ++it, ++it2) {
                GetItrValue(loctestnum, loctesterr, it, true, vec[i]);
                GetItrValue(loctestnum, loctesterr, it2, true, vec[i]);
            }
            Terminated(loctestnum, loctesterr, it, true);
            Terminated(loctestnum, loctesterr, it2, true);

        }
        {
            cout << "Costruttori e assignment Mutable Breadth Iterator" << endl;
            lasd::Vector<int> vec{5};
            for(int i = 0; i < 5; i++)
                vec[i] = i;
            
            lasd::BinaryTreeVec<int> tree{vec};

            lasd::BTBreadthMutableIterator<int> it{tree};
            lasd::BTBreadthMutableIterator<int> it2{it};

            for(int i = 0; !it.Terminated(); ++i, ++it, ++it2) {
                GetItrValue(loctestnum, loctesterr, it, true, vec[i]);
                GetItrValue(loctestnum, loctesterr, it2, true, vec[i]);
            }
            Terminated(loctestnum, loctesterr, it, true);
            Terminated(loctestnum, loctesterr, it2, true);

            it.Reset();
            it2.Reset();

            Terminated(loctestnum, loctesterr, it, false);
            lasd::BTBreadthMutableIterator<int> it3{move(it)};
            Terminated(loctestnum, loctesterr, it, true);

            for(int i = 0; !it2.Terminated(); ++i, ++it2, ++it3) {
                GetItrValue(loctestnum, loctesterr, it2, true, vec[i]);
                GetItrValue(loctestnum, loctesterr, it3, true, vec[i]);
            }
            Terminated(loctestnum, loctesterr, it2, true);
            Terminated(loctestnum, loctesterr, it3, true);

            it2.Reset();
            it = it2;
            for(int i = 0; !it2.Terminated(); ++i, ++it, ++it2) {
                GetItrValue(loctestnum, loctesterr, it, true, vec[i]);
                GetItrValue(loctestnum, loctesterr, it2, true, vec[i]);
            }
            Terminated(loctestnum, loctesterr, it, true);
            Terminated(loctestnum, loctesterr, it2, true);

            it2.Reset();
            it = move(it2);
            it2.Reset();

            for(int i = 0; !it2.Terminated(); ++i, ++it, ++it2) {
                GetItrValue(loctestnum, loctesterr, it, true, vec[i]);
                GetItrValue(loctestnum, loctesterr, it2, true, vec[i]);
            }
            Terminated(loctestnum, loctesterr, it, true);
            Terminated(loctestnum, loctesterr, it2, true);

        }
        {
            cout << "Costruttori e assignment Pre Order Iterator" << endl;

            lasd::Vector<int> vec{5};
            for(int i = 0; i < 5; i++)
                vec[i] = i;
            
            lasd::BinaryTreeVec<int> tree{vec};

            vec[0] = 0;
            vec[1] = 1;
            vec[2] = 3;
            vec[3] = 4;
            vec[4] = 2;

            lasd::BTPreOrderIterator<int> it{tree};
            lasd::BTPreOrderIterator<int> it2{it};

            for(int i = 0; !it.Terminated(); ++i, ++it, ++it2) {
                GetItrValue(loctestnum, loctesterr, it, true, vec[i]);
                GetItrValue(loctestnum, loctesterr, it2, true, vec[i]);
            }
            Terminated(loctestnum, loctesterr, it, true);
            Terminated(loctestnum, loctesterr, it2, true);

            it.Reset();
            it2.Reset();

            Terminated(loctestnum, loctesterr, it, false);
            lasd::BTPreOrderIterator<int> it3{move(it)};
            Terminated(loctestnum, loctesterr, it, true);

            for(int i = 0; !it2.Terminated(); ++i, ++it2, ++it3) {
                GetItrValue(loctestnum, loctesterr, it2, true, vec[i]);
                GetItrValue(loctestnum, loctesterr, it3, true, vec[i]);
            }
            Terminated(loctestnum, loctesterr, it2, true);
            Terminated(loctestnum, loctesterr, it3, true);

            it2.Reset();
            it = it2;
            for(int i = 0; !it2.Terminated(); ++i, ++it, ++it2) {
                GetItrValue(loctestnum, loctesterr, it, true, vec[i]);
                GetItrValue(loctestnum, loctesterr, it2, true, vec[i]);
            }
            Terminated(loctestnum, loctesterr, it, true);
            Terminated(loctestnum, loctesterr, it2, true);

            it2.Reset();
            it = move(it2);
            it2.Reset();

            for(int i = 0; !it2.Terminated(); ++i, ++it, ++it2) {
                GetItrValue(loctestnum, loctesterr, it, true, vec[i]);
                GetItrValue(loctestnum, loctesterr, it2, true, vec[i]);
            }
            Terminated(loctestnum, loctesterr, it, true);
            Terminated(loctestnum, loctesterr, it2, true);

        }
        {
            cout << "Costruttori e assignment Mutable Pre Order Iterator" << endl;
            lasd::Vector<int> vec{5};
            for(int i = 0; i < 5; i++)
                vec[i] = i;
            
            lasd::BinaryTreeVec<int> tree{vec};

            vec[0] = 0;
            vec[1] = 1;
            vec[2] = 3;
            vec[3] = 4;
            vec[4] = 2;

            lasd::BTPreOrderMutableIterator<int> it{tree};
            lasd::BTPreOrderMutableIterator<int> it2{it};

            for(int i = 0; !it.Terminated(); ++i, ++it, ++it2) {
                GetItrValue(loctestnum, loctesterr, it, true, vec[i]);
                GetItrValue(loctestnum, loctesterr, it2, true, vec[i]);
            }
            Terminated(loctestnum, loctesterr, it, true);
            Terminated(loctestnum, loctesterr, it2, true);

            it.Reset();
            it2.Reset();

            Terminated(loctestnum, loctesterr, it, false);
            lasd::BTPreOrderMutableIterator<int> it3{move(it)};
            Terminated(loctestnum, loctesterr, it, true);

            for(int i = 0; !it2.Terminated(); ++i, ++it2, ++it3) {
                GetItrValue(loctestnum, loctesterr, it2, true, vec[i]);
                GetItrValue(loctestnum, loctesterr, it3, true, vec[i]);
            }
            Terminated(loctestnum, loctesterr, it2, true);
            Terminated(loctestnum, loctesterr, it3, true);

            it2.Reset();
            it = it2;
            for(int i = 0; !it2.Terminated(); ++i, ++it, ++it2) {
                GetItrValue(loctestnum, loctesterr, it, true, vec[i]);
                GetItrValue(loctestnum, loctesterr, it2, true, vec[i]);
            }
            Terminated(loctestnum, loctesterr, it, true);
            Terminated(loctestnum, loctesterr, it2, true);

            it2.Reset();
            it = move(it2);
            it2.Reset();

            for(int i = 0; !it2.Terminated(); ++i, ++it, ++it2) {
                GetItrValue(loctestnum, loctesterr, it, true, vec[i]);
                GetItrValue(loctestnum, loctesterr, it2, true, vec[i]);
            }
            Terminated(loctestnum, loctesterr, it, true);
            Terminated(loctestnum, loctesterr, it2, true);

        }
        {
            cout << "Costruttori e assignment Post Order Iterator" << endl;

            lasd::Vector<int> vec{5};
            for(int i = 0; i < 5; i++)
                vec[i] = i;
            
            lasd::BinaryTreeVec<int> tree{vec};

            vec[0] = 3;
            vec[1] = 4;
            vec[2] = 1;
            vec[3] = 2;
            vec[4] = 0;

            lasd::BTPostOrderIterator<int> it{tree};
            lasd::BTPostOrderIterator<int> it2{it};

            for(int i = 0; !it.Terminated(); ++i, ++it, ++it2) {
                GetItrValue(loctestnum, loctesterr, it, true, vec[i]);
                GetItrValue(loctestnum, loctesterr, it2, true, vec[i]);
            }
            Terminated(loctestnum, loctesterr, it, true);
            Terminated(loctestnum, loctesterr, it2, true);

            it.Reset();
            it2.Reset();

            Terminated(loctestnum, loctesterr, it, false);
            lasd::BTPostOrderIterator<int> it3{move(it)};
            Terminated(loctestnum, loctesterr, it, true);

            for(int i = 0; !it2.Terminated(); ++i, ++it2, ++it3) {
                GetItrValue(loctestnum, loctesterr, it2, true, vec[i]);
                GetItrValue(loctestnum, loctesterr, it3, true, vec[i]);
            }
            Terminated(loctestnum, loctesterr, it2, true);
            Terminated(loctestnum, loctesterr, it3, true);

            it2.Reset();
            it = it2;
            for(int i = 0; !it2.Terminated(); ++i, ++it, ++it2) {
                GetItrValue(loctestnum, loctesterr, it, true, vec[i]);
                GetItrValue(loctestnum, loctesterr, it2, true, vec[i]);
            }
            Terminated(loctestnum, loctesterr, it, true);
            Terminated(loctestnum, loctesterr, it2, true);

            it2.Reset();
            it = move(it2);
            it2.Reset();

            for(int i = 0; !it2.Terminated(); ++i, ++it, ++it2) {
                GetItrValue(loctestnum, loctesterr, it, true, vec[i]);
                GetItrValue(loctestnum, loctesterr, it2, true, vec[i]);
            }
            Terminated(loctestnum, loctesterr, it, true);
            Terminated(loctestnum, loctesterr, it2, true);

        }
        {
            cout << "Costruttori e assignment Mutable Post Order Iterator" << endl;
            lasd::Vector<int> vec{5};
            for(int i = 0; i < 5; i++)
                vec[i] = i;
            
            lasd::BinaryTreeVec<int> tree{vec};

            vec[0] = 3;
            vec[1] = 4;
            vec[2] = 1;
            vec[3] = 2;
            vec[4] = 0;

            lasd::BTPostOrderMutableIterator<int> it{tree};
            lasd::BTPostOrderMutableIterator<int> it2{it};

            for(int i = 0; !it.Terminated(); ++i, ++it, ++it2) {
                GetItrValue(loctestnum, loctesterr, it, true, vec[i]);
                GetItrValue(loctestnum, loctesterr, it2, true, vec[i]);
            }
            Terminated(loctestnum, loctesterr, it, true);
            Terminated(loctestnum, loctesterr, it2, true);

            it.Reset();
            it2.Reset();

            Terminated(loctestnum, loctesterr, it, false);
            lasd::BTPostOrderMutableIterator<int> it3{move(it)};
            Terminated(loctestnum, loctesterr, it, true);

            for(int i = 0; !it2.Terminated(); ++i, ++it2, ++it3) {
                GetItrValue(loctestnum, loctesterr, it2, true, vec[i]);
                GetItrValue(loctestnum, loctesterr, it3, true, vec[i]);
            }
            Terminated(loctestnum, loctesterr, it2, true);
            Terminated(loctestnum, loctesterr, it3, true);

            it2.Reset();
            it = it2;
            for(int i = 0; !it2.Terminated(); ++i, ++it, ++it2) {
                GetItrValue(loctestnum, loctesterr, it, true, vec[i]);
                GetItrValue(loctestnum, loctesterr, it2, true, vec[i]);
            }
            Terminated(loctestnum, loctesterr, it, true);
            Terminated(loctestnum, loctesterr, it2, true);

            it2.Reset();
            it = move(it2);
            it2.Reset();

            for(int i = 0; !it2.Terminated(); ++i, ++it, ++it2) {
                GetItrValue(loctestnum, loctesterr, it, true, vec[i]);
                GetItrValue(loctestnum, loctesterr, it2, true, vec[i]);
            }
            Terminated(loctestnum, loctesterr, it, true);
            Terminated(loctestnum, loctesterr, it2, true);

        }
        {
            cout << "Costruttori e assignment In Order Iterator" << endl;

            lasd::Vector<int> vec{5};
            for(int i = 0; i < 5; i++)
                vec[i] = i;
            
            lasd::BinaryTreeVec<int> tree{vec};

            vec[0] = 3;
            vec[1] = 1;
            vec[2] = 4;
            vec[3] = 0;
            vec[4] = 2;

            lasd::BTInOrderIterator<int> it{tree};
            lasd::BTInOrderIterator<int> it2{it};

            for(int i = 0; !it.Terminated(); ++i, ++it, ++it2) {
                GetItrValue(loctestnum, loctesterr, it, true, vec[i]);
                GetItrValue(loctestnum, loctesterr, it2, true, vec[i]);
            }
            Terminated(loctestnum, loctesterr, it, true);
            Terminated(loctestnum, loctesterr, it2, true);

            it.Reset();
            it2.Reset();

            Terminated(loctestnum, loctesterr, it, false);
            lasd::BTInOrderIterator<int> it3{move(it)};
            Terminated(loctestnum, loctesterr, it, true);

            for(int i = 0; !it2.Terminated(); ++i, ++it2, ++it3) {
                GetItrValue(loctestnum, loctesterr, it2, true, vec[i]);
                GetItrValue(loctestnum, loctesterr, it3, true, vec[i]);
            }
            Terminated(loctestnum, loctesterr, it2, true);
            Terminated(loctestnum, loctesterr, it3, true);

            it2.Reset();
            it = it2;
            for(int i = 0; !it2.Terminated(); ++i, ++it, ++it2) {
                GetItrValue(loctestnum, loctesterr, it, true, vec[i]);
                GetItrValue(loctestnum, loctesterr, it2, true, vec[i]);
            }
            Terminated(loctestnum, loctesterr, it, true);
            Terminated(loctestnum, loctesterr, it2, true);

            it2.Reset();
            it = move(it2);
            it2.Reset();

            for(int i = 0; !it2.Terminated(); ++i, ++it, ++it2) {
                GetItrValue(loctestnum, loctesterr, it, true, vec[i]);
                GetItrValue(loctestnum, loctesterr, it2, true, vec[i]);
            }
            Terminated(loctestnum, loctesterr, it, true);
            Terminated(loctestnum, loctesterr, it2, true);

        }
        {
            cout << "Costruttori e assignment Mutable In Order Iterator" << endl;
            lasd::Vector<int> vec{5};
            for(int i = 0; i < 5; i++)
                vec[i] = i;
            
            lasd::BinaryTreeVec<int> tree{vec};

            vec[0] = 3;
            vec[1] = 1;
            vec[2] = 4;
            vec[3] = 0;
            vec[4] = 2;

            lasd::BTInOrderMutableIterator<int> it{tree};
            lasd::BTInOrderMutableIterator<int> it2{it};

            for(int i = 0; !it.Terminated(); ++i, ++it, ++it2) {
                GetItrValue(loctestnum, loctesterr, it, true, vec[i]);
                GetItrValue(loctestnum, loctesterr, it2, true, vec[i]);
            }
            Terminated(loctestnum, loctesterr, it, true);
            Terminated(loctestnum, loctesterr, it2, true);

            it.Reset();
            it2.Reset();

            Terminated(loctestnum, loctesterr, it, false);
            lasd::BTInOrderMutableIterator<int> it3{move(it)};
            Terminated(loctestnum, loctesterr, it, true);

            for(int i = 0; !it2.Terminated(); ++i, ++it2, ++it3) {
                GetItrValue(loctestnum, loctesterr, it2, true, vec[i]);
                GetItrValue(loctestnum, loctesterr, it3, true, vec[i]);
            }
            Terminated(loctestnum, loctesterr, it2, true);
            Terminated(loctestnum, loctesterr, it3, true);

            it2.Reset();
            it = it2;
            for(int i = 0; !it2.Terminated(); ++i, ++it, ++it2) {
                GetItrValue(loctestnum, loctesterr, it, true, vec[i]);
                GetItrValue(loctestnum, loctesterr, it2, true, vec[i]);
            }
            Terminated(loctestnum, loctesterr, it, true);
            Terminated(loctestnum, loctesterr, it2, true);

            it2.Reset();
            it = move(it2);
            it2.Reset();

            for(int i = 0; !it2.Terminated(); ++i, ++it, ++it2) {
                GetItrValue(loctestnum, loctesterr, it, true, vec[i]);
                GetItrValue(loctestnum, loctesterr, it2, true, vec[i]);
            }
            Terminated(loctestnum, loctesterr, it, true);
            Terminated(loctestnum, loctesterr, it2, true);

        }

  	}
  	catch (...) {
		loctestnum++;
		loctesterr++;
		cout << endl << "Unmanaged error! " << endl;
	}
  	cout << "End of My Iterator<int> Test! (Errors/Tests: " << loctesterr << "/" << loctestnum << ")" << endl;
	testnum += loctestnum;
	testerr += loctesterr;
}


// void my_iterator_str(unsigned int &testnum, unsigned int &testerr) {
// 	unsigned int loctesterr{0};
// 	unsigned int loctestnum{0};
// 	cout << endl << "Begin of My Iterator<string> Test:" << endl;
//   	try {
// 		//TODO
//   	} 
//   	catch (...) {
//     	loctestnum++;
//     	loctesterr++;
//     	cout << endl << "Unmanaged error! " << endl;
//   	}
//  	cout << "End of My Iterator<string> Test! (Errors/Tests: " << loctesterr << "/" << loctestnum << ")" << endl;
// 	testnum += loctestnum;
// 	testerr += loctesterr;
// }


/* ************************************************************************** */

void my_iterator_test(unsigned int &testnum, unsigned int &testerr) {
	my_iterator_int(testnum, testerr);
	// my_iterator_str(testnum, testerr);

}