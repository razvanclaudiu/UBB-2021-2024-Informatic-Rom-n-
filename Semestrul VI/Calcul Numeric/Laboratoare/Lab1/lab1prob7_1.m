% Definirea funcției e^x
f = @(x) exp(x);

% Definirea polinoamelor Taylor de ordin 2, 3, 4 și 5 (serii Maclaurin pentru e^x)
T2f = @(x) 1 + x + (x.^2)/2;
T3f = @(x) 1 + x + (x.^2)/2 + (x.^3)/6;
T4f = @(x) 1 + x + (x.^2)/2 + (x.^3)/6 + (x.^4)/24;
T5f = @(x) 1 + x + (x.^2)/2 + (x.^3)/6 + (x.^4)/24 + (x.^5)/120;

% Intervalul pe care se reprezintă graficul
x = linspace(-2, 2, 1000);

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
title('Graficul funcției e^x și aproximarea cu serii Maclaurin de ordin 2, 3, 4 și 5');
xlabel('x');
ylabel('y');

% Adăugarea unei legende
legend('f(x) = e^x', 'T_2(f)', 'T_3(f)', 'T_4(f)', 'T_5(f)', 'Location', 'northwest');
