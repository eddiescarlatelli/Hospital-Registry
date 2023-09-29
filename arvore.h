#include <iostream>

using namespace std;

template<typename T>
struct Node
{
public:
    Node<T> *pLeft;
    Node<T> *pRight;
    T val;

    std::string getString(){
        return val.getString();
    }

    Node<T>(T val)
    {
        this->val = val;
        pLeft = pRight = nullptr;
    }
};

template<typename T>
class Tree
{
    Node<T> *root;

    Node<T> *insert_at_sub(T i, Node<T> *p);
    void print_sub(Node<T> *p);
    int t_size = 0;

public:
    Tree ()
    {
        root = nullptr;
    }

    void add(T i)
    {
        ++t_size;
        root = insert_at_sub(i, root);
    }
    void print()    
    {
        print_sub(root);
    };

    std::string get_string()
    {
        return get_string_sub(root);
    }
    std::string get_string_sub(Node<T> *);

    bool contain(T i)
    {
        return contain_sub(i, root);
    }
    bool contain_sub(T i, Node<T> *p);

    Node<T>* search(T i)
    {
        return search_sub(i,root);
    }
    Node<T>* search_sub(T i, Node<T> *p);

    void test()
    {
        cout << root->pRight->pRight->pRight->pLeft->pRight->val << endl;
    }

    int get_size()
    {
        return t_size;
    }
};

template<typename T>
Node<T>* Tree<T>::insert_at_sub(T i, Node<T> *p)
{
    if( ! p )
        return new Node<T>(i);
    else if (i <= p->val)
        p->pRight = insert_at_sub(i, p->pRight);
    else if (i > p->val)
        p->pLeft = insert_at_sub(i, p->pLeft);

    return p;
}

template<typename T>
void Tree<T>::print_sub(Node<T> *p)
{
    if(p)
    {
        print_sub(p->pRight);
        cout << p->val << endl;
        print_sub(p->pLeft);
    }
}

template<typename T>
std::string Tree<T>::get_string_sub(Node<T>* p){
    if(!p)
    {
        return "";
    }
    return get_string_sub(p->pRight) + "\n" + p->getString() + "\n" + get_string_sub(p->pLeft) + "\n";
}

template<typename T>
bool Tree<T>::contain_sub(T i, Node<T> *p)
{
    if (!p)
        return false;
    else if(i == p->val)
        return true;
    else if (i <= p->val)
        contain_sub(i, p->pRight);
    else
        contain_sub(i, p->pLeft);
}

template<typename T>
Node<T>* Tree<T>::search_sub(T i, Node<T> *p)
{
    if (!p)
        return nullptr;
    else if(i == p->val)
        return p;
    else if (i <= p->val)
        return search_sub(i, p->pRight);
    else
        return search_sub(i, p->pLeft);
}
