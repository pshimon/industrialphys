import sql
c = sql.Connection('(local)\MTD','sa', 'Mtd123', version='sql2014')
print("Connection string: " + c.constr)
if c.connected == 1:
    print("Connected OK")
cu = c.cursor
lst = cu.execute('SELECT TOP 1000 [Id],[Name] FROM [Application].[dbo].[ProjectHeaders]')
print('rowcount=' + str(cu.rowcount))
rows = cu.fetchall()
for x in rows:
    print(x)
c.close()

                                                                
