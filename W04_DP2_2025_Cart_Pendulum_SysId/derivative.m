function y = derivative(x, ts)
    %DERIVATIVE Numerical derivative of a sampled signal
    %   y = derivative(x, ts)
    %   x  : input vector
    %   ts : sampling time
    %   y  : numerical derivative, same length as x
    
    x = x(:);                     % ensure column vector
    y = zeros(size(x));
    
    % Use central difference for interior points
    y(2:end-1) = (x(3:end) - x(1:end-2)) / (2*ts);
    
    % Use forward/backward difference at edges
    y(1)  = (x(2) - x(1)) / ts;              % forward diff
    y(end)= (x(end) - x(end-1)) / ts;        % backward diff
end