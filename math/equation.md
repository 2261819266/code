
$$
	Ax^3 + Bx^2 + Cx + D = 0.\\

	x^3 + \frac B A x^2 + \frac C A x + 
	\frac D A = 0.\\
	令 x = a - \frac b {3a}.\\
	
\begin{aligned}
&则x^3 + \frac B A x^2 + \frac C A x + \frac D A\\
	&= \left (a - \frac B {3A}\right)^3
	+ \frac B A \cdot 
	  \left (a - \frac B {3A}\right)^2
	+ \frac C A \cdot
	  \left (a - \frac B {3A}\right) 
	+ \frac D A \\
	&= a^3 + \frac {3AC-B^2} {3A^2}a + \frac {3AD-BC} {3A^2}
	=0.
\end{aligned}\\
	\therefore a^3 = \frac {B^2-3AC} {3A^2}a +  \frac {BC-3AD^2} {3A^2}.\\
	令 p = \frac {B^2 - 3AC} {3A^2},
	q = \frac {BC-3AD} {3A^2}.\\
	\therefore a^3 = pa + q.\\
	令 a = u + v.\\

	则  x^3 = (u + v)^3
	= u^3 + 3u^2v + 3uv^2 + v^3\\\
	= u^3 + v^3 + 3uv(u + v) 
	= u^3+v^3+3uvx = px + q.\\
	\therefore 
	\begin{cases}
		u^3 + v^3 = q,&(1)\\
		3uv = p. &(2)
	\end{cases}\\
	由 (2) 得 v = \frac {p} {3u}.
	带入 (1) 得 u^3 + \frac {p^3} {27u^3} = q.\\
	\therefore
	(u^3)^2 - qu^3 + \frac {1} {27} p^3 = 0.\\
	\therefore
	\Delta = q^2 - \frac {4} {27} p^3\\
	\therefore 
	u^3 = \frac {q \pm \sqrt \Delta} {2}.\\
	\therefore
	\begin{cases}
		u_1, v1 = 
		\sqrt [3] {\frac {q \pm \sqrt \Delta} {2}}\\
	
		u_2, v2 = \frac {-1 + \sqrt3i}{2} \cdot \sqrt 
		[3] {\frac {q \pm \sqrt \Delta} {2}}\\

		u_3, v3 = \frac {-1 - \sqrt3i}{2} \cdot \sqrt 
		[3] {\frac {q \pm \sqrt \Delta} {2}}\\
	\end{cases}\\

	\therefore
	% \begin{cases}
	% 	a1 = u1 + v1 = 
	% 	\sqrt [3] {\frac {q + \sqrt \Delta} {2}} + 
	% 	\sqrt [3] {\frac {q - \sqrt \Delta} {2}}\\
	% 	a2 = \frac {-1 + \sqrt3i}{2} \cdot \sqrt 
	% 	[3] {\frac {q + \sqrt \Delta} {2}}
	% 	+
	% 	\frac {-1 + \sqrt3i}{2} \cdot \sqrt 
	% 	[3] {\frac {q - \sqrt \Delta} {2}}\\
		
	% 	a3 = \frac {-1 + \sqrt3i}{2} \cdot \sqrt 
	% 	[3] {\frac {q + \sqrt \Delta} {2}}
	% 	+
	% 	\frac {-1 + \sqrt3i}{2} \cdot \sqrt 
	% 	[3] {\frac {q - \sqrt \Delta} {2}}\\
		
	% \end{cases}
$$

$$
	x^3 - 3x - 2 = 0.\\
	\therefore
	x^3 = 3x + 2.\\
	令 x = u + v.\\
	\therefore
	x^3 = u^3 + v^3 + 3uvx.\\
	\therefore
	\begin{cases}
		u^3 + v^3 = 2,\\
		3uv = 3.
	\end{cases}\\

	\therefore 
	v = \frac {1} {u}.\\
	\therefore 
	u^3 + v^3 = u^3 + \frac {1} {u^3} = 2.\\
	\therefore
	(u^3)^2 - 2u^3 + 1 = 0.\\
	\therefore
	u^3 = 1.\\
	\therefore
	\begin{cases}
		u_1 = 1, v_1 = 1.\\

		u_2 = - \frac {1} {2} + 
		\frac {\sqrt 3} {2} i, 
		v_2 = - \frac {1} {2} -
		\frac {\sqrt 3} {2} i.\\

		u_2 = - \frac {1} {2} - 
		\frac {\sqrt 3} {2} i, 
		v_2 = - \frac {1} {2} +
		\frac {\sqrt 3} {2} i.
	\end{cases}\\

	\therefore 
	\begin{cases}
		x_1 = u_1 + v_1 = 2.\\
		x_2 = x_3 = u_2 + v_2 = u_3 + v_3 = -1.
	\end{cases}\\














