import sql
def get_id(project_name):
    c = sql.Connection('(local)\MTD','sa', 'Mtd123', version='sql2014')
    cu = c.cursor
    ss="SELECT [Id],[Name] FROM [Application].[dbo].[ProjectHeaders]" 
    lst = cu.execute(ss)
    rows = cu.fetchall()
    for x in rows:
        if x[1]==project_name :
            pid=x[0]
            break

    c.close()
    return pid

def get_data(pid,spectrum,polarization,na,gtype,direction):
    dbname='Project_'+pid
    print(dbname)
    c = sql.Connection('(local)\MTD','sa', 'Mtd123', version='sql2014',db=dbname)
    print("Connection string: " + c.constr)
    if c.connected == 1:
        print("Connected OK")

    cu = c.cursor
    ss='''SELECT\
       ZPosition, [dbo].[FourierHarmonic].[Order] as HarmOrder, A,B\
	   ,[dbo].[PetalCandidate].GratingType,[dbo].[PetalCandidate].Direction\
	   ,[CoarsePitch],[CoarseCD]\
	   ,[dbo].[HWSubsystemImaging].[ColorFilter]\
	   ,[dbo].[HWSubsystemImaging].[Polarization]\
	   ,[dbo].[HWSubsystemImaging].[NaOption]\
  FROM\
	  [dbo].[PetalAtFocusContext],\
	  [dbo].[PetalAtFocusesToPetalCandidates],\
	  [dbo].[FourierHarmonic],\
	  [dbo].[PetalCandidate],\
	  [dbo].[GDSMapping],\
	  [dbo].[HWSubsystemImaging]\
   WHERE\
	[dbo].[PetalAtFocusContext].Id=[dbo].[PetalAtFocusesToPetalCandidates].PetalAtFocusRefId \
  and	[dbo].[FourierHarmonic].PetalAtFocusContext_Id=[dbo].[PetalAtFocusContext].Id\
  and	[dbo].[PetalAtFocusesToPetalCandidates].PetalCandidateRefId = [dbo].[PetalCandidate].Id\
  and	[dbo].[GDSMapping].NominalGeometry_Id = [dbo].[PetalCandidate].NominalGeometry_Id\
  and	[dbo].[PetalCandidate].HWSubsystem_Id= [dbo].[HWSubsystemImaging].Id\
  and	[dbo].[PetalCandidate].Direction = direction\
  and	[dbo].[PetalCandidate].GratingType = gtype \
  and	[dbo].[HWSubsystemImaging].[ColorFilter] = spectrum\
  and	[dbo].[HWSubsystemImaging].[Polarization] = polarization\
  and	[dbo].[HWSubsystemImaging].[NaOption] = na\
  order by ZPosition, [Order]''' 
    print(ss)


    lst = cu.execute(ss)
    print('rowcount=' + str(cu.rowcount))

    rows = cu.fetchall()

    c.close()
    return rows
                                                  
