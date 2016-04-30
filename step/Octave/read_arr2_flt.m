
## Author: spanfil <spanfil@SPANFIL-OP7010>
## Created: 2015-11-04

function [a] = read_arr2_flt (fname)
fid=fopen(fname,'r');
n1=fread(fid,1,'int32');
n2=fread(fid,1,'int32');
a=fread(fid,n1*n2,'float32');
fclose(fid);
a=reshape(a,n1,n2);
endfunction
