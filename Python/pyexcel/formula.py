import openpyxl

excel_files = ['/Users/shayne_lin/Desktop/Notes/Python/pyexcel/SampleData2.xlsx','/Users/shayne_lin/Desktop/Notes/Python/pyexcel/SampleData1.xlsx']

for file in excel_files:
    wb = openpyxl.load_workbook(file)
    worksheet = wb["SalesOrders"]
    worksheet['G46'] = '=AVERAGE(G3:G45)'
    wb.save(file)
