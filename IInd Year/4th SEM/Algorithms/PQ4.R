library(RMySQL)
library(DBI)

con <- dbConnect(MySQL(),username = "root", host="localhost", dbname = "rprogramm")

#x <- dbGetQuery(con, "create table STUDENT(S_Id INT PRIMARY KEY, Name VARCHAR(10), Course VARCHAR(15), B_Date DATE)")

ins1 <- "INSERT INTO STUDENT(S_Id,Name,Course,B_Date) VALUES (1,'Meir','MATHS','05-03-2002'),(2,'Ashima','CS','12-12-2001'),(3,'Aadya','CS','20-10-2003'),(4,'Anuj','ECONOMICS','19-02-1999'),(5,'Riya','MATHS','26-10-2000')"
dbSendQuery(con, ins1)

y <- dbGetQuery(con, "select * from STUDENT")

z <- dbGetQuery(con, "TRUNCATE TABLE STUDENT")

dbGetQuery(con, "drop table STUDENT")

