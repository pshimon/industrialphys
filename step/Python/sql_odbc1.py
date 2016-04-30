#! python
########################################################################
# Shimon Panfil: Industrial Physics and Simulations                   ##
# http://industrialphys.com                                           ##
# THE SOFTWARE IS PROVIDED "AS IS", USE IT AT YOUR OWN RISK           ##
########################################################################
#   takes project names from db and writes them to file file_name
#   one per line
import sys
import pyodbc
if len(sys.argv)!=2:
    print("usage: ",sys.argv[0]+"file_name")
    quit()
file_name=sys.argv[1]
fid = open(file_name, 'w')

cnx=pyodbc.connect('DRIVER={SQL Server};SERVER=(local)\MTD;DATABASE=master;UID=sa;PWD=Mtd123')
curs = cnx.cursor()
ss="SELECT [Id],[Name] FROM [Application].[dbo].[ProjectHeaders]" 
lst = curs.execute(ss)
rows = curs.fetchall()

for x in rows:
    print(x[1],file=fid)  
    #print('project_name=',x[1],'   project_id=',x[0],file=fid) 
cnx.close()
fid.close()
print ('file:',file_name,'is written')
