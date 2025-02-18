# chatserver
# C++集群聊天服务器项目概述

基于C++11的可以工作在nginx tcp负载均衡环境中的集群聊天服务器和客户端

## 技术栈

Json序列化和反序列化

muduo网络库开发

nginx源码编译安装和环境部署

nginx的tcp负载均衡器配置

redis缓存服务器编程实践

基于发布-订阅的服务器中间件redis消息队列编程实践

MySQL数据库编程

CMake构建编译环境

Github托管项目

## 项目需求

1. 客户端新用户注册

2. 客户端用户登录

3. 添加好友和添加群组

4. 好友聊天

5. 群组聊天

6. 离线消息

7. nginx配置tcp负载均衡

8. 集群聊天系统支持客户端跨服务器通信

## 项目目标

1. 理解并实践服务器的网络I/O模块，业务模块，数据模块分层的设计思想

2. 理解并实践C++ muduo网络库的编程以及实现原理

3. 理解并实践Json的编程应用

4. 理解并实践nginx配置部署tcp负载均衡器的应用以及原理

5. 理解并实践服务器中间件的应用场景和基于发布-订阅的redis编程实践以及应用原理

6. 理解并实践CMake构建自动化编译环境

7. 理解并实践Github管理项目

## 开发环境

1. ubuntu linux环境

2. 安装Json开发库

3. 安装boost + muduo网络库开发环境

4. 安装redis环境

5. 安装mysql数据库环境

6. 安装nginx

7. 安装CMake环境

## 配置远程开发环境

windows+vscode配置远程linux开发环境

1. linux系统运行sshd服务

2. 在vscode上安装Remote Development插件，其依赖插件会自动安装

3. 配置远程linux主机的信息

4. 在vscode上开发远程连接linux

也可以访问以下地址进行学习，对于每部分有较为详细的解释
https://blog.csdn.net/m0_74795952/article/details/145707758?spm=1001.2014.3001.5501
