#include <stdio.h>
#include <sqlist3.h>
#include <string.h>
#define DATABASE "student.db"

static int callback(void*para,int f_num,char **f_value,char **f_name)
{
 int i = -1,j = -1;
 printf("para :%s\n",(char*)para);
 for(j = 0;j < f_num;j++) 
 printf("%-15s",f_name[j]);
 putchar(10);

 for(i = 0;i < f_num;i++) {
 
 if(!strncasecmp((char*)para,f_value[2],3))
	 printf("%-15s",f_value[i]);
 }
 putchar(10);
 return 0;
 }
 
 int main(int argc,char **argv)
{
 sqlist3* db = NULL;
 char *errmsg = NULL;
 if(sqlist3_open(DATABASE,&db) != SQLITE_OK ){
 fprintf(stderr,"open %s\n",sqlist3_errmsg(db));
 return -1;
 } else {
	 printf("数据库打开成功\n");
 }
 char * create_table = "create table if not exists stu(id int,name char,sex char,score int)";
if (sqlist3_exec(db,create_table,NULL,NULL,&errmsg)!=SQLITE_OK) {
 fprintf(stderr,"操作出错: %s\n",errmsg);
 sqlist3_close(db);
 return -2;
} else {
puts("创建或打开成功");
}
 
//插入一条数据


}

