//
//  10.2-4.h
//  CLRSExercises
//
//  Created by Max Reshetey on 03.04.2020.
//  Copyright © 2020 Max Reshetey. All rights reserved.
//

#ifndef _0_2_4_h
#define _0_2_4_h

#include <iostream>

// Singly linked list with sentinel. Interface is limited by exercise scope.
// May and should be used as a base for full-weight class
class SingleListSentinel
{
public:
    struct Node
    {
        Node * next = nullptr;
        int key = 0;

        Node(int key) : key(key) {}
    };

    struct Nil : Node
    {
        Nil(int key) : Node(key) {}
    };

public: // Methods

    // Solution: The idea is to set nil.key to the key being looked up and then
    // check whether found node is Nil (not found) or not (found)
    // Now we can get rid of node != nullptr in the while() condition of search() method
    // The remaining part fully replicates SingleList::search()

    // Time O(n), space O(1)
    Node * search(int key)
    {
        nil->key = key;

        Node * node = head;

        while (node->key != key)
        {
            node = node->next;
        }

        return node;
    }

    // Time O(1), space: 0
    // Just update head
    void pushFront(Node * node)
    {
        // Implementation fully replicates SingleList::pushFront()
        // Initially head == our Nil sentinel, which is well updated in the first line

        node->next = head;
        head = node;
    }

private:
    Nil * nil = new Nil(0);
    Node * head = nil;
};

void test_10_2_4() {

    SingleListSentinel list;

    int kNumberOfElements = 10;

    for (int i = 0; i < kNumberOfElements; ++i)
    {
        int key = i + 1;
        auto node = new SingleListSentinel::Node(key);
        list.pushFront(node);
    }

    // Test returned node is found
    SingleListSentinel::Node * node = list.search(7);
    printf("See node %p, key %i\n\n", node, node?node->key:-1);

    // Test returned node is not found, i.e. Nil sentinel
    node = list.search(15);
    printf("See node %p, key %i\n\n", node, node?node->key:-1);
}

#endif /* _0_2_4_h */
