function c = getColor(r, g, b)
%   Detailed explanation goes here
    if (r > 190) && (r < 200) && (g > 200) && (g < 220) && (b > 165) && (b < 210)
        c = 'blue';
    elseif (r < 125) && (g < 140) && (b < 140)
        c = 'black';
    elseif (r > 235) && (g > 230) && (b > 120) && (b < 175)
        c = 'orange';
    elseif (r > 220) && (g < 75) && (b > 150) && (b < 170)
        c = 'red';
    elseif (r > 240) && (g > 240) && (b > 240)
        c = 'white';
    elseif (r > 240) && (g > 240) && (b > 150) && (b < 185)
        c = 'yellow';
    else
        c = 'undetermined';
    end
end

