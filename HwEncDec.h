#pragma once

#include<iostream>

#include"CEncDesProtocol.h"

class HwEncDec : public CEncDesProtocol
{
public:
    int EncData(unsigned char *plain,int plainlen,unsigned char *cryptdata,int *cryptlen);
    //解密
   int DecData(unsigned char *cryptdata,int cryptlen,unsigned char *plain,int *plainlen);

};
