#pragma once
#include<CSocketProtcol.h>

#include<iostream>

using namespace std;

class CSckFactoryImp2: public CSocketProtocol
{
public:
    //客户端初始化 获取上下

    virtual int cltSocketInit() ;


    //客户端发报文

    virtual   int cltSocketSend(unsigned char *buf/*in*/,int buflen/*in*/) ;

    //客户端收报文

    virtual   int cltSocketRev(unsigned char *buf/*in*/,int *buflen/*in out*/);

    //客户端释放资源


    virtual  int cltSocketDestory();

  private:

    unsigned char *p;

    int len;

};
