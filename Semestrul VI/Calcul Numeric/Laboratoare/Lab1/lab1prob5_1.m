% Define the value of x
x = 1;

true_ln = log(1 + x);

% Initialize the sum for the Taylor series expansion
approx_ln = 0;

n = 0;

% Calculate the Taylor series expansion of ln(1 + t) around t = 0 manually
while true
    % Calculate the nth term of the Taylor series
    term = (-1)^n * (x^(n+1)) / (n+1);

    if n == 7
        fprintf('Approximation of ln(1 + %.2f) using %d terms: %.6f\n', x, n+1, approx_ln_fix);
    end
    
    % Add the nth term to the sum
    approx_ln = approx_ln + term;

    % Fix the precision of approx_ln and true_ln
    approx_ln_fix = fix(approx_ln*1e5)/1e5;
    true_ln_fix = fix(true_ln*1e5)/1e5;
    
    % Break the loop if the fixed precision values are equal
    if approx_ln_fix == true_ln_fix
        break;
    end

    n = n + 1;
end

% Display the result
fprintf('Approximation of ln(1 + %.2f) with 5 correct decimals: %.6f, used %d terms\n', x, approx_ln_fix,n+1);
fprintf('True value of ln(1 + %.2f): %.6f\n', x, true_ln_fix);