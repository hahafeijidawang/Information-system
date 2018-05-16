
/*

完成socket抽象类的集成测试。

*/
#include <iostream>

#include "CSocketProtcol.h"
#include "CSckFactoryImp1.h"
#include "CSckFactoryImp2.h"
#include "string.h"
#include "stdio.h"
//面向抽象类 编程框架

using namespace std;

int SckSendAndRec01(CSocketProtocol *sp,unsigned char *in,int inlen,unsigned char *out,int *outlen ){

    int ret = 0;

    ret = sp->cltSocketInit();

    if(ret !=0){

        goto End;
    }



    ret = sp->cltSocketSend(in,inlen);

    if(ret != 0){

        goto End;

    }

    ret = sp->cltSocketRev(out,outlen);

    if(ret != 0){

        goto End;

    }
    End:

    ret = sp->cltSocketDestory();

    return 0;


}

//写一个框架

int main011(){

   int ret  = 0;

   unsigned char in[4096];

   int inlen ;

   unsigned char out[4096];

   int outlen = 0;

   strcpy((char *)in,"aabbbbccaaaaaaaaaaaaaaaa");

   inlen = 9;


   CSocketProtocol *sp = NULL;

  // sp = new CSckFactoryImp1;
         sp = new CSckFactoryImp2;
  ret =  SckSendAndRec01(sp,in,inlen,out,&outlen);

  if(ret != 0){

    printf("func SckSendAndRec is err %d\n",ret);

    return ret;

  }

    delete sp;


  return ret;
}

