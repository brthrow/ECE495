decimation = 1;
samples = 250;
timestep = 0.001;
frequency = 100;
rad = 12566; 

figure(1)
p1 = plot(tg.TimeLog, tg.OutputLog(:,1));
%axis([0,0.1,-1.1,1.1]);

%figure(2)
%p2 = plot(tg.TimeLog, tg.OutputLog(:,2));
%axis([0,0.1,-1,6]);

%figure(3)
%p2 = plot(tg.TimeLog, tg.OutputLog(:,3));
%axis([0,3.5,-40,100]);
