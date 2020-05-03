
#include <iostream>
#include<string>
#include<vector>
#include<stack>
#include"tree.h"


/*struct node
{
    char data;
    node* left;
    node* right;
    node() :
        data(),
        left(nullptr),
        right(nullptr)
    {

    }
    node(char data) :
        data(data),
        left(nullptr),
        right(nullptr)
    {

    }
};




node* AddNode(char data)
{
    return new node(data);
}


void Traverse(node* root)
{
    if (root == nullptr)
    {
        std::cout << "end" << std::endl;
        return;
    }
    else
    {
        std::cout << root->data << std::endl;
        std::cout << "left :" << std::endl; Traverse(root->left);
        std::cout << "right :" << std::endl; Traverse(root->right);
    }
}

void Destroy(node* root)
{
    if (root == nullptr)
    {
        return;
    }
    else
    {
        Destroy(root->left);
        Destroy(root->right);
        //std::cout << "Destroyed " << root->data << std::endl;
        delete root;
    }
}
*/


bool IsOperator(char str)
{
    char op[] = { "+-*/^" };
    for (int i = 0; i < 6; i++)
    {
        if (str == op[i])
        {
            return true;
        }
    }
    return false;
}

/*
void LevelSpace(int level)
{
    unsigned char drawchar = 179 ;
    for (int i = 0; i < level-1; i++)
    {
        std::cout << drawchar<<"  ";
    }
}

void DrawTree(node* root, int level)
{
    unsigned char drawchar[] = {195,196,192};
   
        if (root != nullptr)
        {
            std::cout << root->data <<std::endl;
            if (root->left == nullptr)
            {
                return;
            }
            else if (root->right == nullptr)
            {
                std::cout << drawchar[2];
                DrawTree(root->left, level + 1);
            }
            else
            {
                LevelSpace(level);
                std::cout << drawchar[0];
                std::cout << drawchar[1];
                std::cout << drawchar[1];
                DrawTree(root->left, level + 1);
                LevelSpace(level);
                std::cout << drawchar[2];
                std::cout << drawchar[1];
                std::cout << drawchar[1];
                DrawTree(root->right, level + 1);
            }
        }
    
}


node* CreateTree(std::string& expression)
{
    std::stack<char> stac;
    node* root = nullptr;
    for (char ch : expression)
    {
        if (IsOperator(ch))
        {
            if (root == nullptr)
            {
                node* op(nullptr);
                op = AddNode(ch);
                op->left = AddNode(stac.top());
                stac.pop();
                op->right = AddNode(stac.top());
                stac.pop();
                root = op;
            }
            else
            {
                node* op(nullptr);
                op = AddNode(ch);
                op->left = root;
                op->right = AddNode(stac.top());
                stac.pop();
                root = op;
            }
        }
        else
        {
            stac.push(ch);
        }
    }
    return root;
}

std::string InfixToPostFix( std::string infix) 
{
    std::stack<char> stak;
    infix.push_back(')');
    infix.insert(0, "(");
    std::string postfix;
    for (int i = 0; i < infix.size(); i++)
    {
        if (infix[i] == '(')
        {
            stak.push('(');
        }
        else if (infix[i] == ')')
        {
            while (stak.top() != '(')
            {
                postfix.push_back(stak.top());
                stak.pop();
            }
            stak.pop();
        }
        else if (IsOperator(infix[i]))
        {
            if (infix[i] == '^' && stak.top() == '^')
            {
                postfix.push_back(infix[i]);
            }
            if (infix[i] == '*' || infix[i] == '/')
            {

                if (stak.top() == '^')
                {
                    postfix.push_back(stak.top());
                    stak.pop();
                    stak.push(infix[i]);
                }
                else if (stak.top() == '*' || stak.top() == '/')
                {
                    postfix.push_back(stak.top());
                    stak.pop();
                    stak.push(infix[i]);
                }
                else
                {
                    stak.push(infix[i]);
                }
            }
            else if (infix[i] == '+' || infix[i] == '-')
            {

                if (stak.top() == '^' || stak.top() == '/' || stak.top() == '*')
                {
                    postfix.push_back(stak.top());
                    stak.pop();
                    stak.push(infix[i]);
                }
                else if (stak.top() == '-' || stak.top() == '+')
                {
                    postfix.push_back(stak.top());
                    stak.pop();
                    stak.push(infix[i]);
                }
                else
                {
                    stak.push(infix[i]);
                }
            }
            else
            {
                stak.push(infix[i]);
            }
        }
        else
        {
            postfix.push_back(infix[i]);
        }

       
    }
    return postfix;
}
*/
int main()
{
    //std::string postfix = "ABC*DEF^/G*-H*+";
    //std::string postfix = "AB+C*D/";
    //std::string postfix = "AB+C*D/EF^+G/";
    //std::string postfix = "ABCD+EF+*G/+*H*";
    //std::string postfix = "ABCDEFGHIJKLMNOP+-+/+^*/*+-++++";
    //node* root = nullptr;
    //std::string infix;
    //infix = "(A+B)*C/D";
    //infix = "((A+B)*C/D+E^F)/G";
   // infix = "A*(B+(C+D)*(E+F)/G)*H";
   // infix = "A+(B*C-(D/E^F)*G)*H";
    //std::string expression = InfixToPostFix(infix);
    //std::cout << expression << std::endl;
   // root = CreateTree(expression);
    //DrawTree(root, 1);
    //Destroy(root);
    tree::node<int>* root = nullptr;
    root = new tree::node<int>(10);
    root->link.push_back(new tree::node<int>(20));
    root->link.push_back(new tree::node<int>(30));
    root->link.push_back(new tree::node<int>(40));
    root->link[0]->link.push_back(new tree::node<int>(20));
    root->link[0]->link.push_back(new tree::node<int>(30));
    root->link[0]->link.push_back(new tree::node<int>(40));
    root->link[0]->link[0]->link.push_back(new tree::node<int>(20));
    root->link[0]->link[0]->link.push_back(new tree::node<int>(30));
    root->link[0]->link[0]->link.push_back(new tree::node<int>(40));
    tree::DrawTree<int>(root,1);
    tree::Search<int>(root,7);
    tree::Destroy<int>(root);
    std::cin.get();
    return 0;
}

