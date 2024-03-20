syms x;
f = sin(x);
res_sin = lab3_pade_approx(0, f, 4, 5);
g = cos(x);
res_cos = lab3_pade_approx(0, g, 4, 5);