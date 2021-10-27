# 

# 项目说明

本项目适用于游戏：《命运神界》

## 游戏版本
国际版：1.0.40

# JavaProject

## 项目内容

根据游戏安装包/assets/64/assets.db中的SQLite文件

将游戏obb资源文件中杂乱的文件进行重命名与移动，变为正常的资源排布。

## 使用方法
1. 请准备好java环境，项目使用jdk8编写

2. 运行命令

`java -jar mysj.jar "E:\sourcePath" "E:\dbPath"`

其中sourcePath代表待移动文件夹的路径，dbPath代表assets.db所在路径

3. 待处理源文件目录安排如下：

```
├──sourcesFolder

    └──release

        ├──00
        ├──0a
        ├──0b
        ├──...
```

# CPPProject

## 项目内容

逆向libcocos2dlua.so进行美术资源解密

## 使用方法

将
