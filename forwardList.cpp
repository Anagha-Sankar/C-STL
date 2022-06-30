/***
* Forward list in C++ STL implements a singly linked list.
* Keeps track of the location of only next element.
* 
* Advantage:- less storage space required compared to list
* Drawback:- cannot be iterated backwards and its individual elements cannot be accessed directly
* 
* Header:- <forward_list>
* 
* forward_list<data_type> list_name;
* 
***/

#include <forward_list>
#include <iostream>
using namespace std;

int main()
{
    // Initialising a forward list
    forward_list<int> l = { 10, 15, 20 };

    // Pushing elements into the list
    l.push_front(5);    //{5, 10, 15, 20}

    // Pushing elements into the list
    l.push_front(3);    //{3, 5, 10, 15, 20}

    // Popping out elements from list
    l.pop_front();      //{5, 10, 15, 20}

    // Displaying the list
    for (int x : l)
        cout << x << " ";   //{5, 10, 15, 20}

    // assign()
    forward_list<int> l;
    l.assign({ 10, 20, 30, 10 });

    // remove()
    l.remove(10);       //{20, 30}

    for (auto it = l.begin(); it != l.end(); it++)
        cout << (*it) << " ";                       //{20, 30}



    /********** Assign - Method 1 ******************/
    forward_list<int> l;
    l.assign({ 10, 20, 30, 10 });
    forward_list<int> l2;
    l2.assign(l.begin(), l.end());
    /********** Assign - Method 2 *****************/
    /* Syntax:
        assign(int n, val) */
    l.assign(5, 10);    //{10 10 10 10 10}
    /*********************************************/



    /****************************************/
    forward_list<int> l1 = { 15, 20, 30 };
    // insert_after():
    // to insert elements at any position in forward list.
    // The arguments in this function are copied at the desired position.
    auto it = l1.insert_after(l1.begin(), 10);      //15 -> 10 -> 20 -> 30
    it = l1.insert_after(it, {2, 3, 5});            //15 -> 10 -> 2 -> 3 -> 5 -> 20 -> 30
    
    // emplace_after()
    // same operation as insert_after() but the elements are directly made without any copy operation.
    it = l1.emplace_after(it, 40);          //15 -> 10 -> 2 -> 3 -> 5 -> 40 -> 20 -> 30

    // erase_after()
    //  deletes the element next to the element pointed by the iterator.
    it = l1.erase_after(it);        // 15 -> 10 -> 2 -> 3 -> 5 -> 40 -> 30
    
    for(int x:l1){
        cout<<x<<" ";
    }

    it = l1.erase_after(it, l1.end());  // Removes all elements from it till end()

    /****************************************/

    /* clear():- All the elements of the forward list are removed
    Syntax:
    forwardlistname.clear()
    Input  : flist{1, 2, 3, 4, 5};
         flist.clear();
    Output : flist{}

    */



    /* empty():-  returns a boolean value indicating whether the forward_list is empty
    forwardlistname.empty()
    True, if the list is empty else false.
    */



    /* reverse():- reverses the order of the elements
    Input  : forward_list l = {10, 20, 30};
         l.reverse();

    Output : {30, 20, 10}
    */



   /* merge():- merges two sorted forward_lists into one
   merges the second list into the first, thus emptying the second list

   The merge() function can be used in two ways:
    * Merge two forward lists that are sorted in ascending order into one.
        forwardlist_name1.merge(forward_list& forwardlist_name2)
    * Merge two forward lists into one using a comparison function.
        forwardlist_name1.merge(forward_list& forwardlist_name2, Compare comp)

    Input : forward_list l1 = {10, 20, 30};
            forward_list l2 = {5, 15};

    Operation : l1.merge(l2)

    Output: l1 = {5, 10, 15, 20, 30}
            l2 = {}    

    */



    /* sort():- sort the elements of the container
    forwardlistname.sort()

    Input  : forward_list l1 = {5, 15, 10};
         l1.sort();

    Output : {5, 10, 15}
    */
}




/***** TIME COMPLEXITY ******
insert_after() - O(1)
erase_after() - erase one element it takes O(1) time and to erase m elements, it will take O(m) time.
push_front() - O(1)
pop_front() - O(1)
reverse() - O(n)
sort() - O(nlogn)
remove() - O(n)
assign() - To assign one element it takes O(1) time and to assign m elements, it will take O(m) time

*/
