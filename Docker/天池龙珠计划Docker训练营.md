# 天池龙珠计划Docker训练营 记录

## Docker 安装

```bash
# 安装命令
sudo curl -sS https://get.docker.com/ | sh
# 查看版本
docker version
```

#### 拉取python3镜像

```bash
docker pull registry.cn-shanghai.aliyuncs.com/tcc-public/python:3
```

#### 运行容器

```bash
 docker run -it a4cc bash
```

#### 在宿主机创建文件

main.py

```python
#main.py
import os
import numpy as np
import torch

device = torch.device("cuda")

data_dir = '/tcdata'
a = np.load(os.path(data_dir,a.npy))
b = np.load(os.path(data_dir,b.npy))

a = torch.from_numpy(a).to(device)
b = torch.from_numpy(b).to(device)
c = torch.matmul(a,b).cpu()

print(c)
np.save("result.npy", c)
```

run.sh

```bash
#bin/bash
#打印GPU信息
nvidia-smi
#执行math.py
python3 mat.py
```

#### 拷贝文件到容器

```bash
# friendly_nash 是容器的名称
root@iZ2ze7o33k5p6wazs9u7ioZ:~# docker cp /home/tianchi-test/main.py friendly_nash:/home
root@iZ2ze7o33k5p6wazs9u7ioZ:~# docker cp /home/tianchi-test/run.sh friendly_nash:/home
```

#### 再次进入容器

```sh
root@iZ2ze7o33k5p6wazs9u7ioZ:~# docker exec -it friendly_nash bash
```

