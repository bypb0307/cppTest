/*
 * @Author: chenq
 * @Date: 2021-05-04 23:21:06
 * @LastEditTime: 2021-05-04 23:24:19
 * @Descripttion: C++调用Python中的函数，无参数无返回值
 */
#include <iostream>
#include "python3.9/Python.h"
using namespace std;

int main()
{
    Py_Initialize();  //初始化Python环境
    if (!Py_IsInitialized())
    {
        cout << "Py_Initialize error" << endl;
        return -1;
    }
    PyRun_SimpleString("import sys");  //设置Python路径
    PyRun_SimpleString("sys.path.append('./')");

    PyObject *pModule = PyImport_ImportModule("hello"); //加载python模块 Python文件名 hello.py
    if (pModule == nullptr)
    {
        cout << "pModule is nullptr" << endl;
        return -1;
    }
    PyObject *pFunc = PyObject_GetAttrString(pModule, "hellofunc");  //加载对应的函数
    if (pFunc == nullptr)
    {
        cout << "pFunc is nullptr" << endl;
        return -1;
    }
    cout<<"C++ main call py func start"<<endl;
    PyObject *pRet = PyObject_CallNoArgs(pFunc);  //调用函数
    cout<<"C++ main call py func end"<<endl;
    if(pRet == nullptr)
    {
        cout << "pRet is nullptr" << endl;
        return -1;
    }
    Py_Finalize();

    return 0;
}