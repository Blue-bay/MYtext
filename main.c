#include<stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <string.h>

int main()
{
    int fd1,fd2;
    char buf[128];
    fd1=open("3.txt",O_RDWR|O_CREAT,0777);
    if(fd1==-1)
    {
       //printf("创建文件3失败");
       perror("创建文件3失败");
       return -1;
    }
    fd2=open("4.txt",O_RDWR|O_CREAT,0755);
    if(fd2==-1)
    {
        //  printf("创建文件4失败");
        perror("创建文件4失败");
          return -1;
    } 
   printf("fd1: %d fd: %d\n",fd1,fd2);
   write(fd1,"Hello World!",strlen("Hello World!"));//写数据
   /*文件偏移
   off_t lseek(int fd, off_t offset, int whence);
   offset//偏移位置
   whence//从哪开始偏移   SEEK_SET：文件起始位置   
   SEEK_CUR：当前光标位置 SEEK_END：文件末尾位置
   */
   lseek(fd1,0,SEEK_SET);
   memset(buf,0,sizeof(buf));//赋值
   read(fd1,buf,strlen("Hello World!"));//读数据
   printf("%s\n",buf);
    //lseek(fd1,SEEK_SET);

   // write(fd2,"Hello World!",strlen("Hello World!"));
   close(fd1);
   close(fd2);
 //  return 0;

 // 标准Io
   char buf2[64];
   memset(buf2,0,sizeof(buf));//赋值
   // read(0,buf2,sizeof(buf));//读数据 123456
    scanf("%s",buf2); //
   // getchar();//吸收掉空格
   // //gets(buf2);尽量不要有
   // fgets(buf,sizeof(buf2),stdin);//stdin 标准输入 
   
 //  write(1,buf2,sizeof(buf2));
   printf("%s",buf2);
    /*获取文件信息
    int f1,res;
    f1 =open ("3.txt",O_RDWR);
    struct stat statbuf;
    res= fstat(f1,&statbuf);
    if(res==0)
    {
       printf("%ld",statbuf.st_size);
    }
    return 0;*/
}