> 本文是一个新起点，从本文开始：<br>
> 1、按 RT-Thread AE 组专家建议“每次写文章之前写个背景介绍”，使文章更易懂。<br>
> 2、正式开始“软件架构训练计划”。


本文背景介绍
---
上一篇推文《RT-Thread pin 设备分析》收到反馈说“STM32 平台 RT-Thread 用 HAL 库有 pin 设备无法读取的 bug”，我就花了3分钟实验了一下，发现**不存在这样的bug**。（后来了解发现，反馈者没有用 CubeMX 配置 GPIO 为“INPUT模式”所致。）

有不少 RTT 的文档都涉及到了用 CubeMX 配置引脚。我通过推文的反馈发现不少使用者不清楚 RTT 和 CubeMX 深层关系。有些表层说法如下：

1、RTT 是 CubeMX 的一个组件；
2、RTT 是 Keil MDK 里的一个包；

其实这些说法都不能算错，但都只是“描述型”，**要想用得顺畅要了解更深入些**。

为了让初入门的人能顺利的了解更多，我做了这个“软件架构训练计划”，**本文就是这个计划的开始**。

复用一下 pin 设备的演示视频
---
> 目前为止，我每个演示都是 0 起点，我不知道这样是不是必要的。<br>
>希望大家能给我反馈（通过微信、微信群、github等各种方式，我期望听到你的声音。）

[RT-Thread pin 设备分析](https://www.bilibili.com/video/av57383624/)

下面开始训练，第一项内容
---
> 上面视频里用 CubeMX 配置 GPIO 输出点亮 LED。现在就展示我 3 分钟确认 RT-Thread 用 HAL 库没有 bug 的过程。

1、重整文件架构
> 这里的文件架构就与代码架构很相关，我为了使文件作用清晰同时兼容 CubeMX 文件结构，特意分了文件夹。

![](https://github.com/SuWeipeng/img/raw/master/12_RT-Thread/pin_demo_3.png)

2、用 RTT 的 pin 设备接口

![](https://github.com/SuWeipeng/img/raw/master/12_RT-Thread/pin_demo_4.png)

3、修改 entry.c 函数

![](https://github.com/SuWeipeng/img/raw/master/12_RT-Thread/pin_demo_5.png)

![](https://github.com/SuWeipeng/img/raw/master/12_RT-Thread/pin_demo_6.png)

![](https://github.com/SuWeipeng/img/raw/master/12_RT-Thread/pin_demo_7.png)

到这里就搞定了，编译、烧写、看现象，我验证是 OK 的。

第二项内容
---
> 我当初把 pin 设备加入到我的精简内核进行编译时的一个问题，也与架构有关。

![](https://github.com/SuWeipeng/img/raw/master/12_RT-Thread/pin_demo_1.png)

![](https://github.com/SuWeipeng/img/raw/master/12_RT-Thread/pin_demo_2.png)

分析下问题原因

![](https://github.com/SuWeipeng/img/raw/master/12_RT-Thread/pin_demo_8.png)

看下文件结构

![](https://github.com/SuWeipeng/img/raw/master/12_RT-Thread/pin_demo_10.png)

看下出错的文件结构

![](https://github.com/SuWeipeng/img/raw/master/12_RT-Thread/pin_demo_9.png)

首次训练结语
---
我是第一次做这样的训练，这篇推文我个人觉得有些生硬。

读者有什么好的建议加强互动、促进学习提高，欢迎各种形式反馈给我（微信、微信群、github issue 留言等不限形式）。

如何参与计划
---
1. 在 github 上 star 训练项目。
2. 扫码加入微信群（通过公众号加 Sugar 为好友，备注“参加训练”）

关注作者
---
欢迎扫码关注我的公众号`MultiMCU EDU`。
![](https://github.com/SuWeipeng/img/raw/master/gongzonghao.jpg)
### `提示：在公众号“关于我”页面可加作者微信好友。`


