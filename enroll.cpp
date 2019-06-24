//
// Created by 王兴钰 on 2018/7/8.
//

#include "filesys.h"

//注册
void enroll()
{
    int i = 0;
    string registername;
    string registerpassword;
    string registerpassword2;
    cout << "请输入要注册的用户名：" << endl;
    cin >> registername;
    for (i = 0; i < 8; i++)
    {
        if (registername == username[i]) {
            cout << "已存在此用户，注册失败" << endl;
            enroll();
            return;
        }
    }

    if (username[7] != "w")
    {
        cout << "注册用户已达上限，请滚去登陆" << endl;
        sign_in();
    }

    for (i = 0; i < 8; i++) {
        if (username[i] == "w") {
            cout << "请输入密码：" << endl;
            cin >> registerpassword;
            cout << "请重新确认密码：" << endl;
            cin >> registerpassword2;
            if (registerpassword == registerpassword2) {
                username[i] = registername;
                userpassword[i] = registerpassword;
                uname[i].u_id = i;
                strcpy(uname[i].u_name, username[i].c_str());
                pwd[i].p_password = userpassword[i];
                pwd[i].p_id = uname[i].u_id ;
                cout << "注册成功" << endl;
                break;
            }
            else if (registerpassword != registerpassword2)
            {
                cout << "两次输入密码不一致" << endl;
                enroll();
                break;
            }
        }
    }
}