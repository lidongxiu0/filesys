//
// Created by 吴佳益 on 2018/7/9.
//

//存文件   超级块*50+i节点*1024+目录项*1024+磁盘块*1024
//读文件   超级块*50+i节点*1024+目录项*1024+磁盘块*1024
#include <string>
#include "filesys.h"

void load_disk()
{
    int i = 0, j = 0;
    ifstream infile("//Users/wujiayi/Desktop/filesys.txt", ios::in);
    //cout<<"infile:"<<infile.is_open()<<endl;
    if(!infile.is_open()) //测试文件是否打开
    {
        cerr << "open error" << endl;
        return;
    }
    else
    {
        //超级块
        infile >> super_block.sbfree;
        for(i = 0;i < 50;i++)
            infile >> super_block.free_block[i];
        //cout<<"fuck infile:";
        //for(i = 0;i < 50;i++)
        //   cout<<super_block.free_block[i]<<" ";
        //cout<<endl;

        //i节点
        for(i = 0;i<1024;i++)
        {
            //开始
            infile >> i_node[i].i_mode>>i_node[i].i_size;
            //物理块号
            for(j = 0;j < NDDR;j++)
            {
                infile >> i_node[i].i_address[j];
            }
            //物理块号结束
            infile >> i_node[i].i_limit >> i_node[i].i_Uid>>i_node[i].i_lenth
                   >>i_node[i].i_count >>i_node[i].i_count;
        }
        /*
        for(i = 0;i<10;i++)
        {
            //开始
            cout <<"i节点开始"<<i<<": ";
            cout << i_node[i].i_mode << i_node[i].i_size;
            //物理块号
            for(j = 0;j < 10;j++)
            {
                cout << i_node[i].i_address[j];
            }
            //物理块号结束
            cout <<"物理块结束"<<"!"<<" ";
            cout << i_node[i].i_limit << i_node[i].i_Uid<<i_node[i].i_lenth
                   <<i_node[i].i_count <<i_node[i].i_count<<endl;
        }
         */

        //目录项
        for(i = 0;i < 1024;i++)
        {
            infile >> dirn[i].f_name >> dirn[i].i_num >> dirn[i].f_dname;
        }

        //盘块
        for(i = 0;i < memorysize;i++)
        {
            infile >> memory[i].bfree ;
            for(j=0;j<50;j++)
            {
                infile >> memory[i].bfree_address[j];
            }
            infile >> memory[i].flag >> memory[i].content;
        }
    }

    /*
    while(!infile.eof())    //读入数据
    {
        infile >> count;
    }
     */
    infile.close();
}

void save_disk()
{
    int i = 0,j = 0;
    ofstream outfile("/Users/wujiayi/Desktop/filesys.txt",ios::out);
    cout << "save_disk" <<endl;
    //cout << outfile.is_open() <<"@ "<<super_block.sbfree<< endl;
    if(outfile.is_open())
    {
        //超级块
        outfile << super_block.sbfree <<" ";
        for(i = 0;i < 50;i++)
        {
            outfile << super_block.free_block[i] <<" ";
        }
        outfile<<endl;

        //i节点
        for(i = 0;i < 1024;i++)
        {
            //outfile <<"开始: ";
            outfile << i_node[i].i_mode <<" "<<i_node[i].i_size<<" ";
            //outfile << "物理块号: ";
            for(j = 0;j < NDDR;j++)
            {
                outfile << i_node[i].i_address[j] << " ";
            }
            //outfile << "物理块号结束 ";
            outfile << i_node[i].i_limit << " " <<i_node[i].i_Uid << " " <<i_node[i].i_lenth
                    << " " <<i_node[i].i_count << " " <<i_node[i].i_count<< endl;
        }

        //目录项
        for(i = 0;i < 1024;i++)
        {
            outfile << dirn[i].f_name <<" "<<dirn[i].i_num<<" "<<dirn[i].f_dname<<endl;
        }

        //盘块
        for(i = 0;i < memorysize;i++)
        {
            //outfile << i <<" @ ";
            outfile << memory[i].bfree <<" ";
            for(j=0;j<50;j++)
            {
                outfile << memory[i].bfree_address[j]<< " ";
            }
            outfile << memory[i].flag<<" ";
            if(strcmp(memory[i].content,"\0")==0)
            {
                outfile<<"@";
            }
            outfile<<memory[i].content<<endl;
        }

        outfile.close();
    }
    return;
}

void load_user()
{
    int i = 0, j = 0;
    ifstream inuserfile("user.txt", ios::in);
    //cout<<"infile:"<<inuserfile.is_open()<<endl;
    if(!inuserfile.is_open()) //测试文件是否打开
    {
        cerr << "open user file error" << endl;
        return;
    }
    else
    {
        for(i = 0;i < 8;i++)
        {
            inuserfile >> uname[i].u_id >> uname[i].u_name >>pwd[uname[i].u_id].p_password;
        }
    }
}

void save_user()
{
    int i = 0,j = 0;
    ofstream outuserfile("/Users/wujiayi/Desktop/user.txt",ios::out);
    for(i = 0;i < 8;i++)
    {
        outuserfile<<uname[i].u_id <<" ";
        if(strcmp(uname[i].u_name," ")==0)
        {
            outuserfile<<"@";
        }
        outuserfile<<uname[i].u_name<<" ";
        if(pwd[uname[i].u_id].p_password == "\0")
        {
            outuserfile<<"@";
        }
            outuserfile<<pwd[uname[i].u_id].p_password<<endl;
    }
}