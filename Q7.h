#ifndef Q7_H_INCLUDED
#define Q7_H_INCLUDED
using namespace std;

class node
{
public:
    node(){left=NULL; right=NULL; ct = 1;}
    node(int v){val = v; left=NULL; right=NULL; ct=1;}
     node( int Pri, int cat)
    : val(Pri), ct(cat) {}

    friend bool operator<(//sorts queue by lowest Priority
    const node& x, const node& y) {
        return x.val < y.val;
          //return max
    }

    friend bool operator>(//sorts queue by greatest Priority
    const node& x, const node& y) {
        return x.ct > y.ct;
    }

   friend ostream&//prints out queue later
    operator<<(ostream& os, const node& Pri) {
    return os  <<"my value = "<<Pri.val<<" occured "<<Pri.ct<<" times";
    }
    int unsortedRemoveDuplicates(vector<int>& numbers)
{
    set<int> seenNums; //log(n) existence check

    auto itr = begin(numbers);
    while(itr != end(numbers))
    {
        if(seenNums.find(*itr) != end(seenNums)) //seen? erase it
            itr = numbers.erase(itr); //itr now points to next element
        else
        {
            seenNums.insert(*itr);
            itr++;
        }
    }

    return seenNums.size();
}
    priority_queue<node, vector<node>, greater<node> > pq;
    priority_queue<node, vector<node>, less<node> > pq1;


    void addnode(int v)
    {
       if(v==val){ct++;}
       pq.emplace(node(v));
       pq1.emplace(node(v));
        if(v<val)
            {
            if(left==NULL){left=new node(v);
                }
            else{left->addnode(v);
                }
            }
        else
            {
            if(right==NULL){right = new node(v);
                }
            else{right->addnode(v);
                }
            }
    }

    int display()
        {

            if(left!=NULL){left->display();}

            cout<<"frequency  "<<ct<<" value"<<val<<endl;

            if(right!=NULL){right->display();}

        }

    void display_Queue()
        {
            cout << "0. size: " << pq.size() << '\n';
            cout << "Popping out elements from Pqueue..."<<'\n';
            while (!pq.empty())
            {
            cout << pq.top() <<  endl;
            pq.pop();
            }
            cout << '\n';
        }
            void display_Queue1()
        {
            cout << "0. size: " << pq1.size() << '\n';
            cout << "Popping out elements from Pqueue..."<<'\n';
            while (!pq1.empty())
            {
            cout << pq1.top() <<  endl;
            pq1.pop();
            }
            cout << '\n';
        }

private:
int val;      ///value in that node
int ct;
    ///ct = count of that value
node * left;
node * right;

};

#endif // Q7_H_INCLUDED
