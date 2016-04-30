#! python
########################################################################
# Shimon Panfil: Industrial Physics and Simulations                   ##
# http://industrialphys.com                                           ##
# THE SOFTWARE IS PROVIDED "AS IS", USE IT AT YOUR OWN RISK           ##
########################################################################
import sys
import pyodbc
import numpy as np
def write_arr2(a,filename):
    (n2,n1)=a.shape
    nn=np.zeros(2,int)
    nn[0]=n1
    nn[1]=n2
    fid = open(filename, 'wb')
    nn.tofile(fid)
    a.tofile(fid)
    fid.close()

def set_search_str(spectrum):
    s1=" ZPosition"
    s2=" [dbo].[FourierHarmonic].[Order] as ordr"
    s3=" A"
    s4=" B"
    s5=" [dbo].[PetalCandidate].GratingType"
    s6=" [dbo].[PetalCandidate].Direction"
    s7=" [CoarsePitch]"
    s8=" [CoarseCD]"
    s9=" [dbo].[HWSubsystemImaging].[Polarization]"
    s10="[dbo].[HWSubsystemImaging].[NaOption]"
    select_str=" SELECT "+s1
    for s in [s2,s3,s4,s5,s6,s7,s8,s9,s10]:
        select_str=select_str+ "," + s

#    print(select_str)

    f1=" [dbo].[PetalAtFocusContext]"
    f2=" [dbo].[PetalAtFocusesToPetalCandidates]"
    f3=" [dbo].[FourierHarmonic]"
    f4=" [dbo].[PetalCandidate]"
    f5=" [dbo].[GDSMapping]"
    f6=" [dbo].[HWSubsystemImaging]"
    from_str=" FROM " +f1
    for f in [f2,f3,f4,f5,f6]:
        from_str=from_str+","+f

#    print(from_str)

    w1=" [dbo].[PetalAtFocusContext].Id=[dbo].[PetalAtFocusesToPetalCandidates].PetalAtFocusRefId"
    w2=" and [dbo].[FourierHarmonic].PetalAtFocusContext_Id=[dbo].[PetalAtFocusContext].Id"
    w3=" and [dbo].[PetalAtFocusesToPetalCandidates].PetalCandidateRefId = [dbo].[PetalCandidate].Id"
    w4=" and [dbo].[GDSMapping].NominalGeometry_Id = [dbo].[PetalCandidate].NominalGeometry_Id"
    w5=" and [dbo].[PetalCandidate].HWSubsystem_Id= [dbo].[HWSubsystemImaging].Id"
    w6=" and [dbo].[HWSubsystemImaging].[ColorFilter] = '%s'" % spectrum
    where_str=" WHERE "
    for w in [w1,w2,w3,w4,w5,w6]:
        where_str=where_str+w
    
#    print(where_str)

    ss=select_str+from_str+where_str+" ORDER BY ZPosition,ordr"
    return ss
        

def save_proj_data(rows,prname,spectrum,comm):
    nc=len(rows[0])
    nr=len(rows)
    a=np.zeros((nr,nc),dtype=float)
    for i in range(nr):
        for j in range(nc):
            a[i,j]=rows[i][j]
    
    fname= prname+"_"+spectrum+"_"+comm+'.flt'
    write_arr2(a,fname)
    print("file: "+fname +" is written")
    return nr



if len(sys.argv)!=4:
    print("usage: ",sys.argv[0]+" proj_name spect comment")
    quit()

project_name=sys.argv[1]
spec=sys.argv[2]
comment=sys.argv[3]
#
cnx=pyodbc.connect('DRIVER={SQL Server};SERVER=(local)\MTD;DATABASE=master;UID=sa;PWD=Mtd123')
curs = cnx.cursor()
ss="SELECT [Id],[Name] FROM [Application].[dbo].[ProjectHeaders]" 
lst = curs.execute(ss)
rows = curs.fetchall()
for x in rows:
    if x[1]==project_name :
        pid=x[0]
        break
cnx.close()
#print('project_name=',project_name,'   project_id=',pid)
print('   project_id=',pid)
dbname='Project_'+pid
cs='DRIVER={SQL Server};SERVER=(local)\MTD;DATABASE=%s;UID=sa;PWD=Mtd123'% dbname


ss=set_search_str(spec) 
cnx=pyodbc.connect(cs)
cu = cnx.cursor()
lst = cu.execute(ss)
rows = cu.fetchall()
L=len(rows) 
if L>0:
    nr=save_proj_data(rows,project_name,spec,comment)
    print(str(nr)+" lines saved")
else:
    print("nothing to save!")
cnx.close()



