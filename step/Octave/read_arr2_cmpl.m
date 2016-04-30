
## Author: spanfil <spanfil@SPANFIL-OP7010>
## Created: 2015-11-04

function [ac] = read_arr2_cmpl (fname)
fid=fopen(fname,'r');
n1=fread(fid,1,'int32');
n2=fread(fid,1,'int32');
a=fread(fid,2*n1*n2,'float32');
fclose(fid);
a=reshape(a,2,n1,n2);
ar=squeeze(a(1,:,:));
ai=squeeze(a(2,:,:));
ac=complex(ar,ai);
endfunction
