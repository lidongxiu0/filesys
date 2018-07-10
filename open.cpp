#include "filesys.h"

//打开文件
int openfile(char filename[])
{
    int i, i_node_num, k;
    int cur_open;
    for (i = 0; i < 1024; i++)
    {
        if (strcmp(filename, dirn[i].f_name) == 0 &&
            i_node[dirn[i].i_num].i_mode == DOCUMENT &&
            (i_node[dirn[i].i_num].i_Uid == uname[login].u_id || uname[login].u_id == 0)&&
            strcmp(dirn[i].f_dname, cur_dir) == 0)
        {
            for (k = 0; k < OSopenfile; k++)
            {
                if (sys_openfile[k].f_count == 0)
                {
                    cur_open = k;
                    break;
                }
                else
                {
                    cout << "系统打开文件已达上限" << endl;
                    return 0;
                }
            }
            if (uname[login].u_open < OFile)
            {

                uname[login].u_ofile[uname[login].u_open] = dirn[i].i_num;
                uname[login].u_open++;
                i_node_num = dirn[i].i_num;
                sys_openfile[cur_open].f_count = 1;
                sys_openfile[cur_open].f_inode = i_node_num;
                sys_openfile[cur_open].f_off = 0;
            }
            else
            {
                cout << "该用户可打开文件数已达上限" << endl;
            }
            i_node_num = dirn[i].i_num;
            break;
        }

        if (i >= 1024)
        {
            cout << "该文件不存在，请重新选择。" << endl;
            return 0;
        }
    }
    showfile(filename, i_node_num);
    return i_node_num;
}

//显示文件信息（不可单独使用）
void showfile(char filename[], int i_node_num)
{
    int j;
    char c[20];
    cout << "文件名\t文件类型\t文件大小\t读取权限\t修改时间\t上级目录\t用户" << endl;
    for (j = 0; j < 1024; j++)
    {
        if (strcmp(filename, dirn[j].f_name) == 0 && (i_node[i_node_num].i_mode == DOCUMENT))
        {
            cout << dirn[j].f_name;  //文件名
            cout << "\t文件";  //文件类型
            cout << "\t" << i_node[i_node_num].i_size;  //文件大小
            switch (i_node[i_node_num].i_limit)
            {
                case 0:cout << "\t可读可写";
                    break;
                case 1:cout << "\t可读不可写";
                    break;
                case 2:cout << "\t可写不可读";
                    break;
            }
            cout << "\t" << i_node[i_node_num].i_time;  //修改时间
            cout << "\t" << dirn[j].f_dname;  //上级目录

            cout << endl;
            //cout << "\t文件物理地址\t";
            //cout << i_node[i_node_num].i_address[0] << "---" << i_node[i_node_num].i_address[i_node[i_node_num]
            //      .i_size] << endl;
            break;
        }
    }
}

//显示文件夹信息（不可单独使用）
void showfolder(char foldername[])
{
    int i;
    //cout << login << endl;
    //cout << "用户：" << uname[login].u_name << endl;  //当前用户
    cout << "包含文件\t文件类型\t文件大小\t上级目录" << endl;
    for (i = 0; i < 1024; i++)
    {
        if (strcmp(foldername, dirn[i].f_dname) == 0 && i_node[dirn[i].i_num].i_Uid == uname[login].u_id)
        {
            cout << dirn[i].f_name;  //文件名
            switch (i_node[dirn[i].i_num].i_mode)
            {
                case FOLDER:cout << "\t文件夹"; break;
                case DOCUMENT:cout << "\t文件  "; break;
            }
            cout << "\t" << i_node[dirn[i].i_num].i_size;  //文件大小
            //cout << "\t" << i_node[dirn[i].i_num].i_time;  //修改时间
            cout << "\t\t" << dirn[i].f_dname;  //上级目录
            cout << endl;
        }
        else
        {
            // cout << "文件夹为空" << endl;
        }
    }
}

//打开文件夹
void openfolder(char foldername[])
{
    int i;
    for (i = 0; i < 1024; i++)
    {
        if (strcmp(foldername, dirn[i].f_name) == 0 &&
            i_node[dirn[i].i_num].i_mode == FOLDER &&
            (i_node[dirn[i].i_num].i_Uid == uname[login].u_id || uname[login].u_id == 0) &&
            strcmp(dirn[i].f_dname, cur_dir) == 0)
        {
            //设置当前目录名
            strcpy(cur_dir, dirn[i].f_name);

            cout << cur_dir << endl;
            //显示当前目录项
            showfolder(cur_dir);
            return;
        }
    }
    if (i >= 1024)
    {
        cout << "文件夹不存在或文件夹不属于该用户" << endl;
    }
}