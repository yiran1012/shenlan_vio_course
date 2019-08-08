import matplotlib.pyplot as plt

file = open('./lambda.txt')
lambda_data = []
for line in file.readlines():
    line=line.strip('\n')
    lambda_data.append(float(line))

length = len(lambda_data)
i = range(0,length)

plt.plot(i,lambda_data,marker='o',markerfacecolor='blue')
plt.xlabel('iter')
plt.ylabel('lambda')
plt.title('lambda_curve')
plt.show()
plt.savefig('./lambda.png')
