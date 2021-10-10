#include <iostream>
#include <cmath>
#include <vector>
#include "node.h"
#include "stack.h"
#include "Vector2d.h"
#include "GameObject.h"
#include "quadtree.h"

int main()
{
    std::cout << "- - - - - -DEL 1- - - - - -" << std::endl;
    Node* root = new Node(7);

    root->Insert(15);
    root->Insert(10);
    root->Insert(20);
    root->Insert(25);
    root->Insert(8);
    root->Insert(12);
    root->Insert(2);


    if(root->Search(root, 15) == true) std::cout << "Number found!\n";
    else std::cout << "Number NOT found!\n";

    root->PreorderLoop();
    std::cout << std::endl;
    root->PostorderLoop();
    std::cout << std::endl;
    root->InorderLoop();
    std::cout << std::endl;

    root->findNodes();
    std::cout << "Number of Nodes: " << root->findNodes2(root) << std::endl;

    std::cout << "Max depth of root is: " << root->findDepth(root) << std::endl;

    std::cout << "Is root balanced? : ";
    if(root->isBalanced(root))
        std::cout << "YES" << std::endl;
    else
        std::cout << "NO" << std::endl;


    std::cout << "\n\n\n- - - - - -DEL 2- - - - - -" << std::endl;

    //Make the square
    Vector2d a{-4, -4};
    Vector2d b{4, -4};
    Vector2d c{4, 4};
    Vector2d d{-4, 4};
    QuadTree quadRoot{a, b, c ,d};

    //Subdivide and assign subtree
    quadRoot.subDivide(1);
    QuadTree* subtree = quadRoot.m_sw;

    //Subdivide only the subtree
    subtree->subDivide(1);

    std::cout << "\nPrinting all leaves for quadRoot: " << std::endl;
    quadRoot.printAllLeaves();

    return 0;
}
