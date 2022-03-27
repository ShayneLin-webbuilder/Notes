#Download the required package:   
#Load the packages.  

#code shown below:  
library(readxl)
library(DBI)  
library(RSQLite)  
library(dplyr)  
head(Bos)
view(mtcars)
load(mtcars)
ncol(mtcars)
nrow(mtcars)
names(mtcars)
mtcars

SampleData1 <- read_excel("SampleData1.xlsx")
Portal_SampleData1 <- dbConnect(RSQLite::SQLite(),"SampleData1")

dbListTables(Portal_SampleData1)
mysample_df <- collect(Portal_SampleData1)
#mycarsconnect <- dbConnect(RSQLite::SQLite(), "mtcars")

## to disconnect from RSQLite when finish, use function 

# dbDisconnect()

## Look at the tables with the connection: mycarsconnect

#dbListTables(mycarsconnect)
#mycarsconnect
#mycarsconnect_df <- collect(mycarsconnect)

## Look at the details (fields) for individual tables

#dbListFields(mycarsconnect,"fields")

## Instead of looking at tables in data frame, we can directly
## look at the tables by using tbl() command from dplyr. 
## we first input the first attribute by using our connection,
## then we should use the table's name that we're trying to 
## connect to. However, surveys is still not a data frame in R yet, 
## so we need to download the actual datafram to be able to do it with 'collect()
## function'

#surveys <- tbl(mycarsconnect,"surveys")
#surveys_df <- collect(surveys)


