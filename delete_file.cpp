//
// Created by 吴佳益 on 2018/7/8.
//

#include "filesys.h"

/*
 * 函数功能：删除文件
 * 输入：文件名,文件模式,用户ID
 * 输出：无
 * */
 void delete_file(char filename[],int mode,int u_id)
{
    int i = 0,j,k;
    for (i = 0; i < 1024; i++)
    {
        if (strcmp(filename, dirn[i].f_name) == 0 &&
                i_node[dirn[i].i_num].i_mode == mode &&
                strcmp(dirn[i].f_dname,cur_dir) == 0)
            //如果有文件名相同，模式相同，且上级目录名相同
        {
            if(i_node[dirn[i].i_num].i_limit == 0 ||
                    i_node[dirn[i].i_num].i_limit == 2) //具有修改权限
            {
                if(mode == DOCUMENT)    //如果是文件
                {
                    for(j = 0;j < i_node[dirn[i].i_num].i_size;j++)
                    {
                        for(k = 0;memory[i_node[dirn[i].i_num].i_address[j]].content[k]!='\0';k++)// 块内容清空
                        {
                            memory[i_node[dirn[i].i_num].i_address[j]].content[k] ='\0';
                        }
                    }
                    i_node[dirn[i].i_num].i_Uid = -1;
                    i_node[dirn[i].i_num].i_limit = -1;

                    for(k = 0;k < i_node[dirn[i].i_num].i_size;k++) //将相应地址送到缓冲区
                    {
                        physic[k] = i_node[dirn[i].i_num].i_address[k];
                    }
                    recycle(i_node[dirn[i].i_num].i_size); // 回收相应盘块

                    for(j = 0;j < 100;j++) //清空缓存区
                    {
                        physic[j] = -1;
                    }

                    //inode相关参数重置为初始值
                    i_node[dirn[i].i_num].i_size = -1;
                    i_node[dirn[i].i_num].i_mode = -1;
                    //目录项相关参数重置为初始值
                    strcpy(dirn[i].f_dname,"");
                    strcpy(dirn[i].f_name,"");
                    dirn[i].i_num = -1;
                }
                else if(mode == FOLDER)
                {
                    //TODO 删除文件夹
                }
            }
            else
                cout<<"无权删除"<<endl;
            break;
        }
    }
}