/*
 *
 *
 * 在socket之上完成加解密

*/



#include <iostream>

#include "CSocketProtcol.h"
#include "CSckFactoryImp1.h"
#include "CSckFactoryImp2.h"
#include "string.h"
#include "stdio.h"
#include "CEncDesProtocol.h"
#include "HwEncDec.h"

//面向抽象类 编程框架

using namespace std;

int SckSendAndRec(CSocketProtocol *sp,unsigned char *in,int inlen,unsigned char *out,int *outlen ){

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

//发送的时候加解密

int SckSendAndRec_EncDec(CSocketProtocol *sp,CEncDesProtocol *ed ,unsigned char *in,int inlen,unsigned char *out,int *outlen ){

    int ret = 0;

    unsigned char data[4096];

    int datalen = 0;

    ret = sp->cltSocketInit();

    if(ret !=0){

        goto End;
    }

    ret = ed->EncData(in,inlen,data,&datalen);

    if(ret !=0){

        goto End;
    }
    //data明文。

    ret = sp->cltSocketSend(data,datalen);//发送数据之前对数据进行加密。

    if(ret != 0){

        goto End;

    }


    ret = sp->cltSocketRev(data,&datalen);//收到的数据是密文，需要解密。

    if(ret != 0){

        goto End;

    }

    ret = ed->DecData(data,datalen,out,outlen);
    if(ret != 0){

        goto End;

    }
    End:

    ret = sp->cltSocketDestory();

    return 0;


}

//写一个框架

int main()
{

   int ret  = 0;

   unsigned char in[4096];

   int inlen ;

   unsigned char out[4096];

   int outlen = 0;

   strcpy((char *)in,"aabbbbccaaaaaaaaaaaaaaaa");

   inlen = 9;


   CSocketProtocol *sp = NULL;
   CEncDesProtocol *ed = NULL;

  // sp = new CSckFactoryImp1;
         sp = new CSckFactoryImp2;
         ed = new  HwEncDec;

  ret =  SckSendAndRec_EncDec(sp,ed,in,inlen,out,&outlen);

  if(ret != 0){

    printf("func SckSendAndRec is err %d\n",ret);

    return ret;

  }

    delete sp;


  return ret;
}

