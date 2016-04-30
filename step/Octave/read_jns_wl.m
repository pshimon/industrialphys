%% Author: spanfil <spanfil@SPANFIL-OP7010>
%% Created: 2016-01-11

function  q=read_jns_wl (fname,i,maxord,np)
global data_arr
fid=fopen(fname,'r');
line='';
%reading header
while   ~strcmp(line,'[START_DIFFORDER]')
    line=fgetl(fid);
end

while ~feof(fid)
    line=fgetl(fid); %DiffractionOrder=[5,0]
    m=sscanf(line,'DiffractionOrder=[%d');
    if abs(m)<=maxord
        line=fgetl(fid); %NAx,NAy,NAx_c,NAy_c,RppReal,RppImg,RpsReal,RpsImg,RspReal,RspImg,RssReal,RssImg
        k=maxord+1-m;
        for j=1:np
            line=fgetl(fid);
            data=sscanf(line,'%f,%f,%f,%f,%f,%f,%f,%f,%f,%f,%f,%f');
            data_arr(:,j,i,k)=data(5:12);
        end
    end
    while ischar(line)&& ~strcmp(line,'[START_DIFFORDER]') 
        line=fgetl(fid);
    end
end
fclose(fid);
end 
