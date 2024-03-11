% Define the function f(x) = e^x
syms x;
f = exp(x);

% Set the desired orders of Pade approximation for R1,1 and R2,2
m1 = 1; % Numerator degree for R1,1
k1 = 1; % Denominator degree for R1,1
m2 = 2; % Numerator degree for R2,2
k2 = 2; % Denominator degree for R2,2

% Define the variable x for plotting
x_values = linspace(-1, 1, 100); % Adjust the range as needed

% Compute the Pade approximations using mypade function
R11 = mypade(f, m1, k1, x);
R22 = mypade(f, m2, k2, x);

% Plot the original function and its Pade approximations
figure;
hold on;
plot(x_values, double(subs(f, x, x_values)), 'b-', 'LineWidth', 2); % Original function
plot(x_values, double(subs(R11, x, x_values)), 'r--', 'LineWidth', 2); % Pade approximation R1,1
plot(x_values, double(subs(R22, x, x_values)), 'g--', 'LineWidth', 2); % Pade approximation R2,2
legend('f(x) = e^x', 'R_{1,1}', 'R_{2,2}');
xlabel('x');
ylabel('y');
title('Pade Approximations of e^x');
grid on;
hold off;
