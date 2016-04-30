#! python
########################################################################
# Shimon Panfil: Industrial Physics and Simulations                   ##
# http://industrialphys.com                                           ##
# THE SOFTWARE IS PROVIDED "AS IS", USE IT AT YOUR OWN RISK           ##
########################################################################

# based on dblib3.py (http://code.activestate.com/recipes/578906-python-database-interface-for-ms-sql-server-python/)
#Created by Jorge Besada, July 2014
#Same program as the Python Database Interface for MS SQL Server (for Python 2.x)
#converted to Python 3
import os
import sys
class Connection:
    def __init__(self, servername, username='', password='', db='', version=''):
        self.version = version;
        self.servername = servername;
        self.username = username;
        self.password = password;
        self.defdb = db;
        self.constr = '';
        if db == '':
            self.defdb = 'master'
        self.connected = 0
        if self.version == None or self.version == "":
            print("Need to pass sql version argument")
            return self
        if self.version == "sql2000" or self.version == "sql7":
            execsql = "osql"
        if self.version in ("sql2005", "sql2008", "sql2012", "sql2014"):
            execsql = "sqlcmd"
        if self.version == "sybase":
            execsql = "isql"
            print("Sorry, Sybase has not been implemented yet!")
            return self
        if username == '':
            self.constr = execsql + " -E -S" + self.servername + " -d" + self.defdb + " /w 8192 "
        else:
            self.constr = execsql + " -U" + self.username + " -P" + self.password + " -S" + self.servername + " -d" + self.defdb + " /w 8192 "

            #test connection:
        s = "set nocount on select name from master..syslogins where name = 'sa'"
        lst = os.popen(self.constr + ' -Q' + '"' + s + '"').readlines()

        try:
            if lst[2].strip() == 'sa':
                self.connected = 1
            else:
                self.connected = 0
            c = Cursor()
            c.servername = servername
            c.username = username
            c.password = password
            c.defdb = db
            c.constr = self.constr
            self.cursor = c
        except IndexError:
            print("Could not connect")

    def commit(self):
        "this is here for compatibility"
        pass

    def close(self):
        self = None
        return self


class Cursor:
    def __init__(self):
        self.defdb = ''
        self.servername = ''
        self.username = ''
        self.password = ''
        self.constr = ''
        self.rowcount = -1
        self.records = []
        self.rowid = 0
        self.sqlfile = "-Q"
        self.colseparator = chr(1)  #default column separator
        #this is going to be a list of lists, each one with:                                                                                       
        #name, type_code, display_size, internal_size, precision, scale, null_ok                                                                   
        self.description = []
        self.fieldnames = []
        self.fieldvalues = []
        self.fieldvalue = []
        #one dictionary by column                                                                                                                  
        self.dictfield = {'name': '', 'type_code': 0, 'display_size': 0, 'internal_size': 0, 'precision': 0, 'scale': 0,
                          'null_ok': 0}
        #list of lists                                                                                                                             
        self.dictfields = []

        #this is for compatibility to allow both types of calls:

    #cursor = connection.cursor() or using cursor = connection.cursor
    def __call__(self):
        c = Cursor()
        return c

    def execute(self, s):
        self.records = []
        lst = os.popen(self.constr + ' -s' + self.colseparator + " " + self.sqlfile + '"' + s + '"').readlines()
        if len(lst) == 0:
            return self.rowcount

        #If we get here we have results
        #rowcount maybe in last line, in this form: (4 rows affected)                                                                              
        tmplastline = lst[-1]
        if tmplastline[
            0] == "(":  #there is a rowcount
            lastline = lst[-1]
            spacepos = lastline.index(" ")
            cnt = lastline[1:spacepos]
            self.rowcount = int(cnt)
        else:
            #last line has no recordcount, so reset it to 0                                                                                        
            self.records = lst[:]
            self.rowcount = 0
            return self.rowcount

            #if we got here we may have a rowcount and the list with results
        i = 0
        #process metadata if we have it:                                                                                                           
        firstline = lst[0]
        lst1 = lst[0].split(self.colseparator)
        self.fieldnames = []
        for x in lst1:
            x1 = x.strip()
            self.fieldnames.append(
                x1)  #add column name
        #need to make a list for each column name                                                                                                  
        self.description = []
        for x in self.fieldnames:
            l = []
            l.append(x)
            for m in range(len(self.dictfield) - 1):
                l.append(0)
            l2 = tuple(l)
            self.description.append(l2)
        self.description = tuple(self.description)

        #Data section: lst[0] is row with column names,skip                                                                                        
        #If the resulting string starts and ends with '-', discard                                                                                 

        for x in lst[1:-1]:
            x0 = ''.join(x)
            x1 = x0.strip()
            if x1 > '' and x1[0] > '-' and x1[-1] > '-':
                #if x1 <> '' and x1[0] <> '-' and x1[-1] <> '-':
                self.records.append(x1)
                #reset for each execution
        self.rowid = 0
        return self.rowcount

        #returns one row of the result set, keeps track of the position

    def fetchone(self):
        i = self.rowid
        j = i + 1
        self.rowid = j
        try:
            return tuple(self.records[i].split(self.colseparator))
        except IndexError:
            pass

            #returns whole recordset

    def fetchall(self):
        lst = []
        try:
            for x in range(self.rowid, self.rowcount):
                x1 = tuple(self.records[x].split(self.colseparator))
                lst.append(x1)
        except IndexError:
            pass
        return lst

    def close(self):
        self.records = None
        self = None
        return self

def get_id(project_name):
    c = Connection('(local)\MTD','sa', 'Mtd123', version='sql2014')
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


