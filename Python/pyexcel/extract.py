import pandas as pd
import numpy as np

files = ['/Users/shayne_lin/Desktop/Notes/Python/pyexcel/SampleData2.xlsx','/Users/shayne_lin/Desktop/Notes/Python/pyexcel/SampleData1']

for file in files:
    df = pd.read_excel(file)
    pencil = df['Rep'].where(df['Item'] == 'Pencil').dropna()
    print(file)
    print(pencil)
