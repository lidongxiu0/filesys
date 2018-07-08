#include <iostream>
#include "filesys.h"
using namespace std;
char cur_dir[20]= ROOTNAME;
struct dir dirn[1024];
struct inode i_node[1024];
struct Username uname[8];
struct block memory[memorysize];
struct Super_Block super_block;
struct file sys_openfile[OSopenfile];
int physic[100];    //文件地址缓冲区
int login;


int main() {
    char test[20] = "test";
    char test2[20] = "test2";
    char test3[20] = "test3";
    cout << "Hello, World!" << endl;
    initialize();
    uname[1] = {1,"user",0,10};
    //showfolder(cur_dir/*临时当前目录名*/)
    login = 1;
    cout << 1 << endl;
    create(test, 4, 1, FOLDER, 0);
    cout << 2 << endl;
    showfolder(cur_dir/*临时当前目录名*/);
    cout << 3 << endl;
    openfolder(test);
    cout << 4 << endl;
    create(test2, 4, 1, FOLDER, 0);
    //showfolder(cur_dir);
    cout << 5 << endl;
    openfolder(test2);
    cout << 6 << endl;
    create(test3, 2, 1, DOCUMENT, 0);
    showfolder(cur_dir);
    cout<<"?"<<endl;
    display(test3);
    cout<<"！"<<endl;
    delete_file(test3,1,1);
    cout << 7 << endl;
    display(test3);
    re_r_dir();
    showfolder(cur_dir);
    //format();
    return 0;
}