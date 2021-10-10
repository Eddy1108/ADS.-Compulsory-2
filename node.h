#ifndef NODE_H
#define NODE_H



class Node
{
public:
    Node(long data);
    void Insert(long data);
    Node* MakeNewNode(long data);
    bool Search(Node* root, long data);
    void Preorder(Node* root);
    void PreorderLoop();
    void Inorder(Node* root);
    void InorderLoop();
    void Postorder(Node* root);
    void PostorderLoop();
    void findNodes();
    long findNodes2(Node* root);
    long findDepth(Node* root);
    bool isBalanced(Node* root);
private:
    long m_data;
    Node* m_left = nullptr;
    Node* m_right = nullptr;
};

#endif // NODE_H
