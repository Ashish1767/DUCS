a<-read.csv("emp.csv")
print("printing the dataframe")
print(a)

print("no of observations and variables")
dim(a)

print(paste("Average Salary Of all Faculty Members = ",mean(a$Salary)))

print("Average Salary Of Male and Female Faculty Members = ")
print(aggregate(a$Salary~a$Gender,a,mean))

print("Average Salary Rank Wise Faculty Members = ")
print(aggregate(a$Salary~a$Rank,a,mean))

print(" Count the number of male Asst. Prof and female Associate professors.")
c <- length(which(a$Rank == "AstProf " & a$Gender == "M"))
print(paste("The number of male Asst. Prof is : ", c))

c<- length(which(a$Rank == "AsctProf" & a$Gender == "F"))
print(paste("The number of female Associate professors are : ", c))

print("first two coloumn of second row are:")
print(a[c(1,2),2])

print("years of service of all teachers:")
print(a$YrsOfService)

print("years since phd of all teachers:")
print(a$YrsSincePhd)

print(" Print the highest salary drawing male Associate Professor with a maximum year of services.")

f<- max(a[a$Rank == "AsctProf" & a$Gender == "M", "YrsOfService"])
x<- which(a$YrsOfService == f)
m<- max(a[x, "Salary"])
print(paste(" The highest salary is : ",m))

print(" Display the Rank of the teacher whose salary is more than 150.")
g <-a[a$Salary > 150, "Rank"]
print(" The rank of teacher with salary more than 150 is : ")
print(g)
print(" Add a new column 'special allowance' which is 5% of the salary.")
h <- a["SpecialAllowance"] <- (a$Salary * 5)/100
print("New column : ")
print(h)
 
 