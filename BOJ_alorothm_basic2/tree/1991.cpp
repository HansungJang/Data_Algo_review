/*
1. 아이디어
- struct 이용하여 node 생성  
- DLL 이용하여, tree rnwh rngus 
- main함수에서 입력받은 Node 갯수 알파벳 순으로 생성 
- 연결 순서 branching, 시작 node는 A 값을 가지는 node fix 
- VLR: 출력 -> L -> R (재귀함수, nullptr, return)
- LVR: stack -> L -> 출력 -> R 
- LRV: stack -> L -> R -> 출력 
stack 이용하여 구현 

2. 실행시간
재귀함수 이지만 max Node의 갯수 : 26
O(2^n) 라고 해도 < 1억 
사용가능  

3. 자료구조
- stack
- DLL 
- tree 
- 재귀 

*/

#include <iostream>

using namespace std; 

struct Node 
{
    char letter; 
    Node* left; 
    Node* right; 
}; 

class Tree_table
{
    private: 
        Node* initial;
        Node* start;  

    public: 
    Tree_table(int size)
    {
        initial = new Node[size];
        start = initial; 

        // 1. intialize Node 
        for(int i  = 0; i < size; i++)
        {
            initial[i].letter = 65 + i; 
            initial[i].left = nullptr; 
            initial[i].right = nullptr; 
        } 
    }

    void Linked_node(char parent, char leftAlp, char rightAlp)
    {
        int nodenum = parent - 65; 
        if(leftAlp != '.') initial[nodenum].left = &initial[leftAlp - 65]; 
        if(rightAlp != '.') initial[nodenum].right = &initial[rightAlp - 65];         
    }

    void VLR(Node* parent)
    { 
        if(parent == nullptr) return; 
        printf("%c", parent->letter); 
        VLR(parent->left); 
        VLR(parent->right); 
    }

    void LVR(Node* parent)
    {
        if(parent == nullptr) return; 
        LVR(parent->left); 
        printf("%c", parent->letter); 
        LVR(parent->right); 
    }

    void LRV(Node* parent)
    {
        if(parent == nullptr) return; 
        LRV(parent->left); 
        LRV(parent->right);
        printf("%c", parent->letter);  
    }

    Node* getStart()
    {
        return start; 
    }

    ~Tree_table()
    {
        delete[] initial; 
    }

}; 



int main()
{
    int size = 0; 
    cin >> size;
    Tree_table tree(size);

    for(int i = 0; i < size; i++)
    {
        char parent, left, right; 
        cin >> parent >> left >> right; 
        tree.Linked_node(parent, left, right); 
    } 

    Node* start = tree.getStart(); 
    tree.VLR(start); cout << endl;
    tree.LVR(start); cout << endl;
    tree.LRV(start); 


    return 0; 
}