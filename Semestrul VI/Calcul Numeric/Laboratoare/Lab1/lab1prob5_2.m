% Define the value of x
x = 1 / 3; % Change x as needed

% Define the number of terms in the Taylor series
num_terms = 8;

% Define the symbolic variable
syms t;

% Calculate the Taylor series expansion of ln((1+x)/(1-x)) around x = 0
taylor_ln = taylor(log((1 + t)/(1 - t)), t, 'Order', num_terms);

% Substitute x into the Taylor series expansion
approx_ln = subs(taylor_ln, t, x);

fprintf('Approximation of ln((1 + %.2f)/(1 - %.2f)) using %d terms: %.6f\n', x, x, num_terms, double(approx_ln));

% Define the true value of ln((1+x)/(1-x))
true_ln = log((1 + x)/(1 - x));

% Refine the approximation to match the true value
n = 1;
while true
    % Calculate the Taylor series expansion of ln(1 + t) around t = 0 manually
    taylor_ln = taylor(log((1 + t)/(1 - t)), t, 'Order', n);

    % Evaluate the Taylor series approximation at x
    approx_ln = subs(taylor_ln, t, x);
    
    % Fix the precision of the approximation
    approx_ln_fix = vpa(approx_ln, 6); % Fix to 6 decimal places
    
    % Break the loop if the fixed precision values are equal
    if abs(approx_ln_fix - true_ln) < 1e-5 % Check if the difference is negligible
        break;
    end

    n = n + 1;
end

% Display the refined result
fprintf('Approximation of ln((1 + %.2f)/(1 - %.2f)) with 5 correct decimals: %.6f, used %d terms\n', x, x, double(approx_ln_fix), n);
fprintf('True value of ln((1 + %.2f)/(1 - %.2f)): %.6f\n', x, x, double(true_ln));
