#pragma once

class CEncDesProtocol
{
public:
    CEncDesProtocol() {}
    //加密
    virtual ~CEncDesProtocol() {}
    virtual int EncData(unsigned char *plain,int plainlen,unsigned char *cryptdata,int *cryptlen) = 0;
    //解密
    virtual int DecData(unsigned char *cryptdata,int cryptlen,unsigned char *plain,int *plainlen) = 0;
};
