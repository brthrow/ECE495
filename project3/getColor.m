function c = getColor(r, g, b)
%   Detailed explanation goes here
    if (r > 60) && (r < 105) && (g > 55) && (g < 95) && (b > 100) && (b < 185)
        c = 'blue';
    elseif (r < 100) && (g < 75) && (b < 100)
        c = 'black';
    elseif (r > 240) && (g > 100) && (g < 200) && (b > 140)
        c = 'orange';
    elseif (r > 240) && (g < 100) && (b > 100) && (b < 200)
        c = 'red';
    elseif (r > 240) && (g > 240) && (b > 240)
        c = 'white';
    elseif (r > 240) && (g > 200) && (b > 100) && (b < 200)
        c = 'yellow';
    else
        c = 'undetermined';
    end
end

