/*
 * @Author: chenq
 * @Date: 2021-05-04 23:26:13
 * @LastEditTime: 2021-05-04 23:30:43
 * @Descripttion: C++调用Python中的函数，有参数有返回值
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

    PyObject *pModule = PyImport_ImportModule("myadd"); //加载python模块 Python文件名 hello.py
    if (pModule == nullptr)
    {
        cout << "pModule is nullptr" << endl;
        return -1;
    }
    PyObject *pFunc = PyObject_GetAttrString(pModule, "addfunc"); //加载对应的函数
    if (pFunc == nullptr)
    {
        cout << "pFunc is nullptr" << endl;
        return -1;
    }
    int i = 10;
    int j = 20;
    string s = "10 + 20 = ";

    PyObject *pArgs = PyTuple_New(3);                 //创建参数，以元组的形式打包
    PyTuple_SetItem(pArgs, 0, Py_BuildValue("i", i)); //0表示序号，"i"表示int型变量, "s"表示字符串
    PyTuple_SetItem(pArgs, 1, Py_BuildValue("i", j));
    PyTuple_SetItem(pArgs, 2, Py_BuildValue("s", s.c_str()));

    cout<<"C++ call py func start"<<endl;
    PyObject *pRet = PyObject_CallObject(pFunc, pArgs); //调用函数
    cout<<"C++ call py func end"<<endl;
    if (pRet == nullptr)
    {
        cout << "pRet is nullptr" << endl;
        return -1;
    }

    int sum;
    const char *res;
    int ret = PyArg_ParseTuple(pRet, "is", &sum, &res); //a int and a string
    // int ret = PyArg_Parse(pRet, "i", &sum);  //a int
    // int ret = PyArg_Parse(pRet, "s", &res);  //a string
    cout << "ret: " << ret << endl;
    cout << "res len: " << strlen(res) << ", res: " << res << endl;
    cout << "sum: " << sum << endl;

    Py_Finalize();

    return 0;
}