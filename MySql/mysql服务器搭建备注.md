# mysql服务器搭建备注

## 一、安装docker

Ubuntu Docker 安装：https://www.runoob.com/docker/ubuntu-docker-install.html

### 使用官方安装脚本自动安装

安装命令如下：

```shell
curl -fsSL https://get.docker.com | bash -s docker --mirror Aliyun
```

也可以使用国内 daocloud 一键安装命令：

```shell
curl -sSL https://get.daocloud.io/docker | sh
```

## 二、安装mysql

Docker 安装 MySQL https://www.runoob.com/docker/docker-install-mysql.html

### 1. 拉取 MySQL 镜像

```shell
$ docker pull mysql:latest
```

### 2. 运行容器

```shell
$ docker run -itd --name mysql-test -p 3306:3306 -e MYSQL_ROOT_PASSWORD=f7bGdcjCR@XX3sOpA mysql
```

### 3. 进入容器

```shell
$ docker exec -it mysql-test bash

$ mysql -uroot -p

mysql> create database db_gdzs;
Query OK, 1 row affected (0.01 sec)

mysql> use db_gdzs;
Database changed
```

### 4. 设置容器开机启动

```shell
$ docker update --restart=always c3eb
```



```shell
ALTER USER 'root'@'localhost' IDENTIFIED BY 'f7bGdcjCR@XX3sOpA' PASSWORD EXPIRE NEVER;
ALTER USER 'root'@'localhost' IDENTIFIED WITH mysql_native_password BY 'f7bGdcjCR@XX3sOpA';


alter user 'root'@'localhost' identified by 'f7bGdcjCR@XX3sOpA';
```

在Docker中安装MySQL并修改 my.cnf 配置文件

https://cloud.tencent.com/developer/article/1831208

## 三、MySql 数据持久化

1. 在阿里云上申请一个存储空间

2. 将存储空间挂载到服务器上

3. 运行以下命令，其中 -v 表示将主机的内容映射到容器中。

   `docker run -itd --name mysql-test --privileged=true -p 3306:3306  -v /mnt/mysql:/var/lib/mysql -e MYSQL_ROOT_PASSWORD=f7bGdcjCR@XX3sOpA mysql`

   

