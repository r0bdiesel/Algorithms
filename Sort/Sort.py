import math
def what_num(item):
	return item.get_num()

class item():
	def __init__(self, num):
		self.num = num
	def get_num(self):
		return self.num

class shape():
	def __init__(self,k):
		self.k = k
		print("constuct")
	def area(self):
		print("area not defined",self.k)
		
class node(shape):
	def __init__(self,v,l=None,h=None):
		self.data = v
		self.Length = l
		self.height = h
		shape.__init__(self,4)
	


def Quicksort(arry,i,j):
	start =i
	end =j
	p =j
	if(j-i<=1):
		return
	pivot = arry[j]
	#print("start",i,j,pivot)
	j-=1
	while(i<j):
		if(arry[i] >= pivot and arry[j] <= pivot):
			#print(i,j,"C")
			temp = arry[i]
			arry[i] = arry[j]
			arry[j] = temp
		if(arry[i] <= pivot):
			i+=1
		if(arry[j] >= pivot):
			j-=1
	if(pivot <= arr[i]):
		temp =arry[i]
		arry[i] = pivot
		arry[p] = temp
		i=i-1
		j=i+1
	#print(arry, start,i,j,end)
	Quicksort(arry,start,i)
	Quicksort(arry,j,end)
			

def mergesort(arry):
	if(len(arry) ==1):
		return arry 
	m = math.floor(len(arry)/2)
	#print(arry, m)
	left = arry[:m]
	right = arry[m:]
	#print(left,m,right)
	left = mergesort(left)
	right = mergesort(right)
	#print(left,m,right)
	return merge(left,right)

def merge(left,right):
	merged = []
	#print("merge",left,right)
	i=0
	j=0
	while((i<len(left)) and (j < len(right))):
		if(left[i] < right[j]):
			merged.append(left[i])
			i +=1
		else:
			merged.append(right[j])
			j+=1
	while(i < len(left)):
		merged.append(left[i])
		i +=1
	while(j<len(right)):
		merged.append(right[j])
		j +=1
	#print("merged",merged)
	return merged
	

if __name__ == "__main__":
	print("here")
	sh = node(1)
	sh.area()
	
	arr = [23,6,5,4,7,30,8,1,2,10,6,6,6]
	Quicksort(arr,0,len(arr)-1)
	#print(arr)
	
	arr = [5,3,2,5,4,6,7,10,3]
	print(arr)
	arr = mergesort(arr)
	print(arr)
	
	arr = [5,3,2,5,4,6,7,10,3]
	arry = []
	for x in arr:
		arry.append(item(x))
	
	for x in arry:
		print(x.get_num())
	
	
	print("sort")
	arry2 = sorted(arry, key=what_num, reverse=True)
	
	for x in arry2:
		print(x.get_num())
	
	