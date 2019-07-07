#include <iostream>
#include<list>
using namespace std;

void merge2list(list<int>&list1,list<int>&list2 )
{

    list<int>::iterator it1 =list1.begin();
    list<int>::iterator it2 =list2.begin();
    while(it1!=list1.end()&&it2!=list2.end())
    {

        if (*it1>*it2)
        {
            list1.insert(it1,*it2);
            ++it2;
        }
        else if
        (*it1<*it2)
        {

            ++it1;
        }
        else
        {
            ++it1;
            ++it2;
        }
    }

while(it2!=list2.end()){

    list1.push_back(*it2);
    ++it2;
}

}

int main()
{
    list<int>firstlist;
    list<int>secondlist;
    ///list 1
    firstlist.push_back(2);
    firstlist.push_back(3);
    firstlist.push_back(5);
    firstlist.push_back(7) ;
    ///list 2
    secondlist.push_back(1);
    secondlist.push_back(3);
    secondlist.push_back(6);
    secondlist.push_back(7) ;
    secondlist.push_back(9) ;
    merge2list(firstlist,secondlist);
    /// print a list after merge two lists
    for (list<int>::iterator it1 = firstlist.begin(); it1 != firstlist.end(); ++it1)
    {
        cout << *it1 << endl;
    }

    return 0;
}
