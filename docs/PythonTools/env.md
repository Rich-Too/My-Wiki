# Conda

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

​			
