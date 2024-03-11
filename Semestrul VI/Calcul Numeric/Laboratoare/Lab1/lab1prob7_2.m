% Definirea funcției ln(1+x)
f = @(x) log(1+x);

% Definirea polinoamelor Taylor de ordin 2, 3, 4 și 5 pentru ln(1+x) (serii Maclaurin pentru ln(1+x))
T2f = @(x) x - (x.^2)/2;
T3f = @(x) x - (x.^2)/2 + (x.^3)/3;
T4f = @(x) x - (x.^2)/2 + (x.^3)/3 - (x.^4)/4;
T5f = @(x) x - (x.^2)/2 + (x.^3)/3 - (x.^4)/4 + (x.^5)/5;

% Intervalul pe care se reprezintă graficul
x = linspace(-0.9, 2, 1000); % Limita inferioara este -0.9 pentru a evita evaluarea ln(0)

% Calculul valorilor funcțiilor
y_f = f(x);
y_T2f = T2f(x);
y_T3f = T3f(x);
y_T4f = T4f(x);
y_T5f = T5f(x);

% Reprezentarea grafică
figure;
plot(x, y_f, 'b', 'LineWidth', 2);
hold on;
plot(x, y_T2f, 'r--', 'LineWidth', 1.5);
plot(x, y_T3f, 'g--', 'LineWidth', 1.5);
plot(x, y_T4f, 'm--', 'LineWidth', 1.5);
plot(x, y_T5f, 'c--', 'LineWidth', 1.5);
hold off;

% Adăugarea titlului și a etichetelor pe axele x și y
title('Graficul funcției ln(1+x) și aproximarea cu serii Maclaurin de ordin 2, 3, 4 și 5');
xlabel('x');
ylabel('y');

% Adăugarea unei legende
legend('f(x) = ln(1+x)', 'T_2(f)', 'T_3(f)', 'T_4(f)', 'T_5(f)', 'Location', 'northwest');
