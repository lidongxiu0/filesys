#include <iostream>
#include <unistd.h>
#include "filesys.h"
using namespace std;

char cur_dir[20]= ROOTNAME;
struct command cmd[cmdnum];
struct dir dirn[1024];
struct inode i_node[1024];
struct Username uname[8];
struct block memory[memorysize];
struct Super_Block super_block;
struct file sys_openfile[OSopenfile];
struct Password pwd[8];
int physic[100];    //文件地址缓冲区
int login = 0;
stack<string> path;

string username[8]={"w","w","w","w","w","w","w","w"};
string userpassword[8];


int main()
{
    load_disk();
    //save_user();
    load_user();
    /*
    int shit;
    for(shit = 0;shit < 8;shit++)
    {
        cout<<uname[shit].u_id<<"#"<<uname[shit].u_name<<"#"<<pwd[uname[shit].u_id].p_password<<endl;
    }
     */
    cout << "欢迎使用本模拟文件系统" << endl;
    int over = 1, i = 0,j = 0;
    char putin[30] = "help";
    string cur;
    strcpy(cmd[0].com, "format");    //将各个命令存进命令表
    strcpy(cmd[1].com, "reg");
    strcpy(cmd[2].com, "help");
    strcpy(cmd[3].com, "du");
    strcpy(cmd[4].com, "ls");
    strcpy(cmd[5].com, "cd");
    strcpy(cmd[6].com, "touch");
    strcpy(cmd[7].com, "read");
    strcpy(cmd[8].com, "write");
    strcpy(cmd[9].com, "open");
    strcpy(cmd[10].com, "close");
    strcpy(cmd[11].com, "mkdir");
    strcpy(cmd[12].com, "rmdir");
    strcpy(cmd[13].com, "exit");
    strcpy(cmd[14].com, "quit");
    strcpy(cmd[15].com, "delete");

    cout << "是否需要注册用户（是Y）" << endl;
    char choose;
    cin >> choose;
    if((choose == 'y')||(choose == 'Y'))
    {
        enroll();
        save_user();
    }
    //cout << "请登录"<< endl;
    sign_in();
    cout<<endl;
    //system("cls");
    help();
    while (over)
    {
        cout << uname[login].u_name << ":";
        cout << cur_dir;
        cout << ">";
        cin >> putin;
        over = input_process(putin);//修改该函数内的字符识别方法
    }
    return 0;
}