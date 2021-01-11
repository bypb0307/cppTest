/*
 * @Author: chenq
 * @Date: 2020-11-19 10:41:00
 * @LastEditTime: 2020-11-19 23:20:00
 * @Descripttion: 
 */
#include <iostream>
#include <vector>
using namespace std;

template <class T>
struct SkipNode
{
    int key;    //
    T val;
    vector<SkipNode*> next;
    SkipNode(int k, T v, int level);
};

template <class T> SkipNode<T>::SkipNode(int k, T v, int level)
    :key(k),
     val(v)
{
    for(int i=0;i<level;i++)
    {
        next.push_back(nullptr);
    }
}


