function bio=downloaded_from_webbio
bio = [];
bio(1).blkName='Constant';
bio(1).sigName='';
bio(1).portIdx=0;
bio(1).dim=[1,1];
bio(1).sigWidth=1;
bio(1).sigAddress='&downloaded_from_web_B.Constant';
bio(1).ndims=2;
bio(1).size=[];

bio(getlenBIO) = bio(1);

bio(2).blkName='Pulse Generator';
bio(2).sigName='';
bio(2).portIdx=0;
bio(2).dim=[1,1];
bio(2).sigWidth=1;
bio(2).sigAddress='&downloaded_from_web_B.PulseGenerator';
bio(2).ndims=2;
bio(2).size=[];


bio(3).blkName='Q4 AD';
bio(3).sigName='';
bio(3).portIdx=0;
bio(3).dim=[1,1];
bio(3).sigWidth=1;
bio(3).sigAddress='&downloaded_from_web_B.Q4AD';
bio(3).ndims=2;
bio(3).size=[];


bio(4).blkName='Q4 Enc ';
bio(4).sigName='';
bio(4).portIdx=0;
bio(4).dim=[1,1];
bio(4).sigWidth=1;
bio(4).sigAddress='&downloaded_from_web_B.Q4Enc';
bio(4).ndims=2;
bio(4).size=[];


bio(5).blkName='Sine Wave';
bio(5).sigName='';
bio(5).portIdx=0;
bio(5).dim=[1,1];
bio(5).sigWidth=1;
bio(5).sigAddress='&downloaded_from_web_B.SineWave';
bio(5).ndims=2;
bio(5).size=[];


function len = getlenBIO
len = 5;

