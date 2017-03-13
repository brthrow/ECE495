function bio=new_analog_loopback_q4bio
bio = [];
bio(1).blkName='Q4 AD2/p1';
bio(1).sigName='';
bio(1).portIdx=0;
bio(1).dim=[1,1];
bio(1).sigWidth=1;
bio(1).sigAddress='&new_analog_loopback_q4_B.Q4AD2_o1';
bio(1).ndims=2;
bio(1).size=[];

bio(getlenBIO) = bio(1);

bio(2).blkName='Q4 AD2/p2';
bio(2).sigName='';
bio(2).portIdx=1;
bio(2).dim=[1,1];
bio(2).sigWidth=1;
bio(2).sigAddress='&new_analog_loopback_q4_B.Q4AD2_o2';
bio(2).ndims=2;
bio(2).size=[];


bio(3).blkName='Q4 Enc ';
bio(3).sigName='';
bio(3).portIdx=0;
bio(3).dim=[1,1];
bio(3).sigWidth=1;
bio(3).sigAddress='&new_analog_loopback_q4_B.Q4Enc';
bio(3).ndims=2;
bio(3).size=[];


bio(4).blkName='Signal Generator';
bio(4).sigName='';
bio(4).portIdx=0;
bio(4).dim=[1,1];
bio(4).sigWidth=1;
bio(4).sigAddress='&new_analog_loopback_q4_B.SignalGenerator';
bio(4).ndims=2;
bio(4).size=[];


bio(5).blkName='Sine Wave';
bio(5).sigName='';
bio(5).portIdx=0;
bio(5).dim=[1,1];
bio(5).sigWidth=1;
bio(5).sigAddress='&new_analog_loopback_q4_B.SineWave';
bio(5).ndims=2;
bio(5).size=[];


function len = getlenBIO
len = 5;

