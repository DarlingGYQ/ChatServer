#include"friendmodel.hpp"
#include"db.h"

//添加好友关系
void FriendModel::insert(int userid,int frinedid)
{
    //1.组装sql语句
    char sql[1024]={0};
    sprintf(sql,"insert into friend values(%d,%d)",userid,frinedid);

    MySQL mysql;
    if(mysql.connect())
    {
        mysql.update(sql);
    }
}

//返回用户好友列表 每次下线更新，每次上线返回给用户
vector<User> FriendModel::query(int userid)
{
    //根据用户号码查询用户信息
    //1.组装sql语句
    char sql[1024]={0};
    sprintf(sql,"select a.id,a.name,a.state from user a inner join friend b on b.friendid=a.id where b.userid = %d",userid);

    vector<User> vec;
    MySQL mysql;
    //建立连接
    if(mysql.connect())
    {
        //获取结果
        MYSQL_RES *res=mysql.query(sql);
        if(res!=nullptr)
        {
            //把所有的离线消息放入vec中返回
            MYSQL_ROW row;
            while((row=mysql_fetch_row(res))!=nullptr)
            {
                User user;
                user.setId(atoi(row[0]));
                user.setName(row[1]);
                user.setState(row[2]);
                vec.push_back(user);
            }
            //释放资源
            mysql_free_result(res);
            return vec;
        }
    }
    //没查询到结果
    return vec;
}