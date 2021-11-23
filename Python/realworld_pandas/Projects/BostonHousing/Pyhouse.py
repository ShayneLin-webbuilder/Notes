import numpy as np # linear algebra
import pandas as pd # data processing, CSV file I/O
# Input data files are available in the "../input/" directory.
#For example, running this (by clicking run or pressing shift+Enter) will list the files in the input directory
import os
print(os.listdir("../input"))
# Any results you write to the currennt directory are saved as output.
from pandas import read_csv
#Lets load the dataset and sample some
column_names= ['CRIM','ZN', 'INDUS','CHAS','NOX','RM','AGE','DIS','RAD','TAX','RAD','TAX','PTRATIO','B','LSTAT','MEDV']