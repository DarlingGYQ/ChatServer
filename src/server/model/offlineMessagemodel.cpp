#include"offlineMessagemodel.hpp"
#include"db.h"

//存储用户的离线消息
void OfflineMsgModel::insert(int userid,string msg)
{
    //1.组装sql语句
    char sql[1024]={0};
    sprintf(sql,"insert into offlineMessage values('%d','%s')",userid,msg.c_str());

    MySQL mysql;
    if(mysql.connect())
    {
        mysql.update(sql);
    }
}

//删除用户的离线消息
void OfflineMsgModel::remove(int userid)
{
    //1.组装sql语句
    char sql[1024]={0};
    sprintf(sql,"delete from offlineMessage where userid = %d",userid);

    MySQL mysql;
    if(mysql.connect())
    {
        mysql.update(sql);
    }
}

//查询用户的离线消息
vector<string> OfflineMsgModel::query(int userid)
{
    //根据用户号码查询用户信息
    //1.组装sql语句
    char sql[1024]={0};
    sprintf(sql,"select message from offlineMessage where userid = %d",userid);

    vector<string> vec;
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
                vec.push_back(row[0]);
            }
            //释放资源
            mysql_free_result(res);
            return vec;
        }
    }
    //没查询到结果
    return vec;
}
