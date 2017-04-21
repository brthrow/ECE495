function [ angle ] = pot(cue, centers, ball, pocket_loc, pocket, radii, color)
%UNTITLED2 Summary of this function goes here
%   Detailed explanation goes here

    x_hold = pocket_loc(pocket,1)-centers(ball,1);                              %determine the difference between the desired pocket and the ball
    y_hold = pocket_loc(pocket,2)-centers(ball,2);
    c = double(color(ball,:))/double(255);
    if(x_hold >= 0)                                                             %if the distance is positive then the ball needs to be shot forwards
        eqx = centers(ball,1):1:pocket_loc(pocket,1);                           %set the range of x values
        eqy = (y_hold/x_hold).*(eqx-centers(ball,1))+(centers(ball,2));         %solve the y values of the line that the ball will travel on
        plot(eqx,eqy,'LineWidth',2,'Color','k');                                %plot the line
        theta = atand(y_hold/x_hold);                                           %calculate the angle of this line
        hit_x = centers(ball,1) - 2*radii(ball)*cosd(theta);                    %calculate the coordinates that the cue ball has to hit
        hit_y = centers(ball,2) - 2*radii(ball)*sind(theta);
    else
        eqx = pocket_loc(pocket,1):1:centers(ball,1);                           %if the distance is negative then the ball needs to be shot backwards
        eqy = (y_hold/x_hold).*(eqx-centers(ball,1))+(centers(ball,2));
        plot(eqx,eqy,'LineWidth',2,'Color','k');
        theta = -atand(y_hold/x_hold);
        hit_x = centers(ball,1) + 2*radii(ball)*cosd(theta);                    %calculate the coordinates that the cue ball has to hit
        hit_y = centers(ball,2) - 2*radii(ball)*sind(theta);
    end

    theta2 = round(atand((hit_y-cue(2))/(hit_x-cue(1))),1);                     %calculate the angle the cue stick needs to point
    angle = num2str(theta2);                                                    %set the output angle to this angle in the form of a string

    x_hold = hit_x-cue(1);
    y_hold = hit_y-cue(2);
    if(x_hold >= 0)
        shotx = cue(1):1:hit_x;
        shoty = (y_hold/x_hold).*(shotx-cue(1))+(cue(2));
    else
        shotx = hit_x:1:cue(1);
        shoty = (y_hold/x_hold).*(shotx-cue(1))+(cue(2));
    end

    temps = 1;
    for j = 1:1:round(abs(cue(1)-hit_x))
        for i = 1:1:size(centers,1)
            if i~=ball
                %disp(sqrt((centers(i,1)-shotx(j))^2+(centers(i,2)-shoty(j))^2)<(round(2*mean(radii))));
                if sqrt((centers(i,1)-shotx(j))^2+(centers(i,2)-shoty(j))^2)<(round(2*mean(radii)))
                    temps = 0;
                    temp = i;
                    c = double(color(temp,:))/double(255);
                    plot(hit_x,hit_y,'o','Color',c,'Markers',radii(temp),'MarkerFaceColor',c);                     %plot the point the ball needs to hit
                end
            end
        end
    end

    if ~temps
        x_hold = hit_x-centers(temp,1);
        y_hold = hit_y-centers(temp,2);
        if(x_hold >= 0)
            xTemp = centers(temp,1):1:hit_x;
            yTemp = (y_hold/x_hold).*(xTemp-centers(temp,1))+(centers(temp,2));
            plot(xTemp,yTemp,'LineWidth',2,'color',c);
            theta3 = atand(y_hold/x_hold);
        else
            xTemp = hit_x:1:centers(temp,1);
            yTemp = (y_hold/x_hold).*(xTemp-centers(temp,1))+(centers(temp,2));
            plot(xTemp,yTemp,'LineWidth',2,'color',c);
            theta3 = -atand(y_hold/x_hold);
        end

        hit_temp_x = centers(temp,1) - 2*radii(temp)*cosd(theta3);
        hit_temp_y = centers(temp,2) - 2*radii(temp)*sind(theta3);

        plot(hit_temp_x,hit_temp_y,'o','color','w','Markers',15,'MarkerFaceColor','w');

        theta4 = round(atand((hit_temp_y-cue(2))/(hit_temp_x-cue(1))),1);
        angle = num2str(theta4);

        x_hold = hit_temp_x-cue(1);
        y_hold = hit_temp_y-cue(2);
        if(x_hold >= 0)
            shotx_temp = cue(1):1:hit_temp_x;
            shoty_temp = (y_hold/x_hold).*(shotx_temp-cue(1))+(cue(2));
            plot(shotx_temp,shoty_temp,'LineWidth',2,'color','w');
        else
            shotx_temp = pocket_loc(pocket,1):1:centers(ball,1);
            shoty_temp = (y_hold/x_hold).*(shotx_temp-centers(temp,1))+(centers(temp,2));
            plot(shotx_temp,shoty_temp,'LineWidth',2,'color','w');
        end
    else
        plot(hit_x,hit_y,'o','Color','w','Markers',15,'MarkerFaceColor','w');                     %plot the point the ball needs to hit
        if(x_hold >= 0)
            plot(shotx,shoty,'LineWidth',2,'Color','w');
        else
            plot(shotx,shoty,'LineWidth',2,'Color','w');
        end
    end
end