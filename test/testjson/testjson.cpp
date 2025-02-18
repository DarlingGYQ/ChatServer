#include"json.hpp"
using json = nlohmann::json;

#include<iostream>
#include<vector>
#include<map>
#include<string>

using namespace std;

//json序列化示例1
string func1()
{
    json js;
    js["msg_type"] = 2;
    js["from"] = "zhang san";
    js["to"] = "li si";
    js["msg"] = "hello,what are you doing now?";

    //cout<<js<<endl;
    //json转字符串操作
    string sendBuf=js.dump();
    //cout<<sendBuf<<endl;
    return sendBuf;
}

//序列化示例2
string func2()
{
    json js;
    // 添加数组
    js["id"] = { 1 , 2 , 3 , 4 , 5 };
    // 添加key-value
    js["name"] = "zhang san";
    // 添加对象 表示json存储的本身就是json
    js["msg"]["zhang san"] = "hello world";
    js["msg"]["liu shuo"] = "hello china";
    // 上面等同于下面这句一次性添加数组对象
    js["msg"] = {{"zhang san", "hello world"}, {"liu shuo", "hello china"}};
    return js.dump();
}

string func3()
{
    json js;
    // 直接序列化一个vector容器
    vector<int> vec;
    vec.push_back( 1 );
    vec.push_back( 2 );
    vec.push_back( 5 );
    js["list"] = vec;
    // 直接序列化一个map容器
    map<int, string> m;
    m.insert({ 1 , "黄山"});
    m.insert({ 2 , "华山"});
    m.insert({ 3 , "泰山"});
    js["path"] = m;
    string sendBuf=js.dump();
    return sendBuf;
}

int main()
{
    string recvBuf1=func1();
    //数据的反序列化
    json jsbuf=json::parse(recvBuf1);
    cout<<jsbuf["msg_type"]<<endl;
    cout<<jsbuf["from"]<<endl;
    cout<<jsbuf["to"]<<endl;
    cout<<jsbuf["msg"]<<endl;

    string recvBuf2=func2();
    //数据的反序列化
    json jsbuf1=json::parse(recvBuf2);
    cout<<jsbuf1["id"]<<endl;
    //直接使用数组
    auto arr=jsbuf1["id"];
    cout<<arr[1]<<endl;

    cout<<jsbuf1["name"]<<endl;

    auto msgjs = jsbuf1["msg"];
    cout<<msgjs["zhang san"]<<endl;
    cout<<msgjs["liu shuo"]<<endl;

    string recvBuf3=func3();
    //数据的反序列化
    json jsbuf2=json::parse(recvBuf3);
    vector<int> vec=jsbuf2["list"];
    for(auto &c:vec)
        cout<<c<<" ";
    cout<<endl;

    map<int,string>mymap=jsbuf2["path"];
    for(auto &p:mymap)
        cout<<p.first<<" "<<p.second<<endl;

    return 0;
}