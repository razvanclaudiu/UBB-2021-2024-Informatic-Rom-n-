function s = lab2p2_mycos(xx)
    % reducere la primul cadran
    [x, sin_sign, cos_sign] = lab2p2_reducere_cadran(xx);
    
    s = 0;
    t = 1;
    n = 0;
    while s + t ~= s
        n = n + 1;
        s = s + t;
        t = (-1)^n * ((x^(2*n)) / (factorial(2*n)));
    end
    s = cos_sign * s 
end