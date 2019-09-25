import numpy as np
def kmeans(input_data,K):
  newc=input_data[:K]
  cluster={  }
  centroids=np.zeros(K)
  while not(np.isclose(newc,centroids)).all() : 
    centroids=newc
    sigma=np.zeros(K)
    count=np.zeros(K)
    for x in input_data : 
      t=np.abs(x-centroids)
      i=np.where(t==t.min())[0][0]
      cluster[x]=i
      sigma[i]+=x
      count[i]+=1 
    
     
    newc=(sigma/count) 
  
   
  return(centroids,cluster)


input_data=np.array([ 3,5,8,0,135,234,29 ],np.float)
centroids,cluster=kmeans(input_data,5)
print "input:",input_data
print centroids
print cluster