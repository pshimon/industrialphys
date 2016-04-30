
## Author: spanfil <spanfil@SPANFIL-OP7010>
## Created: 2015-11-04

function [retval] = write_arr2_dbl (a,fname)
n1=size(a,1);
n2=size(a,2);
fid=fopen(fname,"w");
fwrite(fid,n1,'int32');
fwrite(fid,n2,'int32');
cnt=fwrite(fid,a,'float64');
fclose(fid);
retval=cnt-n1*n2;
endfunction
