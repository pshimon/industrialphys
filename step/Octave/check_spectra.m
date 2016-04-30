function [lbd] = check_spectra (spectrum)
str1=strcat(spectrum,'.flt');
str2=strcat(spectrum,'-res.flt');
ld=read_arr2_flt(str1);
lbd=read_arr2_flt(str2);
np=size(ld,1);
dw=(ld(np,1)-ld(1,1))/(np-1);
p=ld(:,2)/sum(ld(:,2));
#figure;stairs(ld(:,1),ld(:,3));
figure;plot(ld(:,1),p);
hold on; 
 hist(lbd,np,1);
#[f,x]=hist(lbd,np);
#bar(x, f/sum(f)/(x(2)-x(1)));
hold off;
endfunction
