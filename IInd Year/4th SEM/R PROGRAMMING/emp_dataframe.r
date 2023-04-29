print(getwd())
setwd("C:/Users/user/OneDrive/Desktop/DU/DSC SEMESTER 4/SEC - R/SEC - R LAB WORK")
print(getwd())

emp_data<- read.csv("C:/Users/user/OneDrive/Desktop/DU/DSC SEMESTER 4/SEC - R/SEC - R LAB WORK/emp.csv")
print(emp_data)

attach(emp_data)

print("a. Find out the number of observations and variables in the given dataset.")
a <- dim(emp_data)
print("Number of observations and variables is : ")
print(a)

print("'b. Calculate the average salary of all faculty members, male and female faculty members separately, and rank wise faculty members.")
b <- aggregate(Salary ~Rank, emp_data, mean)
print("Average salary on the basis of rank")
print(b)

b <- aggregate(Salary ~Gender, emp_data, mean)
print("Average salary on the basis of gender ")
print(b)

print("c. Count the number of male Asst. Prof and female Associate professors.")
c <- length(which(Rank == "AstProf " & Gender == "M"))
print(paste("The number of male Asst. Prof is : ", c))

c<- length(which(Rank == "AsctProf" & Gender == "F"))
print(paste("The number of female Associate professors are : ", c))

print("d. Display first two columns of second row.")
d <- emp_data[2, 1:2]
print("First two columns of second row are : ")
print(d)

print("e. Display YrsSincePhd and YrsofService of all the teachers.")
e <- emp_data[c("YrsSincePhd", "YrsOfService")]
print("YrsSincePhd and YrsOfService of all the teachers are : ")
print(e)

print("f. Print the highest salary drawing male Associate Professor with a maximum year of services.")
f <- max(emp_data[Rank == "AsctProf" & Gender == "M", "YrsOfService"])
x <- which(YrsOfService == f)
m <- max(emp_data[x, "Salary"])
print(" The highest salary is : ")
print(m)

print("g. Display the Rank of the teacher whose salary is more than 150.")
g <- emp_data[Salary > 150, "Rank"]
print(" The rank of teacher with salary more than 150 is : ")
print(g)

print("h. Add a new column 'special allowance' which is 5% of the salary.")
h <- emp_data["SpecialAllowance"] <- (Salary * 5)/100
print("New column : ")
print(h)