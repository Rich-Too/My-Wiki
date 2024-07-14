## Policy network 

Use a neural net to approximate $π(a|s)$.

- Use policy network $π(a|s;θ)$ to approximate $π (a|s)$ .

- $θ$: trainable parameters of the neural net.

**Definition of Policy-Based RL:** 

Approximate state-value function: $V(s;\mathbf{\theta})=\underset{a}{\sum}\pi(a|s;\mathbf{\theta})\cdot Q_{\pi}(s,a)$.

## Policy-based learning

- Learn $θ$ that maximizes $J(\mathbf{\theta})=\mathbb{E}_{S}[V(S;\mathbf{\theta})]$.
- Using gradient-ascent algorithm maximizing $J(\mathbf{\theta})$: 
  - $\theta_{t+1}=\theta_t+\alpha\nabla_\theta J(\theta_t)  =\theta_t+\alpha\mathbb{E}\left[\nabla_\theta\ln\pi(A|S,\theta_t)q_\pi(S,A)\right]$
  - proof:![image-20240204174509398](static/image-20240204174509398.png)
- Stochastic gradient-ascent algorithm:
  - $\theta_{t+1}=\theta_t+\alpha\nabla_\theta\ln\pi(a_t|s_t,\theta_t)q_\pi(s_t,a_t)$
  - **since $q_\pi$ is unknown, it can be approximated with $q_t$, Monte-Carlo based method, REINFORCE and TD method (AC)**

## REINFORCE(Monte Carlo policy gradient)

If $q_t(s_t, a_t)$ is obtained by Monte Carlo estimation, the algorithm is called REINFORCE.

Since $\nabla_\theta\ln\pi(a_t|s_t,\theta_t)=\frac{\nabla_\theta\pi(a_t|s_t,\theta_t)}{\pi(a_t|s_t,\theta_t)}$: 

- $\theta_{t+1}=\theta_t+\underbrace{\alpha\left(\frac{q_t(s_t,a_t)}{\pi(a_t|s_t,\theta_t)}\right)}_{\beta_t}\nabla_\theta\pi(a_t|s_t,\theta_t)$
- $\theta_{t+1}=\theta_t+\alpha\beta_t\nabla_\theta\pi(a_t|s_t,\theta_t)$

![image-20240204172611859](static/image-20240204172611859.png)











## Policy Gradient

Two forms: 
$$
\begin{aligned}\frac{\partial V(s;\theta)}{\partial\theta}&=\sum_a\frac{\partial\pi(a|s;\theta)}{\partial\theta}\cdot Q_\pi(s,a)\\
\frac{\partial V(s;\theta)}{\partial\theta}&=\mathbb{E}_{A\sim\pi(\cdot|s;\theta)}\Big[\frac{\partial\log\pi(A|s,\theta)}{\partial\theta}\cdot Q_\pi(s,A)\Big]\end{aligned}
$$

![image-20231128213014143](static/image-20231128213014143.png)

## Algorithm

1. Observe the state $s_t.$ 

2. Randomly sample action ${a_t}$ according to $\pi(\cdot|s_t;\mathbf{\theta}_t).$

3. Compute $q_t\approx Q_\pi(s_t,a_t)$ (some estimate).

4. Differentiate policy network: $\mathbf{d}_{\theta,t}=\frac{\partial\log\pi(a_t|s_t,\theta)}{\partial\theta}\mid d_{\mathbf{\theta}=\mathbf{\theta}_t}.$

5. (Approximate) policy gradient: $\mathbf{g}(a_t,\theta_t)=q_t\cdot\mathbf{d}_{\theta,t}.$

6. Update policy network: $\theta_{t+1}=\theta_t+\beta\cdot\mathbf{g}(\alpha_t,\mathbf{\theta}_t).$

**How to  compute $q_t$?**

*Option1:*

Play the game to the end and generate the trajectory:
$$
s_1,{a_1},r_1,s_2,{a_2},r_2,\ ...\ ,s_T,{a_T},r_T.
$$

Compute the discounted return $u_t=\sum_{k=t}^T\gamma^{k-t}\gamma_k$ for all $t.$ Since $Q_\pi(s_t,{a_t})=\mathbb{E}[U_t]$, we can use $u_t$ to approximate $Q_\pi(s_t,{a_t}).$

*Option2:*

Approximate $Q_\pi$ using NN.
