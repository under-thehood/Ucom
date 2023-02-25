#ifndef _CM_TREE_HPP
#define _CM_TREE_HPP
#include<cstdint>
#include <algorithm>
#include <queue>
#include <bits/stdc++.h>
#include <unordered_map>
// struct node
// {
//  uint8_t data;
//  uint32_t frequency;

//  struct node* left,*right;   
// };

// struct node* createNode(uint8_t data){
//     struct node* tmpnode=new node{data,1,nullptr,nullptr};
//     return tmpnode;
// }
struct node
{
    uint8_t _data;
    size_t _freq;

    struct node *right;
    struct node *left;
};

bool cmp(std::pair<uint8_t, size_t> &a,
         std::pair<uint8_t, size_t> &b)
{
    return a.second < b.second;
}

std::vector<node *> getFrequency(std::string &data)
{
    std::unordered_map<uint8_t, size_t> dict;
    std::vector<node *> Node;

    for (auto &&i : data)
    {
        if (dict.count(i) == 0)
        {
            dict[i] = 1;
        }
        else
        {
            dict[i] = dict[i] + 1;
        }
    }

    std::vector<std::pair<uint8_t, size_t>> freqPair;

    // Copy key-value pair from Map
    // to vector of pairs
    for (auto &it : dict)
    {
        freqPair.push_back(it);
    }

    // Sort using comparator function
    std::sort(freqPair.begin(), freqPair.end(), cmp);

    // Print the sorted value
    for (auto &it : freqPair)
    {

        Node.push_back(new node{it.first, it.second, nullptr, nullptr});
        std::cout << it.first << ": "
                  << it.second << std::endl;
    }
    return Node;
}

void printCodes(node *root, std::string str, std::unordered_map<uint8_t, std::string> &codes)
{

    if (!root)
        return;

    if (root->_data != '$' && (root->left == nullptr && root->right == nullptr))
    {
        // std::cout << root->_data << ": " << str << "\n";
        codes[root->_data] = str;
    }

    printCodes(root->left, str + "0", codes);
    printCodes(root->right, str + "1", codes);
}

// std::map<uint8_t,std::string> getCodes(node* root){
//     std::map<uint8_t,std::string> codes;

// }

node *buildTheTree(std::vector<node *> &freqData)
{

    auto comp = [](node *a, node *b)
    {
        return (a->_freq) > (b->_freq);
    };

    std::priority_queue<node *, std::vector<node *>, decltype(comp)> q(comp);
    node *first, *second, *root;
    for (auto i : freqData)
    {
        q.push(i);
    }
    while (q.size() != 0)
    {
        first = q.top();
        q.pop();
        second = q.top();
        q.pop();
        root = new node{'$', first->_freq + second->_freq, first, second};
        if (q.empty())
            break;
        q.push(root);
    }
    std::cout << "Tree is built\n";
    return root;
}

#endif