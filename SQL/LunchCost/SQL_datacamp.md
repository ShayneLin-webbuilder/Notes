---
output:
  html_document: default
  pdf_document: default
---
# Load required packages  
install.packages("sqldf")  
library("sqldf")  
library(readxl)  # only if reading excel xlsx file.

# Importing data to environment  
orders <- read_excel("/Users/shayne_lin/Desktop/work experiennce/UCSB/PSTAT10/LunchCost/orders.xlsx")  
  
# Selecting columns

1. SELECTing multiple columns  
    + To select multiple columns from a table, simply separate the column names with **commas**
2. select all columns from a table  
    + Typing out every column name would be a pain, so there's a handy shortcut: "SELECT *"  
  ```  
    SELECT *  
    FROM people
  ```
  
