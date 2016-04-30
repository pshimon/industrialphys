%% Author: spanfil <spanfil@SPANFIL-OP7010>
%% Created: 2016-01-11
dir='C:\MTD\JonesResults\P_002926a0-094d-4907-8ee8-d2957713a3d2\B_ce6d140e-9d7d-4a81-9fe6-9868e90852fd\NOMINAL\'
prefix='6f805530-1373-4262-87a2-d5aeb028d7d8+NOMINAL'
il_app=0.42;
col_app=0.7;
npoints=40;
nwl=80;
dw=5;
wl0=430;
p=2000;
pref=strcat(dir,prefix);
mm=floor((il_app+col_app)*p/wl0);
global data_arr
data_arr=zeros(8,npoints,nwl,2*mm+1);
for j=1:nwl
    wl=wl0+(j-1)*dw;
    fn=strcat(pref,'+',sprintf('%0.2f',wl),'.jns');
    read_jns_wl (fn,j,mm,npoints);
end

