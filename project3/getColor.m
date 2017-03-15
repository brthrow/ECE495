function c = getColor(r, g, b)
%   Detailed explanation goes here
    if (r > 60) && (r < 105) && (g > 100) && (g < 135) && (b > 165) && (b < 200)
        c = 'blue';
    elseif (r < 105) && (g < 100) && (b < 100)
        c = 'black';
    elseif (r > 235) && (g > 150) && (g < 205) && (b > 120) && (b < 175)
        c = 'orange';
    elseif (r > 220) && (g < 75) && (b > 150) && (b < 170)
        c = 'red';
    elseif (r > 240) && (g > 240) && (b > 240)
        c = 'white';
    elseif (r > 240) && (g > 225) && (b > 115) && (b < 175)
        c = 'yellow';
    else
        c = 'undetermined';
    end
end

