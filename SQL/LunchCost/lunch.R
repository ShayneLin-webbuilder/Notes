#Load sqldf package, which will load all others necessary
# By default, SQLite runs in background to do processing, could use others DB 
# engines if you wanted  

install.packages("sqldf")
library("sqldf")
library(readxl)

#Import employees data
employees <- read_excel("/Users/shayne_lin/Desktop/work experiennce/UCSB/PSTAT10/LunchCost/employees.xlsx")
View(employees)

#Import orders data - Matt G, Jason T, Matt W, and La Shanda H go to sushi lunch
#Taking a potential client with them

orders <- read_excel("/Users/shayne_lin/Desktop/work experiennce/UCSB/PSTAT10/LunchCost/orders.xlsx")

##### Single Table operations #####

#1 - Select all employees that are male and name it "male_employees"

male_employees <- sqldf("SELECT * FROM employees WHERE gender ='m' ")

#2 - Get a count by first name

name_counts <- sqldf("SELECT *, COUNT(firstname) as occurances FROM employees GROUP BY firstname")

#3 - Get a count by first name, excluding non-employees  

name_counts_emponly  <- sqldf("SELECT firstname, COUNT(firstname) as occurances 
                              FROM employees 
                              WHERE firstname != 'rudi' 
                              GROUP BY firstname")

#4 - Use a case statement to define a new data column of california employees,
#    using "Lower" to evaluate all names as lowercase to ensure case insensitivity

employees_cali <- sqldf("SELECT *,
                        CASE
                          WHEN lower(firstname) = 'stewart' THEN 1
                          WHEN lower(firstname) = 'hilo' THEN 1
                          WHEN lower(firstname) = 'jon' THEN 1
                          WHEN lower(firstname) = 'solon' THEN 1
                          ELSE 0
                        END as cali_emp
                        FROM employees")
# additional useful information from the net on searching for 'like' and '%gmail%'

      ####library(sqldf)
          #data <- data.frame(E_MAIL = c("x@x.com", "x@yahoo.com"))
          
          #sqldf("select E_MAIL,
          #  case
          #    when E_MAIL like '%gmail%' then 1
          #    when E_MAIL like '%yahoo%' then 1
          #    when E_MAIL like '%hotmail%' then 1
          #    else 0
          #  end express
          #  from data")

#5 Sort employees_cali by cali_emp descending, first name assending (ascending is default)

employees_cali_sorted <- sqldf("SELECT *
                               FROM employees_cali
                               ORDER BY cali_emp DESC, firstname
                               ")


##### Multi-Table connections ##### 

#1. Left join employees and orders table (keep all records from employees table,
#   matching records from orders)

left_join_equiv <- sqldf("SELECT * 
                    FROM employees a
                    LEFT JOIN orders b ON a.id=b.id
                    WHERE a.firstname !='rudi'
                   ")
# to remove a dataset: use "rm("table_name")

#2. "Right join" isn't supported in sqldf package, but switching order of tables
#    and left join is functionally equivalant

right_join_equiv <- sqldf("SELECT *
                          FROM orders a
                          LEFT JOIN employees b on a.id=b.id
                          ")
right_join_drop <- sqldf("SELECT item, quantity_ordered, item_cost, lastname, firstname
                          FROM orders 
                          LEFT JOIN employees  on orders.id=employees.id
                          ")

#3. Inner join...select only records that mach both tables, done by only a 
#   where statement.

inner_join <- sqldf("SELECT *
                    FROM employees a, orders b
                    WHERE a.id = b.id
                    ")

#4. Matt G. sees bill, wonders how bill can be so low?
#   Join orders to employees, find who is ordering item less than 10 dollars,
#   sorted by lowest cost

inexpensive_items <- sqldf("SELECT *
                           FROM right_join_drop
                           WHERE item_cost<10
                           ORDER BY item_cost
                           ")

#4a. Realizing some things are priced by piece, figure out who spent less than 
#   $20 on any one kind of food

inexpensive_line_items <- sqldf("SELECT *,
                                (item_cost*quantity_ordered) as item_level_cost
                                FROM inexpensive_items
                                WHERE item_level_cost < 20
                                ORDER BY item_level_cost
                                ")

#5.  Realizing that even item level cost is wrong question, Matt G. wants to 
#    know whose total lunch < $30
#    Need to use GROUP BY to get totals by person, then use HAVING instead of 
#    WHERE because of the use of GROUP BY summary function (WHERE is a record )
#    level operator

lunch_under_30 <- sqldf("SELECT lastname, firstname,
                        SUM(item_cost * quantity_ordered) as lunch_cost
                        FROM orders a
                        LEFT JOIN employees b ON a.id=b.id
                        GROUP BY a.id
                        HAVING lunch_cost <30
                        ")

#6.   Matt G. wants to keep track of food consumption per person, particularly 
#     who are the "lightweights' are in the group. Who's eating less than average
#     on a cost basis?    This requires a subquery to first determine the average
#     cost of this meal, passing that value to the having clasuse

# Subquery: returns a single value for the average lunch cost for employees (those
# with valid ID num)

# "SELECT SUM(item_cost * quantity_ordered)/COUNT(DISTINCT id) as avg_lunch_cost
# FROM orders WHERE id != 'NA'")

lower_than_avarage_cost <- sqldf("SELECT lastname,firstname,
                                  SUM(item_cost * quantity_ordered) as lunch_cost
                                  FROM orders a
                                  LEFT JOIN employees b ON a.id= b.id
                                  WHERE a.id != 'NA'
                                  GROUP BY a.id
                                  HAVING lunch_cost < (
                                                        SELECT SUM(item_cost * quantity_ordered)/COUNT(DISTINCT id) as avg_lunch_cost
                                                        FROM orders
                                                        WHERE id != 'NA'
                                  )
                                 ")
cost <- sqldf("SELECT SUM(item_cost * quantity_ordered)/COUNT(DISTINCT id)
              FROM orders
              WHERE id != 'NA'")



