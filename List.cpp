/***
 * List in C++ is implemented using doubly linked lists.
 * list<data_type> list_name;
 * 
 * Header: <list>
 * 
 * 
 ***/

#include<iostream>
#include<list>

using namespace std;

int main()
{
    // Create a List
    list<int> l;
    
    /***** push_back() and push_front() *****/
    // Push two elements at back
    l.push_back(10);
    l.push_back(20); 
    
    // Push an element to front
    l.push_front(5);
    
    // Traverse and print elements
    for(auto x: l)
    {
        cout<<x<<" ";       //5 10 20
    }
    
    /***** pop_back() and pop_front() *****/
    list<int> l = {10, 2, 5, 20};
    l.pop_front();      // 2 5 20
    l.pop_back();       // 2 5

    /************ insert() ***************/
    // insert at the iterator position
    // insert(pos_iter, ele_num, ele)
    list<int> l = {10, 20, 30};
    auto itr = l.begin();
    itr++;
    // insert 15 at second position
    itr = l.insert(itr, 15);    // { 10 15 20 30}
    // Insert 7 two times at position 2
    l.insert(itr, 2, 7);        // { 10 7 7 15 20 30}
    cout<<" "<<l.size();         // 6



    /********* erase() and remove() **********/
    // erase():- used to delete elements from a list container at the or range of iterator
    // iterator list_name.erase(iterator position)
    // or,
    // iterator list_name.erase(iterator first, iterator last)


    // remove():- remove elements from a list container, by comparing the alue
    // list_name.remove(val) 

    list<int> l = {10, 20, 30, 40, 20, 40};
    auto itr = l.begin();

    // Erase element pointed by itr
    itr = l.erase(itr);         // 20, 30, 40, 20, 40
    
    // Remove all occurrences of 40
    l.remove(40);               // 20, 30, 20



    /******************** merge() *****************/
    // merges two sorted lists into one
    // lists should be sorted in ascending order.
    // list1_name.merge(list2_name)
    list<int> list1 = { 10, 20, 30 }; 
    list<int> list2 = { 40, 50, 60 }; 
    list2.merge(list1); 
    for (auto it = list2.begin(); it != list2.end(); ++it) 
        cout << *it << " ";         // 10 20 30 40 50 60

    return 0;
}



/******* TIME COMPLEXITY ********/
/**
 * front() - O(1)
 * back() - O(1)
 * size() - O(1)
 * begin() - O(1)
 * end() - O(1)
 * erase(itr) - O(1)
 * push_back() - O(1)
 * push_front() - O(1)
 * pop_front() - O(1)
 * pop_back() - O(1)
 * reverse() - O(N)
 * remove() - O(N)
 * sort() - O(NlogN)
 **/
