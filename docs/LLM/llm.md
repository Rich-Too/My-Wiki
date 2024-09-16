Scaling law:
- Jared Kaplan et al. “Scaling Laws for Neural Language Models”. In: arXiv preprint arXiV: 2001.08361 (2020).
- Tom Henighan et al. “Scaling laws for autoregressive generative modeling”. In: arXiv Preprint arXiv: 2010.14701 (2020).

上下文学习（In-context Learning, ICL）.
- 上下文学习能力在 GPT-3 的论文中被正式提出。具体方式为，在提示中为语言模型提供自然语言指令和多个任务示例（Demonstration），无需显式的训练或梯度更新，仅输入文本的单词序列就能为测试样本生成预期的输出。在 GPT 系列模型中，175 B 参数的 GPT-3 模型展现出强大的上下文学习能力，而 GPT-1 和 GPT-2 模型则不具备这种能力。




GPT-1 基于生成式、仅有解码器的 Transformer 架构开发，奠定了 GPT 系列模型的核心架构与基于自然语言文本的预训练方式，即预测下一个词元
GPT-2 沿用了 GPT-1 的类似架构，将参数规模扩大到 1.5 B，并使用大规模网页数据集 WebText 进行预训练
GPT-3 175B 模型
2022 年 1 月，OpenAI 正式推出 InstructGPT 这一具有重要影响力的学术工作，旨在改进 GPT-3 模型与人类对齐的能力，正式建立了基于人类反馈的强化学习算法，即 RLHF 算法。
zero shot
Instruct gpt [Ouyang L, Wu J, Jiang X, et al. Training language models to follow instructions with human feedback[M]. arXiv, 2022.]


