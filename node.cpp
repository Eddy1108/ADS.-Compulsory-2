#include <iostream>
#include <math.h>
#include <stack>
#include "node.h"


Node::Node(long data) : m_data (data)
{

}

void Node::Insert(long data)
{
    if(data >= m_data)
    {
        if(m_right)
            m_right->Insert(data);
        else
            m_right = new Node(data);
    }
    else if(data < m_data)
    {
        if(m_left)
            m_left->Insert(data);
        else
            m_left = new Node(data);
    }
}

Node *Node::MakeNewNode(long data)
{
    Node* newNode = new Node(data);
    newNode->m_left = nullptr;
    newNode->m_right = nullptr;
    return newNode;
}

bool Node::Search(Node *root, long data)
{
    if(root == nullptr) return false;
    else if(root->m_data == data) return true;
    else if(data < root->m_data) return Search(root->m_left, data);
    else return Search(root->m_right, data);

}

void Node::Preorder(Node *root)
{
    if(root == nullptr) return;
    std::cout << root->m_data << " ";
    root->Preorder(root->m_left);
    root->Preorder(root->m_right);
}

void Node::PreorderLoop()
{

    std::stack<Node*> stack;
    Node* current = this;
    stack.push(current);

    while(stack.empty() == false)
    {
        std::cout << current->m_data << " ";

        stack.pop();

        if(current->m_right != nullptr)
            stack.push(current->m_right);
        if(current->m_left != nullptr)
            stack.push(current->m_left);

        if(stack.empty() == false)
            current = stack.top();
    }

}

void Node::Inorder(Node *root)
{
    if(root == nullptr) return;
    root->Preorder(root->m_left);
    std::cout << root->m_data << " ";
    root->Preorder(root->m_right);
}

void Node::InorderLoop()
{
    std::stack<Node*> stack;
    Node* current = this;

    while(current != nullptr || stack.empty() == false)
    {
        while(current != nullptr)
        {
            stack.push(current);
            current = current->m_left;
        }

        if(stack.top() != nullptr)
            current = stack.top();

        stack.pop();

        std::cout << current->m_data << " ";

        current = current->m_right;
    }
}

void Node::Postorder(Node *root)
{
    if(root == nullptr) return;
    root->Postorder(root->m_left);
    root->Postorder(root->m_right);
    std::cout << root->m_data << " ";
}

void Node::PostorderLoop()
{

    std::stack<Node*> stack;
    std::stack<long> intStack;
    Node* current = this;
    stack.push(current);

    while(stack.empty() == false)
    {
        intStack.push(current->m_data);

        stack.pop();

        if(current->m_left != nullptr)
            stack.push(current->m_left);
        if(current->m_right != nullptr)
            stack.push(current->m_right);

        if(stack.empty() == false)
            current = stack.top();
    }

    while(intStack.empty() == false)
    {
        std::cout << intStack.top() << " ";
        intStack.pop();
    }
}

void Node::findNodes()
{

    int nodes{0};

    std::stack<Node*> stack;
    std::stack<int> intStack;
    Node* current = this;
    stack.push(current);

    while(stack.empty() == false)
    {
        intStack.push(current->m_data);

        stack.pop();
        nodes++;

        if(current->m_left != nullptr)
            stack.push(current->m_left);
        if(current->m_right != nullptr)
            stack.push(current->m_right);

        if(stack.empty() == false)
            current = stack.top();
    }

    std::cout << "\nNumber of Nodes: " << nodes << std::endl;
}

long Node::findNodes2(Node *root)
{
    if (root == nullptr)
    {
        return 0;
    }

    return 1 + findNodes2(root->m_left) + findNodes2(root->m_right);
}
long Node::findDepth(Node* root)
{
    if(root == nullptr)
    {
        return 0;
    }
    else
    {
        int leftDepth = findDepth(root->m_left);
        int rightDepth = findDepth(root->m_right);

        if(leftDepth < rightDepth)
            return (rightDepth + 1);
        else
            return (leftDepth + 1);
    }
}

bool Node::isBalanced(Node *root)
{
    int leftDepth = findDepth(root->m_left);
    int rightDepth = findDepth(root->m_right);
    std::cout << "Left: " << leftDepth << ", Right: " << rightDepth << std::endl;   //DEBUG

    if (abs(leftDepth - rightDepth) <= 1)
        return true;
    else
        return false;
}
