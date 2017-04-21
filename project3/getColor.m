function c = getColor(r, g, b)
%   Detailed explanation goes here
    if (r > 80) && (r < 145) && (g > 60) && (g < 125) && (b > 180)
        c = 'blue';
    elseif (r > 120) && (r < 155) && (g > 120) && (g < 155) && (b > 150) && (b < 180)
        c = 'black';
    elseif (r > 240) && (g > 240) && (b > 220) && (b < 235)
        c = 'orange';
    elseif (r > 185) && (r < 225) && (g > 170) && (g < 210) && (b > 185) && (b < 230)
        c = 'red';
    elseif (r > 245) && (g > 245) && (b > 245)
        c = 'white';
    elseif (r > 240) && (g > 240) && (b > 200) && (b < 210)
        c = 'yellow';
    elseif (r > 80) && (r < 100) && (g > 140) && (g < 165) && (b > 110) && (b < 130)
        c = 'table';
    else
        c = 'undetermined';
    end
end

