###MouseTerminator
---
####1.功能说明
这个软件通过识别人脸部一些器官的动作，控制电脑实现地图的浏览。
####2.使用技术
使用[Qt][1]实现了软件的界面和模块的结构。

使用开源的人脸识别库[ENCARA2][2]实现视频中脸部器官的识别。

使用[OpenCV][3]实现摄像头相关的操作。

####3.运行环境
Qt+OpenCV

还要去[ENCARA2][4]的库导入到项目中（本程序中不包含该库）。
####4.该项目包含目录说明
`result`目录中的1.py文件实现绘制脸部某器官和图像帧数的折线图。具体相关的设置参照[《用Qt获取到的数据写如文本文件中，然后再用python读取绘制折线图》][5]这篇文章中的一些描述可以修改绘制所需要的图像。


  [1]: http://qt-project.org/
  [2]: http://new-mozart.dis.ulpgc.es/encara2
  [3]: http://opencv.org/
  [4]: http://new-mozart.dis.ulpgc.es/encara2/ENCARA2v2.11.zip
  [5]: http://blog.segmentfault.com/tairy/1190000000355738