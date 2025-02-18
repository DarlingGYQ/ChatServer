#ifndef FRIENDMODEL_H
#define FRIENDMODEL_H

#include<vector>
#include"user.hpp"
using namespace std;

//维护好友信息的操作接口方法
class FriendModel
{
public:
    //添加好友关系
    void insert(int userid,int frinedid);

    //返回用户好友列表 每次下线更新，每次上线返回给用户
    vector<User> query(int userid);
};  

#endif