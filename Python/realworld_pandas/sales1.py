import pandas as pd
import os

# Task # 1: Merge the 12 months of sales data into 
# a single CSV file

files = [file for file in os.listdir('/Users/shayne_lin/Desktop/Pandas-Data-Science-Tasks/SalesAnalysis/Sales_Data')]

all_months_data = pd.DataFrame()

for file in files:
    df = pd.read_csv("/Users/shayne_lin/Desktop/Pandas-Data-Science-Tasks/SalesAnalysis/Sales_Data"+file)
    all_months_data = pd.concat([all_months_data, df])

all_months_data.to_csv("all_data.csv",index=False)

