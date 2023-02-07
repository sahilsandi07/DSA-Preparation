original_dict={1: 1, 2: 2, 3: 3, 4: 4}
new_dict={k:v*v for k,v in original_dict.items()}
print("New Dictionary is: ",new_dict)