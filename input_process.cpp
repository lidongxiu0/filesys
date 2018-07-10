//
// Created by lidongxiu on 2018/7/8.
//

#include "filesys.h"

int input_process(char str[])
{
    int i, j = 0, i_node_num, p;
    int size, limit;
    char temp[20], com[50];
    struct command temp2[30];
    string cur;
    while (1)
    {
        j = 0;         //必须重新给恢复0否则出错
        strcpy(temp, cur_dir);
        while (strcmp(temp, "filesystem") != 0)
        {
            for (i = 0; i<640; i++)
            {
                i_node_num = dirn[i].i_num;
                if (strcmp(temp, dirn[i].f_name) == 0 && (i_node[i_node_num].i_mode == FOLDER))
                {
                    strcpy(temp2[j].com, temp);
                    j++;
                    strcpy(temp, dirn[i].f_dname);
                }
            }
        }

        cur = cur_dir;
        /*
        path.push(cur);
        for(i = 0;i < 3;i++)
        {
            if(strcmp(cur_dir,dirn[i].f_name) == 0)
            {
                cur = dirn[i].f_dname;
                path.push(cur);
            }
        }
        for(i = 0;i < path.size();i++)
        {
            //cout << path.top() << "\\";
            path.pop();
        }
         */
        //cout << ">";

        strcpy(com,str);   //输入命令并且查找命令的相关操作
        for (i = 0; i < cmdnum; i++)
        {
            if (strcmp(com, cmd[i].com) == 0)
            {
                p = i;
                break;
            }
        }
        if (i == 18)
        {
            p = -1; //随便的一个值
        }
        switch (p)
        {
            case 0:
                initialize();       //初始化
                uname[0] = {0,"user",0,10};
                save_disk();
                return 1;
            case 1:
                //注册用户
                return 1;
            case 2:
                help();     //查看帮助
                return 1;
            case 3:
                display_memory();      //查看系统信息
                return 1;
            case 4:
                showfolder(cur_dir);      //显示当前目录下的文件
                return 1;
            case 5:  //改变路径
                cin >> temp;
                if (strcmp(temp, "..") == 0)
                {
                    re_p_dir();
                }
                else if (strcmp(temp, "...") == 0)
                {
                    re_r_dir();
                }
                else
                {
                    openfolder(temp);
                }
                return 1;
            case 6:
                cin >> temp;     //创建文件
                cin >> size;
                cin >> limit;
                create(temp, size, uname[login].u_id, DOCUMENT, limit);
                return 1;
            case 7:
                cin >> temp;    //读文件
                read(temp);
                return 1;
            case 8:
                cin >> temp;    //写文件
                char in[50];
                cin >> in;
                write(temp, in);
                return 1;
            case 9:
                cin >> temp;       //打开文件
                openfile(temp);
                return 1;
            case 10:
                cin >> temp;      //关闭文件
                closefile(temp);
                return 1;
            case 11:
                cin >> temp;   //创建文件夹
                create(temp, 4, uname[login].u_id, FOLDER, 0);
                return 1;
            case 12:
                cin >> temp;     //删除文件夹
                delete_file(temp, FOLDER, uname[login].u_id);
                return 1;
            case 13:
                save_disk();
                return 0;  //退出
            case 14:
                //登出
                return 0;
            case 15:
                cin >> temp;  //删除文件
                delete_file(temp, DOCUMENT, uname[login].u_id);
                return 1;
            default:printf("SORRY,没有这个命令\n");
                return 1;
        }
    }

    return 1;
}

void help()
{
    cout << "****格式化———————————format" << endl;
    cout << "****注册用户——————————reg" << endl;
    cout << "****帮助————————————help" << endl;
    cout << "****查看磁盘使用情况——————du" << endl;
    cout << "****显示当前文件夹———————ls" << endl;
    cout << "****打开文件夹—————————cd [目录名]" << endl;
    cout << "****返回根目录—————————cd ..." << endl;
    cout << "****返回上级目录————————cd .." << endl;
    cout << "****创建文件——————————touch [文件名] [文件大小] [读写权限]" << endl;
    cout << "****读取文件——————————read [文件名]" << endl;
    cout << "****写入文件——————————write [文件名] [写入内容]" << endl;
    cout << "****打开文件——————————open [文件名]" << endl;
    cout << "****关闭文件——————————close [文件名]" << endl;
    cout << "****创建文件夹—————————mkdir [文件夹]" << endl;
    cout << "****删除文件夹—————————rmdir [文件夹]" << endl;
    cout << "****删除文件——————————delete [文件名]" << endl;
    cout << "****退出————————————exit" << endl;
    cout << "****登出————————————quit" << endl;
}