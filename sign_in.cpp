//
// Created by 王兴钰 on 2018/7/8.
//

#include "filesys.h"


void sign_in()
{
    int i =0;
    string tempusername;
    cout<<"登陆"<<endl;
    cout << "请输入用户名："<<endl;
    cin >> tempusername;
    for(i=0;i<8;i++)
    {
        uname[i].u_id = i;
        strcpy(uname[i].u_name,username[i].c_str());
        pwd[i].p_password = userpassword[i];
        uname[i].u_id = pwd[i].p_id;
        if(tempusername == uname[i].u_name)
        {
            cout<<"HELLO!!!   "<<uname[i].u_name<<"   请输入密码"<<endl;
            cout<<"密码：";
            string temppassword;
            cin >> temppassword;
            if(temppassword == pwd[i].p_password)
            {
                cout<<"成功登陆"<<endl;
                break;
            }
            else
            {
                cout<<"请重新输入"<<endl;
                cin >> temppassword;
                continue;
            }
        }
        else
        {
            cout<<"该用户不存在请重新输入"<<endl;
            sign_in();
            break;
        }
    }



}