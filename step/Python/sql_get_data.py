import sql

def get_data(pid,spectrum,polarization,na,gtype,direction):
    dbname='Project_'+pid
    print(dbname)
    c = sql.Connection('(local)\MTD','sa', 'Mtd123', version='sql2014',db=dbname)
    print("Connection string: " + c.constr)
    if c.connected == 1:
        print("Connected OK")

    cu = c.cursor
    sstr='s='+spectrum
    pstr='_p='+str(polarization)
    nstr='_n='+str(na)
    gstr='_g='+str(gtype)
    dstr='_d='+str(direction) 
    ttl=sstr+pstr+nstr+gstr+dstr
    s1=" ZPosition,"
    s2=" [dbo].[FourierHarmonic].[Order] as ord,"
    s3=" A,B"
    select_str=" SELECT "
    for s in [s1,s2,s3]:
        print(s)
        select_str=select_str+s

    f1=" [dbo].[PetalAtFocusContext],"
    f2=" [dbo].[PetalAtFocusesToPetalCandidates],"
    f3=" [dbo].[FourierHarmonic],"
    f4=" [dbo].[PetalCandidate],"
    f5=" [dbo].[GDSMapping],"
    f6=" [dbo].[HWSubsystemImaging]"
    from_str=" FROM "
    for f in [f1,f2,f3,f4,f5,f6]:
        print(f)
        from_str=from_str+f

    w1=" [dbo].[PetalAtFocusContext].Id=[dbo].[PetalAtFocusesToPetalCandidates].PetalAtFocusRefId"
    w2=" and [dbo].[FourierHarmonic].PetalAtFocusContext_Id=[dbo].[PetalAtFocusContext].Id"
    w3=" and [dbo].[PetalAtFocusesToPetalCandidates].PetalCandidateRefId = [dbo].[PetalCandidate].Id"
    w4=" and [dbo].[GDSMapping].NominalGeometry_Id = [dbo].[PetalCandidate].NominalGeometry_Id"
    w5=" and [dbo].[PetalCandidate].HWSubsystem_Id= [dbo].[HWSubsystemImaging].Id"
    w6=" and [dbo].[PetalCandidate].Direction = "+str(direction)
    w7=" and [dbo].[PetalCandidate].GratingType = "+str(gtype)
    w8=" and [dbo].[HWSubsystemImaging].[ColorFilter] = '%s'" % spectrum
    w9=" and [dbo].[HWSubsystemImaging].[Polarization] = " + str(polarization)
    w10=" and [dbo].[HWSubsystemImaging].[NaOption] = " +str(na)
    where_str=" WHERE "
    for w in [w1,w2,w3,w4,w5,w6,w7,w8,w9,w10]:
        print(w)
        where_str=where_str+w

    print(ttl)
    ss=select_str+from_str+where_str
    print(ss)
    lst = cu.execute(ss)
    print('rowcount=' + str(cu.rowcount))
    rows = cu.fetchall()
    c.close()
    return rows

pid=sql.get_id('SN1_SCC-shimon')
#pid='A8168FD0-1F56-4827-87F4-B7B89747E205'                                                           
dt=get_data(pid,spectrum="White",polarization=0,na=0,gtype=1,direction=0)
