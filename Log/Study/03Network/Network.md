# Linux网络编程

## 1 网络基础

### 1.1 协议

+ 一组规则，用来规定数据传输的格式

### 1.2 分层模型

+ OSI七层模型: 物, 数, 网, 传, 会, 表, 应

+ TCP/IP四层模型: (链路层、网络接口层)数据链路层, 网络层, 传输层, 应用层
    1. 应用层: **http**、ftp、smtp、telnet、dns、ssh
    2. 传输层: **TCP**、UDP
    3. 网络层: **IP**、ICMP、IGMP
    4. 链路层: **MAC**、ARP、RARP

+ 网络传输流程：
    1. 数据没有封装之前，是不能在网络中传递。

+ 以太网帧协议：
    1. ARP协议：根据 Ip 地址获取 mac 地址。
    2. 以太网帧协议：根据mac地址，完成数据包传输。

+ IP协议：
    1. 版本： IPv4、IPv6  -- 4位
    2. TTL： time to live 。 设置数据包在路由节点中的跳转上限。每经过一个路由节点，该值-1， 减为0的路由，有义务将该数据包丢弃

+ IP地址：可以在网络环境中，唯一标识一台主机。

+ 端口号：可以网络的一台主机上，唯一标识一个进程。

+ ip地址+端口号：可以在网络环境中，唯一标识一个进程。

+ UDP：
    1. 16位：源端口号, 2^16 = 65536  
    2. 16位：目的端口号

+ TCP协议：
    1. 16位：源端口号, 2^16 = 65536  
    2. 16位：目的端口号
    3. 32序号
    4. 32确认序号
    5. 6个标志位
    6. 16位窗口大小, 2^16 = 65536

+ c/s模型
    1. client-server
    2. 优点: 可缓存大量数据, 协议选择灵活, 速度快
    3. 缺点: 安全性低, 跨平台不方便, 开发工作量大

+ b/s模型
    1. browser-server
    2. 优点: 安全性高, 跨平台, 开发工作量小
    3. 缺点: 不能换成大量数据, 严格遵守http协议

## 2 Socket编程

### 2.1 网络套接字函数

+ 一个文件描述指向一个套接字(该套接字内部又内核借助两个缓冲区实现)

+ 在通信过程中, 套接字一定是成对出现的

### 2.2 网络字节序

+ 小端法(PC本地存储)
    1. 高位存在高地址, 低地址存放低字节
+ 大端法(网络存储)
    1. 高位存在低地址, 低地址存放高字节
+ htonl
    1. 将本地端字节序转换为网络字节序(主要是针对ip协议)
+ htons
    1. 将本地端字节序转换为网络字节序(主要是针对端口号port)
+ ntohl
    1. 将网络字节序转换为本地字节序(主要是针对ip协议)
+ ntohs
    1. 将网络字节序转换为本地字节序(主要是针对端口号port)

### 2.3 IP地址转换函数

+ int inet_pton(int af, const char *src, void*dst); // 本地字节序(string ip)转换为网络字节序
    1. af: AF_INET, AF_INET6
    2. src: ip地址字符串
    3. dst: ip地址结构体指针
    4. 返回值: 1成功, 0异常, -1失败

+ const char* inet_ntop(int af, const void*src, char*dst, socklen_t size); // 网络字节序转换为本地字节序(string ip)
    1. af: AF_INET, AF_INET6
    2. src: 网络字节序ip地址
    3. dst: 本地字节序(string ip)
    4. size: dst的长度
    5. 返回值: 成功dst, NULL失败

### 2.4 sockaddr数据结构

+ sockaddr地址结构

```C++
struct sockaddr_in addr;
addr.sin_family = AF_INET/AF_INET6;
addr.sin_port = htons(port); 
int dst;
addr.sin_addr.s_addr = inet_pton(AF_INET, "127.0.0.1", (void*)dst);
addr.sin_addr.s_addr = INADDR_ANY; // 取出系统中有效的任意ip地址, 默认二进制类型
bind(df, (struct sockaddr*)&addr, size());
```
