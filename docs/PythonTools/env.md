# ENV

## Conda

```bash
conda create -n ENV_NAME python=x.x 
conda env list # 列出所有环境
conda env remove --name <environment_name> # 删除环境
conda activate ENV_NAME
conda deactivate # 退出
conda config --set auto_activate_base false # 关闭自动激活环境
```

```python
python3 -m venv .venv
. .venv/bin/activate
```

热重载
## poetry
```
poetry env list --full-path # 查看有哪些虚拟环境
poetry env remove python2 # 删除环境
poetry shell # 进入环境
poetry run <你的命令> 
```

```shell
poetry new p2 # 初始化文件夹
poetry init
poetry add flask # 添加库

```

## Vscode

https://k0nze.dev/posts/python-relative-imports-vscode/

https://www.zhihu.com/question/50700473

https://blog.csdn.net/gongjianbo1992/article/details/106981599
## Docker
> https://iphysresearch.github.io/blog/post/programing/docker-tutorial/

## jupyter book 
```python
%load_ext autoreload 
%autoreload 2
--------------------------
import foo

import importlib
importlib.reload(foo)
```