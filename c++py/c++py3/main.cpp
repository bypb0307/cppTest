/*
 * @Author: chenq
 * @Date: 2021-05-04 23:33:29
 * @LastEditTime: 2021-05-05 00:18:45
 * @Descripttion: C++调用Python类中的函数，有参构造实例
 */
#include <iostream>
#include "python3.9/Python.h"
using namespace std;

int main()
{
    Py_Initialize(); //初始化Python环境
    if (!Py_IsInitialized())
    {
        cout << "Py_Initialize error" << endl;
        return -1;
    }
    PyRun_SimpleString("import sys"); //设置Python路径
    PyRun_SimpleString("sys.path.append('./')");

    PyObject *pModule = PyImport_ImportModule("mymath"); //加载python模块 Python文件名 hello.py
    if (pModule == nullptr)
    {
        cout << "pModule is nullptr" << endl;
        return -1;
    }

    PyObject *pDict = PyModule_GetDict(pModule); //模块的字典列表
    if (!pDict)
    {
        cout << "pDict is nullptr" << endl;
        return -1;
    }

    PyObject *pClassMyMath = PyDict_GetItemString(pDict, "MyMath");
    if (!pClassMyMath)
    {
        cout << "pClassMyMath is nullptr" << endl;
        return -1;
    }

    PyObject *pConstruct = PyInstanceMethod_New(pClassMyMath); //得到构造函数
    if (!pConstruct)
    {
        cout << "pConstruct is nullptr" << endl;
        return -1;
    }
    
    PyObject *pArgs = PyTuple_New(2);                 //创建参数，以元组的形式打包
    PyTuple_SetItem(pArgs, 0, Py_BuildValue("i", 10)); //0表示序号，"i"表示int型变量, "s"表示字符串
    PyTuple_SetItem(pArgs, 1, Py_BuildValue("i", 20));

    // PyObject *pInstanceMyMath = PyObject_CallObject(pConstruct, nullptr);  //无参构造实例
    PyObject *pInstanceMyMath = PyObject_CallObject(pConstruct, pArgs);  //有参构造实例
    if (!pInstanceMyMath)
    {
        cout << "pInstanceMyMath is nullptr" << endl;
        return -1;
    }

    int i = 10;
    int j = 5;
    cout << "C++ call py func start" << endl;
    PyObject *pRet = PyObject_CallMethod(pInstanceMyMath, "myaddtion", "ii", i, j);
    cout << "C++ call py func end" << endl;
    if (pRet == nullptr)
    {
        cout << "pRet is nullptr" << endl;
        return -1;
    }

    int sum = 0;
    int ret = PyArg_Parse(pRet, "i", &sum); //a int
    cout << "ret: " << ret << endl;
    cout << "sum: " << sum << endl;

    Py_Finalize();

    return 0;
}