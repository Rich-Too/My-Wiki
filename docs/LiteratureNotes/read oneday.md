https://zhuanlan.zhihu.com/p/597586623 通向AGI之路：大型语言模型（LLM）技术精要


https://huggingface.co/learn/nlp-course/chapter1/1  huggingface 的 nlp 课程
Andrej Karpathy 的 GPT 系列教程
python cookbook
[大模型白盒子教程](https://github.com/datawhalechina/tiny-universe/tree/main)
因果推理的文章也许值得一看：Improving the accuracy of medical diagnosis with causal machine learning
手写个 VAE 看看？
https://github.com/ianzhao05/textshot/tree/master 一个极短的 python ocr 程序
https://wnzhang.net/teaching/sjtu-rl-2024/ 上交的强化学习课程



ACL 2024 LLM-based Agent 论文总结 https://zhuanlan.zhihu.com/p/722064605
长文 | Reverse-o1：OpenAI o1原理逆向工程图解 https://mp.weixin.qq.com/s/yDiFQRuSJOCG70Lqzgms0g

推荐系统 llm   https://zhuanlan.zhihu.com/p/713097211
https://www.hello-algo.com/ hello 算法



| 标题                                                                                                                       | 年份   | 应用领域   | KG 技术       | RL算法      | 多agent | 奖励设计             | 动作设计                                                | 状态设计                   | 数据集                                                                              | 评价指标                                                                                         | 谷歌引用 | 源码  | 引用率         | 出版物                                                    |
| ------------------------------------------------------------------------------------------------------------------------ | ---- | ------ | ----------- | --------- | ------ | ---------------- | --------------------------------------------------- | ---------------------- | -------------------------------------------------------------------------------- | -------------------------------------------------------------------------------------------- | ---- | --- | ----------- | ------------------------------------------------------ |
| Reinforcement  knowledge graph reasoning for explainable recommendation                                                  | 2019 | 可解释性推荐 | 知识推理        | REINFORCE | 单agent | delayed reward   | all edges:user-conditional action  pruning strategy | vector，如源实体，当前实体，目标实体等 | Amazon e-commerce datasets：CDs  and     Vinyl, Clothing, Cell Phones and Beauty. | Normalized Discounted  Cumulative Gain (NDCG), Recall, Hit Ratio (HR) and Precision (Prec.) | 241  | 1   | 80.33333333 | [SIGIR](https://dblp.org/db/conf/sigir/sigir2019.html) |
| Reinforced  Negative Sampling over Knowledge Graph for Recommendation                                                    | 2020 | 推荐系统   | 知识抽取，命名实体识别 | REINFORCE | 单agent | immediate reward | all possible exploration  operations,Pruning        | others                 | Amazon-book, Last-FM,     and Yelp2018,                                          | recall@K and ndcg@K                                                                          | 95   | 1   | 47.5        | [WWW](https://dblp.org/db/conf/www/www2020.html)       |
| Interactive  Recommender System via Knowledge Graph-enhanced Reinforcement Learning                                      | 2020 | 推荐系统   | unspecified | DQN       | 单agent | immediate reward |                                                     | GCN+GRU+RNN            | Book-Crossing,Movielens-20M                                                      | reward，precision，recall                                                                      | 66   | 1   | 33          | [SIGIR](https://dblp.org/db/conf/sigir/sigir2020.html) |
| Inferring  substitutable and complementary products with Knowledge-Aware Path Reasoning  based on dynamic policy network | 2022 | 推荐系统   | 知识推理        | REINFORCE | 单agent | delayed reward   | instance and relation                               | unspecified            | Baby, Beauty, Cell Phone  (Cell     Phones and Accessories) and Electronics      | Normalized Discounted Cumulation Gain  (NDCG), Hit Ratio (HR), Recall and     Precision     | 3    | 1   |             | Knowl. Based Syst.                                     |
| Time-aware  Path Reasoning on Knowledge Graph for Recommendation                                                         | 2022 | 推荐系统   | 知识推理        | REINFORCE | 单agent | immediate reward | the outgoing relation and entity                    | BiLSTM                 | Amazon e-commerce                                                                | [NDCG@K，R,P,hitsk](mailto:NDCG@K，R,P,hitsk)                                                  | 19   | 1   | 9           | ACM Trans. Inf. Syst.                                  |

\* implicit
prm


reward -> agents

STaR: Bootstrapping Reasoning With Reasoning

Quiet-STaR: Language Models Can Teach Themselves to Think Before Speaking