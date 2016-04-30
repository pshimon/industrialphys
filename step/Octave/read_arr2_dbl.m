%% Author: spanfil <spanfil@SPANFIL-OP7010>
%% Created: 2015-12-22

function [a] = read_arr2_dbl (fname)
fid=fopen(fname,'r');
n1=fread(fid,1,'int32');
n2=fread(fid,1,'int32');
a=fread(fid,n1*n2,'float64');
fclose(fid);
a=reshape(a,n1,n2);
end 
