import csv as csv 
import numpy as np


csv_file_object = csv.reader(open('classification_dataset_training.csv', 'rU')) 
header = next(csv_file_object)                        
data=[]                       
for row in csv_file_object:      
    data.append(row)             
data = np.array(data) 	      
number_ID = np.size(data[0::,51].astype(np.float))
number_rate1 = np.sum(data[0::,51].astype(np.float))
proportion_rate1=number_rate1/number_ID
print(proportion_rate1)
but_0=data[0::,1]=="0";
but_0_rate1=data[but_0,51].astype(np.float)
proportion_1 = np.sum(but_0_rate1) / np.size(but_0) 
print(proportion_1)
# women_only_stats=data[0::,4]=="female" 
# men_only_stats=data[0::,4] !="female"
# women_onboard=data[women_only_stats,1].astype(np.float)    
# men_onboard=data[men_only_stats,1].astype(np.float)
# proportion_women_survived = \
#                        np.sum(women_onboard) / np.size(women_onboard) 
# proportion_men_survived = \
#                        np.sum(men_onboard) / np.size(men_onboard) 
# print ('Proportion of women who survived is %s' % proportion_women_survived)
# print ('Proportion of men who survived is %s' % proportion_men_survived)
#predict the test_file
test_file = open('classification_dataset_testing.csv', 'rU')
test_file_object = csv.reader(test_file)
header = next(test_file_object)			       
# #write the prediction result to the predition file
prediction_file = open("BasedModel.csv", "wt", newline='\n')
prediction_file_object = csv.writer(prediction_file)

prediction_file_object.writerow(["ID", "rating"])
for row in test_file_object:       # For each row in test.csv
    if row[1] == '0':         # is it a female, if yes then                                       
        prediction_file_object.writerow([row[0],'0'])    # predict 1
    else:                              # or else if male,       
        prediction_file_object.writerow([row[0],'1'])    # predict 0
test_file.close()
prediction_file.close()