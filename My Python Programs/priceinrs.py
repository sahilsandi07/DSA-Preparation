#item price in dollars
old_price = {'milk': 1.02, 'coffee': 2.5, 'bread': 2.5}
#item price in rupees
new_price = {k:v*72 for k,v in old_price.items()}
print("New Price In Rupees is: ",new_price)