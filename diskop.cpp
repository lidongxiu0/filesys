//
// Created by 吴佳益 on 2018/7/9.
//

#include "filesys.h"

void load_disk()
{
    int count = 0;
    ifstream infile("filesys.txt", ios::in);

    if(!infile) //测试文件是否打开
    {
        cerr << "open error" << endl;
    }

    while(!infile.eof())    //读入数据
    {
        //infile >> memory[count] >> ;
    }
}

void save_disk()
{
    return;
}
