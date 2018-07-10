//
// Created by 王兴钰 on 2018/7/8.
//

#include "filesys.h"

//登录
void sign_in()
{
    int i = 0;
    string tempusername;
    //cout << "登陆" << endl;
    /*
    for(int i = 0;i<8;i++){
        cout << "yonghuqun:" << uname[i].u_name<<endl;
    }
     */
    cout << "请输入用户名：";
    cin >> tempusername;
    for (i = 0; i<8; i++)
    {
        /*uname[i].u_id = i;
        strcpy(uname[i].u_name, username[i].c_str());
        pwd[i].p_password = userpassword[i];
        uname[i]9.u_id = pwd[i].p_id;*/
        if (cmp(uname[i].u_name, tempusername) == 1)
        {
            //cout << "HELLO!!!   " << uname[i].u_name << "   请输入密码" << endl;
            cout << "密码：";
            string temppassword;
            cin >> temppassword;
            if (temppassword == pwd[i].p_password)
            {
                cout << "成功登陆" << endl;

                login = uname[i].u_id;
                break;
            }
            else
            {
                cout << "请重新输入" << endl;
                cin >> temppassword;
                continue;
            }

        }
            //for (int j = 0; j < 20; j++)
            //{
            //	if (uname[i].u_name[j] == tempusername[j])
            //	{
            //	}
            //}

    }
    if(i == 8)
    {
        cout << "该用户不存在请重新输入" << endl;
        sign_in();
        //break;
    }


}

int cmp(char str1[], string str2)
{
    int i;
    for (i = 0; i < str2.size(); i++)
    {
        if (str1[i] == str2[i])
        {
            continue;
        }
        else
            return 0;
    }
    return 1;
}