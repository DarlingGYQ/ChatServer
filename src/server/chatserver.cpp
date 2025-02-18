#include"chatserver.hpp"
#include"json.hpp"
#include"chatservice.hpp"

#include<string>
using namespace std;
using namespace placeholders;
using json = nlohmann::json;

//初始化聊天服务器对象
ChatServer::ChatServer(EventLoop* loop,
            const InetAddress& listenAddr,
            const string& nameArg)
            :_server(loop,listenAddr,nameArg),
            _loop(loop)
{
    //注册连接回调
    _server.setConnectionCallback(std::bind(&ChatServer::onConnection,this,_1));

    //注册消息回调
    _server.setMessageCallback(std::bind(&ChatServer::onMessage,this,_1,_2,_3));

    //设置线程数量
    _server.setThreadNum(4);
}

//启动服务
void ChatServer::start()
{
    _server.start();
}

//上报连接创建关闭相关信息的回调函数
void ChatServer::onConnection(const TcpConnectionPtr& conn)
{
    //用户断开连接的情况
    if(!conn->connected())
    {
        ChatService::instance()->clientCloseExecption(conn);
        //释放sockfd资源
        conn->shutdown();
    }
}

//上报读写时间相关信息的回调函数
void ChatServer::onMessage(const TcpConnectionPtr& conn,
                            Buffer* buffer,
                            Timestamp time)
{
    //把Buffer里面存着的放到字符串里面去
    string buf=buffer->retrieveAllAsString();
    //数据的反序列化
    json js=json::parse(buf);

    //通过js["msgid"]绑定一个回调函数，获得一个业务处理器handler
    //只要解析出来msgid就可以回调对应的函数
    //要达到的目的：完全解耦网络模块的代码和业务模块的代码
    auto msgHandler=ChatService::instance()->getHandler(js["msgid"].get<int>());
    //回调消息绑定好的事件处理器，来执行相应的业务处理
    msgHandler(conn,js,time);
}
