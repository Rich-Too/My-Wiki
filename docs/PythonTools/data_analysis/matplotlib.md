>记录绘图技巧

`%matplotlib inline` 是一个 Jupyter Notebook 的魔法命令，用于在 Jupyter Notebook 中内嵌绘图，而无需调用 `plt.show()`
```python
import matplotlib.pyplot as plt

  

eli = np.arange(len(acc_list))

fig, ax1 = plt.subplots()

color = (255 / 255, 81 / 255, 134 / 255)

ax1.set_xlabel("Epochs")
ax1.set_ylabel("Loss")
ax1.plot(eli, l_list, color=color, label="Loss")
ax1.tick_params(axis="y")
ax1.set_facecolor((234 / 255, 234 / 255, 242 / 255))
ax2 = ax1.twinx()
color = "tab:purple"
ax2.set_ylabel("Accuracy")
ax2.plot(eli, acc_list, color=color, label="Accuracy")
ax2.tick_params(axis="y")
ax1.grid(color="white")

lines, labels = ax1.get_legend_handles_labels()

lines2, labels2 = ax2.get_legend_handles_labels()

ax2.legend(lines + lines2, labels + labels2, loc='upper right')

  

fig.tight_layout()

# plt.savefig('./fig/simple_figure1.jpg', format='jpg', dpi=300)  # Set dpi to 300 for high resolution

plt.savefig('adam+cos.svg', format='svg')

plt.show()
```

![](static/image-20241027224343333.png)

```python
colors = ["#8ECFC9", "#FFBE7A", "#FA7F6F", "#82B0D2", "#BEB8DC"]
```