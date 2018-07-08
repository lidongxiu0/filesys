#include "filesys.h"

//关闭文件
void closefile(char filename[])
{
    int i, j, k, m;
    for (i = 0; i < 1024; i++)
    {
        if (strcmp(filename, dirn[i].f_name) == 0 &&
            i_node[dirn[i].i_num].i_mode == DOCUMENT &&
            (i_node[dirn[i].i_num].i_Uid == uname[login].u_id || uname[login].u_id == 0))//超级用户可打开所有文件
        {
            for (j = 0; j < OSopenfile; j++)
            {
                if (sys_openfile[j].f_inode == i_node[dirn[i].i_num]) //找到匹配的打开文件
                {
                    for (m = 0; m < uname[login].u_open; m++)
                    {
                        if (uname[login].u_ofile[m] == dirn[i].i_num)
                        {
                            int n;
                            for (n = m; n < 10; n++)
                            {
                                uname[login].u_ofile[n] = uname[login].u_ofile[n + 1];
                            }
                            uname[login].u_open--;
                        }
                    }
                    for (k = j; k < OSopenfile; k++)
                    {
                        sys_openfile[k] = sys_openfile[k + 1];  //在打开文件表中删除该文件信息
                    }
                    return;
                }
            }
            if (j >= OSopenfile)
            {
                cout << "该文件似乎未打开" << endl;
            }
            return;
        }
    }
    if (i >= 1024)
    {
        cout << "该文件不存在" << endl;
    }
    return;
}

//返回上级目录
void re_p_dir()
{
    int i;
    for (i = 0; i < 1024; i++)
    {
        //查询当前目录的上级目录名，修改当前目录为原目录的上级目录
        if (strcmp(cur_dir, dirn[i].f_name) == 0 && i_node[dirn[i].i_num].i_mode == FOLDER)
        {
            strcpy(cur_dir, dirn[i].f_dname);
        }
    }
}


//返回根目录
void re_r_dir()
{
    //TODO 返回根目录
    strcpy(cur_dir, ROOTNAME);
}