#ifndef LLIST_H
#define LLIST_H

#include <cstdlib>
#include <stdexcept>
#include <iostream>

//template <class T>
class llist {
  public:
    struct Node {
      Node* next;
      Node* prev;
      int value;
    };

    llist();
    ~llist();
    // setters
    void push_back(int val);
    void pop_back();
    
    void push_front(int val);
    void pop_front();
    
    void insert(int loc, int val);
    void update(int loc, int val);
    void remove(int loc);

    // accessors
    int get_front();
    int get_back();
    int get_at(int loc);

    // utilities
    bool is_empty();
    int size();
    void clear();

  private: 
    Node* head;
    Node* tail;

    int size_;

    Node* get_node(int pos);
    //Node * traverse(int pos);

    // Multiple llist functions
    /*
    splits the list in two lists (target1, target2). Original list is either preserved or
    deleted based on the preserve parameter. If odd target1 contains the extra element.
    */
    //void FrontBackSplit(llist target1, llist target2, bool preserve);
};

/*
SortedInsert(): given a list that is sorted in increasing order, and a
single node, inserts the node into the correct sorted position in the list. While Push()
allocates a new node to add to the list, SortedInsert() takes an existing node, and just
rearranges pointers to insert it into the list. 

InsertSort(): given a list, rearranges its nodes so they are sorted in
increasing order. It should use SortedInsert()

FrontBackSplit(): Given a list, split it into two sublists — one for the front half, and one for the back half. If
the number of elements is odd, the extra element should go in the front list. So
FrontBackSplit() on the list {2, 3, 5, 7, 11} should yield the two lists {2, 3, 5} and {7,
11}. Getting this right for all the cases is harder than it looks. You should check your
solution against a few cases (length = 2, length = 3, length=4) to make sure that the list
gets split correctly near the short-list boundary conditions. If it works right for length=4,
it probably works right for length=1000. You will probably need special case code to deal
with the (length <2) cases.

RemoveDuplicates(): takes a list sorted in increasing order and deletes any duplicate nodes from the list. Ideally, the list should only be traversed once.

MoveNode(): This is a variant on Push(). Instead of creating a new node and pushing it onto the given
list, MoveNode() takes two lists, removes the front node from the second list and pushes
it onto the front of the first. This turns out to be a handy utility function to have for
several later problems. Both Push() and MoveNode() are designed around the feature that
list operations work most naturally at the head of the list. Here's a simple example of
what MoveNode() should do...
void MoveNodeTest() {
struct node* a = BuildOneTwoThree(); // the list {1, 2, 3}
struct node* b = BuildOneTwoThree();
}
*
MoveNode(&a, &b);
// a == {1, 1, 2, 3}
// b == {2, 3}

AlternatingSplit(): takes one list and divides up its nodes to make
two smaller lists. The sublists should be made from alternating elements in the original
list. So if the original list is {a, b, a, b, a}, then one sublist should be {a, a, a} and the
other should be {b, b}. You may want to use MoveNode() as a helper. The elements in
the new lists may be in any order (for some implementations, it turns out to be convenient
if they are in the reverse order from the original list.)

ShuffleMerge(): Given two lists, merge their nodes together to make one list, taking nodes alternately
between the two lists. So ShuffleMerge() with {1, 2, 3} and {7, 13, 1} should yield {1, 7,
2, 13, 3, 1}. If either list runs out, all the nodes should be taken from the other list. The
solution depends on being able to move nodes to the end of a list as discussed in the
Section 1 review. You may want to use MoveNode() as a helper. Overall, many
techniques are possible: dummy node, local reference, or recursion. Using this function
and FrontBackSplit(), you could simulate the shuffling of cards.

SortedMerge(): Write a SortedMerge() function that takes two lists, each of which is sorted in increasing
order, and merges the two together into one list which is in increasing order.
SortedMerge() should return the new list. The new list should be made by splicing
together the nodes of the first two lists (use MoveNode()). Ideally, Merge() should only
make one pass through each list. Merge() is tricky to get right — it may be solved
iteratively or recursively. There are many cases to deal with: either 'a' or 'b' may be
empty, during processing either 'a' or 'b' may run out first, and finally there's the problem
of starting the result list empty, and building it up while going through 'a' and 'b'.

MergeSort(): (This problem requires recursion) Given FrontBackSplit() and SortedMerge(), it's pretty
easy to write a classic recursive MergeSort(): split the list into two smaller lists,
recursively sort those lists, and finally merge the two sorted lists together into a single
sorted list. Ironically, this problem is easier than either FrontBackSplit() or
SortedMerge().

SortedIntersect(): Given two lists sorted in increasing order, create and return a new list representing the
intersection of the two lists. The new list should be made with its own memory — the
original lists should not be changed. In other words, this should be Push() list building,
not MoveNode(). Ideally, each list should only be traversed once. This problem along
with Union() and Difference() form a family of clever algorithms that exploit the
constraint that the lists are sorted to find common nodes efficiently.

RecursiveReverse(): (This problem is difficult and is only possible if you are familiar with recursion.) There is
a short and efficient recursive solution to this problem. As before, the code should only
make a single pass over the list. Doing it with multiple passes is easier but very slow, so
here we insist on doing it in one pass.. Solving this problem requires a real understanding
of pointer code and recursion.
*
 Recursively reverses the given linked list by changing its .next
 pointers and its head pointer in one pass of the list.
*
*/

#endif