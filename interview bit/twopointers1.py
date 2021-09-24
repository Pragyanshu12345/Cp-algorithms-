'''https://www.interviewbit.com/problems/sort-by-color/
  
Given an array with n objects colored red, white or blue, 

sort them so that objects of the same color are adjacent, with the colors in the order red, white and blue.

Here, we will use the integers 0, 1, and 2 to represent the color red, white, and blue respectively.

Note: Using library sort function is not allowed.

Example :

Input : [0 1 2 0 1 2]
Modify array so that it becomes : [0 0 1 1 2 2]'''


Code is given below:
  
  class Solution:
    def sortColors(self, a):
        l,mid,h=0,0,len(a)-1
        while(mid<=h):
            if(a[mid]==0):
                a[mid],a[l]=a[l],a[mid]
                mid,l=mid+1,l+1
            elif(a[mid]==1):
                mid+=1
            else:
                a[mid],a[h]=a[h],a[mid]
                h=h-1
        return a
