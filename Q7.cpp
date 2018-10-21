#include <iostream>
#include <random>
#include <ctime>
#include <queue>
#include <set>
#include <functional>
#include <algorithm>
#include<list>
#include "Q7.h"

using namespace std;

int main()
{
    node * root=NULL;
    node z;
    int n,v;
    ///ct = count of that value
    vector<int> first;
    vector<int>::iterator fi;
    default_random_engine gen(time(NULL));
    cout<<"how many values? "; cin>>n;
    for(int i=0; i<n; i++)
    {  (v=gen()%n);
    first.push_back(v);

        if(root==NULL){root = new node(v); }
        else{

          root->addnode(v);

           }
    }

    z.unsortedRemoveDuplicates(first);
    cout<<"Binary Tree in a depth first manner with Duplicates removed!"<<endl;
    for ( fi = first.begin() ; fi != first.end(); ++fi){cout<<"Node "<<*fi<<endl;}
    cout<<"-------------------"<<endl;
    root->display();
    cout<<"-------------------"<<endl;
    cout<<"-------------------"<<endl;
     root->display_Queue1();
    cout<<"-------------------"<<endl;

return 0;


}


