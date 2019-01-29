# Git 学习记录




## 1、问题记录

| 问题             | 解决方案                       | 备注                                                     |
| ---------------- | ------------------------------ | -------------------------------------------------------- |
| git log 中文乱码 | 给环境变量配置：LC_ALL=C.UTF-8 | https://blog.csdn.net/dxhua1996/article/details/81367069 |
| git log 后退出   | 按字母q可以退出                |                                                          |




## 2、命令总结
### 2.1 公共
| 命令                                        | 描述                                                         | 备注                                                |
| ------------------------------------------- | ------------------------------------------------------------ | --------------------------------------------------- |
| git init                                    | 初始化一个Git存储库                                          |                                                     |
| git status                                  | 查看Git目前的状态                                            |                                                     |
| git add file                                | 将文件或文件夹添加到暂存区                                   | [git add .] 添加所有文件到暂存区                    |
| git commit -m "备注"                        | 将暂存区的文件提交到存储库                                   | 如果提交的备注里面是（单引号+空格）还有莫名其妙问题 |
| git commit -am "备注"                       | 同git add . + git commit -m 同时执行                         |                                                     |
| git rm file                                 | 从暂存区中删除文件                                           |                                                     |
| git mv file1 file2                          | 将file1的文件名称修改为file2                                 |                                                     |
| gitk                                        | 查看图形界面                                                 |                                                     |
| git cat-file -p 1678ea91c88d                | 显示对象的内容                                               |                                                     |
| git cat-file -t 1678ea91c88d                | 显示对象的类型                                               | https://git-scm.com/docs/git-cat-file               |
| git reset HEAD                              | 将暂存区所有的变更都撤销（就是恢复暂存区和HEAD一致）         |                                                     |
| git reset HEAD -- index.html                | 将暂存区中index.html的变更撤销                               |                                                     |
| git checkout -- index.html                  | 将工作区中的文件index.html修改撤销（就是恢复工作区同暂存区一致） |                                                     |
| git stash                                   | 将工作区的修改存放起来                                       |                                                     |
| git stash list                              | 查看之前存放的列表                                           |                                                     |
| git stash apply                             | 恢复将之前存放的修改到工作区                                 | 该操作会保留stash                                   |
| git stash pop                               | 恢复将之前存放的修改到工作区                                 | 该操作不会保留stash                                 |
| git stash clear                             | 清空stash                                                    |                                                     |
| git stash drop stash@{0}                    | 删除第一个                                                   |                                                     |
| git config --local --add user.name 'Oliver' | 设置userName                                                 |                                                     |
| git config --local -l                       | 查看config 中的配置                                          |                                                     |

### 2.2 diff 相关
| 命令                    | 描述                                       | 备注 |
| ----------------------- | ------------------------------------------ | ---- |
| git diff 123123  123123 | 比较两次提交的不同                         |      |
| git fiff HEAD HEAD~2    | 比较HEAD对应的提交与HEAD的父亲的父亲的不同 |      |
| git diff --cached       | 比较暂存区与HEAD的不同                     |      |
| git diff                | 工作区与暂存区的不同                       |      |

### 2.3 分支相关
| 命令                         | 描述                                    | 备注                       |
| ---------------------------- | --------------------------------------- | -------------------------- |
| git branch -av               | 查询分支                                |                            |
| git checkout master          | 切换分支                                |                            |
| git checkout ffb0ec8         | 新建分离头指针分支                      |                            |
| git checkout -b temp 011da64 | 创建一个temp分支                        | 011da64 是某次提交的版本号 |
| git checkout -b temp2 master | 创建一个temp2分支，该分支基于master分支 |                            |
| git branch -d updatecss      | 删除分支updatecss                       |                            |

### 2.4 log 相关
| 命令                            | 描述                           | 备注 |
| ------------------------------- | ------------------------------ | ---- |
| git log                         | 查看Git的日志信息              |      |
| git log --oneline               | 将查询出来的日志信息显示到一行 |      |
| git log -n3 --oneline           | 查询前三条日志信息             |      |
| git log --all                   | 查询全部分支的日志信息         |      |
| git log --all --graph --oneline | 图形化日志                     |      |
| git log master --oneline        | 查询master分支下的日志信息     |      |
| git help --web log              | 通过web查看日志帮助文档        |      |


### 2.5 git仓库备份
| 命令                                                         | 描述                 | 备注     |
| ------------------------------------------------------------ | -------------------- | -------- |
| git clone -bare d:/.../.git .git                             | 呀克隆               | 没有进度 |
| git clone -bare file://d:/.../.git .git                      | 呀克隆               | 有进度   |
| git remote add zhineng  file://D:\work\Git-Work\Git\clone\zhineng\.git | 新建远端             |          |
| git push --set-upstream zhineng temp                         | 将temp分支推送到远端 |          |


#### 2.5.1 备份到GitHub
| 命令                                                         | 描述                                                         | 备注 |
| ------------------------------------------------------------ | ------------------------------------------------------------ | ---- |
| 生成SSH Key 用于配置GitHub SSH Keys                          | https://help.github.com/articles/adding-a-new-ssh-key-to-your-github-account/ |      |
| git remote add github-study git@github.com:Oliver59/Git-Study.git | 添加远端仓库(Github)                                         |      |
| git push github-study --all                                  | 推送所有修改到GitHub                                         |      |
| git fetch github-study master                                | 将Github上的修改取到本地                                     |      |
| git merge -h                                                 | 查看合并帮助                                                 |      |
| git merge github-study/master --allow-unrelated-histories    | 将Github分支与本地分支合并                                   |      |
| git push github-study master                                 | 将本地master分支的修改推送到GitHub                           |      |


### 2.6 其它
1. 修改工作区内容使用checkout；修改暂存区内容使用reset。
2. windows 系统一定使用Git Bash 工具


## 3、其他
### 3.1 Git 使用vi或vim命令打开、关闭、保存文件
#### 1、vi & vim 有两种工作模式：
 - （1） 命令模式：接受、执行 vi & vim 操作命令的模式，打开文件后的默认模式；
 - （2） 编辑模式：对打开的文件内容进行 增、删、改 操作的模式；
     在编辑模式下按下 ESC 键，回退到命令模式。
#### 2、创建、打开文件：$ vi [filename]
- （1）使用 vi 加 文件路径（或文件名）的模式打开文件，如果文件存在则打开现有文件，如果文件不存在则新建文件，并在终端最下面一行显示打开的是一个新文件。
- （2）键盘输入字母 “i”或“Insert”键进入最常用的插入编辑模式。
#### 3、保存文件：
- （1）在插入编辑模式下编辑文件。
- （2）按下 “ESC” 键，退出编辑模式，切换到命令模式。
- （3）在命令模式下键入"ZZ"或者":wq"保存修改并且退出 vi 。
- （4）如果只想保存文件，则键入":w"，回车后底行会提示写入操作结果，并保持停留在命令模式。
#### 4、放弃所有文件修改：
- （1）放弃所有文件修改：按下 "ESC" 键进入命令模式，键入 ":q!" 回车后放弃修改并退出vi。
- （2）放弃所有文件修改，但不退出 vi ，即回退到文件打开后最后一次保存操作的状态，继续进行文件操作：按下 "ESC" 键进入命令模式，键入 ":e!" ，回车后回到命令模式。


## 探秘.git目录