#pragma once
#include<vector>
#include<iostream>

namespace tree
{
    template<typename T>
    struct node
    {
        static int key_count;
        T data;
        std::vector<node<T>*> link;
        int key;
        node() :
            data(),
            link(),
            key(0)
        {
            node::key_count += 1;
            key = node::key_count;
        }
        node(T data) :
            data(data),
            link(),
            key(key)
        {
            node::key_count += 1;
            key = node::key_count;
        }
    };

    template<typename T>
    int node<T>::key_count = 0;

    template<typename T>
    void Destroy(node<T>* root)
    {
        if (root == nullptr)
        {
            return;
        }
        else
        {
            for (int i = 0; i < root->link.size(); i++)
            {
                Destroy(root->link[i]);
            }
        }
    }

    template<typename T>
    void Search(node<T>* root,int key)
    {
        if (root != nullptr)
        {
            if (root->key == key)
            {
               std::cout<< root->data << std::endl;
               
            }
            else
            {
                if (root->link.size() == 0)
                {

                }
                else
                {
                    for (int i = 0; i < root->link.size(); i++)
                    {
                        Search(root->link[i],key);
                    }
                }
            }
        } 
    }

    void LevelSpace(int level)
    {
        unsigned char drawchar = 179;
        for (int i = 0; i < level - 1; i++)
        {
            std::cout << drawchar << "  ";
        }
    }

  
    template<typename T>
    void DrawTree(node<T>* root, int level)
    {
        unsigned char drawchar[] = { 195,196,192 };

        if (root != nullptr)
        {
            std::cout << root->data << std::endl;
            if (root->link.size() == 0)
            {
                return;
            }
            else
            {
                for (int i = 0; i < root->link.size(); i++)
                {
                    if (root->link.size()-1 == i)
                    {
                        LevelSpace(level);
                        std::cout << drawchar[2];
                        std::cout << drawchar[1];
                        std::cout << drawchar[1];
                        DrawTree(root->link[i], level + 1);
                        continue;
                    }
                    LevelSpace(level);
                    std::cout << drawchar[0];
                    std::cout << drawchar[1];
                    std::cout << drawchar[1];
                    DrawTree(root->link[i], level + 1);
                }  
            }
        }
    }
}
